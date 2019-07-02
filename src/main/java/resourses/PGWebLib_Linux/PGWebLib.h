/*********************** SETIS - Automa��o e Sistemas ************************

 Arquivo          : PGWebLib.h
 Projeto          : Pay&Go WEB
 Plataforma       : POSPlug
 Data de cria��o  : 25/02/2013
 Autor            : Guilherme Eduardo Leite
 Descri��o        : Defini��es da dll para integra��o com a solu��o Pay&Go WEB.

 ================================= HIST�RICO =================================
 Data      Respons�vel Modifica��o
 --------  ----------- -------------------------------------------------------
 07/Ago/17 Guilherme    - Criados retornos PWRET_OFFCFGxxx (CA17-0049).
 06/Out/17 Guilherme    - Criado intervalo exclusivo para os erros no 
                          processamento local.(CA17-0061).
 23/Out/17 Massaia      - Criado PWRET_OFFINTERNAL17 para erros relacionados
                          ao processo de criptografia espec�fica (CA17-0060).
 16/Nov/17 Guilherme    - Criado PWRET_OFFINTERNAL18 (CA17-0079).
 14/Dez/17 Guilherme    - Criado PWRET_PPABORT (CA17-0090).
 01/Fev/18 Guilherme    - Criado o novo erro PWRET_OFFINTERNAL19(CA18-0012).
 07/Fev/18 Guilherme    - Criada nova fun��o PW_iPPGetUserData (CA18-0014).
 22/Fev/18 Guilherme    - Amplia��o de PWMENU_MAXINTENS de 20 para 40 (CA18-0021).
 20/Jul/18 Massaia      - Adicionado PWRET_PPERRTREATMENT (CA18-0062).
 01/Ago/18 Erwin			- Adicionado PWINFO_AUTHSYSTEXTENDED (CA18-0067).
 30/Ago/18 Guilherme    - Adicionadas TAGS para recebimento dos dados de confirma��o
                          da biblioteca de integra��o.
 \*****************************************************************************/
#ifndef _PGWEBLIB_INCLUDED_
#define _PGWEBLIB_INCLUDED_

// Incluindo o header que define os tipos de vari�veis para a plataforma em quest�o
#ifndef PGLIB_DACASA
#include "PWL_Type.h"
#endif 

#ifndef CALLBACK
#define CALLBACK
#endif /* CALLBACK */

#ifndef PW_EXPORT
#define PW_EXPORT
#endif /* PW_EXPORT */

// C�digos de retorno da biblioteca
enum {
   // Erros gerais
   PWRET_OK = 0,   
   PWRET_FROMHOSTPENDTRN = -2599, 
   PWRET_FROMHOSTPOSAUTHERR,
   PWRET_FROMHOSTUSRAUTHERR,
   PWRET_FROMHOST,
   PWRET_TLVERR,
   PWRET_SRVINVPARAM,
   PWRET_REQPARAM,
   PWRET_HOSTCONNUNK,
   PWRET_INTERNALERR,
   PWRET_BLOCKED,
   PWRET_FROMHOSTTRNNFOUND,
   PWRET_PARAMSFILEERR,
   PWRET_NOCARDENTMODE,
   PWRET_INVALIDVIRTMERCH,
   PWRET_HOSTTIMEOUT,
   PWRET_CONFIGREQUIRED,
   PWRET_HOSTCONNERR,
   PWRET_HOSTCONNLOST,
   PWRET_FILEERR,
   PWRET_PINPADERR,
   PWRET_MAGSTRIPEERR,
   PWRET_PPCRYPTERR,
   PWRET_SSLCERTERR,
   PWRET_SSLNCONN,
   PWRET_GPRSATTACHFAILED,
   PWRET_EMVDENIEDCARD,
   PWRET_EMVDENIEDHOST,
   PWRET_NOLINE,
   PWRET_NOANSWER,
   PWRET_SYNCERROR,
   PWRET_CRCERR,
   PWRET_DECOMPERR,
   PWRET_PROTERR,
   PWRET_NOSIM,
   PWRET_SIMERROR,
   PWRET_SIMBLOCKED,
   PWRET_PPPNEGFAILED,
   PWRET_WIFICONNERR,
   PWRET_WIFINOTFOUND,
   PWRET_COMPERR,
   PWRET_INVALIDCPFCNPJ,
   /* Inserir novos erros gerais somente AQUI */

   // Erros espec�ficos da biblioteca
   PWRET_INVPARAM = -2499,
   PWRET_NOTINST,   
   PWRET_MOREDATA,  
   PWRET_NODATA,    
   PWRET_DISPLAY,    
   PWRET_INVCALL,    
   PWRET_NOTHING,    
   PWRET_BUFOVFLW,   
   PWRET_CANCEL,     
   PWRET_TIMEOUT,    
   PWRET_PPNOTFOUND, 
   PWRET_TRNNOTINIT, 
   PWRET_DLLNOTINIT, 
   PWRET_FALLBACK,   
   PWRET_WRITERR,    
   PWRET_PPCOMERR,	 
   PWRET_NOMANDATORY,
   PWRET_OFFINTERNAL,
   PWRET_OFFINVCAP,
   PWRET_OFFNOCARDENTMODE,
   PWRET_OFFINVCARDENTMODE,
   PWRET_OFFNOTABLECARDRANGE,
   PWRET_OFFNOTABLEPRODUCT,
   PWRET_OFFINVTAG,
   PWRET_OFFNOCARDFULLPAN,
   PWRET_OFFINVCARDEXPDT,
   PWRET_OFFCARDEXP,
   PWRET_OFFNOTRACKS,
   PWRET_OFFTRACKERR,
   PWRET_OFFCHIPMANDATORY,
   PWRET_OFFINVCARD,
   PWRET_OFFINVCURR,
   PWRET_OFFINVAMOUNT,
   PWRET_OFFGREATERAMNT,
   PWRET_OFFLOWERAMNT,
   PWRET_OFFGREATERINST,
   PWRET_OFFLOWERINST,
   PWRET_OFFINVCARDTYPE,
   PWRET_OFFINVFINTYPE,
   PWRET_OFFINVINST,
   PWRET_OFFGREATERINSTNUM,
   PWRET_OFFLOWERINSTNUM,
   PWRET_OFFMANDATORYCVV,
   PWRET_OFFINVLASTFOUR,
   PWRET_OFFNOAID,
   PWRET_OFFNOFALLBACK,
   PWRET_OFFNOPINPAD,
   PWRET_OFFNOAPOFF,
   PWRET_OFFTRNNEEDPP,
   PWRET_OFFCARDNACCEPT,
   PWRET_OFFTABLEERR,
   PWOFF_OFFMAXTABERR,
   PWRET_OFFINTERNAL1,
   PWRET_OFFINTERNAL2,
   PWRET_OFFINTERNAL3,
   PWRET_OFFINTERNAL4,
   PWRET_OFFINTERNAL5,
   PWRET_OFFINTERNAL6,
   PWRET_OFFINTERNAL7,
   PWRET_OFFINTERNAL8,
   PWRET_OFFINTERNAL9,
   PWRET_OFFINTERNAL10,
   PWRET_OFFINTERNAL11,
   PWRET_OFFNOPRODUCT,
   PWRET_OFFINTERNAL12,
   PWRET_OFFINTERNAL13,
   PWRET_OFFINTERNAL14,
   PWRET_NOPINPAD,
   PWRET_OFFINTERNAL15,
   PWRET_OFFINTERNAL16,
   PWRET_ABECSERRCOM,
   PWRET_OFFCFGNOCARDRANGE,
   PWRET_OFFCFGNOPRODUCT,
   PWRET_OFFCFGNOTRANSACTION,
   PWRET_OFFINTERNAL17,
   PWRET_OFFINTERNAL18,
   PWRET_PPABORT,
   PWRET_OFFINTERNAL19,
   PWRET_PPERRTREATMENT,
   /* Inserir novos erros de processamento local somente AQUI */
   PWRET_OFFEND
   /* Inserir novos erros da biblioteca somente AQUI */

};
// Erros espec�ficos da biblioteca compartilhada de PIN-pad
#define PWRET_PPS_MAX      -2100
#define PWRET_PPS_MIN      PWRET_PPS_MAX - 100

