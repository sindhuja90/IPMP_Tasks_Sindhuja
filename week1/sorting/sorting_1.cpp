class Solution {
public:
    void merge(vector<int>& nums, int const left, int const mid, int const right) {
        const int size1=mid-left+1;
        const int size2=right-left;
        
        int *larray=new int[size1];
        int *rarray=new int[size2];
        
        for(int i=0; i<size1; i++)
            larray[i]=nums[left+i];
        for(int i=0; i<size2; i++)
            rarray[i]=nums[mid+1+i];
        
        int i=0, j=0, k=left;
        while(i<size1 && j<size2) {
            if(larray[i]<=rarray[j]) 
                nums[k++]=larray[i++];
            else
                nums[k++]=rarray[j++];
        }
        while(i<size1)
            nums[k++]=larray[i++];
        while(j<size2)
            nums[k++]=rarray[j++];
        
        delete[] larray;
        delete[] rarray;
        
        return;
    }
    
    void mergeSort(vector<int>& nums, int const begin, int const end) {
        if(begin>=end)
            return;
        
        int mid=(begin+end)/2;
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, begin, mid, end);
        
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};