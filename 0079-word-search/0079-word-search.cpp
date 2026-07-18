class Solution {
public:
    bool helper(vector<vector<bool>> &visited,vector<vector<char>>& board,
                string& word,int idx,int i,int j,int& m,int& n){
                    if(idx==word.size()) return true;
                
                    if(i>=m||j>=n||i<0||j<0) return false;
                    if(visited[i][j]) return false;
                    if(board[i][j]!=word[idx]) return false;

                    visited[i][j] = true;
                    bool l = helper(visited,board,word,idx+1,i,j+1,m,n);
                    if(l) return true;
                    bool r = helper(visited,board,word,idx+1,i,j-1,m,n);
                    if(r) return true;
                    bool u = helper(visited,board,word,idx+1,i-1,j,m,n);
                    if(u) return true;
                    bool d = helper(visited,board,word,idx+1,i+1,j,m,n);
                    if(d) return true;
                    visited[i][j] = false;

                    return false;
                }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(m*n<word.size()) return false;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(helper(visited,board,word,0,i,j,m,n)) return true;
            }
        }
        return false;
    }
};