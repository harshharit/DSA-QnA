// int f(int i,int j,vector<vector<int>>& triangle,int n, vector<vector<int>> &dp){
    
//     if(i == n-1){
//          return triangle[n-1][j];
//     }
//     if(dp[i][j] != -1) return dp[i][j];
    
//     int down = triangle[i][j] + f(i+1, j, triangle, n ,dp );
//     int dg = triangle[i][j] + f(i+1 , j+1,triangle , n , dp);
    
//     return dp[i][j]=min(down , dg);
// }
int minimumPathSum(vector<vector<int>>& triangle, int n){
// 	vector<vector<int>> dp(n ,vector<int>(n , -1));
    vector<vector<int>> dp(n ,vector<int>(n , 0));
    
   for(int j = 0 ;j < n;j++) dp[n-1][j]= triangle[n-1][j];
    
    for(int i=n-2;i>=0;i--){
        for(int j=i;j >=0 ;j--){
             int down = triangle[i][j] + dp[i+1][j];
             int dg = triangle[i][j] + dp[i+1][j+1];
            
            dp[i][j]= min(down,dg);
        }
    }
    return dp[0][0];
}