class Solution {
    private:
    int totalodd(vector<int>& nums, int k){
        if(k<0) return 0;
        int n = nums.size();
        int subs = 0;
        int cnt = 0;
        int r=0,l=0;

        while(r<n){
            if(nums[r]%2!=0) cnt++;

            while(cnt>k){
                if(nums[l]%2!=0) cnt--;
                l++;
            }

            subs += r-l+1;
            r++;
        }
        return subs;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return totalodd(nums,k)-totalodd(nums,k-1);
    }
};