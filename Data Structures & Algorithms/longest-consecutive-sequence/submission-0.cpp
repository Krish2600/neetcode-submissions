class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        int current;
        int length;

        for(int num : nums){
            if(st.count(num-1) == 0){          // make sure that the starting number should not have any
                 current = num;             // predecessor number. only that should begin sequence
                 length = 1;
            }

            while(st.count(current + 1)){    // checks if there is a number one greater than current to 
                current++;                   // be included in the sequence
                length++;
            }

            longest = max(longest,length);
        }

        return longest;
    }
};
