/**
 * Author: LeticiaFCS
 */
#include<bits/stdc++.h>

using namespace std;

int p, n, pos;

int solve(){
	for(int i=0;;i++){
		if(i>0 && pos==1) return i;
		if(pos < n)
			pos=2*pos+1;
		else
			pos=2*(pos-n);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>p;
	
	n = p/2;
	pos = 1;
	cout<<solve()<<"\n";
	
	return 0;	
}


