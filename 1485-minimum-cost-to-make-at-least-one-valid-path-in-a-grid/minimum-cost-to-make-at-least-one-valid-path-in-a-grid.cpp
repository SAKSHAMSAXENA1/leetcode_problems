class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        pq.emplace(0, 0, 0);
        cost[0][0] = 0;

        while (!pq.empty()) {
            auto [currCost, x, y] = pq.top(); pq.pop();
            if (currCost > cost[x][y]) continue;
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dirs[dir][0], ny = y + dirs[dir][1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int nextCost = currCost + (dir != grid[x][y] - 1);
                if (nextCost < cost[nx][ny]) {
                    cost[nx][ny] = nextCost;
                    pq.emplace(nextCost, nx, ny);
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};