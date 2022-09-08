// bool f(int ind , int k,vector<int> &arr , vector<vector<int>> &dp){
//     if(k == 0) return true;
    
//     if(ind == 0) return(arr[0] == k);
    
//     if(dp[ind][k] != -1) return dp[ind][k];
    
//     bool notTake = f(ind - 1 , k, arr, dp);
    
//     bool take = false;
//     if(arr[ind] <= k){
//         take = f(ind-1, k-arr[ind], arr, dp);
//     }
    
//     return dp[ind][k] = (take || notTake);
// }
bool subsetSumToK(int n, int target, vector<int> &arr) {
   vector<vector<int>> dp(n, vector<int>(target+1,false));
  
     for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    if(arr[0]<=target)
        dp[0][arr[0]] = true;
    
    for(int i=1 ;i<n ; i++){
        for(int k=1;k<=target; k++){
            
            bool notTake = dp[i - 1][k];
    
            bool take = false;
            if(arr[i] <= k)
                take = dp[i-1][k-arr[i]];
     
                dp[i][k] = (take || notTake);
        }
    }
    return dp[n-1][target] ;
}