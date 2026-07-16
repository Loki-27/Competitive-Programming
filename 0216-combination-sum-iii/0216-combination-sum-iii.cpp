class Solution {
public:
    vector<vector<int>> res; 
    void helper(vector<int>& sub,int i,int sum,int& k){
        if(sub.size()==k){
            if(sum==0){
                res.push_back(sub);
            }
            return;
        }

        for(int num = i;num<10;num++){
            sub.push_back(num);
            helper(sub,num+1,sum-num,k);
            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45) return res;
        vector<int> sub;

        helper(sub,1,n,k);

        return res;
        
    }
};