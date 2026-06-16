class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxones = 0;
        
        int i=0,j=0;

        while(j<n){
            if(nums[j]==1){
                maxones = max(maxones,j-i+1);
                j++;
            }
            else if(nums[j]==0){
                if(k>0){
                    maxones = max(maxones,j-i+1);
                    j++;
                    k--;
                }
                else{
                    if(nums[i]==0){
                        i++;
                        k++;
                    }
                    else{
                        while(nums[i]==1 && i<j){
                            i++;
                        }
                    }
                }
            }
        }
        return maxones;
    }
};