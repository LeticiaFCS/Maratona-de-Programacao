/**
 * Author: LeticiaFCS
 */

#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define MOD 10000

using namespace std;

/**
 * Author: Ulf Lundstrom modified by Chris Ciafrino
 * Date: 2009-08-03
 * License: CC0
 */
template<class T, int N> struct Matrix {
	typedef Matrix M;
	array<array<T, N>, N> d{};
	M operator*(const M &m) const {
		M a;
		for(int i = 0; i < N; ++i) 
		    for(int j = 0; j < N; ++j)
			    for(int k = 0; k < N; ++k){
					a.d[i][j] += d[i][k]*m.d[k][j];
					a.d[i][j] %= MOD;
				}
		return a;
	}
	vector<T> operator*(const vector<T> &vec) const {
		vector<T> ret(N);
		for(int i = 0; i < N; ++i) 
		    for(int j = 0; j < N; ++j){
				ret[i] += d[i][j] * vec[j];
				ret[i] %= MOD; 
			}
		return ret;
	}
	M operator^(T p) const {
		assert(p >= 0);
		M a, b(*this);
		for(int i = 0; i < N; ++i) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};

int n,s,t;
lint l;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(cin>>n>>l){
		Matrix<lint,100> m;
		cin>>s>>t;
		s--;t--;

		for(int i=0;i<n;i++)
			for(int j=0;j<4;j++){
				int v; cin>>v;
				m.d[i][v-1]++;
			}

		m=m^l;
		cout<<m.d[s][t]<<"\n";
	}
	return 0;	
}


