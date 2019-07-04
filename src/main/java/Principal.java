import Enums.PWCNF;
import Enums.PWINFO;
import Enums.PWOPER;
import Enums.PWRET;
import Utililities.NativeUtils;
import com.sun.jna.Platform;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class Principal {
    static int cont_args = 0;

    //Esse bloco é responsável por desempacotar a bibilioteca PGWebLib durante a execução do Jar
    static {

        try {
            NativeUtils.loadLibraryFromJar(Platform.isLinux() ? "/PGWebLib_Linux/PGWebLib.so" :
                    "/PGWebLib_Windows/PGWebLib.dll");
        } catch (IOException e) {
            // This is probably not the best way to handle exception :-)
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws InterruptedException, IllegalAccessException {

        Scanner scan;
        int opcao;
        DadosDaConfirmacao dadosDaConfirmacao;

        System.out.println("Init: "+ ChamarFuncoes.chamarPW_iInit(".")); //Init
        System.out.println("Mansagem no PIN PAD " + ChamarFuncoes.chamarPW_iPPDisplay("   **Testes**   \n" +
                "   **Basilio**   ")); //16 caracteres por linha

        do {
            System.out.println("Escolher uma opção:\n" +
                "0 - ADMINISTRATIVA\n1 - VENDA\n2 - CONFIRMAR TRANSAÇÃO\n3 - IDLE PROC\n4 - SAIR");
            //scan = new Scanner(System.in);
            System.out.println("ADCIONANDO: " + args[cont_args]);
            opcao = Integer.parseInt(args[cont_args++]);

            switch (opcao) {
                case 0: //ADMINISTRATIVA
                    Transacao transacAdm = new Transacao();
                    PWRET newTransc = transacAdm.newTransac(PWOPER.ADMIN);

                    System.out.println("ADM newTransac " + newTransc);
                    System.out.println("AGUARDE...");
                    fluxoDeTransacao(newTransc, transacAdm, args);
                 break;

                case 1: //VENDA
                    Transacao transacVenda = new Transacao();
                    PWRET newTransac = transacVenda.newTransac(PWOPER.SALE);
                    System.out.println("New Transac " + newTransac);
                    transacVenda.newTransac(PWOPER.SALE);
                    System.out.println("AGUARDE...");
                    PWRET pwRet = fluxoDeTransacao(newTransac, transacVenda, args);

                    if(pwRet == PWRET.OK) {
                        dadosDaConfirmacao = new DadosDaConfirmacao();
                        guadarDados(dadosDaConfirmacao, transacVenda);

                        System.out.println("Escolha a opção\n0 - CONFIRMAR\n1 - DESFAZER");
                        if(dadosDaConfirmacao != null)
                            System.out.println(dadosDaConfirmacao.getAllPWinfo());

                        System.out.println("Escolha uma opção?\n0 - CONFIRMAR a ultima transação\n" +
                                "1 - DESFAZER a ultima transação");

                        String pszReqNum = dadosDaConfirmacao.getPWinfo(PWINFO.REQNUM);
                        String pszLocRef = dadosDaConfirmacao.getPWinfo(PWINFO.AUTLOCREF);
                        String pszExtRef = dadosDaConfirmacao.getPWinfo(PWINFO.AUTEXTREF);
                        String pszVirtMerch = dadosDaConfirmacao.getPWinfo(PWINFO.VIRTMERCH);
                        String pszAuthSyst = dadosDaConfirmacao.getPWinfo(PWINFO.AUTHSYST);
                        //scan = new Scanner(System.in);
                        System.out.println("ADCIONANDO: " + args[cont_args]);
                        int opt = Integer.parseInt(args[cont_args++]);

                        PWRET pwret;
                        switch (opt){
                            case 0:

                                pwret = transacVenda.ippConfirmation(PWCNF.PWCNF_CNF_MANU_AUT, pszReqNum, pszLocRef,
                                        pszExtRef, pszVirtMerch, pszAuthSyst);
                                if(pwret == PWRET.OK)
                                    System.out.println("Transação Confirmada!");
                                break;
                            case 1:
                                pwret = transacVenda.ippConfirmation(PWCNF.PWCNF_REV_MANU_AUT, pszReqNum, pszLocRef,
                                        pszExtRef, pszVirtMerch, pszAuthSyst);
                                if(pwret == PWRET.OK)
                                    System.out.println("Transação Desfeita!");
                                break;
                            default:
                                System.out.println("opção invalida!");
                        }

                    }
                    break;

                case 2: //CONFIRMAÇÃO e DESFAZIMENTO

                    break;

                case 3:
                    byte [] pszData = new byte[1000];
                    System.out.println("iGetResult " + ChamarFuncoes.chamarPW_iGetResult(PWINFO.IDLEPROCTIME,pszData,
                            pszData.length));
                    String pszDataString = new String(pszData).substring(0,12);
                    final SimpleDateFormat SDFParse = new SimpleDateFormat("yyMMddHHmmss");
                    final SimpleDateFormat SDFShow = new SimpleDateFormat("dd/MM/yyyy  - HH:mm:ss");

                    GregorianCalendar gcDataAtual = new GregorianCalendar();
                    GregorianCalendar gcDataProcTime = new GregorianCalendar();
                    try {
                        gcDataProcTime.setTime(SDFParse.parse(pszDataString)); //armazena a data obtida pelo SDF p/ o gc
                        System.out.println("Proximo tempo para idleProcTime("+pszDataString+"): "
                                + SDFShow.format(gcDataProcTime.getTime()));
                        System.out.println("data Atual: " + SDFShow.format(gcDataAtual.getTime()));

                        System.out.println("É depois : " + gcDataAtual.after(gcDataProcTime));

                        if(gcDataAtual.after(gcDataProcTime))
                            System.out.println("Executrando Idle Proc..." + ChamarFuncoes.chamarPW_iIdleProc());

                    } catch (ParseException e) {
                        System.out.println("Problema de conversão de data; Idle Proc não chamado!");
                        e.printStackTrace();
                    }
                    break;

                case 4:
                    System.out.println("Finalizado!");
                    break;

                default:
                    System.out.println("Opção invalida!");
                    break;
            }

        }while (opcao != 4);

    } //Fim do Main

    static PWRET fluxoDeTransacao(PWRET newTransac, Transacao transac, String args[]) throws InterruptedException, IllegalAccessException {
        Scanner scan;
        int optTransac;

        if(newTransac != PWRET.OK){ //Parando o fluxo caso um newTransac não ocorra;
            mostrarDadosDaTransacao(transac);
            return null;
        }

        System.out.println("Mandatory Params " + transac.mandatoryParams());

        if(transac.getOper() == PWOPER.SALE){
            System.out.println("\n**Adicionando parametros obrigatórios de venda**");
            System.out.println("Add param Currency " + transac.addParam(PWINFO.CURRENCY,"986"));
            System.out.println("Add param Currexp " + transac.addParam(PWINFO.CURREXP,"2"));
            System.out.println("ADCIONANDO: " + args[cont_args]);
            System.out.println("Add param Valor da transação " + transac.addParam(PWINFO.TOTAMNT,args[cont_args++]));
            System.out.println("Add param Numero do cartão " + transac.addParam(PWINFO.CARDFULLPAN,"4444333322221111"));
            System.out.println("Add param Data de venc " + transac.addParam(PWINFO.CARDEXPDATE, "0229"));
            System.out.println("Add param Tipo de financiamento " + transac.addParam(PWINFO.FINTYPE,"01"));
            System.out.println("Add param Cod do cartão " + transac.addParam(PWINFO.CVV,"123"));
        }

        System.out.println("\niGetResult(STATUS): " + transac.getResult(PWINFO.STATUS) +
                "\npszData(STATUS): " + transac.getPszData(true));

        PWRET pwRet = transac.execTransac();
        System.out.println("Exec Transac " + pwRet);
        System.out.println("AGUARDE...");
        mostrarDadosDaTransacao(transac);

        int j = transac.getInumParam() - 1; // j serve para indicar os indices do vetor de estrutura
        //FLUXO DA OPERACAO
        do {
            System.out.println("\nbTipoDeDados : " + transac.getBtipoDeDado(j));
            System.out.println("bTipoEntradaPermitidos " + transac.getBtipoEntradaPermitidos(j));
            System.out.println("bTamanhoMinimo " + transac.getBtamanhoMinimo(j));
            System.out.println("bTamanhoMaximo " + transac.getBtamanhoMaximo(j));
            System.out.println("szMascaraDeCaptura " + transac.getSzMascaraDeCaptura(j));
            System.out.println("szMsgPrevia " + transac.getSzMsgPrevia(j));
            System.out.println("szValorInicial(Valor atual) " + transac.getSzValorInicial(j));

            switch (transac.getBtipoDeDado(j)) {
                case MENU:
                    System.out.println("\nDIGITE UMA OPERAÇÃO:" + transac.getSzPrompt(j));
                    String [] vetorDeMenus = transac.getMenu(j);
                    int metadeVetor = vetorDeMenus.length / 2;
                    optTransac = tratarEscolhaOpcoesMenu(vetorDeMenus, metadeVetor, args); //entrada do usuario

                    switch (transac.getWidentificador(j)){
                        case LOCALINFO1:
                            System.out.println("Add Param " + transac.addParam( //adicioando opcao usuario
                                    transac.getWidentificador(j), vetorDeMenus[optTransac + metadeVetor]));
                            break;
                        case APAGADADOS:
                            System.out.println("Add Param " + transac.addParam( //adicioando opcao usuario
                                    transac.getWidentificador(j), Integer.toString(optTransac + 1)));
                            break;
                        case VIRTMERCH:
                            System.out.println("Add Param " + transac.addParam( //adicioando opcao usuario
                                    transac.getWidentificador(j), vetorDeMenus[optTransac + metadeVetor]));
                            break;
                        case CARDTYPE:
                            System.out.println("Add Param " + transac.addParam( //adicioando opcao usuario
                                    transac.getWidentificador(j), vetorDeMenus[optTransac + metadeVetor]));
                            break;
                        case FINTYPE:
                            System.out.println("Add Param " + transac.addParam( //adicioando opcao usuario
                                    transac.getWidentificador(j), vetorDeMenus[optTransac + metadeVetor]));
                            break;
                        default:
                            System.out.println("Add Param " + transac.addParam( //adicioando opcao usuario
                                    transac.getWidentificador(j), Integer.toString(optTransac + metadeVetor)));
                            break;
                    }
                    break;

                case USERAUTH:
                    System.out.println("DIGITE A SENHA:");
                    //scan = new Scanner(System.in);
                    System.out.println("ADCIONANDO: " + args[cont_args]);
                    String senha = args[cont_args++];
                    System.out.println("Add Param: " + transac.addParam(transac.getWidentificador(j), senha));
                    break;

                case TYPED:
                    String dado = tratarDadoDigitado(transac.getSzPrompt(j),transac.getBtamanhoMinimo(j),
                            transac.getBtamanhoMaximo(j),transac.getBtipoEntradaPermitidos(j),
                            transac.getSzValorInicial(j), args);

                    System.out.println("Add Param: " + transac.addParam(transac.getWidentificador(j), dado));
                    break;

                case PPREMCRD:
                    System.out.println("Saindo do fluxo pelo RemoveCard " + transac.getSzPrompt(j));
                    System.out.println("iPPRemoveCard: " +transac.removeCard());
                    tratarEventLoop(transac);
                    break;
                case CARDINF:
                    System.out.println("szPrompt " + transac.getSzPrompt(j));
                    //CARTAO DIGITADO
                    if(transac.getUlTipoEntradaCartao(j) == 1) {
                         System.out.println("Digite o numero do cartão");
                         //scan = new Scanner(System.in);
                        System.out.println("ADCIONANDO: " + args[cont_args]);
                         String numCartao = args[cont_args++];

                         if(transac.addParam(PWINFO.CARDFULLPAN,numCartao)== null);
                            System.out.println("Erro ao adicionar numero do cartão");
                     }
                     //APENAS PIN PAD
                     else if (transac.getUlTipoEntradaCartao(j) == 2){
                         System.out.println("Aguarde a capturta no PIN PAD...");
                         transac.ippGetCard((j));
                         tratarEventLoop(transac);
                     }
                    //CARTAO DIGITADO E PIN PAD
                     else{
                         System.out.println("Implementar função para PIN PAD e Cartão digitado");
                     }
                    break;

                case CARDOFF:
                    System.out.println("ippGoOnChip " + transac.ippGoOnChip(j));
                    tratarEventLoop(transac); //Para inserir a senha
                    Thread.sleep(10000);
                    break;
                case CARDONL:
                    System.out.println("ippFinishChip " + transac.ippFinishChip(j));
                    tratarEventLoop(transac); //Para inserir a senha
                    break;
            }

            j++;
            if( j == transac.getInumParam() ){

                System.out.println("\niGetResult(STATUS): " + transac.getResult(PWINFO.STATUS) +
                        "\npszData(STATUS): " + transac.getPszData(true));

                pwRet = transac.execTransac();
                System.out.println("Exec Transac " + pwRet);
                System.out.println("AGUARDE...\n");
                mostrarDadosDaTransacao(transac);
                j = 0;
            }

        }while (pwRet == PWRET.MOREDATA);
        return pwRet;
    } // FIM do fluxo de transação

    static void tratarEventLoop(Transacao transac) throws InterruptedException {
        PWRET eventLoop = transac.ippEventLoop();
        String result="";
        while (eventLoop != PWRET.OK) {
            if(eventLoop == null) {
                System.out.println("ERRO DESCONHECIDO!!!");
                break;
            }

            if(eventLoop == PWRET.DISPLAY)
                System.out.println("szDspMsg "+ transac.getsZDspMsg() + "\n"); //mensagem do eventLoop

            result = eventLoop == PWRET.NOTHING ? "." : "\n"+eventLoop;
            System.out.print(result);
            eventLoop = transac.ippEventLoop();

            if(eventLoop == PWRET.CANCEL){ //Cancelada no PIN PAD
                System.out.println("transac Abort: " + transac.Abort());
            }
        }
    }

    static int tratarEscolhaOpcoesMenu(String []vetorDeMenus, int metadeVetor, String args[]){
        int optTransac;
        do {
            System.out.println("\nDIGITE UMA OPERAÇÃO:");
            for (int i = 0; i < metadeVetor; i++) {
                System.out.println(i + " " + vetorDeMenus[i] + "(" + vetorDeMenus[metadeVetor + i] + ")");
            }
            //Scanner scan = new Scanner(System.in);
            System.out.println("ADCIONANDO: " + args[cont_args]);
            String entrada = args[cont_args++];

            optTransac = entrada.matches("[0-9]+") ? Integer.parseInt(entrada) : -1; //entrada do usuario

            if (optTransac > (metadeVetor - 1) || optTransac < 0)
                System.out.println("Opção inválida");
        }while(optTransac > (metadeVetor - 1) || optTransac < 0);

        return optTransac;
    }

    static String tratarDadoDigitado(String szPrompt, byte tamanhoMinimo, byte tamanhoMaximo, byte
            tipoEntradaPermitidos, String szValorInicial, String args[]){
        boolean continuar = true;
        String dadoDigitado;

        do{
            System.out.println("DIGITE O DADO SOLICITADO: " + szPrompt);
            //Scanner scan = new Scanner(System.in);
            System.out.println("ADCIONANDO: " + args[cont_args]);
            dadoDigitado = args[cont_args++];
            
            if (dadoDigitado.length() > tamanhoMaximo)
                System.out.println("Tamanho maior que o maximo permitido("+tamanhoMaximo+")\nTente novamente...");
            else if (dadoDigitado.length() < tamanhoMinimo)
                System.out.println("Tamanho menor que o maximo permitido("+tamanhoMinimo+")\nTente novamente...");
            else {
                switch (tipoEntradaPermitidos){
                    case 0: //VALOR INICIAL SOBREPÕE
                        System.out.println("entrada digitada está sendo sobrescrita por: " + szValorInicial);
                        dadoDigitado = szValorInicial.replace(" ","");
                        continuar = false;
                        break;
                    case 1: //SÓ NUMEROS
                        if(dadoDigitado.matches("[0-9]+"))
                            continuar = false;
                        else System.out.println("Digite apenas numeros");
                        break;
                    case 2: // SÓ ALFABÉTICOS
                        if(dadoDigitado.matches("[a-zA-Z]+"))
                            continuar = false;
                        else System.out.println("Digite apenas alfabéticos");
                        break;
                    case 3: //SÓ ALFANUMERICOS
                        if(dadoDigitado.matches("[0-9a-zA-Z]+"))
                            continuar = false;
                        else System.out.println("Digite apenas alfanuméricos");
                        break;
                    case 7: //ALFANUMÉRICOS E ESPECIAS
                        System.out.println("aceitando numericos, alfanumericos e especiais");
                        continuar = false;
                        break;
                }
            }
        }while(continuar);

        return dadoDigitado;
    }

    static void mostrarDadosDaTransacao(Transacao transac){
        if(transac.getInumParam() != 10) {
            System.out.println("Dados da Transação\n=========================================================\n"
                    + transac + " \n=========================================================\n");
        }
        for (PWINFO pwinfo : PWINFO.values()){
            PWRET pwret = transac.getResult(pwinfo);
            if (pwret == PWRET.OK) {
                if(!(pwinfo == PWINFO.RCPTMERCH || pwinfo ==PWINFO.RCPTCHOLDER     //Se não for um recibo formata a msg
                        || pwinfo == PWINFO.RCPTCHSHORT || pwinfo == PWINFO.RCPTFULL))
                System.out.println(pwinfo + ": " + transac.getPszData(true));
                else
                    System.out.println(pwinfo + ": " + transac.getPszData(false));
            }
        }
    }

    static void guadarDados( DadosDaConfirmacao dadosDaConfirmacao, Transacao transac){
        for (PWINFO pwinfo : PWINFO.values()){
            PWRET pwret = transac.getResult(pwinfo);
            if (pwret == PWRET.OK) {
                if (!(pwinfo == PWINFO.RCPTMERCH || pwinfo == PWINFO.RCPTCHOLDER     //Se não for um recibo formata a msg
                        || pwinfo == PWINFO.RCPTCHSHORT || pwinfo == PWINFO.RCPTFULL))
                    dadosDaConfirmacao.addPWinfo(pwinfo, transac.getPszData(true));
                else
                    dadosDaConfirmacao.addPWinfo(pwinfo, transac.getPszData(false));
            }
        }
    }

}