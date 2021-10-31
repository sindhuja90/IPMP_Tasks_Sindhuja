// solution 1
class Solution{
public:

	vector<int> valueEqualToIndex(int arr[], int n) {
	    vector<int> ans;
	    for(int i=0;i<n;i++)
	        if(arr[i]==i+1)
	            ans.push_back(i+1);
	    
	    return ans;
	}
};

// solution 2
class Solution{
public:
    vector<int> valueEqualToIndex(int arr[], int n) {
	    int f=0, l=n-1, m;
	    vector<int> ans;
	    while(f<=l) {
	        m=(f+l)/2;
	        if(arr[m]==m+1)
	            ans.push_back(m+1);
	        else if(arr[m]<m+1)
	            f=m+1;
	        else
	            l=m-1;
	    }
	    
	    return ans;
	}
};