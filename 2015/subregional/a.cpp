/**
 * Author: LeticiaFCS
 */

#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f
using namespace std;

typedef vector<vector<pair<int,int>>> grafo;

typedef pair<int,pair<int,int>> piii;

int c,v;

int dijkstra(grafo &g){
	vector<vector<int>> dist(c, vector<int>(2,INF));
	vector<vector<bool>> vis(c, vector<bool>(2,false));
	priority_queue <piii, vector<piii>, greater<piii>> q;
	
	q.push({dist[0][0] = 0,{0,0}});
	
	while(!q.empty()) {
		int u=q.top().nd.nd;
		vis[u][q.top().nd.st]=1;
		q.pop();
		for(auto p: g[u]){
			int e=p.st, v=p.nd;
			if (!vis[v][0]){
				int distpar = dist[u][1]+e;
				if(distpar<dist[v][0]){
					q.push({dist[v][0] = distpar,{0,v}});
				}
			}
			if(!vis[v][1]){
				int distimpar = dist[u][0]+e;
				if(distimpar<dist[v][1]){
					q.push({dist[v][1] = distimpar,{1,v}});
				}
			}
		}
	}
	return dist[c-1][0];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>c>>v;
	grafo g(c);
	while(v--){
		int u,v,val;
		cin>>u>>v>>val;
		u--;v--;
		g[u].push_back({val, v});
		g[v].push_back({val, u});
	}
	int d = dijkstra(g);
	if(d == INF)
		cout<<"-1\n";
	else
		cout<<d<<"\n";

	return 0;	
}

