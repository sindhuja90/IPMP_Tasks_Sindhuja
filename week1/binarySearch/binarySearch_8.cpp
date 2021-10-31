// solution 1
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0, h=arr.size()-1, m;
        while(l<=h) {
            m=(l+h)/2;
            if(arr[m]>arr[m-1] && arr[m]>arr[m+1])
                return m;
            else if(arr[m]<arr[m+1])
                l=m;
            else
                h=m;
        }
        return -1;
    }
};