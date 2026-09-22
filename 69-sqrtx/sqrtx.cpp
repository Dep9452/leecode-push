class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        long long l=1,r=x,ans=1;
        while(l<=r){
            long long m=(l+r)/2;
            if(m*m<=x){
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};