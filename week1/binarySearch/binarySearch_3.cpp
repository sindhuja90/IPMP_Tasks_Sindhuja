// solution 1
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

// solution 2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

// solution 3
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), val, l;
        if(n%2==0)
            l=n/2;
        else
            l=n/2 +1;
        
        for(int i=0; i<l; i++) 
            if(nums[i] == nums[i+ n/2])
                val=nums[i];
        
        return val;
    }
};
