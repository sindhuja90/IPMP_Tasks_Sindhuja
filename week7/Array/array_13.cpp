// solution 1
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        for(int i=0; i<nums.size()-2; i++)
            for(int j=i+1; j<nums.size()-1; j++)
                for(int k=j+1; k<nums.size(); k++)
                    if(nums[i] < nums[j] && nums[j] < nums[k])
                        return true;
        
        return false;
    }
};

// solution 2
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int *smaller = new int[n], *greater = new int[n];
        int min = 0, max = n-1;
         
        smaller[0] = -1;
        for(int i=1; i<n; i++) {
            if(nums[i] <= nums[min]) {
                min = i;
                smaller[i] = -1;
            }
            
            else
                smaller[i] = min;
        }
        
        greater[n-1] = -1;
        for(int i=n-2; i>=0; i--) {
            if(nums[i] >= nums[max]) {
                max = i;
                greater[i] = -1;
            }
        
            else
                greater[i] = max;
        }
        
        for(int i=0; i<n; i++)
            if(smaller[i]!=-1 && greater[i]!=-1)
                return true;
        
        return false;
    }
};

// solution 3
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int min_num = nums[0], store_min = min_num, max_seq = INT_MAX;
        for(int i=1; i<n; i++) {
            if(nums[i] == min_num)
                continue;
            else if(nums[i] < min_num) {
                min_num = nums[i];
                continue;
            }
            else if(nums[i] < max_seq) {
                max_seq = nums[i];
                store_min = min_num;
            }
            else if(nums[i] > max_seq)
                return true;
        }
        
        return false;
    }
};