// solution 1
class Solution {
public:
    int nextGreaterElement(int n) {
        long long int c=0;
        int n1=n;
        while(n1) {
            n1/=10;
            c++;
        }
        long long int *num = new long long int[c];
        n1=n;
        for(int i=c-1; i>=0; i--) {
            num[i]=n1%10;
            n1/=10;
        }
        next_permutation(num, num+c);
        long long int ans=0;
        for(long long int i=0; i<c; i++) {
            ans = ans*10 + num[i];
            if(ans > INT_MAX)
                return -1;
        }
        
        if(ans<=n)
            return -1;
        else
            return ans;
    }
};

// solution 2
class Solution {
public:
    int nextGreaterElement(int n) {
        long long int c=0;
        int n1=n;
        while(n1) {
            n1/=10;
            c++;
        }
        
        long long int *num = new long long int[c];
        n1=n;
        for(int i=c-1; i>=0; i--) {
            num[i]=n1%10;
            n1/=10;
        }
        
        for(long long int i=c-2; i>=0; i--) 
            if(num[i]<num[i+1]) {
                int smallBig = INT_MAX, pos;
                for(long long int j=i+1; j<c; j++) 
                    if(num[j]>num[i] && num[j]<smallBig) {
                        pos=j;
                        smallBig = num[j];
                    }
                for(long long int k=pos; k>i; k--)
                    num[k]=num[k-1];
                num[i]=smallBig;
                sort(num+i+1, num+c);
                break;
            }
        
        long long int ans=0;
        for(long long int i=0; i<c; i++) {
            ans = ans*10 + num[i];
            if(ans > INT_MAX)
                return -1;
        }
        
        if(ans<=n)
            return -1;
        else
            return ans;
    }
};