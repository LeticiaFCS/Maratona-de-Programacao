/**
 * Author: LeticiaFCS
 */

#include<bits/stdc++.h>
#define lint long long

using namespace std;

lint pa(lint n){
	return n*(n+1)/2;
}

lint espiral(lint e, lint n){
	if(e == 0) return 0;
	return (4*n-4)*(e) - 8*pa(e-1);
}

lint UpperBound(lint n, lint b){
    lint l = 1, r = n/2 + n%2, m;
    while(l <= r){
        m=(l+r)/2; 
        if(espiral(m,n) > b && (m == 1 || espiral(m-1,n) <= b)) 
            return m;
        else if(espiral(m,n) > b) r=m-1;
        else l=m+1;
    }
    return m;
}


int dirx[] = { 0, 1, 0,-1};
int diry[] = { 1, 0,-1, 0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	lint n,b;
	cin>>n>>b;

	lint e = UpperBound(n,b);
	lint x=e, y=e;
	lint passos = espiral(e-1,n)+1;
	
	lint tamLado = n-2*(e-1);
	
	
	for(int l=0;l<4;l++){
		lint p = min(b-passos, tamLado-1);
		x += dirx[l]*p;
		y += diry[l]*p;
		passos += p;
	}

	cout<<x<<" "<<y<<"\n";

	return 0;	
}


