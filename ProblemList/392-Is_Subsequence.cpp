class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool solucion = false;
        int i = 0;
        int i_grande = 0;
        int j = s.size()-1;
        int j_grande = t.size()-1;
        int count = 0;

        while((i <= j) && (i_grande <=  j_grande)){
            if(t[i_grande] == s[i]){
                //Paso a la siguiente letra
                i++;
                count++;
            }
            if(t[j_grande] == s[j] && (i <= j) && (i_grande <  j_grande)){
                j--;
                count++;
            }
            i_grande++;
            j_grande--;
        }
        if(s.size() == count){
            solucion = true;
        }
        return solucion;
    }
};
