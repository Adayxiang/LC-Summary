class Solution {
private:
    vector<int> parent;
    int count;
    int m,n;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    
    int find(int root)
    {
        int tmp = root;
        while(root != parent[root])
        {
            root = parent[root];
        }
        while(tmp != root)
        {
            int cur = parent[tmp];
            parent[tmp] = root;
            tmp = cur;
        }
        return root;
    }
    
    void unionSet(int i, int j)
    {
        int rootI = find(i);
        int rootJ = find(j);
        if(rootI == rootJ) return;
        parent[rootI] = rootJ;
        --count;
        return;
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        if(grid[0].size() == 0) return 0;
        m = grid.size(), n = grid[0].size();
        count = 0;
        for(int i = 0; i < m * n ; ++i)
        {
            parent.push_back(i);
        }
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '0') continue;
                ++count;
                for(int k = 0; k < 4; ++k)
                {
                    int nextI = i + dx[k], nextJ = j + dy[k];
                    if(nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n || grid[nextI][nextJ] == '0') continue;
                    unionSet(i*n + j, nextI * n + nextJ);
                }
                //cout << "i: " << i << "j: " << j << " " << count << endl;
            }
            
        }
        
        return count;
    }
};