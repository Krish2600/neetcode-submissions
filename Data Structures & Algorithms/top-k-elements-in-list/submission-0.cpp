class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<int> res;

        for(int num : nums){             // getting freq of all elements in count hash map
            count[num]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto& entry : count){
            pq.push({entry.second, entry.first});  // filling the max heap with (freq,number)
        }

        for(int i=0; i<k; i++){
            res.push_back(pq.top().second);        // getting the most freq element first k times
            pq.pop();
        }
       return res;
        
    }
};
