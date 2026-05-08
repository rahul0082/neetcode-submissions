class Solution {
    vector<int> d = {0,1,0,-1};
// [i, j, di, dj] = [0, 3, 1, 3]
    bool search(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int idx, int i, int j) {
        cout << i << " " << j << " " << '\n';
        int m = board.size();
        int n = board[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }

        if(visited[i][j] || word[idx] != board[i][j]) {
            return false;
        }

        if(idx == word.size() - 1) {
            return true;
        }

        visited[i][j] = true;
        idx++;

        for(int k=0; k<4; k++) {
            int di = i + d[k % 4]; // 0
            int dj = j + d[(k+1) % 4]; // 3

            if(search(board, word, visited, idx, di, dj)) {
                return true;
            }
        }
        visited[i][j] = false;
        
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
    
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                vector<vector<bool>> visited = vector<vector<bool>> (m, vector<bool> (n, false));
                if(search(board, word, visited, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};
