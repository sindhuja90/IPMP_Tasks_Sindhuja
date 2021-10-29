class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto i=nums.begin(); i!=nums.end(); i++)
            freq[*i]++;
        int n=nums.size(), val;
        for(auto i=freq.begin(); i!=freq.end(); i++)
            if(i->second > floor(n/2))
                val=i->first;
        return val;
    }
};