// solution 1
int Solution::findCount(const vector<int> &A, int B) {
    int n=A.size();
    int f=0, l=n-1, p1=0, p2=0;
    bool flag=false;
    while(f<=l) {
        int m=(f+l)/2;
        if(A[m]==B) {
            p1=p2=m;
            while(A[--p1]==B && p1>=0);
            p1++;
            while(A[++p2]==B && p2<=n-1);
            p2--;
            flag=true;
            break;
        }
        else if(B<A[m])
            l=m-1;
        else
            f=m+1;
    }
    if(flag)
        return p2-p1+1;
    else
        return 0;
}

// solution 2
int Solution::findCount(const vector<int> &A, int B) {
    auto l=lower_bound(A.begin(), A.end(), B);
    auto u=upper_bound(A.begin(), A.end(), B);

    if(*l!=B || l==A.end())
        return 0;
    else
        return u-l;
}
