class Solution {
public:
    void dfs(){

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        queue<pair<int,int>> q;

        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2) {
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            ans++;
            int level = q.size();
            for(int i = 0;i<level;i++){
                int r = q.front().first; int c = q.front().second;
                q.pop();
                if(r-1>=0 && !visited[r-1][c] && grid[r-1][c]==1){ 
                    q.push({r-1,c}); 
                    visited[r-1][c]=true;}
                if(c-1>=0 && !visited[r][c-1] && grid[r][c-1]==1){ 
                    q.push({r,c-1}); 
                    visited[r][c-1]=true;}
                if(r+1<n &&  !visited[r+1][c] && grid[r+1][c]==1){ 
                    q.push({r+1,c}); 
                    visited[r+1][c]=true;}
                if(c+1<m && !visited[r][c+1] && grid[r][c+1]==1){ 
                    q.push({r,c+1}); 
                    visited[r][c+1]=true;}
            }
        }

        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]) {
                    return -1;
                }
            }
        }

        return ans-1 < 0 ? 0:ans-1;
    }
};