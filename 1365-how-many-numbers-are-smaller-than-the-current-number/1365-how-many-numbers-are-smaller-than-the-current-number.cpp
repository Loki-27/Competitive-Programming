class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int > sorted = nums;
        sort(sorted.begin(),sorted.end());

        unordered_map<int,int> tracker;

        for(int i =0;i<nums.size();i++){
            if (tracker.find(sorted[i])== tracker.end()){
                tracker[sorted[i]] = i;
            }
        }
        vector<int> ans(nums.size());

        for(int i =0;i<nums.size();i++){
            ans[i] = tracker[nums[i]];
        }
        return ans;
    }
};