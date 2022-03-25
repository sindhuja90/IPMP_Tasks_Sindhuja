// solution 1
#include <iostream>

using namespace std;

int pythagoreanTriple(int n) {
    int ans = 0;
    for(int i=1; i<=n-2; i++)
        for(int j=i+1; j<=n-1; j++)
            for(int k=j+1; k<=n; k++)
                if(i*i+j*j == k*k)
                    ans++;
    
    return ans;
}

int main() {
    int n, ans;
    cin>>n;
    ans = pythagoreanTriple(n);
    cout<<ans;
    
    return 0;
}

// solution 2
#include <iostream>
#include <cmath>

using namespace std;

int pythagoreanTriple(int n) {
    int ans = 0;
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++) {
            int x = i*i + j*j;
            int y = sqrt(x);
            
            if(y*y==x && y<=n)
                ans++;
        }
    
    return ans;
}

int main() {
    int n, ans;
    cin>>n;
    ans = pythagoreanTriple(n);
    cout<<ans;
    
    return 0;
}

// solution 3
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int pythagoreanTriple(int n) {
    int ans = 0;
    vector<int> perfectSq;
    for(int i=1; i<=n; i++)
        perfectSq.push_back(i*i);
    for(int i=1; i<=n; i++)
        for(int j=0; j<perfectSq.size(); j++) {
            int k = perfectSq[j] - i*i;
            int x = sqrt(k);
            if(x*x==k && i<=x && x<=j)
                ans++;
        }
        
    return ans;
}

int main() {
    int n, ans;
    cin>>n;
    ans = pythagoreanTriple(n);
    cout<<ans;
    
    return 0;
}