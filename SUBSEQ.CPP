#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printF(int ind,vector<int> &ds,int arr[],int n,int s,int sum)
{
    if(ind==n){
       if(sum==s){
            for(auto it : ds) cout<<it<<" ";
            cout<<endl; 
        }
        return;
    }
    //else return;
   
    ds.push_back(arr[ind]);
    s+=arr[ind];

    printF(ind+1,ds,arr,n,s,sum);

    s-=arr[ind];
    ds.pop_back();
    
    printF(ind+1,ds,arr,n,s,sum);
}
int main()
{
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    int s=0;
    vector<int> ds;
    printF(0,ds,arr,n,s,sum);

return 0;
}