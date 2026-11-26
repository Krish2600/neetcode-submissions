class Solution {
public:

    void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &visited){
        int m = grid.size();
        int n = grid[0].size();

        if(r<0 || c<0 || r>=m || c>=n){    // check for out of bounds.then skip it
            return;
        }

        if(grid[r][c] == '0' || visited[r][c]){  // check if water or already visited cell.then skip it
            return;
        }

        visited[r][c] = 1;

        dfs(r-1,c,grid,visited);
        dfs(r+1,c,grid,visited);
        dfs(r,c-1,grid,visited);
        dfs(r,c+1,grid,visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n,0));

        int islands = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !visited[i][j] ){

                    islands++;
                    dfs(i,j,grid,visited);
                }
            }
        }

        return islands;
        
    }
};
