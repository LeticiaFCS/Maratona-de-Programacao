/**
 * Author: LeticiaFCS
 */

#include<bits/stdc++.h>

using namespace std;

int gols[101];

int n,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	int ans=0;
	for(int i=0;i<n;i++){
		int cont=0;
		for(int j=0;j<m;j++){
			int g; cin>>g; cont += (g>0);
		}
		ans += (cont == m);
	}

	cout<<ans<<"\n";


	return 0;	
}


