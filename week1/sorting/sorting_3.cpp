class Solution {
public:
    int partition(vector<int>& nums, int l, int h) {
        int pivot=nums[h];
        int i=l-1;
        for(int j=l; j<h; j++) 
            if(nums[j]<pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        swap(nums[i+1], nums[h]);
        
        return i+1;
    }
    
    void quickSort(vector<int>& nums, int l, int h) {
        if(l<h) {
            int pi=partition(nums, l, h);
            quickSort(nums, l, pi-1);
            quickSort(nums, pi+1, h);
        }
        
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        
        return nums;
    }
};