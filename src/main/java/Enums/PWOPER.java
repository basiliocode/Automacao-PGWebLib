package Enums;

public enum PWOPER {
    NULL(0),
    INSTALL(1),
    PARAMUPD(2),
    REPRINT(16),
    RPTTRUNC(17),
    RPTDETAIL(18),
    RPTSUMMARY(21),
    ADMIN(32),
    SALE(33),
    SALEVOID(34),
    PREPAID(35),
    CHECKINQ(36),
    RETBALINQ(37),
    CRDBALINQ(38),
    INITIALIZ(39),
    SETTLEMNT(40),
    PREAUTH(41),
    PREAUTVOID(42),
    CASHWDRWL(43),
    LOCALMAINT(44),
    FINANCINQ(45),
    ADDRVERIF(46),
    SALEPRE(47),
    LOYCREDIT(48),
    LOYCREDVOID(49),
    LOYDEBIT(50),
    LOYDEBVOID(51),
    VOID(57),
    SHOWPDC(251),
    VERSION(252),
    CONFIG(253),
    MAINTENACE(254);

    private int valor;

    PWOPER(int valor){
        this.valor = valor;
    }

    public int getValor(){
        return this.valor;
    }
}
