#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef pair<long long,pair<int,int> >pp;
queue <pp> trip;
vector <long long> time;

int main(){
	int n,x,y,a,b,c;
	pair <int,int> pr1;
	pp pr;
	scanf("%d %d %d", &n,&x,&y);
	for(int i=0;i<=n;i++)time.push_back(-1);
	time[x]=0;
	for(int i=1;i<n;i++){
		scanf("%d %d %d", &a,&b,&c);
		pr1=make_pair(a,b);
		pr=make_pair(c,pr1);
		trip.push(pr);
	}
	while(!trip.empty()){
		pp p;
		p=trip.front();
		trip.pop();
		if(time[p.second.first]!=-1){
			time[p.second.second]=time[p.second.first]+p.first;
		}else if(time[p.second.second]!=-1){
			time[p.second.first]=time[p.second.second]+p.first;
		}else trip.push(p);
	}

	printf("%lld\n", time[y]);
	return 0;
}