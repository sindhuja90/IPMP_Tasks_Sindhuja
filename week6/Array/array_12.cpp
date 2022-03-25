// solution 1
class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int N) {
        // Your code here
        unordered_set<int> hash;
        vector<int> dup;
        for(int i=0; i<N+2; i++) {
            if(hash.find(arr[i]) == hash.end())
                hash.insert(arr[i]);
            else
                dup.push_back(arr[i]);
        }
        
        return dup;
    }
};

// solution 2
class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int N) {
        // Your code here
        vector<int> ans;
        int count[N+1];
        memset(count, 0, sizeof(count));
        for(int i=0; i<N+2; i++)
            count[arr[i]]++;
        for(int i=0; i<N+1; i++)
            if(count[i]>1)
                ans.push_back(i);
        
        return ans;
    }
};

// solution 3
class Solution {
  public:
    //Function to find two repeated elements.
    int fact(int n) {
        if(n==0 || n==1)
            return 1;
        else 
            return n*fact(n-1);
    }
    
    vector<int> twoRepeated (int arr[], int N) {
        // Your code here
        vector<int> ans;
        int sum=0, p=1, S=N*(N+1)/2, P=fact(N), a, b, c;
        for(int i=0; i<N+2; i++) {
            sum += arr[i];
            p *= arr[i];
        }
        a = sum-S;
        b = p/P;
        c = sqrt(pow(a, 2)-4*b);
        ans.push_back((a+c)/2);
        ans.push_back(a-ans[0]);
        
        return ans;
    }
};