enum{
   /* Status de -2199 a -2180 : Erros de processamento de cart�o com chip sem contato */
   PWRET_PPS_CTLSSAPPNAUT = PWRET_PPS_MAX - 85,
   PWRET_PPS_CTLSSAPPNAV,
   PWRET_PPS_CTLSSPROBLEMS,
   PWRET_PPS_CTLSSINVALIDAT,
   PWRET_PPS_CTLSSCOMMERR,
   PWRET_PPS_CTLSSMULTIPLE,

   /* Status de -2179 a -2160 : Erros de processamento de cart�o com chip com contato */
   PWRET_PPS_ERRFALLBACK = PWRET_PPS_MAX - 76,
   PWRET_PPS_VCINVCURR,
   PWRET_PPS_CARDNOTEFFECT,
   PWRET_PPS_LIMITEXC,
   PWRET_PPS_NOBALANCE,
   PWRET_PPS_CARDAPPNAUT,
   PWRET_PPS_CARDAPPNAV,
   PWRET_PPS_CARDINVDATA,
   PWRET_PPS_CARDPROBLEMS,
   PWRET_PPS_CARDINVALIDAT,
   PWRET_PPS_CARDERRSTRUCT,
   PWRET_PPS_CARDEXPIRED,
   PWRET_PPS_CARDNAUTH,
   PWRET_PPS_CARDBLOCKED,
   PWRET_PPS_CARDINV,
   PWRET_PPS_ERRCARD,
   PWRET_PPS_DUMBCARD,

   /* Status de -2159 a -2150 : Erros de processamento de cart�o com chip (SAM) */
   PWRET_PPS_SAMINV = PWRET_PPS_MAX - 52,
   PWRET_PPS_NOSAM,
   PWRET_PPS_SAMERR,

   /* Status de -2149 a -2140 : Erros b�sicos reportados pelo pinpad */
   PWRET_PPS_PINBUSY = PWRET_PPS_MAX - 44,
   PWRET_PPS_NOCARD,
   PWRET_PPS_ERRPIN,
   PWRET_PPS_MCDATAERR,
   PWRET_PPS_INTERR,

   /* Status de -2139 a -2130 : Erros de comunica��o/protocolo com o pinpad */
   PWRET_PPS_COMMTOUT = PWRET_PPS_MAX - 34,
   PWRET_PPS_RSPERR,
   PWRET_PPS_UNKNOWNSTAT,
   PWRET_PPS_COMMERR,
   PWRET_PPS_PORTERR,

   /* Status de -2129 a -2110 : Erros b�sicos da biblioteca */
   PWRET_PPS_NOAPPLIC = PWRET_PPS_MAX - 22,
   PWRET_PPS_TABERR,
   PWRET_PPS_TABEXP,
   RESERVED,
   PWRET_PPS_NOFUNC,
   PWRET_PPS_INVMODEL,
   PWRET_PPS_EXECERR,
   PWRET_PPS_NOTOPEN,
   PWRET_PPS_ALREADYOPEN,
   PWRET_PPS_CANCEL,
   PWRET_PPS_TIMEOUT,
   PWRET_PPS_INVPARM,
   PWRET_PPS_INVCALL,

   /* Status de -2109 a -2100  : N�o representam erros */
   PWRET_PPS_BACKSP = PWRET_PPS_MAX - 8,
   PWRET_PPS_F4,
   PWRET_PPS_F3,
   PWRET_PPS_F2,
   PWRET_PPS_F1,
   PWRET_PPS_NOTIFY = PWRET_PPS_MAX - 2,
   PWRET_PPS_PROCESSING,
   PWRET_PPS_OK
};

// C�digos de confirma��o de transa��o
#define PWCNF_CNF_AUTO	      0x00000121	/*A transa��o foi confirmada pelo Ponto de Captura, sem interven��o do usu�rio.*/
#define PWCNF_CNF_MANU_AUT	   0x00003221	/*A transa��o foi confirmada manualmente na Automa��o.*/
#define PWCNF_REV_MANU_AUT	   0x00003231	/*A transa��o foi desfeita manualmente na Automa��o.*/
#define PWCNF_REV_PRN_AUT	   0x00013131	/*A transa��o foi desfeita pela Automa��o, devido a uma falha na impress�o do comprovante (n�o fiscal). A priori, n�o usar. Falhas na impress�o n�o devem gerar desfazimento, deve ser solicitada a reimpress�o da transa��o.*/
#define PWCNF_REV_DISP_AUT	   0x00023131	/*A transa��o foi desfeita pela Automa��o, devido a uma falha no mecanismo de libera��o da mercadoria.*/
#define PWCNF_REV_COMM_AUT	   0x00033131	/*A transa��o foi desfeita pela Automa��o, devido a uma falha de comunica��o/integra��o com o ponto de captura (Cliente Muxx).*/
#define PWCNF_REV_ABORT	      0x00043131	/*A transa��o n�o foi finalizada, foi interrompida durante a captura de dados.*/
#define PWCNF_REV_OTHER_AUT   0x00073131	/*A transa��o foi desfeita a pedido da Automa��o, por um outro motivo n�o previsto.*/
#define PWCNF_REV_PWR_AUT	   0x00083131	/*A transa��o foi desfeita automaticamente pela Automa��o, devido a uma queda de energia (rein�cio abrupto do sistema).*/
#define PWCNF_REV_FISC_AUT	   0x00093131	/*A transa��o foi desfeita automaticamente pela Automa��o, devido a uma falha de registro no sistema fiscal (impressora S@T, on-line, etc.).*/

