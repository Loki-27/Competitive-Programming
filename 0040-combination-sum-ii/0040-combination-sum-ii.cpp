class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& candis,vector<int>& sub,int i,int sum,int target){
        if(sum==target){
            res.push_back(sub);
            return;
        }

        for(int index = i;index<candis.size();index++){
            if(index>i && candis[index]==candis[index-1]) continue;
            if(sum>target) break;
            sub.push_back(candis[index]);
            helper(candis,sub,index+1,sum+candis[index],target);
            sub.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sub;
        sort(candidates.begin(),candidates.end());
        helper(candidates,sub,0,0,target);

        return res;
    }
};