// solution 1
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t nbit=sizeof(n)*8;
        uint32_t rev=0, rem, i;
        for(i=0;i<nbit;i++) {
            rem=(n & (1<<i));
            if(rem)
                rev|=(1<<(nbit-i-1));
        }
        return rev;
    }
};

// solution 2
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t count=sizeof(n)*8-1;
        uint32_t rev=n;
        
        n>>=1;
        while(n) {
            rev<<=1;
            rev|=n&1;
            n>>=1;
            count--;
        }
        rev<<=count;
        
        return rev;
    }
};