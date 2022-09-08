//int f(int ind,int amount, vector<int>& coins, vector<vector<int>> &dp ){
//         if(ind == 0){
//             if(amount % coins[ind] == 0) return 1;
//                 else return 0;
//         }
        
//         if(amount == 0) return 1;
//         if(dp[ind][amount] != -1) return dp[ind][amount];
        
//         int notPick = f(ind-1,amount,coins,dp);
        
//         int pick = 0;
//         if(coins[ind]<=amount){
//             pick = f(ind,amount - coins[ind],coins,dp);
//         }
        
//         return dp[ind][amount] = pick+notPick;
//     }
    int change(int amount, vector<int>& coins) {
       
        
        int n = coins.size();
       //  vector<vector<int>> dp(n ,vector<int>(amount+1,0));
        
        vector<int> curr(amount+1,0), prev(amount+1,0);
        
        for(int T=0;T <=amount;T++)
            prev[T] = (T % coins[0] == 0);
            
            for(int ind=1;ind < n; ind++){
                for(int T =0;T<=amount;T++){
                    
                     int notPick = prev[T];

                        int pick = 0;
                        if(coins[ind]<=T){
                            pick = curr[T - coins[ind]];
                        }
        
                        curr[T] = pick+notPick;
                }
                prev=curr;
            }
        
        return prev[amount];
    }