// Tipos utilizados na captura de dados dinamica
#define PWDAT_MENU      1     /*menu de op��es*/
#define PWDAT_TYPED     2     /*entrada digitada*/
#define PWDAT_CARDINF   3     /*dados de cart�o*/
#define PWDAT_PPENTRY   5     /*entrada digitada no PIN-pad*/
#define PWDAT_PPENCPIN  6     /*senha criptografada   */             
#define PWDAT_CARDOFF   9     /*processamento off-line de cart�o com chip*/
#define PWDAT_CARDONL   10    /*processamento on-line de cart�o com chip*/
#define PWDAT_PPCONF    11    /*confirma��o de informa��o no PIN-pad*/
#define PWDAT_BARCODE	12	   /*C�digo de barras, lido ou digitado.*/
#define PWDAT_PPREMCRD  13    /*Remo��o do cart�o do PIN-pad.*/
#define PWDAT_PPGENCMD  14    /*comando propriet�rio da rede no PIN-pad.*/
#define PWDAT_PPDATAPOSCNF 16 /*confirma��o positiva de dados no PIN-pad.*/
#define PWDAT_USERAUTH     17 /*valida��o da senha.*/

// Tipos de evento a serem ativados para monitora��o no PIN-pad
#define PWPPEVTIN_KEYS     1
#define PWPPEVTIN_MAG      2  
#define PWPPEVTIN_ICC      4
#define PWPPEVTIN_CTLS     8

// Tipos de evento retornados pelo PIN-pad
#define PWPPEVT_MAGSTRIPE  0x01  /* Foi passado um cart�o magn�tico. */
#define PWPPEVT_ICC        0x02  /* Foi detectada a presen�a de um cart�o com chip. */
#define PWPPEVT_CTLS       0x03  /* Foi detectada a presen�a de um cart�o sem contato. */
#define PWPPEVT_KEYCONF    0x11  /* Foi pressionada a tecla [OK]. */
#define PWPPEVT_KEYBACKSP  0x12  /* Foi pressionada a tecla [CORRIGE]. */
#define PWPPEVT_KEYCANC    0x13  /* Foi pressionada a tecla [CANCELA]. */
#define PWPPEVT_KEYF1      0x21  /* Foi pressionada a tecla [F1]. */
#define PWPPEVT_KEYF2      0x22  /* Foi pressionada a tecla [F2]. */
#define PWPPEVT_KEYF3      0x23  /* Foi pressionada a tecla [F3]. */
#define PWPPEVT_KEYF4      0x24  /* Foi pressionada a tecla [F4]. */

// N�mero maximo de itens em um menu de sele��o
#define PWMENU_MAXINTENS        40

// Tipos de opera��o poss�veis
#define PWOPER_NULL              0x00
#define PWOPER_INSTALL           0x01
#define PWOPER_PARAMUPD          0x02
#define PWOPER_REPRINT           0x10
#define PWOPER_RPTTRUNC          0x11
#define PWOPER_RPTDETAIL         0x12
#define PWOPER_REPRINTNTRANSACTION  0x13
#define PWOPER_COMMTEST          0x14
#define PWOPER_RPTSUMMARY        0x15
#define PWOPER_TRANSACINQ        0x16
#define PWOPER_ROUTINGINQ        0x17
#define PWOPER_ADMIN             0x20
#define PWOPER_SALE              0x21
#define PWOPER_SALEVOID          0x22
#define PWOPER_PREPAID           0x23
#define PWOPER_CHECKINQ          0x24
#define PWOPER_RETBALINQ         0x25
#define PWOPER_CRDBALINQ         0x26
#define PWOPER_INITIALIZ         0x27
#define PWOPER_SETTLEMNT         0x28
#define PWOPER_PREAUTH           0x29
#define PWOPER_PREAUTVOID        0x2A
#define PWOPER_CASHWDRWL         0x2B
#define PWOPER_LOCALMAINT        0x2C
#define PWOPER_FINANCINQ         0x2D
#define PWOPER_ADDRVERIF         0x2E
#define PWOPER_SALEPRE           0x2F
#define PWOPER_LOYCREDIT         0x30
#define PWOPER_LOYCREDVOID       0x31
#define PWOPER_LOYDEBIT          0x32
#define PWOPER_LOYDEBVOID        0x33
#define PWOPER_BILLPAYMENT	      0x34    
#define PWOPER_DOCPAYMENTQ	      0x35    
#define PWOPER_LOGON	            0x36    
#define PWOPER_SRCHPREAUTH	      0x37    
#define PWOPER_ADDPREAUTH	      0x38    
#define PWOPER_VOID	            0x39    
#define PWOPER_STATISTICS	      0x40    
#define PWOPER_CARDPAYMENT	      0x41    
#define PWOPER_CARDPAYMENTVOID	0x44    
#define PWOPER_CASHWDRWLVOID	   0x45    
#define PWOPER_CARDUNLOCK	      0x46    
//#define PWOPER_TRANSACINQ	      0x47 
#define PWOPER_UPDATEDCHIP       0x48
#define PWOPER_RPTPROMOTIONAL    0x49
#define PWOPER_SALESUMMARY       0x4A
#define PWOPER_STATISTICSAUTHORIZER 0x4B
#define PWOPER_OTHERADMIN	      0x4C
#define PWOPER_BILLPAYMENTVOID   0x4E
#define PWOPER_VERSION	         0xFC
#define PWOPER_CONFIG            0xFD
#define PWOPER_MAINTENANCE       0xFE	

