/**
 * Author: LeticiaFCS
 */

#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second

using namespace std;


int somaL[101], somaC[101];
bool visL[101], visC[101];
string grid[101][101];

int l,c;
map<string,int> sol;

bool mudouLinha(){
	for(int i=0;i<l;i++){
		if(!visL[i]){
			set<string> nova;
			for(int j=0;j<c;j++){
				if(! sol.count(grid[i][j]))
					nova.insert(grid[i][j]);				
			}
			if(nova.size() == 0)
				return visL[i]=true;
			
			if(nova.size() == 1){
				int val = somaL[i];
				int coef=0;
				for(int j=0;j<c;j++)
					if(sol.count(grid[i][j]))
						val -= sol[grid[i][j]];
					else
						coef++;
				val = val/coef;
				sol[*(nova.begin())] = val;
				
				return visL[i]=true;
			}
		}
	}	
	return false;
}
bool mudouColuna(){
	for(int j=0;j<c;j++){
		if(!visC[j]){
			set<string> nova;
			for(int i=0;i<l;i++){
				if(! sol.count(grid[i][j]))
					nova.insert(grid[i][j]);				
			}
			if(nova.size() == 0)
				return visC[j]=true;
			
			if(nova.size() == 1){
				int val = somaC[j];
				int coef=0;
				for(int i=0;i<l;i++)
					if(sol.count(grid[i][j]))
						val -= sol[grid[i][j]];
					else
						coef++;
				val = val/coef;
				sol[*(nova.begin())] = val;
				
				return visC[j]=true;
			}
		}
	}	
	return false;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>l>>c;
	
	for(int i=0;i<l;i++){
		for(int j=0;j<c;j++)
			cin>>grid[i][j];
		cin>>somaL[i];
	}

	for(int j=0;j<c;j++)
		cin>>somaC[j];

	while(mudouLinha() || mudouColuna());
	
	for(auto &var:sol)
		cout<<var.st<<" "<<var.nd<<"\n";

	return 0;	
}


