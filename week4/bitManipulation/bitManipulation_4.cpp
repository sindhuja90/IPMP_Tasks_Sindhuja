// solution 1
class Solution{
    public:
    int hammingWeight(int n) {
        int count=0;
        while(n) {
            count+=n&1;
            n>>=1;
        }
        
        return count;
    }
    
    int countBitsFlip(int a, int b){
        return hammingWeight(a^b);
    }
};

// solution 2
class Solution{
    public:
    int hammingWeight(int n) {
        int count=0;
        while(n) {
            n&=(n-1);
            count++;
        }
        
        return count;
    }
    
    int countBitsFlip(int a, int b){
        return hammingWeight(a^b);
    }
};