#include <bits/stdc++.h>
using namespace std;
 
// Function returns the
// Minimum GCD of any pair
int MinimumGCD(int arr[], int n)
{
    int g = 0;
 
    // Finding GCD of all the
    // elements in the array.
    for (int i = 0; i < n; i++) {
        g = __gcd(g, arr[i]);
    }
    return g;
}
 
// Driver code
int main()
{
    int arr[] = { 2, 3, 4,6, 8, };
 
    int N = sizeof(arr) / sizeof(arr[0]);
 
    cout << MinimumGCD(arr, N) << endl;
}