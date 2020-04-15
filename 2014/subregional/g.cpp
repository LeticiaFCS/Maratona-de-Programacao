/**
 * Author: LeticiaFCS
 */
 
#include<bits/stdc++.h>
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;

int numdir = 4;
int diri[] = {0,1,0,-1}; 
int dirj[] = {1,0,-1,0}; 

char grid[101][101];
int dist[101][101];

int mask;
int n;

bool validletra(char x){
	if(x>='a' && x<='z'){
		if(mask & (1<<(x-'a'))) return false;
		return true;
	}else{
		if(mask & (1<<(x-'A'))) return true;
		return false;
	}
}

bool valid(int i, int j){
	if(i<0 || i>=n) return 0;
	if(j<0 || j>=n) return 0;
	if(dist[i][j]!=-1 || !validletra(grid[i][j])) return 0;
	return 1;
}

void bfs(int x, int y){
	queue<pair<int,int>> q;
	q.push({x,y});
	dist[x][y]=1;
	
	while(!q.empty()){
		pair<int,int> f=q.front();
		q.pop();
		for(int d=0;d<numdir;d++){
			int pi = f.st + diri[d];
			int pj = f.nd + dirj[d];
			if(valid(pi,pj)){
					dist[pi][pj]=1+dist[f.st][f.nd];
					q.push({pi,pj});
			}			
		}
	}
}



int ans=INF;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>grid[i][j];
	
	for(mask=0;mask<(1<<11);mask++){
		memset(dist,-1,sizeof dist);
		if(valid(0,0))bfs(0,0);
		if(dist[n-1][n-1]!=-1)
			ans=min(ans,dist[n-1][n-1]);
	}
	if(ans == INF)
		cout<<"-1\n";
	else
		cout<<ans<<"\n";
	return 0;	
}



