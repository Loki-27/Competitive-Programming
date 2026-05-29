class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int pfx =1;
        int sfx = 1;

        int max_pro = INT_MIN;
        for ( int i = 0; i<n ;i++){
            
            if (pfx==0) pfx = 1 ;
            if (sfx == 0) sfx =1;

            pfx *= nums[i];
            sfx *= nums[n-1-i];
            
            max_pro = max(max_pro,max(pfx,sfx)); 
        }
        return max_pro;
    }
};