// Tipos de dados
#define PWINFO_OPERATION         0x02
#define PWINFO_PPPPWD            0x03
#define PWINFO_SENHASIM          0x04
#define PWINFO_AUTIP             0x05
#define PWINFO_USINGAUT          0x06
#define PWINFO_AUTPORT           0x07
#define PWINFO_ADDRMODE          0x08
#define PWINFO_LOCALIP           0x09
#define PWINFO_GATEWAY           0x0A
#define PWINFO_SUBNETMASK        0x0B
#define PWINFO_SSID              0x0C
#define PWINFO_WIFITYPE          0x0D
#define PWINFO_WIFIKEY           0x0E
#define PWINFO_COMMTYPE          0x0F
//Livre!!
#define PWINFO_POSID				   0x11
#define PWINFO_AUTNAME			   0x15
#define PWINFO_AUTVER			   0x16
#define PWINFO_AUTDEV			   0x17
#define PWINFO_DESTTCPIP			0x1B
#define PWINFO_MERCHCNPJCPF      0x1C
#define PWINFO_AUTCAP			   0x24
#define PWINFO_TOTAMNT		      0x25
#define PWINFO_CURRENCY		      0x26
#define PWINFO_CURREXP			   0x27
#define PWINFO_FISCALREF			0x28
#define PWINFO_CARDTYPE		      0x29
#define PWINFO_PRODUCTNAME			0x2A	
#define PWINFO_DATETIME		      0x31
#define PWINFO_REQNUM				0x32
#define PWINFO_AUTHSYST		      0x35
#define PWINFO_VIRTMERCH	      0x36
#define PWINFO_AUTMERCHID	      0x38
#define PWINFO_PHONEFULLNO		   0x3A
#define PWINFO_FINTYPE		      0x3B
#define PWINFO_INSTALLMENTS	   0x3C
#define PWINFO_INSTALLMDATE	   0x3D
#define PWINFO_PRODUCTID         0x3E
#define PWINFO_RESULTMSG	      0x42
#define PWINFO_CNFREQ   	      0x43
#define PWINFO_AUTLOCREF	      0x44
#define PWINFO_AUTEXTREF	      0x45
#define PWINFO_AUTHCODE		      0x46
#define PWINFO_AUTRESPCODE	      0x47
#define PWINFO_DISCOUNTAMT	      0x49
#define PWINFO_CASHBACKAMT	      0x4A
#define PWINFO_CARDNAME		      0x4B
#define PWINFO_ONOFF				   0x4C	
#define PWINFO_BOARDINGTAX		   0x4D
#define PWINFO_TIPAMOUNT			0x4E
#define PWINFO_INSTALLM1AMT		0x4F
#define PWINFO_INSTALLMAMNT		0x50
#define PWINFO_RCPTFULL 			0x52
#define PWINFO_RCPTMERCH			0x53
#define PWINFO_RCPTCHOLDER			0x54		
#define PWINFO_RCPTCHSHORT			0x55
#define PWINFO_TRNORIGDATE	      0x57
#define PWINFO_TRNORIGNSU	      0x58
#define PWINFO_TRNORIGAMNT		   0x60
#define PWINFO_LANGUAGE          0x6C
#define PWINFO_PROCESSMSG        0x6F
#define PWINFO_TRNORIGAUTH		   0x62
#define PWINFO_TRNORIGREQNUM		0x72
#define PWINFO_TRNORIGTIME		   0x73
#define PWINFO_CNCDSPMSG	      0x74	
#define PWINFO_CNCPPMSG	         0x75	
#define PWINFO_OPERABORTED	      0x76
#define PWINFO_AUTHSYSTEXTENDED  0x87
#define PWINFO_CARDENTMODE	      0xC0
#define PWINFO_CARDFULLPAN		   0xC1
#define PWINFO_CARDEXPDATE		   0xC2
#define PWINFO_CARDNAMESTD       0xC4
#define PWINFO_CARDPARCPAN			0xC8
#define PWINFO_CHOLDVERIF	      0xCF
#define PWINFO_SMSGCHOLDER	      0xE2 
#define PWINFO_SMSGMERCH	      0xE3 
#define PWINFO_SMSGTOUTSEC	      0xE4 
#define PWINFO_BARCODENTMODE	   0xE9
#define PWINFO_BARCODE	         0xEA
#define PWINFO_SMSGLOCAL         0xEB 
#define PWINFO_MERCHADDDATA1	   0xF0
#define PWINFO_MERCHADDDATA2	   0xF1	   
#define PWINFO_MERCHADDDATA3	   0xF2	
#define PWINFO_MERCHADDDATA4	   0xF3	
#define PWINFO_RCPTPRN           0xF4
#define PWINFO_AUTHMNGTUSER      0xF5
#define PWINFO_AUTHTECHUSER      0xF6
#define PWINFO_PAYMNTTYPE        0x1F21
#define PWINFO_USINGPINPAD       0x7F01
#define PWINFO_PPCOMMPORT        0x7F02
#define PWINFO_IDLEPROCTIME      0x7F04
#define PWINFO_PNDAUTHSYST	      0x7F05
#define PWINFO_PNDVIRTMERCH	   0x7F06
#define PWINFO_PNDREQNUM	      0x7F07
#define PWINFO_PNDAUTLOCREF	   0x7F08
#define PWINFO_PNDAUTEXTREF	   0x7F09
#define PWINFO_LOCALINFO1        0x7F0A
#define PWINFO_SERVERPND	      0x7F0B
#define PWINFO_COMMODE           0x7F0C
#define PWINFO_COMMPROT          0x7F0D
#define PWINFO_DIALMODE          0x7F0E
#define PWINFO_PRINUMBER         0x7F0F
#define PWINFO_SECNUMBER         0x7F10
#define PWINFO_DIALPREFIX        0x7F11
#define PWINFO_DIALWAITTIME      0x7F12
#define PWINFO_MODSPEED          0x7F13
#define PWINFO_TPDU              0x7F14
#define PWINFO_PPINFO            0x7F15
#define PWINFO_DUEAMNT           0xBF06
#define PWINFO_READJUSTEDAMNT    0xBF09
#define PWINFO_SMSPHONE          0xBF6D

