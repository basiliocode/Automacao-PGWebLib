package Enums;

public enum PWRET {
    OK((short)0),
    FROMHOSTPENDTRN((short)-2599),
    FROMHOSTPOSAUTHERR((short)-2598),
    FROMHOSTUSRAUTHERR((short)-2597),
    FROMHOST((short)-2596),
    TLVERR((short)-2595),
    SRVINVPARAM((short)-2594),
    REQPARAM((short)-2593),
    HOSTCONNUNK((short)-2592),
    INTERNALERR((short)-2591),
    BLOCKED((short)-2590),
    FROMHOSTTRNNFOUND((short)-2589),
    PARAMSFILEERR((short)-2588),
    NOCARDENTMODE((short)-2587),
    INVALIDVIRTMERCH((short)-2586),
    HOSTTIMEOUT((short)-2585),
    CONFIGREQUIRED((short)-2584),
    HOSTCONNERR((short)-2583),
    HOSTCONNLOST((short)-2582),
    FILEERR((short)-2581),
    PINPADERR((short)-2580),
    MAGSTRIPEERR((short)-2579),
    PPCRYPTERR((short)-2578),
    SSLCERTERR((short)-2577),
    SSLNCONN((short)-2576),
    GPRSATTACHFAILED((short)-2575),
    EMVDENIEDCARD,
    EMVDENIEDHOST,
    NOLINE,
    NOANSWER,
    SYNCERROR,
    CRCERR,
    DECOMPERR,
    PROTERR,
    NOSIM,
    SIMERROR,
    SIMBLOCKED,
    PPPNEGFAILED,
    WIFICONNERR,
    WIFINOTFOUND,
    //endregion


    //region Erros específicos da biblioteca*/
    INVPARAM((short)-2499),
    NOTINST((short)-2498),
    MOREDATA((short)-2497),
    NODATA((short)-2496),
    DISPLAY((short)-2495),
    INVCALL((short)-2494),
    NOTHING((short)-2493),
    BUFOVFLW((short)-2492),
    CANCEL((short)-2491),
    TIMEOUT((short)-2490),
    PPNOTFOUND((short)-2489),
    TRNNOTINIT((short)-2488),
    DLLNOTINIT((short)-2487),
    FALLBACK((short)-2486),
    WRITERR((short)-2485),
    PPCOMERR((short)-2484),
    NOMANDATORY((short)-2483),
    OFFINTERNAL,
    OFFINVCAP,
    OFFNOCARDENTMODE,
    OFFINVCARDENTMODE,
    OFFNOTABLECARDRANGE,
    OFFNOTABLEPRODUCT,
    OFFINVTAG,
    OFFNOCARDFULLPAN,
    OFFINVCARDEXPDT,
    OFFCARDEXP,
    OFFNOTRACKS,
    OFFTRACKERR,
    OFFCHIPMANDATORY,
    OFFINVCARD,
    OFFINVCURR,
    OFFINVAMOUNT,
    OFFGREATERAMNT,
    OFFLOWERAMNT,
    OFFGREATERINST,
    OFFLOWERINST,
    OFFINVCARDTYPE,
    OFFINVFINTYPE,
    OFFINVINST,
    OFFGREATERINSTNUM,
    OFFLOWERINSTNUM,
    OFFMANDATORYCVV,
    OFFINVLASTFOUR,
    OFFNOAID,
    OFFNOFALLBACK,
    OFFNOPINPAD,
    OFFNOAPOFF,
    OFFTRNNEEDPP,
    OFFCARDNACCEPT,
    OFFTABLEERR,
    OFFMAXTABERR,
    OFFINTERNAL1,
    OFFINTERNAL2,
    OFFINTERNAL3,
    OFFINTERNAL4,
    OFFINTERNAL5,
    OFFINTERNAL6,
    OFFINTERNAL7,
    OFFINTERNAL8,
    OFFINTERNAL9,
    OFFINTERNAL10,
    OFFINTERNAL11,
    OFFNOPRODUCT;

    private short valor;

    PWRET(short valor){
        this.valor = valor;
    }

    PWRET(){
        this.valor = -1;
    }


    public short getValor(){
        return this.valor;
    }

    @Override
    public String toString(){
        return "PWRET." + super.toString();
    }

}
