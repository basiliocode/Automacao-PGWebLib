package Enums;

public enum PWOPER {
    ADMIN(32),
    SALE(33),
    INSTALL(1),
    VERSION(252),
    MAINTENACE(254);

    private int valor;

    PWOPER(int valor){
        this.valor = valor;
    }

    public int getValor(){
        return this.valor;
    }
}
