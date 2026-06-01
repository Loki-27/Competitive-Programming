class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int islands = 0;
        int neighbors = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) {
                    islands++;

                    if (i + 1 < r && grid[i + 1][j])
                        neighbors++;
                    if (j + 1 < c && grid[i][j + 1])
                        neighbors++;
                }
            }
        }

        return islands * 4 - neighbors * 2;
    }
};