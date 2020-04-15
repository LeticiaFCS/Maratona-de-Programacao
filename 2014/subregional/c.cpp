/**
 * Author: LeticiaFCS
 */

#include<bits/stdc++.h>
#define lint long long

using namespace std;

int m,n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>m>>n;
	vector<vector<int>> planos(m,vector<int>(4));
	for(int i=0;i<m;i++){
		cin>>planos[i][0]>>planos[i][1]>>planos[i][2]>>planos[i][3];
	}
	map<vector<bool>, int> freq;

	for(int i=0;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		vector<bool> aux(m);
		for(int j=0;j<m;j++){
			lint d=planos[j][0]*x+planos[j][1]*y+planos[j][2]*z-planos[j][3];
			if(d>0) aux[j]=1;
		}
		
		freq[aux]++;
	}

	int ans=0;
	for(auto f:freq)
		ans=max(ans,f.nd);
	
	cout<<ans<<"\n";

	return 0;	
}


