class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array de 62 posiciones:
        // 0-25: 'a'-'z'
        // 26-51: 'A'-'Z'
        // 52-61: '0'-'9'
        int letras[62] = {0};
        int letra;
        int i = 0, j = 0;
        int actual = 0, maximo = 0;

        // Se trabaja en ASCII: al encontrar un duplicado en letras/dígitos se reinicia la subcadena.
        while(j < s.size()){
            char c = s[j];

            // Caso especial: para espacios se cuenta cada uno, incluso si son consecutivos.
            if(c == ' ') {
                actual = 1;
                if(actual > maximo)
                    maximo = actual;
                j++;
                continue;
            }
            
            // Para letras y dígitos se asigna un índice en el array.
            if(c >= 'a' && c <= 'z'){
                letra = c - 'a';
            }
            else if(c >= 'A' && c <= 'Z'){
                letra = 26 + (c - 'A');
            }
            else if(c >= '0' && c <= '9'){
                letra = 52 + (c - '0');
            }
            else {
                // Para otros caracteres (distintos de espacio), simplemente se cuentan sin registro de duplicados.
                actual++;
                if(actual > maximo)
                    maximo = actual;
                j++;
                continue;
            }
            
            if(letras[letra] <= 0){
                letras[letra]++;
            }
            else{
                // Al encontrar un duplicado, se reinicia el array y se mueve el inicio de la subcadena.
                memset(letras, 0, sizeof(letras));
                i++;
                j = i;
                if(i < s.size()){
                    char c2 = s[i];
                    if(c2 == ' ') {
                        // No se registra el espacio en el array.
                    }
                    else if(c2 >= 'a' && c2 <= 'z')
                        letras[c2 - 'a']++;
                    else if(c2 >= 'A' && c2 <= 'Z')
                        letras[26 + (c2 - 'A')]++;
                    else if(c2 >= '0' && c2 <= '9')
                        letras[52 + (c2 - '0')]++;
                }
                actual = 0;
            }
            actual++;
            if(actual > maximo)
                maximo = actual;
            j++;
        }
        return maximo;
    }
};
