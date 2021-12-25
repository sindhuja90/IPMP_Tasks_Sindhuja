// solution 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n) {
            count+=n&1;
            n>>=1;
        }
        
        return count;
    }
};

// solution 2
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n) {
            n &= (n-1);
            count++;
        }
        
        return count;
    }
};

// solution 3
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n==0)
            return 0;
        return 1 + hammingWeight(n & (n-1));
    }
};