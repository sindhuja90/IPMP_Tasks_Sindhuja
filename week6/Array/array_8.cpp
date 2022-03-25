// solution 1
class Solution {
public:vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(auto i=nums.begin(); i!=nums.end(); i++) {
                vector<int>::iterator it = find(nums.begin(), nums.end(), target - *i);
                if(it != nums.end() && i!= it) {
                    ans.push_back(i - nums.begin());
                    ans.push_back(it - nums.begin());
                    break;
                }
            }
        
        return ans;
    }
};

// solution 2
class Solution {
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
    
    public:vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int, int>> nums1;
        for(int i=0; i<nums.size(); i++)
            nums1.push_back(make_pair(nums[i], i));
        sort(nums1.begin(), nums1.end(), cmp); 
    
        int l=0, r=nums1.size()-1, sum;
        while(l<r) {
            sum = nums1[l].first + nums1[r].first;
            if(sum == target) {
                ans.push_back(nums1[l].second);
                ans.push_back(nums1[r].second);
                break;
            }
            
            else if(sum < target)
                l++;
            
            else
                r--;
        }
        
        return ans;
    }
};