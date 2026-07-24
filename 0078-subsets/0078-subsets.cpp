class Solution {
public:
    // vector<vector<int>> res;
    // void genrate(vector<int>& subs,int i,vector<int>& nums){
    //     if(i==nums.size()){
    //         res.push_back(subs);
    //         return;
    //     }

    //     genrate(subs,i+1,nums);

    //     subs.push_back(nums[i]);
    //     genrate(subs,i+1,nums);
    //     subs.pop_back();
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<int> subs;
        // genrate(subs,0,nums);

        // return res;

        int n = nums.size();
        vector<vector<int>> res;

        int totalsubsets = (1<<n);
        for(int snum = 0;snum<totalsubsets;snum++){
            vector<int> sub;
            for(int i = 0;i<n;i++){

                if(snum&(1<<i)) sub.push_back(nums[i]);
            }
            res.push_back(sub);
        }        
        return res;
    }
};