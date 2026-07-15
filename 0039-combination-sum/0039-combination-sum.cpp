class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& candis,vector<int>& sub,int i,int sum,int target){
        if(sum==target){
            res.push_back(sub);
            return;
        }
        if(sum>target){
            return;
        }

        for(int index = i;index<candis.size();index++){
            sub.push_back(candis[index]);
            helper(candis,sub,index,sum+candis[index],target);
            sub.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        helper(candidates,sub,0,0,target);

        return res;
    }
};