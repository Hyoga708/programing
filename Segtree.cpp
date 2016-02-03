#include <bits/stdc++.h>
using namespace std;
struct segtree{
	vector<int> data;
	int n;
	int init(int N){
		n=1;
		while(n<N)	n*=2;
		data.assign(2*n-1,INT_MAX);
		return n;
	}
	void update(int i,int x){
		i+=n-1;
		data[i]=x;
		while(i>0){
			i=(i-1)/2;
			data[i]=min(data[2*i+1],data[2*i+2]);
		}
	}
	int find(int l,int r,int a,int b,int k){
		if(b<=l or r<=a)	return INT_MAX;
		if(a<=l and r<=b)	return data[k];
		int vl=find(l,(l+r)/2,a,b,2*k+1);
		int vr=find((l+r)/2,r,a,b,2*k+2);
		return min(vl,vr);
	}
};
int main(){
	int n,q;	cin>>n>>q;
	segtree seg;	n=seg.init(n);
	for(int i=0;i<q;i++){
		int com,x,y;	cin>>com>>x>>y;
		if(com==0){
			seg.update(x,y);
		}
		else{
			cout<<seg.find(0,n,x,y+1,0)<<endl;
		}
	}
	return 0;
}
