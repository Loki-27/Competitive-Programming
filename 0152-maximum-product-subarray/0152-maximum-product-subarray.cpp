class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_prod = INT_MIN;
        
        int prefix = 1;
        int suffix = 1;
        
        for (int i = 0; i < n; i++) {
            // If previous product became 0, reset it to 1
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
            
            prefix *= nums[i];       // Moving left-to-right
            suffix *= nums[n - 1 - i]; // Moving right-to-left
            
            max_prod = max(max_prod, max(prefix, suffix));
        }
        
        return max_prod;
    }
};