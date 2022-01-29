// solution 1
class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
    	unsigned int even = n & 0xAAAAAAAA;
    	unsigned int odd = n & 0x55555555;
    	even >>= 1;
    	odd <<= 1;
    	return even | odd;
    }
};