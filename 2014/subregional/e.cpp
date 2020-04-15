/**
 * Author: LeticiaFCS
 * Date: 2020-04-01
 * License: CC0
 */

#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define LIM 11

using namespace std;

int diri[] = { 0, 1, 0,-1};
int dirj[] = { 1, 0,-1, 0};

typedef pair<int,int> pii;
vector<vector<pii>> poly [LIM];
void generate(int n){
	poly[1] = {{{0 , 0}}};
	for(int i = 2 ; i <= n; i++) {
		set<vector<pii>> cur_om;
		for(auto &om : poly[i-1]) {
			pii mini = om[0];
			for(auto &p : om)
				for(int d = 0; d < 4; d++) {
					int x = p.st + diri[d];
					int y = p.nd + dirj[d];
					if(!binary_search(om.begin(), om.end(), pii(x,y))) {
						pii m = min(mini, {x, y});
						pii new_cell(x - m.st, y - m.nd);
						bool new_in = false;
						vector<pii> norm;
						for(pii &pn : om) {
							pii cur(pn.st - m.st, pn.nd - m.nd);
							if(cur > new_cell && !new_in) {
								new_in = true;
								norm.push_back(new_cell);
							}
							norm.push_back(cur);
						}
						if(!new_in) norm.push_back(new_cell);
						if(!cur_om.count(norm)) cur_om.insert(norm);
					}
				}
		}
		poly[i].assign(cur_om.begin(),cur_om.end());
	}
}

lint ans=-1;
int v[53][53];

int n, lim;

bool valid(int i, int j){
	if(i<0 || i>=n) return 0;
	if(j<0 || j>=n) return 0;
	return 1;
}
void run(int x, int y){
	for(auto &omino: poly[lim]){

		lint soma = 0;

		for(pii pos:omino){
			if(valid(x+pos.st, y+pos.nd))
				soma += v[x+pos.st][y+pos.nd];
			else{
				soma =-1;
				break;
			}
		}
		ans=max(ans,soma);

	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n>>lim;

	generate(lim);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>v[i][j];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			run(i,j);

	cout<<ans<<"\n";

	return 0;	
}






