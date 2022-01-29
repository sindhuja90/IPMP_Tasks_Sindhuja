// solution 1
#include <iostream>
#include <cmath>

using namespace std;

int posSetBit(int n) {
    if(n != pow(2, log2(n)))
        return -1;
    else
        return log2(n)+1;
}

int main()
{
    int n;
    cin>>n;
    cout<<posSetBit(n);

    return 0;
}
