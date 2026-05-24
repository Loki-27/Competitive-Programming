class Solution {
private:
    bool check(vector<int>& nums,int k , long long maxsum){
        int cnt = 1;
        long long sum = nums[0];

        for(int i = 1; i< nums.size(); i++){
            if (sum+nums[i]>maxsum){
                cnt+=1;
                sum = nums[i];
            }
            else sum+=nums[i];
        }
        return (cnt <= k);
    }

public:
    int splitArray(vector<int>& nums, int k) {
        
        long long low = *max_element(nums.begin(),nums.end());
        long long high = accumulate(nums.begin(),nums.end(),0);
        int res = 0;
        while(low<=high){
            long long mid = low + (high- low)/2;

            if (check(nums,k,mid)){
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};