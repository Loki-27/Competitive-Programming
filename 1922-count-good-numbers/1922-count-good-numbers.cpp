class Solution {
public:
    long long myPow(long long x, long long n) {
        long long ans = 1;
        long long nn = n;
        long long mod = 1e9+7;

        if(nn<0) nn = -1.0*nn;
        while(nn){
            if(nn%2){
                ans = (ans*x) % mod;
                nn--;
            }
            else{
                x = (x*x) % mod;
                nn/=2;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long e = 5;
        long long o = 4;

        long long n1 = 1LL*(n-1)/2 +1;
        long long n2 = 1LL*n/2;
        long long mod = 1e9+7;
        return (int)(myPow(e,n1)%mod * myPow(o,n2)%mod)%mod;
    }
};