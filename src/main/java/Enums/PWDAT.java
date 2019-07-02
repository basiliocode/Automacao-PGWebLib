package Enums;

public enum PWDAT {

    MENU((byte)1),
    TYPED((byte)2),
    CARDINF((byte)3),
    PPENTRY((byte)5),
    PPENCPIN((byte)6),
    CARDOFF((byte)9),
    CARDONL((byte)10),
    PPCONF((byte)11),
    BARCODE((byte)12),
    PPREMCRD((byte)13),
    PPGENCMD(),
    PPDATAPOSCNF((byte)16),
    USERAUTH((byte)17);

    private byte valor;

    PWDAT(byte valor){
        this.valor = valor;
    }
    PWDAT(){ valor = -1; }

    public byte getValor(){
        return this.valor;
    }
}
