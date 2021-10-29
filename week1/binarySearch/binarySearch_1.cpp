// solution 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int f=0, l=nums.size()-1;
        while(f<=l) {
            int m=(f+l)/2;
            if(nums[m]==target)
                return m;
            else if(target<nums[m])
                l=m-1;
            else
                f=m+1;
        }
        return -1;
    }
};

// solution 2
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++)
            if(nums[i] == target)
                return i;
        return -1;
    }
};