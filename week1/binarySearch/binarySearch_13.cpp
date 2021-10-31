// solution 1
class Solution {
public:
    int firstIndex(int a[], int n) 
    {
        if(a[0]==1)
            return 0;
        else if(a[n-1]==0)
            return -1;
        else {
            int l=0, h=n-1, m;
            while(l<=h) {
                m=(l+h)/2;
                if(a[m-1]==1)
                    h=m-1;
                else if(a[m]==1)
                    return m;
                else
                    l=m+1;
            }
        }
    }
};