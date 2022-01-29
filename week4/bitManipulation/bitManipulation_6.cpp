// solution 1
#include <iostream>

using namespace std;

int getAbs(int n) {
    int mask = n>>(sizeof(int)*8 - 1);
    return ((n+mask)^mask);
}

int main() {
    int n;
    cin>>n;
    cout<<getAbs(n);
    
    return 0;
}

// solution 2
#include <iostream>

using namespace std;

int getAbs(int n) {
    int mask = n>>(sizeof(int)*8 - 1);
    return ((n^mask)-mask);
}

int main() {
    int n;
    cin>>n;
    cout<<getAbs(n);
    
    return 0;
}