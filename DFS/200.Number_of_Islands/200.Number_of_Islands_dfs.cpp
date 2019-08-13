class Solution {
private:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    int m,n;
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        if(grid[0].size() == 0) return 0;
        int res = 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++res;
                    helper(grid, i, j);
                }
            }
        }
        return res;
    }
    
    void helper(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        for(int k = 0; k < 4; ++k)
        {
            helper(grid, i + dx[k], j + dy[k]);
        }
        return;
    }
};