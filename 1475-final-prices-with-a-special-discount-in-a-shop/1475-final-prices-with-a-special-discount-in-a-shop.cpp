class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;

        vector<int> ans(prices.size());
        for(int x= prices.size()-1;x>=0;x--){
            while(!st.empty() && prices[x] < st.top()){
                st.pop();
            }
            int discount = (st.empty()) ? 0 : st.top();
            st.push(prices[x]);
            ans[x] = prices[x]-discount;
        }
        return ans;
    }
};