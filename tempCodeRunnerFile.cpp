#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;


// int count = INT_MAX;
vvi dp(input1, vi(input2, INT_MAX));

void solve(int x, int y, int **grid, int cnt){
    if(x < 0 || y<0)  return;