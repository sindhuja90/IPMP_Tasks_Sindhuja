// solution 1
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0, h=n-1, m;
        if(n==1)
            return nums[0];
        while(l<=h) {
            m=(l+h)/2;
            if(nums[l]<nums[h] || l==h)
                return nums[l];
            else if(nums[m]>nums[h])
                l=m+1;
            else
                h=m;
        }
        return -1;
    }
};