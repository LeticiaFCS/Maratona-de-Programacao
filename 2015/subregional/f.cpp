/**
 * Author: LeticiaFCS
 */

#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int quant[100010];
int fat[10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fat[0]=1;
	for(int i=1;i<9;i++)
		fat[i]=i*fat[i-1];
	
	memset(quant, INF, sizeof quant);
	quant[0] = 0;

	for(int i=1; i<9; i++)
		for(int j=fat[i]; j<=100000; j++)
			quant[j] = min(quant[j], quant[j-fat[i]] + 1);

	int n;
	cin>>n;
	cout<<quant[n]<<"\n";

	return 0;	
}

