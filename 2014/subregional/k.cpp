/**
 * Author: LeticiaFCS
 */

#include<bits/stdc++.h>

using namespace std;

int c,n;

int pre[200020];
int posicao[10010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>c>>n;

	for(int i=0;i<n;i++){
		cin>>posicao[i];
		pre[++posicao[i]] = pre[posicao[i]+c+1]=1;
	}
	
	for(int i=1;i<=2*c+1;i++)
		pre[i] += pre[i-1];
	
	bool possivel=false;
	
	for(int i=0;i<n;i++){
		possivel=true;
		for(int dist=1; dist<n; dist++){
			if(pre[posicao[i] + dist * c/n] - pre[posicao[i]] != dist){
				possivel=false; break;
			}
		}
		if(possivel) break;
	}

	if(possivel) cout<<"S\n";
	else cout<<"N\n";

	return 0;	
}


