class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;

        long long x=0;
        // int 
        int sum =0;
        int factor = 1;
        while(n>0){
            if(n%10!=0){
                x += factor*(n%10);
                sum+=n%10;
                factor*=10;
            }
            n /=10;
        }
        return x*sum;

    }
};