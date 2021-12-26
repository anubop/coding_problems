class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        for(int y = 0; y < grid.size(); ++y) {
            for(int x = 0; x < grid[0].size(); ++x) {
                if(grid[y][x] == '1') {
                    numIslands++;
                    dfs(grid, x, y);
                }
            }
        }
        return numIslands;
    }
    
private:
    void dfs(vector<vector<char>> & grid, int x , int y) {
        //base cases - out of bounds or zero
        if(x >= grid[0].size() || x < 0 || y < 0 || y >= grid.size()) {
            return;
        }
        if(grid[y][x] == '0') {
            return;
        }
        //recursive case - set tile to "0" and recurse in adjacent direction
        grid[y][x] = '0';
        dfs(grid, x + 1 , y);
        dfs(grid, x , y - 1);
        dfs(grid, x - 1, y);
        dfs(grid, x , y + 1);
        
    }
};