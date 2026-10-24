class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for(const auto& s : strs){
            string sorteds = s;
            sort(sorteds.begin(), sorteds.end());
            res[sorteds].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto& pair : res){
            ans.push_back(pair.second);
        }
    return ans; 
    }
};
