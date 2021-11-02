class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r) {
        int n1=m-l+1, n2=r-l;
        
        int *larray=new int[n1];
        int *rarray=new int[n2];
        
        for(int i=0; i<n1; i++)
            larray[i]=nums[l+i];
        for(int i=0; i<n2; i++)
            rarray[i]=nums[m+1+i];
        
        int i=0, j=0, k=l;
        while(i<n1 && j<n2) {
            if(larray[i]<=rarray[j]) 
                nums[k++]=larray[i++];
            else
                nums[k++]=rarray[j++];
        }
        while(i<n1)
            nums[k++]=larray[i++];
        while(j<n2)
            nums[k++]=rarray[j++];
        
        return;
    }
    
    void mergeSort(vector<int>& nums, int const begin, int const end) {
        int n=nums.size();
        for(int c=0; c<n; c*=2)
            for(int l=0; l<n-1; l+=c*2) {
                int mid=min(l+c-1, n-1);
                int r=min(l+c*2-1, n-1);
                merge(nums, l, mid, r);
            }
        
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};