// solution 1
int Solution::addNumbers(int a, int b) {
    while(b) {
        int carry=a&b;
        a=a^b;
        b=carry<<1;
    }

    return a;
}

// solution 2
int Solution::addNumbers(int a, int b) {
    int sum=a;
    for(int i=0; i<b; i++)
        sum++;

    return sum;
}

// solution 3
int Solution::addNumbers(int a, int b) {
    if(b==0)
        return a;
    else
        return addNumbers(a^b, (a&b)<<1);
}
