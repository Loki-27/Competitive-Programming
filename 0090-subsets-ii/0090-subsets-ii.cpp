class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>&nums,vector<int>&sub,int i){
        res.push_back(sub);

        for(int idx = i;idx<nums.size();idx++){
            if(idx>i && nums[idx]==nums[idx-1]) continue;
            sub.push_back(nums[idx]);
            helper(nums,sub,idx+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        sort(nums.begin(),nums.end());
        helper(nums,sub,0);
        return res;

    }
};