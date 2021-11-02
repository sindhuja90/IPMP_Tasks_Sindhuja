class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int j, key;
        int n=nums.size();
        
        int *arr=new int[n];
        for(int i=0; i<n; i++)
            arr[i]=nums[i];
        
        for(int i=1; i<n; i++) {
            j=i-1;
            key=arr[i];
            while(j>=0 && arr[j]>key) {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        
        vector<int> op;
        for(int i=0; i<n; i++)
            op.push_back(arr[i]);
        
        delete[] arr;
		
	    return op;
    }
};