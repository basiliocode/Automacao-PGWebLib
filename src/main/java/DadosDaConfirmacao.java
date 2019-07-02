import Enums.PWINFO;
import java.util.HashMap;
import java.util.Map;

public class DadosDaConfirmacao {

    private Map<PWINFO,String> results;

    public DadosDaConfirmacao(){
        this.results  = new HashMap<PWINFO, String>();
    }

    public void addPWinfo (PWINFO pwinfo, String value){
        this.results.put(pwinfo, value);
    }

    public String getPWinfo (PWINFO pwinfo){
        if(this.results.containsKey(pwinfo)){
            return this.results.get(pwinfo);
        } else{
            return pwinfo.toString() + " Não encontrado!";
        }
    }

    public String getAllPWinfo (){
        if(!this.results.isEmpty()){
            String data = "";
            for ( PWINFO pwinfo: this.results.keySet()) {
                data += pwinfo.toString() +": "+ this.results.get(pwinfo)+ "\n";
            }
            return data;
        } else{
            return " Não há dados!";
        }
    }
}
