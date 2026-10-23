class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mapa;
        unordered_map<char,int> mapb;

        if(s.size() != t.size()){
            return false;
        }

        for(char p : s){
            mapa[p]++;
        }
        
        for(char q : t){
            mapb[q]++;
        }

        return mapa == mapb;


    }
};
