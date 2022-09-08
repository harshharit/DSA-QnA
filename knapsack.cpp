int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	
    vector<int> prev(maxWeight+1, 0);
 
    for(int W = weight[0]; W <= maxWeight;W++) prev[W] = value[0];
    
    for(int ind = 1; ind < n;ind++){
        for(int W = maxWeight;W >=0;W--){
            
             int notPick = 0 + prev[W];
                    int pick = INT_MIN;
                    if(weight[ind]<= W){
                        pick = value[ind] + prev[W - weight[ind]];
                            }
                    prev[W] = max(pick, notPick);
        }
       
    }
    
    return prev[maxWeight];
   
}