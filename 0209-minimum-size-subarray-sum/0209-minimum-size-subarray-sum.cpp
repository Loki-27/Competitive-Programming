class Solution {

public:
    bool checker(vector<int>& nums,int tgt,int current_len){
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.begin()+current_len,0);
        if (n==current_len) return sum>=tgt ? true : false;

        for(int i=0;i+current_len<n;i++){
            if (sum >= tgt){
                return true;
            }
            else
                sum = sum -nums[i]+nums[i+current_len];
        }
        if (sum >= tgt) return true;
        return false;

    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int min_len = n;
        int low = 1;
        int high = n;
        while(low<=high){
            int current_len = low + (high-low)/2;
            
            if (checker(nums,target,current_len)){
                ans = current_len;
                high = current_len-1;

            }
            else low = current_len+1;
        }
        return ans;

    }
};