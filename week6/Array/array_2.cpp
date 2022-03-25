// solution 1
class Solution{
    public:
    int findSingle(int N, int arr[]){
        // code here
        multiset<int> count;
        for(int i=0; i<N; i++)
            count.insert(arr[i]);
        for(int i=0; i<N; i++)
            if(count.count(arr[i])%2 != 0)
                return arr[i];
    }
};

// solution 2
class Solution{
    public:
    int findSingle(int N, int arr[]){
        // code here
        unordered_map<int, int> hash;
        for(int i=0; i<N; i++)
            hash[arr[i]]++;
        for(auto i : hash)
            if(i.second%2 != 0)
                return i.first;
    }
};

// solution 3
class Solution{
    public:
    int findSingle(int N, int arr[]){
        // code here
        int ans = 0;
        for(int i=0; i<N; i++)
            ans ^= arr[i];
        return ans;
    }
};