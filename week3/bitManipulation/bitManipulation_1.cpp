// solution 1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long int n1=n;
        return (n1 && !(n1 & (n1-1)));
    }
};

// solution 2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n && (ceil(log2(n)) == floor(log2(n))));
    }
};

// solution 3
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        else {
            while(n%2==0)
                n/=2;
            return n==1;
        }
    }
};

// solution 4
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
            return true;
        else if(n%2!=0 || n==0)
            return false;
        return isPowerOfTwo(n/2);       
    }
};

// solution 5
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        else {
            long long int n1=n;
            return ((n1 & ~(n1-1))==n1);
        }
    }
};