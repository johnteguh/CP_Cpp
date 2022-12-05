#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef unsigned long long ll;
int main(){
	int t,n;
	ll a,b,fpb,a1,b1;
	long double x,y;
	scanf("%d", &t);
	while(t--){
		a=0.0;
		b=0.0;
		scanf("%d", &n);
	while(n--){
		scanf("%Lf %Lf", &x, &y);
		a1=floor(x*10000+0.5);
		b1=floor(y*10000+0.5);
		a+=a1;
		b+=b1;
		}
		fpb = __gcd(a,b);
		b = b/fpb;
		a = a/fpb;
		printf("f(x) = %llux, g(x) = %llux\n", b, a);
	}
	return 0;
}


