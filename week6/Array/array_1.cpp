// Union of two arrays
// solution 1
class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_set<int> hash;
        int ans = 0;
        for(int i=0; i<n; i++)
            if(hash.find(a[i]) == hash.end()) {
                ans++;
                hash.insert(a[i]);
            }
        for(int i=0; i<m; i++)
            if(hash.find(b[i]) == hash.end()) {
                ans++;
                hash.insert(b[i]);
            }
        return ans;
    }
};

// Intersection of two arrays
// solution 1
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> hash1, hash2;
        vector<int> nums3;
        for(int i=0; i<nums1.size(); i++)
            hash1.insert(nums1[i]);
        for(int i=0; i<nums2.size(); i++)
            hash2.insert(nums2[i]);
        for(auto i=hash1.begin(); i!=hash1.end(); i++)
            if(hash2.find(*i) != hash2.end())
                nums3.push_back(*i);
        
        return nums3;
    }
};


