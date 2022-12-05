#include <stdio.h>
#include <math.h>
#define ll long long
int n,k;
ll solve(ll x, ll y){
	ll h;
	if(n&1) h = (ll) pow((double)(y-1), (double) x) - (y-1);
	else h = (ll) pow((double) (y-1), (double) x) + (y-1);
	return h;
}
int main(){
	scanf("%d %d", &n, &k);
	if(n==1) printf("%lld\n", k);
	else if ((k==1) || (n&1 && k==2)) printf("-1\n");
	else printf("%lld", solve(n, k));	
return 0;
}