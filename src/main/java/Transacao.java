import Enums.*;
import Estruturas.PW_GetData;
import com.sun.jna.ptr.ShortByReference;
import java.lang.reflect.Field;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Transacao {
    private PWOPER oper = null;
    private final ShortByReference iNumParam;
    private PW_GetData [] vstParam;
    private byte[] szDspMsg, pszData;

    public Transacao() {
        this.iNumParam = new ShortByReference((short)10);
        this.vstParam =  (PW_GetData[]) new PW_GetData().toArray(iNumParam.getValue());
        this.szDspMsg = new byte[128];
        this.pszData  = new byte[1000];
    }

    //FUNCOES NATIVAS
    public PWRET newTransac(PWOPER oper){
        this.oper = oper;
        return ChamarFuncoes.chamarPW_iNewTransac(oper);
    }

    public PWRET addParam(PWINFO param, String data){
        return  ChamarFuncoes.chamarPW_iAddParam(param, data);
    }

    public PWRET mandatoryParams(){
        return ChamarFuncoes.addMandatoryParams();
    }

    public PWRET execTransac() throws InterruptedException {
        setINumParam((short)10);
        Thread.sleep(500);
        return ChamarFuncoes.chamarPW_iExecTransac(vstParam, iNumParam);
    }

    public PWRET ippEventLoop() throws InterruptedException {
        Thread.sleep(500);
        return ChamarFuncoes.chamarPW_iPPEventLoop(szDspMsg, szDspMsg.length);
    }

    public PWRET removeCard(){
        return ChamarFuncoes.chamarPW_iPPRemoveCard();
    }

    public PWRET Abort(){ return ChamarFuncoes.chamarPW_iPPAbort (); }

    public  PWRET getResult(PWINFO param){
        this.pszData = new byte[1000];
        return ChamarFuncoes.chamarPW_iGetResult(param, pszData, 1000);
    }

    public PWRET ippGetCard(int indiceVstParam){
        return ChamarFuncoes.chamarPW_iPPGetCard((short) indiceVstParam);
    }

    public PWRET ippGoOnChip(int indiceVstParam){
        return ChamarFuncoes.chamarPW_iPPGoOnChip((short) indiceVstParam);
    }

    public PWRET ippFinishChip(int indiceVstParam){ return ChamarFuncoes.chamarPW_iPPFinishChip((short) indiceVstParam); }

    public PWRET ippConfirmation(PWCNF ulSatus,String pszReqNum, String pszLocRef, String pszExtRef,
                                 String pszVirtMerch, String pszAuthSyst){
        return ChamarFuncoes.chamarPW_iConfirmation(ulSatus, pszReqNum, pszLocRef, pszExtRef, pszVirtMerch, pszAuthSyst);
    }

    public PWRET ippDataConfirmation(int indiceVstParam){
        return ChamarFuncoes.chamarPW_iPPDataConfirmation((short) indiceVstParam);
    }


    //GETS
    public PWOPER getOper() { return oper; }

    public String getPszData(boolean formatarMensagem){
        if(formatarMensagem)
            return correcaoMensagem(pszData);
        else
            return new String (pszData);
    }

    public String getsZDspMsg(){ return correcaoMensagem(szDspMsg); }

    public short getInumParam(){
        return iNumParam.getValue();
    }

    //SETS
    public void setINumParam(short value){
        this.iNumParam.setValue(value);
    }


    //GETS PARAMENTROS DO VETOR
    public PWINFO getWidentificador(int index){
        return converterPWINFO(vstParam[index].wIdentificador);
    }

    public PWDAT getBtipoDeDado(int index){
        return converterPWDAT(vstParam[index].bTipoDeDado);
    }

    public String getSzPrompt(int index){ return correcaoMensagem(vstParam[index].szPrompt); }

    public int getBnumOpcoes(int index){
        return vstParam[index].bNumOpcoesMenu;
    }

    public String getSzMascaraDeCaptura(int index){
        return correcaoMensagem(vstParam[index].szMascaraDeCaptura);
    }

    public byte getBtipoEntradaPermitidos(int index){
        return vstParam[index].bTiposEntradaPermitidos;
    }

    public byte getBtamanhoMinimo(int index) { return vstParam[index].bTamanhoMinimo; }

    public byte getBtamanhoMaximo(int index) { return vstParam[index].bTamanhoMaximo; }

    public int getUlValorMinimo(int index) { return vstParam[index].ulValorMinimo; }

    public int getUlValorMaximo(int index) { return vstParam[index].ulValorMaximo; }

    public byte getBocultarDadosDigitados(int index) { return vstParam[index].bOcultarDadosDigitados; }

    public byte getBvalidacaoDado(int index) { return vstParam[index].bValidacaoDado; }

    public byte getBaceitaNulo(int index) { return vstParam[index].bAceitaNulo; }

    public String getSzValorInicial(int index) { return correcaoMensagem(vstParam[index].szValorInicial); }

    public byte getBteclasDeAtalho(int index) { return vstParam[index].bTeclasDeAtalho; }

    public String getSzMsgValidacao(int index) { return correcaoMensagem(vstParam[index].szMsgValidacao); }

    public String getSzMsgConfirmacao(int index) { return correcaoMensagem(vstParam[index].szMsgConfirmacao); }

    public String getSzMsgDadoMaior(int index) { return correcaoMensagem(vstParam[index].szMsgDadoMaior); }

    public String getSzMsgDadoMenor(int index) { return correcaoMensagem(vstParam[index].szMsgDadoMenor); }

    public byte getBcapturarDataVencCartao(int index) { return vstParam[index].bCapturarDataVencCartao; }

    public int getUlTipoEntradaCartao(int index) { return vstParam[index].ulTipoEntradaCartao; }

    public byte getBitemInicial(int index) { return vstParam[index].bItemInicial; }

    public byte getBnumeroCapturas(int index) { return vstParam[index].bNumeroCapturas; }

    public String getSzMsgPrevia(int index) { return correcaoMensagem(vstParam[index].szMsgPrevia); }

    public byte getBtipoEntradaCodigoBarras(int index) { return vstParam[index].bTipoEntradaCodigoBarras; }

    public byte getBomiteMsgAlerta(int index) { return vstParam[index].bOmiteMsgAlerta; }

    public byte getBiniciaPelaEsquerda(int index) { return vstParam[index].bIniciaPelaEsquerda; }

    public byte getBnotificarCancelamento(int index) { return vstParam[index].bNotificarCancelamento; }


    //OBTENDO UM VETOR COM A QUANTIDADE DE MENUS PREENCHIDOS
    public String [] getMenu(int indexVstParam) throws IllegalAccessException {
        int bNumOpcoesMenu = vstParam[indexVstParam].bNumOpcoesMenu;
        String [] menu = new String[bNumOpcoesMenu*2]; //dobrando o vetor para obter Texto/Valor
        int metadeVetor = menu.length/2;
        Field fields [] = vstParam[indexVstParam].stMenu.getClass().getDeclaredFields();

        for (int i = 0; i < bNumOpcoesMenu; i++) {
            //preenchendo do inicio: szTexto
            menu[i] = new String((byte[]) fields[i].get(vstParam[indexVstParam].stMenu));
            //preenchendo a partir da metade: szValor
            menu[metadeVetor + i] = new String((byte[]) fields[i + 40].get(vstParam[indexVstParam].stMenu));
        }
        return menu;
    }


    @Override
    public String toString(){
        return "Operação: " + oper + "\nvetor GetData preenchido: " + iNumParam.getValue()
                + "\nEstrutura GetData: \n{\n" + getDataToString()+ "\n}";
    }

    private String getDataToString() {
        String getdata = "";
        for (int i = 0; i < iNumParam.getValue(); i++){
            String menus = ""; int cont = 0;
            try {
                for(String menu: getMenu(i)){ menus += (cont++) + "-" + menu + " "; }
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            }
            getdata += "wIdwntificador = " + getWidentificador(i) + "\n"
                    + "bTipoDeDaDo  = " + getBtipoDeDado(i) + "\n"
                    + "szPrompt  = " +  getSzPrompt(i) + "\n"
                    + "bNumOpcoesMenu = " + getBnumOpcoes(i) + "\n"
                    + "stMenu = {" + menus + " }\n"
                    + "szMascaraDeCaptura = " + getSzMascaraDeCaptura(i) + "\n"
                    + "bTiposEntradaPermitidos = " + getBtipoEntradaPermitidos(i) + "\n"
                    + "bTamanhoMinimo = " + getBtamanhoMinimo(i) + "\n"
                    + "bTamanhoMaximo = " + getBtamanhoMaximo(i) + "\n"
                    + "ulValorMinimo = " + getUlValorMinimo(i) + "\n"
                    + "ulValorMaximo = " + getUlValorMaximo(i) + "\n"
                    + "bOcultarDadosDigitados = " + getBocultarDadosDigitados(i) + "\n"
                    + "bValidacaoDado = " + getBvalidacaoDado(i) + "\n"
                    + "bAceitaNulo = " + getBaceitaNulo(i) + "\n"
                    + "szValorInicial = " + getSzValorInicial(i) + "\n"
                    + "bTeclasDeAtalho = " + getBteclasDeAtalho(i) + "\n"
                    + "szMsgValidacao = " + getSzMsgValidacao(i) + "\n"
                    + "szMsgConfirmacao = " + getSzMsgConfirmacao(i) + "\n"
                    + "szMsgDadoMaior = " + getSzMsgDadoMaior(i) + "\n"
                    + "szMsgDadoMenor = " + getSzMsgDadoMenor(i) + "\n"
                    + "bCapturarDataVencCartao = " + getBcapturarDataVencCartao(i) + "\n"
                    + "ulTipoEntradaCartao = " + getUlTipoEntradaCartao(i) + "\n"
                    + "bItemInicial = " + getBitemInicial(i) + "\n"
                    + "bNumeroCapturas = " + getBnumeroCapturas(i) + "\n"
                    + "szMsgPrevia = " + getSzMsgPrevia(i) + "\n"
                    + "bTipoEntradaCodigoBarras = " + getBtipoEntradaCodigoBarras(i) + "\n"
                    + "bOmiteMsgAlerta = " + getBomiteMsgAlerta(i) + "\n"
                    + "bIniciaPelaEsquerda = " + getBiniciaPelaEsquerda(i) + "\n"
                    + "bNotificarCancelamento = " + getBnotificarCancelamento(i) + "\n";
        }
        return getdata;
    }

    //Formatada bytes em String com correção de exibicao
    private String correcaoMensagem(byte [] param) {
        String mensagem = new String (param); // transaformando array de bytes em string
        String mensagemFormatada = mensagem.replace('\0',' '); //substituindo byte vazio por espaços

        Pattern p = Pattern.compile("\\s+"); // expressão para mais de um espaço
        Matcher m = p.matcher(mensagemFormatada);
        mensagem = m.replaceAll(" ");
        return mensagem.substring(0,mensagem.length()-1);
    }

    //Conversores
    private PWINFO converterPWINFO(short valor){
        for ( PWINFO pwinfo : PWINFO.values()){
            if(pwinfo.getValor() == valor)
                return pwinfo;
        }
        return null;
    }

    private PWDAT converterPWDAT(byte valor){
        for ( PWDAT pwdat : PWDAT.values()){
            if(pwdat.getValor() == valor)
                return pwdat;
        }
        return null;
    }

}
