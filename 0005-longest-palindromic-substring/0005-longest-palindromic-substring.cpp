class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool> (n) );

        array<int,2> ans = {0,0};

        for( int i = 0; i<n; i++){
            dp[i][i] = true;
        }

        for ( int j = 0;j< n-1; j++){
            if (s[j] == s[j+1]){
                dp[j][j+1] = true;
                ans = {j,j+1};
            }
        }
        
        for( int diff = 2;diff< n;diff++){
            for ( int i = 0;i < n-diff; i++){
                int j = i+diff;
                if (dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j]=true;
                    ans = {i,j};
                }
            }
        }
        return s.substr(ans[0],ans[1]-ans[0]+1);
        
    }
};