import Estruturas.PW_GetData;
import Interfaces.InterfaceComPGWebLib;
import com.sun.jna.Native;
import com.sun.jna.NativeLibrary;
import com.sun.jna.Platform;
import com.sun.jna.ptr.ShortByReference;

public class LibIntegrada {

    private InterfaceComPGWebLib pgWebLib;


    public LibIntegrada() {

        this.pgWebLib = Native.loadLibrary(Platform.isLinux() ? "/PGWebLib_Linux/PGWebLib.so" : "/PGWebLib_Windows/PGWebLib.dll",
                InterfaceComPGWebLib.class); //lendo a lib pela Interface
    }

    public short chamarPW_iInit(String caminho) {
        return pgWebLib.PW_iInit(caminho);
    }

    public short chamarPW_iNewTransac(int tipoOperacao) {
        return pgWebLib.PW_iNewTransac(tipoOperacao);
    }

    public short chamarPW_iAddParam(int wParam, String pszValue) {
        return pgWebLib.PW_iAddParam(wParam, pszValue);
    }

    public short chamarPW_iExecTransac(PW_GetData[] vstParam, ShortByReference iNumParam) {
        return pgWebLib.PW_iExecTransac(vstParam, iNumParam);
    }

    public short chamarPW_iPPDisplay (String pszMsg) { return pgWebLib.PW_iPPDisplay(pszMsg); }

    public short chamarPW_iPP_EventLoop(byte[] szDspMsg, int ulDisplaySize) {
        return pgWebLib.PW_iPPEventLoop(szDspMsg, ulDisplaySize);
    }

    public short chamarPW_iPP_RemoveCard() {
        return pgWebLib.PW_iPPRemoveCard();
    }

    public short chamarPW_iPPAbort () { return pgWebLib.PW_iPPAbort (); }

    public short chamarPW_iGetResult(int iInfo, byte[] pszData, int ulDataSize) {
        return pgWebLib.PW_iGetResult(iInfo, pszData, ulDataSize);
    }

    public short chamarPW_iPPGetCard(short uiIndex){ return pgWebLib.PW_iPPGetCard(uiIndex); }

    public short chamarPW_iPPGoOnChip(short uiIndex){ return pgWebLib.PW_iPPGoOnChip(uiIndex); }

    public short chamarPW_iPPFinishChip(short uiIndex){ return pgWebLib.PW_iPPFinishChip(uiIndex); }

    public short chamarPW_iConfirmation(int ulStatus,String pszReqNum, String pszLocRef,
                                        String pszExtRef, String pszVirtMerch, String pszAuthSyst){
        return pgWebLib.PW_iConfirmation(ulStatus, pszReqNum, pszLocRef, pszExtRef, pszVirtMerch, pszAuthSyst);
    }

    public short chamarPW_iIdleProc (){return pgWebLib.PW_iIdleProc(); }

    public short chamarPW_iPPDataConfirmation (short uiIndex){ return pgWebLib.PW_iPPDataConfirmation(uiIndex); }

}