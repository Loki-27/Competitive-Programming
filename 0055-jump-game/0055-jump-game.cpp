class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;

        if(nums[0]==0) return false;

        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j<n){
            if(j==n-1) return true;
            if(nums[j]==0){
                // int k = j;
                int t = j-1;
                while(j<n && nums[j]==0){
                    j++;
                }
                while(t>=0){
                    if(n-1 <= nums[t]+t){
                        return true;
                    }
                    if(j <= nums[t]+t){
                        if(n-1 <= nums[t]+t){
                            return true;
                        }
                        break;
                    }
                    t--;
                    if(t<0) return false;
                }
            }
            else{
                j++;
            }
        }
        return false;
    }
};