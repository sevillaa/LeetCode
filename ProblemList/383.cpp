class Solution {
public:
    bool canConstruct(string magazine, string ransomNote) {
        unordered_map<char,int> hashmap; 

        for(int i= 0; i < ransomNote.size();i++){
            char c = ransomNote[i];
            hashmap[c]++;
        }

        bool sePuede = true;
        int j = 0;
        while(sePuede && j < magazine.size()){
            char c = magazine[j];
            if(hashmap[c] > 0){
                hashmap[c]--;
            }else{
                sePuede = false;
            }
            j++;
        }

        return sePuede;
    }
};
