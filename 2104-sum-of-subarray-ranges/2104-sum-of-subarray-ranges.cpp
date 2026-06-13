class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        //* solution can be also done using PSEE,NSE for minsum and NGE and PGEE for maxsum. and then maxsum-minsum
        // ans = sum(max_k-min_k)
        // ==> ans = sum(max_k)-sum(min_k);
        //  1<=k<=N where N = number of subarrays=n(n+1)/2 
        int n=nums.size();
        vector<int> st;
        vector<long long> dp(n);
        long long ans = 0;

        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.back()] > nums[i]){
                st.pop_back();
            }
            st.push_back(i);

            if(st.size()==1){
                dp[i] = 1LL*nums[i]*(i+1);
            }
            else{
                int pre_val = st[st.size()-2];
                dp[i] = 1LL*nums[i]*(i-pre_val) + dp[pre_val];
            }
            ans = ans - dp[i];
        }

        while(!st.empty()){
            st.pop_back();
        }
        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.back()] < nums[i]){
                st.pop_back();
            }
            st.push_back(i);

            if(st.size()==1){
                dp[i] = 1LL*nums[i]*(i+1);
            }
            else{
                int pre_val = st[st.size()-2];
                dp[i] = 1LL*nums[i]*(i-pre_val) + dp[pre_val];
            }
            ans = ans + dp[i];
        }
    return ans;
    }
};