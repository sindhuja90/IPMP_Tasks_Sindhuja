class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int pos1=0, pos2=n-1, min, max;
        
        for(pos1=0; pos1<n-1; pos1++)
            if(nums[pos1]>nums[pos1+1])
                break;
        if(pos1==n-1)
            return 0;
        
        for(pos2=n-1; pos2>0; pos2--)
            if(nums[pos2]<nums[pos2-1])
                break;
        
        min=*min_element(nums.begin()+pos1, nums.begin()+pos2+1);
        max=*max_element(nums.begin()+pos1, nums.begin()+pos2+1);
        
        for(int i=0; i<pos1; i++)
            if(nums[i]>min) {
                pos1=i;
                break;
            }
        for(int i=n-1; i>pos2; i--)
            if(nums[i]<max) {
                pos2=i;
                break;
            }
        
        return pos2-pos1+1;
    }
};