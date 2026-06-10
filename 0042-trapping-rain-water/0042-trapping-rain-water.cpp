class Solution {
    private:
    vector<int> PGE(vector<int>&height){
        stack <int> st;
        vector <int> next(height.size(),-1);
        
        for(int i = 0 ; i < height.size() ; i++){
            while(!st.empty() && height[i]>height[st.top()]){
                st.pop();
            }
            next[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        for(auto x: next){
            cout<<x<< " ";
        }
        return next;
    }

public:
    int trap(vector<int>& height) {
        vector<int> pge = PGE(height);
        int n = height.size()-1;

        long long ans = 0;
        if (n<=1) return 0;
        // else{
        //     while(height[n-1]>=height[n]){
        //         n--;
        //     }
        // }

        int i = n-1;
        while(n>0 && i>0){
            while((height[i] < height[n] && pge[i]!=-1) && i>0){
                i = pge[i];
            }
            int max_wheight = min(height[i],height[n]);

            for(int x = i+1;x<n;x++){
                ans += max(0,(max_wheight-height[x]));
            }
            n = i;
            i--;
        }
        return ans;
    }
};


















