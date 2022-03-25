// solution 1
class Solution{
    public:
    vector<int> twoOddNum(int Arr[], int N)  
    {
        // code here
        unordered_map<int, int> count;
        vector<int> ans;
        for(int i=0; i<N; i++)
            count[Arr[i]]++;
        for(auto i:count)
            if(i.second %2 != 0)
                ans.push_back(i.first);
        sort(ans.begin(), ans.end(), greater<int>());
        
        return ans;
    }
};

