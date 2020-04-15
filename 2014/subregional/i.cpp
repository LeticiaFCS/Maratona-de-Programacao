/**
 * Author: LeticiaFCS
 */

#include<bits/stdc++.h>
#define lint long long

using namespace std;

/**
 * Author: Chris
 */
template<typename T>
T modinv(T a, T m){
	assert(m>0);
	if(m==1) return 0;
	a%=m;
	if(a<0)a+=m;
	assert(a!=0);
	if(a==1)return 1;
	return m-modinv(m,a)*m/a;

}
/**
 * Author: Håkan Terelius
 * Date: 2009-09-25
 * License: CC0
 */
template<typename T>
T phi(T n){
    T aux, result;
    aux = result = n;
    for (T i = 2; i*i <= n; ++i) 
        if (aux % i == 0) {
            while (aux % i == 0) aux /= i;
            result /= i;
            result *= (i-1);
        }
    if (aux > 1) {
    	result /= aux;
    	result *= (aux-1);
    }
    return result;
}

/**
 * Author: Chris
 */
lint modpow(lint b, lint e, lint mod) {
	lint ret = 1;
	for (int i = 1; i <= e; i *= 2, b = b * b % mod)
		if (i & e) ret = ret * b % mod;
	return ret;
}


lint n,e,c;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n>>e>>c;
	lint d = modinv(e, phi(n));
	lint m = modpow(c, d, n);
	cout<<m<<"\n";

	return 0;	
}


