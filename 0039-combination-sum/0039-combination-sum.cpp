class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& candis,vector<int>& sub,int i,int sum,int target){
        if(sum==target){
            res.push_back(sub);
            return;
        }
        if(i==candis.size() || sum>target){
            return;
        }

        sub.push_back(candis[i]);
        sum+=candis[i];
        helper(candis,sub,i,sum,target);
        sub.pop_back();
        sum-=candis[i];

        helper(candis,sub,i+1,sum,target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        helper(candidates,sub,0,0,target);

        return res;
    }
};