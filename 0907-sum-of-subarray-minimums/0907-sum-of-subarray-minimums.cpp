class Solution {
    private :
        vector<int> NSE(vector<int>&nums){
            stack<int> st;
            vector<int> next(nums.size());
            int n = nums.size();


            for(int i = nums.size()-1;i>=0;i--){
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    st.pop();
                } 
                next[i] = (st.empty()) ? n : st.top();
                st.push(i);
            }
            return next;
        }
        vector<int>PSEE(vector<int>&arr){
            stack<int> st;
            vector<int> next(arr.size());
            int n = arr.size();

            for(int i = 0;i<n;i++){
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                } 
                next[i] = (st.empty()) ? -1 : st.top();
                st.push(i);
            }
            return next;
        }

public:

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = NSE(arr);
        vector<int> psee = PSEE(arr);

        long long modu = 1e9+7; 
        long long ans=0;
        int n= arr.size();
        for(int i = 0; i<n;i++){
            ans = (ans+ 1LL*(nse[i]-i)*(i-psee[i])*arr[i])%modu;
        } 

        return ans;
    }

};