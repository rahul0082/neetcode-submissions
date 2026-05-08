class Solution {
    int offset[5] = {0,1,0,-1,0};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool treasure_check = false;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    treasure_check = true;
                    q.push({{i,j},0});
                }
            }
        }
        if(!treasure_check) return;
        while(!q.empty()) {
            pair<pair<int,int>,int> p = q.front();
            q.pop();
            for(int i=0; i<4; i++) {
                int dx = p.first.first + offset[i];
                int dy = p.first.second + offset[i+1];
                if(dx >= 0 && dx < m && dy >= 0 && dy < n) {
                    if(grid[dx][dy] == INT_MAX) {
                        grid[dx][dy] = p.second+1;
                        q.push({{dx,dy},p.second+1});
                    }
                }
            }
        }
    }
};
