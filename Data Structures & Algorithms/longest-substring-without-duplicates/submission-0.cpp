class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seq;
        int left = 0;
        int maxlen = 0;

        for(int right=0; right<s.size(); right++){
            while(seq.count(s[right])){
                seq.erase(s[left]);
                left++;
            }
            seq.insert(s[right]);
            
            maxlen = max(maxlen, right-left+1);
        }

        return maxlen;
    }
};