/* Faixa reservada para tags de transmiss�o (PTI), evitando conflitos com as tags da lib   */
/* Devido a padroniza��o, a faixa foi criada para evitar eventuais conflitos de tags entre */
/* comunica��o do POS e PTI.                                                               */
#define PWPTI_FIRSTTAG           0x80 /* In�cio do range para Tags na PTI */
#define PWPTI_RESULT             0x81
#define PWPTI_MSGTYPE            0x82
#define PWPTI_TIMEOUT            0x83
#define PWPTI_POSMACADD          0x84
#define PWPTI_VERSION            0x85
#define PWPTI_POSMODEL           0x86
#define PWPTI_POSSERNO           0x87
#define PWPTI_DSPMSG             0x88
#define PWPTI_KEY                0x89
#define PWPTI_PROMPT             0x8A
#define PWPTI_DATA               0x8B
#define PWPTI_FORMAT             0x8C
#define PWPTI_LENMIN             0x8D
#define PWPTI_LENMAX             0x8E
#define PWPTI_FROMLEFT           0x8F
#define PWPTI_MASK               0x90
#define PWPTI_ALPHA              0x91
#define PWPTI_NUMITENS           0x92
#define PWPTI_MENUITENS          0x93
#define PWPTI_SELECTION          0x94
#define PWPTI_BEEPTYPE           0x95
#define PWPTI_PRNTEXT            0x96
#define PWPTI_AUTVERSION         0x97
#define PWPTI_AUTDEVELOP         0x98
#define PWPTI_CAPTURELINE        0x99
#define PWPTI_IDLEMSG            0x9A
#define PWPTI_IDLETIME           0x9B
#define PWPTI_RCPTTOPRN          0x9C
#define PWPTI_MUXTERMINALID      0x9D
#define PWPTI_AUTCAP             0x9E
#define PWPTI_EFTRESMSG          0xA0
#define PWPTI_EFTCONF            0xA1
#define PWPTI_CODESYMBOL         0xA2
#define PWPTI_BARCODEERR         0xA3
#define PWPTI_RESPCODE           0xA4
#define PWPTI_COMMODE            0xA5
#define PWPTI_CLIVERSION         0xA6
#define PWPTI_EFTCONFREQNUM      0xA7
#define PWPTI_EFTCONFLOCREF      0xA8
#define PWPTI_EFTCONFEXTREF      0xA9
#define PWPTI_EFTCONFVIRTMERCH   0xAA
#define PWPTI_EFTCONFAUTSYST     0xAB
#define PWPTI_LASTTAG            0xBF /* Fim do range para Tags na PTI */


// Tipos de opera��o, utilizados na fun��o PW_iGetOperations
#define PWOPTYPE_ADMIN           1
#define PWOPTYPE_SALE            2

// Tipo de chave de criiptografia wi-fi
#define PW_WIFITYPE_UNKNOWN  0
#define PW_WIFITYPE_NONE     1
#define PW_WIFITYPE_WPA      2
#define PW_WIFITYPE_WEP      3
#define PW_WIFITYPE_WEP64    4
#define PW_WIFITYPE_WEP128   5
#define PW_WIFITYPE_WPA2     6

// Defini��es para chave de criptografia Wi-Fi
#define PW_WPAKEY_ASC_MIN_SIZE    8
#define PW_WPAKEY_ASC_MAX_SIZE   63
#define PW_WEP64KEY_ASC_SIZE      5
#define PW_WEP128KEY_ASC_SIZE    13
#define PW_WIFIKEY_ASC_MAX_SIZE  PW_WPAKEY_ASC_MAX_SIZE
#define PW_SSID_MAX_SIZE         32

typedef struct{
   Word     wIdentificador; 
   Byte     bTipoDeDado;
   char     szPrompt[84];
   Byte     bNumOpcoesMenu;
   char     vszTextoMenu[PWMENU_MAXINTENS][41];
   char     vszValorMenu[PWMENU_MAXINTENS][256];
   char     szMascaraDeCaptura[41];
   Byte     bTiposEntradaPermitidos;
   Byte     bTamanhoMinimo;
   Byte     bTamanhoMaximo;
   Uint32   ulValorMinimo;
   Uint32   ulValorMaximo;
   Byte     bOcultarDadosDigitados;
   Byte     bValidacaoDado;
   Byte     bAceitaNulo;
   char     szValorInicial[41];
   Byte     bTeclasDeAtalho;
   char     szMsgValidacao[84];
   char     szMsgConfirmacao[84];
   char     szMsgDadoMaior[84];
   char     szMsgDadoMenor[84];
   Byte     bCapturarDataVencCartao;
   Uint32   ulTipoEntradaCartao;
   Byte     bItemInicial;
   Byte     bNumeroCapturas;
   char     szMsgPrevia[84];
   Byte     bTipoEntradaCodigoBarras;
   Byte     bOmiteMsgAlerta;
   Byte     bIniciaPelaEsquerda;
   Byte     bNotificarCancelamento;
   Byte     bAlinhaPelaDireita;
} PW_GetData; 

typedef struct{
   Byte  bOperType;
   char  szText[21];
   char  szValue[21];
} PW_Operations;

