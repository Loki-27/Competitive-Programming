class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool isneg = false;
        if(dividend<0 && divisor>0) isneg = true;
        if(dividend>0 && divisor<0) isneg = true;

        long n = abs(1L*dividend);
        long d = abs(1L*divisor);

        long q = 0;

        while(n>=d){
            int cnt = 0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            q += 1L<<cnt;
            n-= (d<<cnt);
        }

        if(q==(1L<<31) && !isneg) return INT_MAX;
        if(q==(1L<<31) && isneg) return INT_MIN;

        return isneg ? -q:q;
    }
};