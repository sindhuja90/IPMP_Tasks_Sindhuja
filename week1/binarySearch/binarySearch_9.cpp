// solution 1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0, k=0;
        while(i<m && j<n) {
            if(nums1[k]<=nums2[j]) 
                i++;
            else {
                nums1.insert(nums1.begin()+k, nums2[j]);
                j++;
            }
            k++;
        }
        while(j<n) {
            nums1.insert(nums1.begin()+k, nums2[j]);
            j++;
            k++;
        }
        nums1.resize(m+n);
    }
};