/******************************************/
/* Public functions - Exported within DLL */
/******************************************/
/*=========================================================================================================*\
 Funcao     :  PW_iInit

 Descricao  :  Esta fun��o � utilizada para inicializar a biblioteca, e retorna imediatamente. Deve ser 
               garantido que uma chamada dela retorne PWRET_OK antes de chamar qualquer outra fun��o.
 
 Entradas   :  pszWorkingDir:    Diret�rio de trabalho (caminho completo, com final nulo) para uso exclusivo 
                                 do Pay&Go Web.

 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         Opera��o bem sucedida.
               PWRET_WRITERR	   Falha de grava��o no diret�rio informado.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iInit (const char* pszWorkingDir);

/*=========================================================================================================*\
 Funcao     :  PW_iNewTransac

 Descricao  :  Esta fun��o deve ser chamada para iniciar uma nova transa��o atrav�s do Pay&Go Web, 
               e retorna imediatamente.

               Importante: independentemente das funcionalidades suportadas pela Automa��o e pelo Ponto de 
               Captura, � requerido que a Automa��o disponibilize ao operador uma fun��o para realizar uma 
               transa��o administrativa (PWOPER_ADMIN), para permitir o acesso �s fun��es de manuten��o do 
               Pay&Go Web. Caso desejado, o acesso a este recurso pode ser restrito a operadores espec�ficos.
 
 Entradas   :  bOper:	Tipo de opera��o sendo efetuada (constantes PWOPER_xxx):
                        1:  Pagamento 
                        2:  Administrativa 

 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         Transa��o inicializada.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               PWRET_NOTINST	   � necess�rio efetuar uma transa��o de Instala��o.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iNewTransac (Byte bOper);

/*=========================================================================================================*\
 Funcao     :  PW_iAddParam

 Descricao  :  Esta fun��o � utilizada para alimentar a biblioteca com as informa��es da transa��o a ser 
               realizada, e retorna imediatamente. Estas informa��es podem ser:
                  �	Pr�-fixadas na Automa��o;
                  �	Capturadas do operador pela Automa��o antes do acionamento do Pay&Go Web;
                  �	Capturadas do operador ap�s solicita��o pelo Pay&Go Web (retorno PW_MOREDATA por PW_iExecTransac).

 Entradas   :  wParam:	      Identificador do par�metro.
               pszValue:	   Valor do par�metro informado.

 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         Par�metro acrescentado com sucesso.
               PWRET_INVPARAM	   O valor do par�metro � inv�lido.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               PWRET_TRNNOTINIT	N�o foi executado PW_iNewTransac (ver p�gina 10).
               PWRET_NOTINST	   � necess�rio efetuar uma transa��o de Instala��o.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iAddParam (Word wParam, const char *pszValue);

/*=========================================================================================================*\
 Funcao     :  PW_iExecTransac

 Descricao  :  Esta fun��o tenta realizar uma transa��o atrav�s do Pay&Go Web, utilizando os par�metros 
               previamente definidos atrav�s de PW_iAddParam. Caso algum dado adicional precise ser informado, 
               o retorno ser� PWRET_MOREDATA e o par�metro pvstParam retornar� informa��es dos dados que ainda 
               devem ser capturados.
               Esta fun��o, por se comunicar com a infraestrutura Pay&Go Web, pode demorar alguns segundos 
               para retornar.
 
 Entradas   :  piNumParam: 	Quantidade m�xima de dados que podem ser capturados de uma vez, caso o retorno 
                              seja PW_MOREDATA. (Deve refletir o tamanho da �rea de mem�ria apontada por 
                              pvstParam.) Valor sugerido: 9.
 
 Saidas     :  pvstParam: 	   Lista e caracter�sticas dos dados que precisam ser informados para executar a 
                              transa��o. Consultar �8.Captura de dados� (p�gina 29) para a descri��o da estrutura 
                              e instru��es para a captura de dados adicionais.
               piNumParam:	   Quantidade de dados adicionais que precisam ser capturados (quantidade de ocorr�ncias 
                              preenchidas em pvstParam).

 Retorno    :  PWRET_OK	         Transa��o realizada com sucesso. Os resultados da transa��o devem ser obtidos atrav�s da fun��o PW_iGetResult.
               PWRET_MOREDATA	   Mais dados s�o requeridos para executar a transa��o.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               PWRET_TRNNOTINIT	N�o foi executado PW_iNewTransac (ver p�gina 10).
               PWRET_NOTINST	   � necess�rio efetuar uma transa��o de Instala��o.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iExecTransac (PW_GetData vstParam[], Int16 *piNumParam);

/*=========================================================================================================*\
 Funcao     :  PW_iGetResult

 Descricao  :  Esta fun��o pode ser chamada para obter informa��es que resultaram da transa��o efetuada, 
               independentemente de ter sido bem ou mal sucedida, e retorna imediatamente.
 
 Entradas   :  iInfo:	   C�digo da informa��o solicitada sendo requisitada (PWINFO_xxx, ver lista completa 
                           em �9. Dicion�rio de dados�, p�gina 36).
               ulDataSize:	Tamanho (em bytes) da �rea de mem�ria apontada por pszData. Prever um tamanho maior 
                           que o m�ximo previsto para o dado solicitado.

 
 Saidas     :  pszData:	   Valor da informa��o solicitada (string ASCII com terminador nulo).
 
 Retorno    :  PWRET_OK	         Sucesso. pszData cont�m o valor solicitado.
               PWRET_NODATA	   A informa��o solicitada n�o est� dispon�vel.
               PWRET_BUFOVFLW 	O valor da informa��o solicitada n�o cabe em pszData.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               PWRET_TRNNOTINIT	N�o foi executado PW_iNewTransac (ver p�gina 10).
               PWRET_NOTINST	   � necess�rio efetuar uma transa��o de Instala��o.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iGetResult (Int16 iInfo, char *pszData, Uint32 ulDataSize);

/*=========================================================================================================*\
 Funcao     :  PW_iConfirmation

 Descricao  :  Esta fun��o informa ao Pay&Go Web o status final da transa��o em curso (confirmada ou desfeita). 
               Consultar �7. Confirma��o de transa��o� (p�gina 28) para informa��es adicionais.
 
 Entradas   :  ulStatus:   	Resultado da transa��o (PWCNF_xxx, ver lista abaixo).
               pszReqNum:  	Refer�ncia local da transa��o, obtida atrav�s de PW_iGetResult (PWINFO_REQNUM).
               pszLocRef:  	Refer�ncia da transa��o para a infraestrutura Pay&Go Web, obtida atrav�s de PW_iGetResult (PWINFO_AUTLOCREF). 
               pszExtRef:  	Refer�ncia da transa��o para o Provedor, obtida atrav�s de PW_iGetResult (PWINFO_AUTEXTREF).
               pszVirtMerch:	Identificador do Estabelecimento, obtido atrav�s de PW_iGetResult (PWINFO_VIRTMERCH). 
               pszAuthSyst:   Nome do Provedor, obtido atrav�s de PW_iGetResult (PWINFO_AUTHSYST).
 
 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         O status da transa��o foi atualizado com sucesso.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               PWRET_NOTINST	   � necess�rio efetuar uma transa��o de Instala��o.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/ 
extern Int16 PW_EXPORT PW_iConfirmation (Uint32 ulResult, const char* pszReqNum, const char* pszLocRef, const char* pszExtRef,
   const char* pszVirtMerch, const char* pszAuthSyst);

/*=========================================================================================================*\
 Funcao     :  PW_iIdleProc

 Descricao  :  Para o correto funcionamento do sistema, a biblioteca do Pay&Go Web precisa de tempos em tempos 
               executar tarefas autom�ticas enquanto n�o est� realizando nenhuma transa��o a pedido da Automa��o. 

 Entradas   :  n�o h�.

 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         Opera��o realizada com �xito.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               PWRET_NOTINST	   � necess�rio efetuar uma transa��o de Instala��o.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/ 
extern Int16 PW_EXPORT PW_iIdleProc(void);

/*=========================================================================================================*\
 Funcao     :  PW_iGetOperations

 Descricao  :  Esta fun��o pode ser chamada para obter quais opera��es o Pay&Go WEB disponibiliza no momento, 
               sejam elas administrativas, de venda ou ambas. 

 Entradas   :              bOperType	      Soma dos tipos de opera��o a serem inclu�dos na estrutura de 
                                             retorno (PWOPTYPE_xxx).	
                           piNumOperations	N�mero m�ximo de opera��es que pode ser retornado. (Deve refletir 
                                             o tamanho da �rea de mem�ria apontada por pvstOperations).
 
 Sa�das     :              piNumOperations	N�mero de opera��es dispon�veis no Pay&Go WEB.
                           vstOperations	   Lista das opera��es dispon�veis e suas caracter�sticas.

 
 Retorno    :  PWRET_OK	         Opera��o realizada com �xito.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               PWRET_NOTINST	   � necess�rio efetuar uma transa��o de Instala��o.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/ 
extern Int16 PW_EXPORT PW_iGetOperations(Byte bOperType, PW_Operations vstOperations[], Int16 *piNumOperations);

/*=========================================================================================================*\
 Funcao     :  PW_iPPEventLoop

 Descricao  :  Esta fun��o dever� ser chamada em �loop� at� que seja retornado PWRET_OK (ou um erro fatal). Nesse 
               �loop�, caso o retorno seja PWRET_DISPLAY o ponto de captura dever� atualizar o �display� com as 
               mensagens recebidas da biblioteca.
 
 Entradas   :  ulDisplaySize	Tamanho (em bytes) da �rea de mem�ria apontada por pszDisplay. 
                              Tamanho m�nimo recomendado: 100 bytes.

 Saidas     :  pszDisplay	   Caso o retorno da fun��o seja PWRET_DISPLAY, cont�m uma mensagem de texto 
                              (string ASCII com terminal nulo) a ser apresentada pela Automa��o na interface com 
                              o usu�rio principal. Para o formato desta mensagem, consultar �4.3.Interface com o 
                              usu�rio�, p�gina 8.
 
 Retorno    :  PWRET_NOTHING	   Nada a fazer, continuar aguardando o processamento do PIN-pad.
               PWRET_DISPLAY	   Apresentar a mensagem recebida em pszDisplay e continuar aguardando o processamento do PIN-pad.
               PWRET_OK	         Captura de dados realizada com �xito, prosseguir com a transa��o.
               PWRET_CANCEL	   A opera��o foi cancelada pelo Cliente no PIN-pad (tecla [CANCEL]).
               PWRET_TIMEOUT	   O Cliente n�o realizou a captura no tempo limite.
               PWRET_FALLBACK	   Ocorreu um erro na leitura do cart�o, passar a aceitar a digita��o do n�mero do cart�o, caso j� n�o esteja aceitando.
               PWRET_PPCOMERR	   Falha na comunica��o com o PIN-pad.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               PWRET_INVCALL	   N�o h� captura de dados no PIN-pad em curso.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/ 
extern Int16 PW_EXPORT PW_iPPEventLoop (char *pszDisplay, Uint32 ulDisplaySize);

/*=========================================================================================================*\
 Funcao     :  PW_iPPAbort

 Descricao  :  Esta fun��o pode ser utilizada pela Automa��o para interromper uma captura de dados no PIN-pad 
               em curso, e retorna imediatamente.
 
 Entradas   :  n�o h�.

 Saidas     :  n�o h�. 
 
 Retorno    :  PWRET_OK	         Opera��o interrompida com sucesso.
               PWRET_PPCOMERR	   Falha na comunica��o com o PIN-pad.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/ 
extern Int16 PW_EXPORT PW_iPPAbort(void);

/*=========================================================================================================*\
 Funcao     :  PW_iPPGetCard

 Descricao  :  Esta fun��o � utilizada para realizar a leitura de um cart�o (magn�tico, com chip com contato, 
               ou sem contato) no PIN-pad.
 
 Entradas   :  uiIndex	�ndice (iniciado em 0) do dado solicitado na �ltima execu��o de PW_iExecTransac 
                        (�ndice do dado no vetor pvstParam).

 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         Captura iniciada com sucesso, chamar PW_iPPEventLoop para obter o resultado.
               PWRET_INVPARAM	   O valor de uiIndex informado n�o corresponde a uma captura de dados deste tipo.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/ 
extern Int16 PW_EXPORT PW_iPPGetCard (Uint16 uiIndex);

/*=========================================================================================================*\
 Funcao     :  PW_iPPGetPIN

 Descricao  :  Esta fun��o � utilizada para realizar a captura no PIN-pad da senha (ou outro dado criptografado) 
               do Cliente.
 
 Entradas   :  uiIndex	�ndice (iniciado em 0) do dado solicitado na �ltima execu��o de PW_iExecTransac 
                        (�ndice do dado no vetor pvstParam).
   
 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         Captura iniciada com sucesso, chamar PW_iPPEventLoop para obter o resultado.
               PWRET_INVPARAM	   O valor de uiIndex informado n�o corresponde a uma captura de dados deste tipo.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iPPGetPIN (Uint16 uiIndex);

/*=========================================================================================================*\
 Funcao     :  PW_iPPGetData

 Descricao  :  Esta fun��o � utilizada para fazer a captura no PIN-pad de um dado n�o sens�vel do Cliente..
 
 Entradas   :  uiIndex	�ndice (iniciado em 0) do dado solicitado na �ltima execu��o de PW_iExecTransac 
                        (�ndice do dado no vetor pvstParam).

 Saidas     :  nao ha.
 
 Retorno    :  PWRET_OK	         Captura iniciada com sucesso, chamar PW_iPPEventLoop para obter o resultado.
               PWRET_INVPARAM	   O valor de uiIndex informado n�o corresponde a uma captura de dados deste tipo.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iPPGetData (Uint16 uiIndex);

/*=========================================================================================================*\
 Funcao     :  PW_iPPGoOnChip

 Descricao  :  Esta fun��o � utilizada para realizar o processamento off-line (antes da comunica��o com o Provedor) 
               de um cart�o com chip no PIN-pad. 
 
 Entradas   :  uiIndex	�ndice (iniciado em 0) do dado solicitado na �ltima execu��o de PW_iExecTransac 
                        (�ndice do dado no vetor pvstParam).

 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         Captura iniciada com sucesso, chamar PW_iPPEventLoop para obter o resultado.
               PWRET_INVPARAM	   O valor de uiIndex informado n�o corresponde a uma captura de dados deste tipo.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iPPGoOnChip (Uint16 uiIndex);

/*=========================================================================================================*\
 Funcao     :  PW_iPPFinishChip

 Descricao  :  Esta fun��o � utilizada para finalizar o processamento on-line (ap�s comunica��o com o Provedor) 
               de um cart�o com chip no PIN-pad.
 
 Entradas   :  uiIndex	�ndice (iniciado em 0) do dado solicitado na �ltima execu��o de PW_iExecTransac 
                        (�ndice do dado no vetor pvstParam).

 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         Captura iniciada com sucesso, chamar PW_iPPEventLoop para obter o resultado.
               PWRET_INVPARAM	   O valor de uiIndex informado n�o corresponde a uma captura de dados deste tipo.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iPPFinishChip (Uint16 uiIndex);

/*=========================================================================================================*\
 Funcao     :  PW_iPPConfirmData

 Descricao  :  Esta fun��o � utilizada para obter do Cliente a confirma��o de uma informa��o no PIN-pad.
 
 Entradas   :  uiIndex	�ndice (iniciado em 0) do dado solicitado na �ltima execu��o de PW_iExecTransac 
                        (�ndice do dado no vetor pvstParam).

 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         Captura iniciada com sucesso, chamar PW_iPPEventLoop para obter o resultado.
               PWRET_INVPARAM	   O valor de uiIndex informado n�o corresponde a uma captura de dados deste tipo.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iPPConfirmData (Uint16 uiIndex);

/*=========================================================================================================*\
 Funcao     :  PW_iPPRemoveCard

 Descricao  :  Esta fun��o � utilizada para fazer uma remo��o de cart�o do PIN-pad.
 
 Entradas   :  n�o h�.

 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         Captura iniciada com sucesso, chamar PW_iPPEventLoop para obter o resultado.
               PWRET_INVPARAM	   O valor de uiIndex informado n�o corresponde a uma captura de dados deste tipo.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iPPRemoveCard(void);

/*=========================================================================================================*\
 Funcao     :  PW_iPPDisplay

 Descricao  :  Esta fun��o � utilizada para apresentar uma mensagem no PIN-pad
 
 Entradas   :  pszMsg   Mensagem a ser apresentada no PIN-pad. O caractere �\r� (0Dh) indica uma quebra de linha.

 Saidas     :  n�o h�.
 
 Retorno    :  PWRET_OK	         Captura iniciada com sucesso, chamar PW_iPPEventLoop para obter o resultado.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iPPDisplay(const char *pszMsg);

/*=========================================================================================================*\
 Funcao     :  PW_iPPWaitEvent

 Descricao  :  Esta fun��o � utilizada para aguardar a ocorr�ncia de um evento no PIN-pad.
 
 Entradas   :  n�o h�.

 Saidas     :  pulEvent	         Evento ocorrido.
 
 Retorno    :  PWRET_OK	         Captura iniciada com sucesso, chamar PW_iPPEventLoop para obter o resultado.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/
extern Int16 PW_EXPORT PW_iPPWaitEvent(Uint32 *pulEvent);

/*===========================================================================*\
 Funcao   : PW_iPPGenericCMD

 Descricao  :  Realiza comando gen�rico de PIN-pad.
 
 Entradas   :  uiIndex	�ndice (iniciado em 0) do dado solicitado na �ltima execu��o de PW_iExecTransac 
                        (�ndice do dado no vetor pvstParam).

 Saidas     :  N�o h�.
 
 Retorno    :  PWRET_xxx.
\*===========================================================================*/
extern Int16 PW_EXPORT PW_iPPGenericCMD (Uint16 uiIndex);

