#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;


// int count = INT_MAX;

void solve(int x, int y, vvi &grid, int cnt, vvi &dp){
    if(x < 0 || y<0)  return;
    if(x == 0 && y == 0){
        dp[x][y]= min(dp[x][y], cnt);
    } else {
        // if(dp[x][y] != -1 && )  return;
        if(dp[x][y] != INT_MAX && dp[x][y] >= cnt)  return;
        solve(x - grid[x][y], y, grid, cnt+1, dp);
        solve(x, y - grid[x][y], grid, cnt+1, dp);
    }
}

int matrixHops(int input1, int input2, vvi &input3){
    vvi dp(input1, vi(input2, INT_MAX));
    solve(input1-1, input2-1, input3, 0, dp);
    return dp[0][0];
}

int main(){
    vvi grid= {{0,1,1}, {1,1,1}, {2,1,2}};
    // for(auto it: grid)
    //     for(auto jt: it)
    //         cout << jt << " ";
    cout << matrixHops(3,3,grid);
}