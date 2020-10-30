class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m = grid.size(), n = grid[0].size();
        int freshcount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    freshcount++;
                }
            }
        }
        int dir [][2] = {{0, -1}, {0, 1}, { -1, 0}, {1, 0}};
        int time = 0;

        // queue contains the coordinates of rotten oranges in the current timestep
        while (!q.empty() && freshcount > 0) {
            time++;
            int size = q.size();
            while (size--) {
                auto curr = q.front();
                q.pop();

                // go to neighbours and rot them
                for (auto d : dir) {

                    int x = curr[0] + d[0];
                    int y = curr[1] + d[1];

                    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0 || grid[x][y] == 2)
                        continue;

                    grid[x][y] = 2;
                    q.push({x, y});
                    freshcount--;
                }
            }
        }
        return freshcount > 0 ? -1 : time;
    }
};