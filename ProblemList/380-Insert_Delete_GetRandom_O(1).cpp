class RandomizedSet {
public:
    unordered_map<int,int> valores;
    vector<int> listaValores;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valores.find(val) != valores.end()){
            return false;
        }
        listaValores.push_back(val);
        valores[val] = listaValores.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (valores.find(val) == valores.end()) {
            return false; // Si no está, retorna false
        }

        int index = valores[val];
        int lastValue = listaValores.back();

        listaValores[index] = lastValue;
        valores[lastValue] = index;

        listaValores.pop_back();
        valores.erase(val);

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % listaValores.size();
        return listaValores[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
