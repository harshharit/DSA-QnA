class Solution {
public:
    int f(int i , int j ,int n, int m, vector<vector<int>>& grid){
        
        if(grid[i][j] == -1) return -1e9;
        
        if(i == n-1 ) return grid[i][j];
        
        if( j < 0 || j>=m-1 )
            return -1e9;
        
        int down = grid[i][j] + f(i + 1, j, n, m , grid );
        
         int ld = grid[i][j] + f(i + 1, j-1, n, m , grid );
        
         int rd = grid[i][j] + f(i + 1, j+1, n, m , grid );
        
        return max(down , max(rd, ld,));
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        return f(0 , 0 ,n , m ,grid);
        
    }
};