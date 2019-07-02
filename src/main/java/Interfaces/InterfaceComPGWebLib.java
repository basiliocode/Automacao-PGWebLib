package Interfaces;
import Estruturas.PW_GetData;
import com.sun.jna.Library;
import com.sun.jna.ptr.ShortByReference;

public interface InterfaceComPGWebLib extends Library {

    short PW_iInit (String path);

    short PW_iNewTransac (int bOper);

    short PW_iAddParam (int wParam, String pszValue);

    short PW_iExecTransac (PW_GetData [] vstParam, ShortByReference iNumParam );

    short PW_iPPDisplay (String pszMsg);

    short PW_iGetResult (int iInfo, byte [] pszData, int ulDataSize);

    short PW_iPPEventLoop (byte [] szDspMdg, int ulDisplaySize);

    short PW_iPPRemoveCard ();

    short PW_iPPAbort ();

    short PW_iPPGetCard (short uiIndex);

    short PW_iPPGoOnChip (short uiIndex);

    short PW_iPPFinishChip (short uiIndex);

    short PW_iConfirmation ( int ulStatus, String pszReqNum, String pszLocRef,
                             String pszExtRef, String pszVirtMerch, String pszAuthSyst);

    short PW_iIdleProc ();

    short PW_iPPDataConfirmation (short uiIndex);
}
