#include <cstdio>
#include <math.h>
#define gc getchar
#define ULL unsigned long long
typedef long long ll;
using namespace std;

ULL read(){
	ULL value = 0;bool ne=0;
	char c = gc();
	while(c==' ' or c=='\n') c =gc();
	if(c=='-'){ne = 1;c = gc();}
	while(c>='0' and c<='9'){
		value = (value<<3)+(value<<1)+c-'0';c = gc();}
	if(ne) value*=-1;
	return value;
}

ll modex(ll b, ll e, ll m){
	if(b==0 || e == 0) return 0;
	ll r = 1;
	while(e>0){
		if((e&1)==1) r = (r*b)%m;
		e>>=1;
		b = (b*b)%m;
	}
	return r;
}

ULL solve(ULL a){
	ULL b = (a*(a-1))/2;
	return modex(2,b,1000000007);
}

int main(){
	ULL a;
	a =read();
	if(a==1) {
		printf("1");
		return 0;
	}
	printf("%lld\n",solve(a));
}