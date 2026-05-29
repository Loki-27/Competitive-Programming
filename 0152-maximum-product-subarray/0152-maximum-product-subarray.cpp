class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int firstneg = -1;
        int lastneg = -1;
        int segment_start = 0; 

        int ans = INT_MIN;
        
        // Use long long to handle potential intermediate overflow safely before clamping to int
        vector<long long> pfx(n + 1, 1); 

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans = max(ans, 0); 
                
                // Evaluate the segment that just ended before the zero
                if (i > segment_start) {
                    long long segment_prod = pfx[i];
                    if (segment_prod > 0) {
                        ans = max(ans, (int)segment_prod);
                    } else if (firstneg != -1) {
                        // If total product is negative, the max positive product 
                        // could be found by dropping everything up to the first negative.
                        if (firstneg + 1 < i) {
                            ans = max(ans, (int)(segment_prod / pfx[firstneg + 1]));
                        }
                    }
                }

                // Reset trackers for the next segment
                firstneg = -1;
                lastneg = -1;
                segment_start = i + 1;
                pfx[i + 1] = 1; 
            } 
            else {
                pfx[i + 1] = pfx[i] * nums[i];
                ans = max(ans, (int)pfx[i + 1]); 

                if (nums[i] < 0) {
                    if (firstneg == -1) {
                        firstneg = i;
                    }
                    lastneg = i;
                }
            }
        }

        // Handle the final segment if the array didn't end in 0
        if (n > segment_start) {
            long long segment_prod = pfx[n];
            if (segment_prod > 0) {
                ans = max(ans, (int)segment_prod);
            } else if (firstneg != -1) {
                // Drop everything up to the first negative if there are elements remaining
                if (firstneg + 1 < n) {
                    ans = max(ans, (int)(segment_prod / pfx[firstneg + 1]));
                }
            }
        }

        return ans;
    }
};