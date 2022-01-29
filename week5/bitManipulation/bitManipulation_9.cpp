// solution 1
class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        if(!n)
            return 0;
        
        else {
            int pwr;
            while(n) {
                pwr=log2(n);
                n-=pow(2, pwr);
            }
        
            return pwr+1;
        }
    }
};

// solution 2
class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        return log2(n&(~(n-1)))+1;
    }
};