class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xr = 0;
        int n = nums.size();
        for (int i = 0;i<n ;i++){
            xr = xr ^ nums[i];
            xr = xr ^(i+1);
        }

        int bit = xr & -xr;

        int a = 0, b = 0;

        for( int x:nums){
            if (x & bit)
                a^= x;
            else b^=x;
        }
        for (int x = 1; x <=n ;x++){
            if (x & bit)
                a^= x;
            else b^=x;
        }

        for (int x : nums){
            if (a == x) return {a,b};
        }

        return {b,a};
    }
};