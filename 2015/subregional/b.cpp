/**
 * Author: LeticiaFCS
 */

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define lint long long
#define com_acao 1
#define sem_acao 0

using namespace std;

int n;
lint pd[200010][5];
lint v[200010];
lint c;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n>>c;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    
    pd[0][com_acao] = -INF;
    pd[0][sem_acao] = 0;
    
    for(int i=1;i<=n;i++){
        pd[i][com_acao] = max(pd[i-1][com_acao], pd[i-1][sem_acao] -v[i]-c);
        pd[i][sem_acao] = max(pd[i-1][com_acao] + v[i] , pd[i-1][sem_acao]);
    }
    cout<<max(pd[n][com_acao],pd[n][sem_acao])<<"\n";
    
}
