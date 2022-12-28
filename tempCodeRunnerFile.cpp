#include <stdio.h>
#include <algorithm>
#define MX 250001
#define gc getchar

char str[1000];

char getchar(){
	char cz=gc();
	for(int i=0;cz==' '||cz=='\n';i++){
		cz=gc();
		str[i]=cz;
	}
}

int main(){
//	char str[10];
	getchar();
//	char cz=gc();
//    while(cz==' '||cz=='\n')cz = gc(),str[i]=cz;
//    for(int i=0;i<n;i++)vl[sh[i]]=cz,cz=gc();

    for(int i=0;i<5;i++){
    	printf("%c",str[i]);
	}
}