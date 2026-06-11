class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;

        vector<int> ans(temperatures.size());
        for(int x= temperatures.size()-1;x>=0;x--){
            while(!st.empty() && temperatures[x] >= temperatures[st.top()]){
                st.pop();
            }
            int temp = (st.empty()) ? 0 : temperatures[st.top()];
            if (temp>temperatures[x]) ans[x] = st.top()-x;
            else ans[x]=0;
            st.push(x);
        }
        return ans;
    }
};