/*===========================================================================*\
 Funcao     : PW_iPPPositiveConfirmation

 Descricao  :  Realiza a confirma��o positiva de um dado, ou um bloco de dados,
                no PIN-pad
 
 Entradas   :  uiIndex	�ndice (iniciado em 0) do dado solicitado na �ltima execu��o de PW_iExecTransac 
                        (�ndice do dado no vetor pvstParam).

 Saidas     :  N�o h�.
 
 Retorno    :  PWRET_xxx.
\*===========================================================================*/
extern Int16 PW_EXPORT PW_iPPPositiveConfirmation (Uint16 uiIndex);

/*===========================================================================*\
 Funcao     : PW_iTransactionInquiry

 Descricao  :  Esta fun��o � utilizada para realizar uma consulta de transa��es 
               efetuadas por um ponto de captura junto ao Pay&Go WEB.
 
 Entradas   :  pszXmlRequest	Arquivo de entrada no formato XML, contendo as informa��es 
                              necess�rias para fazer a consulta pretendida.
               ulXmlResponseLen Tamanho da string pszXmlResponse.

 Saidas     :  pszXmlResponse	Arquivo de sa�da no formato XML, contendo o resultado da consulta 
                              efetuada, o arquivo de sa�da tem todos os elementos do arquivo de entrada.
 
 Retorno    :  PWRET_xxx.
\*===========================================================================*/
extern Int16 PW_EXPORT PW_iTransactionInquiry (const char *pszXmlRequest, char* pszXmlResponse, Uint32 ulXmlResponseLen);

