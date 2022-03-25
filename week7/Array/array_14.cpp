// solution 1
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> hash;
        for(int i=0; i<nums.size(); i++)
            hash.insert(nums[i]);
        for(int i=1; i<=nums.size()+1; i++)
            if(hash.find(i) == hash.end())
                return i;
        return -1;
    }
};

// solution 2
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=1;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] == ans)
                ans++;
        return ans;
    }
};