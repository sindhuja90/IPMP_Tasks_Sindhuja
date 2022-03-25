// solution 1
#include <iostream>

using namespace std;

bool checkPalindrome(long long int n) {
    long long int n1=n, rem, rev=0, ans;
    while(n1) {
        rem=n1%10;
        n1/=10;
        rev=rev*10+rem;
    } 
    
    return n==rev;
}

int nextSmallPalindrome(long long int n) {
    long long int ans=n+1;
    while(!checkPalindrome(ans))
        ans++;
    
    return ans;
}

int main() {
    long long int n, ans;
    cin>>n;
    ans=nextSmallPalindrome(n);
    cout<<ans;
    
    return 0;
}

// solution 2
#include <iostream>

using namespace std;

typedef long long int ll;

bool areAllNine(ll num) {
    ll num1=num, rem;
    while(num1) {
        rem=num1%10;
        if(rem != 9)
            return false;
        num1/=10;
    }
    
    return true;
}

void nextSmallPalindrome(ll num) {
    ll n=0, num1=num;
    while(num1) {
        n++;
        num1/=10;
    }
    
    
    if(areAllNine(num)) {   // case 1: num has all 9s
        cout<<'1';
        for(int i=0; i<n; i++)
            cout<<'0';
        cout<<'1';
    }
    
    else {
        int *ans = new int[n], num2=num, rem;
        for(int k=n-1; k>=0; k--) {
            rem=num2%10;
            ans[k]=rem;
            num2/=10;
        }
        
        int i=n/2 -1, j;
        if(n%2==0) 
            j=n/2;
        else 
            j=n/2 +1;
        
        while(ans[i]==ans[j] && i>=0 && j<=n-1) {
            i--;
            j++;
        }
        
        if(i==-1 && j==n) {     // case 2: num is a palindrome
            int k, l;
            ll carry=0;
            if(n%2!=0) {
                carry = (ans[n/2]+1)/10;
                ans[n/2] = (ans[n/2]+1)%10;
                k=n/2 -1;
            }
            else {
                carry = (ans[n/2]+1)/10;
                ans[n/2 -1] = ans[n/2] = (ans[n/2]+1)%10;
                k=n/2 -2;
            }
            for(l=n/2 +1; k>=0 && l<=n-1; k--, l++) {
                ans[k] = ans[l] = (ans[k]+carry)%10;
                carry = ans[k]/10;
            }
            if(carry) {
                cout<<carry;
                for(int m=0; m<n; m++)
                    cout<<ans[m];
                cout<<carry;
            }
            else
                for(int m=0; m<n; m++)
                    cout<<ans[m];
        }
        
        else {
            // case 3.1: left digit is greater than right digit
            if(ans[i]>ans[j]) {
                for(int k=j, l=i; k<n && l>=0; k++, l--)
                    ans[k]=ans[l];
                for(int k=0; k<n; k++)
                    cout<<ans[k];
            }
            
            // case 3.2: left digit is lesser than right digit
            else {
                for(int k=j, l=i; k<n && l>=0; k++, l--)
                    ans[k]=ans[l];
                    
                int k, l;
                ll carry=0;
                if(n%2!=0) {
                    carry = (ans[n/2]+1)/10;
                    ans[n/2] = (ans[n/2]+1)%10;
                    k=n/2 -1;
                }
                else {
                    carry = (ans[n/2]+1)/10;
                    ans[n/2 -1] = ans[n/2] = (ans[n/2]+1)%10;
                    k=n/2 -2;
                }
                for(l=n/2 +1; k>=0 && l<=n-1; k--, l++) {
                    ans[k] = ans[l] = (ans[k]+carry)%10;
                    carry = ans[k]/10;
                }
                if(carry) {
                    cout<<carry;
                    for(int m=0; m<n; m++)
                        cout<<ans[m];
                    cout<<carry;
                }
                else
                    for(int m=0; m<n; m++)
                        cout<<ans[m];
            }
        }
    }
    
    return;
}

int main() {
    ll num, ans;
    cin>>num;
    nextSmallPalindrome(num);
    
    return 0;
}