#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(vector< pair<int, int> > a, int x, int low, int high) {    
    // mid, low and high represent indices after sorting
    while(low <= high) {
        int mid = (low + high)/2;

        if(x == a[mid].first)     // Element found at index mid 
            return a[mid].second + 1;

        else if(x < a[mid].first) // Element has value lower than that at mid
            high = mid - 1;

        else    // Element has value greater than that at mid
            low = mid + 1;
    }

    return -1;  // Element not found
}

int main() {
    int n;
    cout<<"Enter the number of elements in array: ";
    cin>>n;

    int *a = new int[n];
    vector< pair <int, int> > vp;
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++) {
        cin>>a[i];
        vp.push_back(make_pair(a[i], i));
    }
    sort(vp.begin(), vp.end());

    int x;
    cout<<"Enter element to be searched for: ";
    cin>>x;

    int pos = binarySearch(vp, x, 0, n-1);

    if(pos != -1)
        cout<<x<<" is found at position "<<pos;
    else
        cout<<x<<" is not found";

    free(a);

    return 0;
}