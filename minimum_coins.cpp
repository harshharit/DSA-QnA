// int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp ){
//     if(ind == 0 ){
//         if(target%arr[ind] == 0) 
//             return target/arr[ind];
//         else
//             return 1e9;
//     }
//     if(dp[ind][target] != -1) return dp[ind][target];
 
//     int pick = INT_MAX;
//     if(arr[ind] <= target)
//      pick = 1 + f(ind, target - arr[ind], arr,dp);
    
//     int notPick = 0 + f(ind - 1, target, arr, dp);

//     return dp[ind][target] = min(notPick, pick);

// }
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x+1 , 0));
    
    for(int i = 0;i <=x;i++ )
        if(i%num[0] == 0) dp[0][i] = i/num[0];
    else
        dp[0][i] = 1e9;
    
    for(int ind = 1;ind < n;ind++){
        for(int target = 0;target <=x;target++){
            
             int notPick = 0 + dp[ind - 1][target];
             int pick = 1e9;
                    if(num[ind] <= target)
                     pick = 1 + dp[ind][target - num[ind]];
            
                     dp[ind][target] = min(notPick, pick);
        }
    }
    
    int ans = dp[n-1][x] ;
    if(ans>=1e9) return -1;
     return ans;
}