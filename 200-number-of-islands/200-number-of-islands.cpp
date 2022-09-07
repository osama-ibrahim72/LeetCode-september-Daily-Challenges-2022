class Solution {
public:
    int m,n;
    void dfs(int i,int j, vector<vector<char>>& grid){
        if(i>=0 && j>=0 && i<m && j<n && grid[i][j] =='1')
        {
            grid[i][j] = '0';
            dfs(i + 1, j, grid);
            dfs(i - 1, j, grid);
            dfs(i, j - 1, grid);
            dfs(i, j + 1, grid);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    ++ans;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};