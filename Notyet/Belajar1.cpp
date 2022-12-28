#include <cstdio>
using namespace std;
#define gc getchar//_unlocked()

// int getchar(){
//     char cz=gc();

// }

int main(){
    char text[100];
    char cz=gc();
    printf("cz = %c\n",cz);
    while(cz==' '||cz=='\n')cz = gc();
    for(int i=0;i<10;i++){
        text[i]=cz;
        printf("%d, %c ",i,text[i]);
        cz=gc();
    }
}