/*=========================================================================================================*\
 Funcao     :  PW_iGetUserData

 Descricao  :  Esta fun��o � utilizada para obter um dado digitado pelo portador do cart�o no PIN-pad.

 Entradas   :  uiMessageId : Identificador da mensagem a ser exibida como prompt para a captura.
               bMinLen     : Tamanho m�nimo do dado a ser digitado.
               bMaxLen     : Tamanho m�ximo do dado a ser digitado.
               iToutSec    : Tempo limite para a digita��o do dado em segundos.
 
 Sa�das     :  pszData     : Dado digitado pelo portador do cart�o no PIN-pad.
 
 Retorno    :  PWRET_OK	         Opera��o realizada com �xito.
               PWRET_DLLNOTINIT	N�o foi executado PW_iInit.
               PWRET_NOTINST	   � necess�rio efetuar uma transa��o de Instala��o.
               PWRET_CANCEL	   A opera��o foi cancelada pelo Cliente no PIN-pad (tecla [CANCEL]).
               PWRET_TIMEOUT	   O Cliente n�o realizou a captura no tempo limite.
               PWRET_PPCOMERR	   Falha na comunica��o com o PIN-pad.
               PWRET_INVCALL	   N�o � poss�vel capturar dados em um PIN-pad n�o ABECS.
               Outro	            Outro erro de execu��o (ver �10. C�digos de retorno�, p�gina 40). Uma mensagem 
                                 de erro pode ser obtida atrav�s da fun��o PW_iGetResult (PWINFO_RESULTMSG).
\*=========================================================================================================*/ 
extern Int16 PW_EXPORT PW_iPPGetUserData(Uint16 uiMessageId, Byte bMinLen, Byte bMaxLen, Int16 iToutSec, char *pszData);

#endif










