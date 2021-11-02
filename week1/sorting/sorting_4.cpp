class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int output[nums.size()];
        int range=*max_element(nums.begin(), nums.end());
        
        int count[range+1];
        memset(count, 0, sizeof(count));
        
        for(auto i=nums.begin(); i!=nums.end(); i++)
	        count[*i]++;
        
        for(int i=1; i<=range; i++)
		    count[i]+=count[i-1];
        
        for(auto i=nums.begin(); i!=nums.end(); i++) {
		    output[count[*i]-1]=*i;
		    count[*i]--;
	    }

        nums.clear();
	    for(int i=0; i<nums.size(); i++)
		    nums.push_back(output[i]);
		
	    return nums;
    }
};