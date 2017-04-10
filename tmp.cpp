#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define mp(a,b)	make_pair(a,b)
#define fst first
#define scn second

int stone[10010];
vector<int> edge[10010];

int main(){
	int n;	cin>>n;
	for(int i=0;i<n;i++)	cin>>stone[i];
	for(int i=0;i<n-1;i++){
		int a,b;	cin>>a>>b;	a--;	b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	vector<int> leave;
	for(int i=0;i<n;i++){
		if(edge[i].size()==1)	leave.push_back(i);
	}

	return 0;
}
