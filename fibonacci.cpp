#include<iostream>
using namespace std;
 // namespacestd

int fibb(int n)
{
    if(n<=1)
    {
     return n;
    }
    
    int last=fibb(n-1);
    int secondlast=fibb(n-2);
    return secondlast+last;

}
int main()
{
   // int n=5;
    cout<<fibb(1000);
    return 0;
}