class Solution {
     public :
    void combSum(int ind,int target,vector<int> &candidates,vector<int> &ds,vector<vector<int>> &ans){
        if(ind==candidates.size()){
                if(target==0){
                    ans.push_back(ds);
                }
             return;
            }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            combSum(ind,target-candidates[ind],candidates,ds,ans);
            ds.pop_back();
        }
         combSum(ind+1,target,candidates,ds,ans);
        }
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
        vector<int> ds;
        vector<vector<int>> ans;
        combSum(0,target,candidates,ds,ans);
        return ans;
    }
   
};