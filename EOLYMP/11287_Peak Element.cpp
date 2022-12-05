#include <cstdio>
#define gc getchar_unlocked
#define ULL unsigned long long
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

int main(){
	int n=read();
	int a2,temp;
	a2 = read();
	for(int i=0;i<n;i++){
		temp=read();
		if(temp<a2){
			printf("%d",i);
			return 0;
		}
		a2 = temp;
	}
	return 0;
}