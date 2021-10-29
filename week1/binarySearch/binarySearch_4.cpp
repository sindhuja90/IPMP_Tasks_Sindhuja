class Solution {
public:
    int findCeil(vector<int>& nums, int target, int f, int l) {
        if(target<=nums[f])
            return f;
        
        if(target==nums[l])
            return l;
        
        if(target>nums[l])
            return l+1;
        
        int mid=(f+l)/2;
        if(target==nums[mid])
            return mid;
        
        else if(target<nums[mid]) {
            if(target>nums[mid-1] && mid-1>=f)
                return mid;
            return findCeil(nums, target, f, mid-1);
        }
        
        else {
            if(target<nums[mid+1] && mid+1<=l)
                return mid+1;
            return findCeil(nums, target, mid+1, l);
        }
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return findCeil(nums, target, 0, nums.size()-1);
    }
};