class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1 , zcount = 0;
        for(int num : nums){
            if(num != 0){
                prod *= num;
            } else{
                zcount++;
            }

        }

        if(zcount > 1){
            return vector<int>(nums.size(), 0);
        }

        vector<int> res(nums.size());

        for(int i=0; i<nums.size(); i++){

            if(zcount > 0){
                res[i] = (nums[i] == 0) ? prod : 0;
            } else{
                res[i] = prod/nums[i];
            }
        }

        return res;

    }
};
