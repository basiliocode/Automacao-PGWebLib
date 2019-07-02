import Enums.PWCNF;
import Enums.PWINFO;
import Enums.PWOPER;
import Enums.PWRET;
import Estruturas.PW_GetData;
import com.sun.jna.ptr.ShortByReference;

public class ChamarFuncoes {

    static private LibIntegrada libIntegrada = new LibIntegrada();

    public static PWRET chamarPW_iInit(String caminho){
        short pwInit = libIntegrada.chamarPW_iInit (caminho);
        return convertPWRET(pwInit);
    }

    public static PWRET chamarPW_iNewTransac(PWOPER tipoOperacao){
        short pwNewTransac = libIntegrada.chamarPW_iNewTransac(tipoOperacao.getValor());
        return convertPWRET(pwNewTransac);
    }

    public static PWRET chamarPW_iAddParam(PWINFO wParam, String pszValue){
        short pwAddParam = libIntegrada.chamarPW_iAddParam(wParam.getValor(), pszValue);
        return convertPWRET(pwAddParam);
    }

    public static PWRET chamarPW_iExecTransac(PW_GetData[] vstParam, ShortByReference iNUmParam) {
        short pwExecTransac = libIntegrada.chamarPW_iExecTransac(vstParam, iNUmParam);
        return convertPWRET(pwExecTransac);
    }

    public static PWRET chamarPW_iPPEventLoop (byte [] szDspMsg, int ulDisplaySize) {
        short pwEventLoop = libIntegrada.chamarPW_iPP_EventLoop(szDspMsg,ulDisplaySize);
        return convertPWRET(pwEventLoop);
    }

    public static PWRET chamarPW_iPPRemoveCard () {
        short pwRemoveCard = libIntegrada.chamarPW_iPP_RemoveCard();
        return convertPWRET(pwRemoveCard);
    }

    public static PWRET chamarPW_iPPAbort () {
        short pwAbort = libIntegrada.chamarPW_iPPAbort();
        return convertPWRET(pwAbort);
    }

    public static PWRET chamarPW_iGetResult (PWINFO iInfo, byte [] pszData, int ulDataSize) {
        short pwGetResult = libIntegrada.chamarPW_iGetResult(iInfo.getValor(),pszData,ulDataSize);
        return convertPWRET(pwGetResult);
    }

    public static PWRET chamarPW_iPPDisplay (String pszMsg) {
       short pwDisplay = libIntegrada.chamarPW_iPPDisplay(pszMsg);
       return convertPWRET(pwDisplay);
    }

    public static PWRET chamarPW_iPPGetCard (short uiIndex) {
        short pwGetCard = libIntegrada.chamarPW_iPPGetCard(uiIndex);
        return convertPWRET(pwGetCard);
    }

    public static PWRET chamarPW_iPPGoOnChip (short uiIndex) {
        short pwGOnChip = libIntegrada.chamarPW_iPPGoOnChip(uiIndex);
        return convertPWRET(pwGOnChip);
    }

    public static PWRET chamarPW_iPPFinishChip (short uiIndex) {
        short pwFinishChip = libIntegrada.chamarPW_iPPFinishChip(uiIndex);
        return convertPWRET(pwFinishChip);
    }

    public static PWRET chamarPW_iConfirmation(PWCNF ulStatus, String pszReqNum, String pszLocRef, String pszExtRef,
                                               String pszVirtMerch, String pszAuthSyst) {
        short pwConfirmation = libIntegrada.chamarPW_iConfirmation(ulStatus.getValor(), pszReqNum, pszLocRef,
                pszExtRef, pszVirtMerch, pszAuthSyst);
        return convertPWRET(pwConfirmation);
    }

    public static PWRET chamarPW_iIdleProc (){
        short pwIdleProc = libIntegrada.chamarPW_iIdleProc();
        return convertPWRET(pwIdleProc);
    }

    public static PWRET chamarPW_iPPDataConfirmation (short uiIndex) {
        short pwDataConfirmation = libIntegrada.chamarPW_iPPDataConfirmation(uiIndex);
        return convertPWRET(pwDataConfirmation);
    }

    //metodo opcional, pode mandar um de cada vez se desejar
    public static PWRET addMandatoryParams(){
        PWRET pwret = chamarPW_iAddParam(PWINFO.AUTDEV,"SETIS AUTOMACAO E SISTEMA LTDA");
        if(pwret != PWRET.OK)
            return pwret;

        pwret = chamarPW_iAddParam(PWINFO.AUTVER,"1.1.0.0");
        if(pwret != PWRET.OK)
            return pwret;

        pwret = chamarPW_iAddParam(PWINFO.AUTNAME,"PGWEBLIBTEST");
        if(pwret != PWRET.OK)
            return pwret;

        pwret = chamarPW_iAddParam(PWINFO.AUTCAP,"15");
        return pwret;
    }


    private static PWRET convertPWRET(short result){

        for (PWRET pwret : PWRET.values()){
            if(pwret.getValor() == result)
                return pwret;
        }
        return null;
    }

}
