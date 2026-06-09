class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int> s;
        vector<int> ans(nums.size(),0);
        for (int i = nums.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            ans[i] = (s.empty())? INT_MIN : s.top();
            s.push(nums[i]);
        }
        for (int i = nums.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            if (ans[i]==INT_MIN)
                ans[i] = (s.empty())? -1 : s.top();
        }
        return ans;
    }
};