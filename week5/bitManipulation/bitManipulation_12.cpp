// solution 1
class Solution{
public:
    int swapNibbles(unsigned char x){
        // code here
        return (((x&240)>>4) | ((x&15)<<4));
    }
};