#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void print(int i,int n)
{
	if(i>n){
		return;
	}
	print(i+1,n);
	cout<<i;
}




int main() {
	int n=4;
	int i=1;
	print(i,n);
	return 0;
}