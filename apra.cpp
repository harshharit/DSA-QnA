#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int f(int i, int j, vvi &grid, vvi &dp){

    if(i == 0 && j == 0){
        return 0;
    }
    if(i < 0 || j < 0) return 1e9;

    if(dp[i][j] != -1) return dp[i][j];


    int top = 1 + f(i - grid[i][j], j, grid, dp);
    int left = 1 + f(i, j - grid[i][j], grid, dp);

    return dp[i][j] = min(left,top);

}

int main(){
   vvi dp(3 , vi(3 , -1));
    int count = 0;
    vvi grid= {{0,1,1}, {1,1,1}, {2,1,2}};
    cout << f(2 , 2 , grid , dp);
}