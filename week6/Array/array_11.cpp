// solution 1
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-3; i++)
            for(int j=i+1; j<nums.size()-2; j++) {
                int x = target - nums[i] - nums[j];
                int l = j+1, r = nums.size()-1;
                while(l<r) {
                    int sum = nums[l] + nums[r];
                    if(sum == x) {
                        vector<int> op;
                        op.push_back(nums[i]);
                        op.push_back(nums[j]);
                        op.push_back(nums[l]);
                        op.push_back(nums[r]);
                        ans.push_back(op);
                    }
                    else if(sum > x)
                        r--;
                    else 
                        l++;
                }
            }
        
        return ans;
    }
};

// solution 2
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    
    bool noCommon(vector<int> a, vector<int> b) {
        if(a[1] == b[1] || a[1] == b[2] || a[2] == b[1] || a[2] == b[2])
            return false;
        return true;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<vector<int>> pairSum;
        for(int i=0; i<nums.size()-1; i++) 
            for(int j=i+1; j<nums.size(); j++) {
                vector<int> el;
                int sum = nums[i] + nums[j];
                el.push_back(sum);
                el.push_back(i);
                el.push_back(j);
                pairSum.push_back(el);
            }
        
        sort(pairSum.begin(), pairSum.end(), cmp);
        
        int n = nums.size();
        int size = n*(n-1)/2;
        int l = 0, r = size-1;
        while(l<size && r>=0) {
            int x = pairSum[l][0] + pairSum[r][0];
            if(x == target && noCommon(pairSum[l], pairSum[r])) {
                vector<int> y;
                y.push_back(nums[pairSum[l][1]]);
                y.push_back(nums[pairSum[l][2]]);
                y.push_back(nums[pairSum[r][1]]);
                y.push_back(nums[pairSum[r][2]]);
                ans.push_back(y);
            }
            else if(x < target)
                l++;
            else
                r--;
        }
        
        return ans;
    }
};
