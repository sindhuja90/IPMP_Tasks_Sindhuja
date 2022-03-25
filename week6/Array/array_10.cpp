// solution 1
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
                for(int k=j+1; k<n; k++)
                    if(A[i]+A[j]+A[k]==X)
                        return true;
                    
        return false;
    }

};

// solution 2
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A+n);
        for(int i=0; i<n-1; i++) {
            int y = X - A[i];
            int l = i+1, r = n-1;
            while(l<r) {
                int sum = A[l] + A[r];
                if(sum == y)
                    return true;
                else if(sum > y)
                    r--;
                else
                    l++;
            }
        }
        
        return false;
    }

};

// solution 3
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        for(int i=0; i<n-1; i++) {
            unordered_set<int> hash;
            int y = X - A[i];
            for(int j=i+1; j<n; j++) {
                if(hash.find(y-A[j]) != hash.end())
                    return true;
                hash.insert(A[j]);
            }
        }
        
        return false;
    }

};