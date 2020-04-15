#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x,y;
	cin>>x>>y;
	cout<<y/(y-x) + (y%(y-x) != 0) <<"\n";
	return 0;	
}
