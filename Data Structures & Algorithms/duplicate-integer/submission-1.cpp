class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num : nums){
            if(seen.count(num)){  // check if num exists in the set seen
                return true;
            }
            seen.insert(num);    // if not then add it to the set
        }
        return false;  
    }
};