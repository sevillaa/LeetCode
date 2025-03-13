class Solution {
public:
    string compressedString(string word) {
        string solucion;
        int contador = 1;
        char aux = word[0];
        for(int i = 1; i <word.size();i++){
            if(word[i]==aux){
                if(contador < 9){
                    contador++;
                }else{
                    solucion += to_string(contador);
                    solucion +=aux;
                    contador = 1;
                }
                
            }else{
                //escribo la solucion ya que cambio de letra
                solucion += to_string(contador);
                solucion +=aux;
                aux = word[i];
                contador = 1;
            }
        }
        //escribo la ultima letra
        solucion += to_string(contador);
        solucion +=aux;
        return solucion;
    }
};
