class Solution {
public:
    int pivotSearch(vector<int>& nums, int target, int f, int l) {
        if(f>l)
            return -1;
        
        int m=(f+l)/2;
        if(nums[m]==target)
            return m;
        
        if(nums[f]<=nums[m]) {
            if(target>=nums[f] && target<=nums[m])
                return pivotSearch(nums, target, f, m-1);
            return pivotSearch(nums, target, m+1, l);
        }
        
        else {
            if(target>=nums[m] && target<=nums[l])
                return pivotSearch(nums, target, m+1, l);
            return pivotSearch(nums, target, f, m-1);
        }
    }
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return pivotSearch(nums, target, 0, n-1);
    }
};