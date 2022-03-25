// solution 1
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
            if(i != nums[i])
                return i;
        return nums.size();
    }
};

// solution 2
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int s = accumulate(nums.begin(), nums.end(), 0);
        
        return sum-s;
    }
};

// solution 3
