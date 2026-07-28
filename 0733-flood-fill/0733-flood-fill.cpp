class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int original = image[sr][sc];

        if(original==color) return image;

        vector<pair<int,int>> direc = {{-1,0},{0,-1},{1,0},{0,1}}; // up left down right

        queue<pair<int,int>> q;

        q.emplace(sr,sc);
        image[sr][sc] = color;

        while(!q.empty()){
                int r1 = q.front().first;
                int c1 = q.front().second;
                q.pop();
                for(int i = 0;i<4;i++){
                    int r = r1 + direc[i].first;
                    int c = c1 + direc[i].second;

                    if(r>=0 && r <m && c>=0 && c<n && image[r][c]==original){
                        q.emplace(r,c);
                        image[r][c] = color;
                    }
                }
            
        }
        return image;
    }
};