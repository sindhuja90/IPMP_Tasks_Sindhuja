// solution 1
#include <iostream>
#include <cmath>

using namespace std;

int unsetRight(int n) {
    int pwr;
    int n1=n;
    while(n1) {
        pwr = log2(n1);
        n1 -= pow(2, pwr);
    }
    
    return n-pow(2, pwr);
}

int main() {
    int n;
    cin>>n;
    cout<<unsetRight(n);
    
    return 0;
}

// solution 2
#include <iostream>

using namespace std;

int unsetRight(int n) {
    return n & (n-1);
}

int main() {
    int n;
    cin>>n;
    cout<<unsetRight(n);
    
    return 0;
}