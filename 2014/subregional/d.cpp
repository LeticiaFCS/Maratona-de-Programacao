/**
 * Author: LeticiaFCS
 */

#include<bits/stdc++.h>
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int,int> pii;
vector<vector<pii>> g;
vector<int> comp;
vector<int> maior_ciclo;
vector<int> nociclo;
vector<int> tamciclo;
vector<int> in;

int n,m;
int t, c, ci;

int dfs(int u, int p){
	int id = -1;
	comp[u] = c;
	in[u]=t++;
	for(auto e:g[u]){
		if(e.nd == p) continue;
		if(in[e.nd] < in[u]){
			nociclo[u]=e.nd;
			id = e.nd;
		}else if(comp[e.nd] == -1){
			int dfse = dfs(e.nd,u);
			if(dfse != -1){
				nociclo[u]=dfse;
				if(dfse == u){
					id=-1;
				}else
					id=dfse;
			}
		}
	}	return id;
}


int dijkstra(int start, int tam){
	unordered_set<int> vis;
	unordered_map<int,int> dist;
	priority_queue <pii, vector<pii>, greater<pii>> q;
	q.push({dist[start] = 0,start});
	int ans = INF;
	while(!q.empty()) {
		int u = q.top().nd;
		int passos = q.top().st;
		if(nociclo[u] != nociclo[start] &&
		   nociclo[u] != -1 &&
		   tamciclo[nociclo[u]] >= tam){
				ans = min(ans, 2*passos+tamciclo[nociclo[u]]);
		}
		q.pop();
		vis.insert(u);
		for(pii p: g[u]){
			int e=p.st, v=p.nd;
			if (vis.count(v))
				continue;
			int new_dist = dist[u]+e;
			if(!dist.count(v))
				dist[v] = INF;
			if(new_dist<dist[v])
				q.push({dist[v] = new_dist,v});
		}
	}
	
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(cin>>n>>m){
		c=0;t=0;ci=0;
		
		g.assign(n,vector<pii>());
		comp.assign(n,-1);
		nociclo.assign(n,-1);
		in.assign(n,INF);

		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			a--;b--;
			g[a].push_back({c,b});
			g[b].push_back({c,a});
		}
	
		for(int i=0;i<n;i++)
			if(comp[i] == -1)
				dfs(i,i), c++;
			
		tamciclo.assign(n,0);
	
		for(int u=0;u<n;u++){
			if(nociclo[u]==-1) continue;
			for(auto e:g[u])
				if(nociclo[u] == nociclo[e.nd])
					tamciclo[nociclo[u]] += e.st;
		}

		for(int &val:tamciclo)
			val /= 2;
		
		int q;
		cin>>q;
		while(q--){
			int u, tam;
			cin>>u>>tam;
			u--;
			if(nociclo[u] != -1 && tamciclo[nociclo[u]] >= tam)
				cout<<min(dijkstra(u,tam),tamciclo[nociclo[u]])<<"\n";
			else{
				int d=dijkstra(u,tam);
				if(d == INF) cout<<"-1\n";
				else cout<<d<<"\n";
			}
			
		}		
	}

	return 0;	
}


