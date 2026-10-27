class Solution {
public:
    int findMin(vector<int> &nums) {
        int minelement = INT_MAX;

        for(int num : nums){
          int  minnum = min(minelement, num);
          minelement = minnum;
        }

        return minelement;
        
    }
};
