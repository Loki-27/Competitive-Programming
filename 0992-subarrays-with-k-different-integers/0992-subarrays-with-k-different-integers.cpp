


class Solution {
private:
    int totalsubsuptok(vector<int>& nums, int k){
        if(k<=0) return 0;
        vector<int> freq(nums.size()+1,0);
        int currentk = 0;
        int l =0;
        int ans = 0;

        for(int r = 0;r<nums.size();r++){
            if(freq[nums[r]]==0){
                currentk++;
            }
            freq[nums[r]]++;

            while(currentk>k){
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    currentk--;
                }
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return totalsubsuptok(nums,k)-totalsubsuptok(nums,k-1);
    }
};