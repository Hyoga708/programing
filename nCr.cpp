#include <iostream>
using namespace std;
#define mod 1000000007
long long nCr(long long n,long long r);
long long pow(long long a,long long b);

int main(){
	int n,r;	cin>>n>>r;
	cout<<nCr(n,r)<<endl;
	return 0;
}

long long nCr(long long n, long long r){ 
  long long ret=1LL;
  for(int i=1;i<=r;i++){
    ret=(ret*((n-i+1)%mod))%mod;
  }
  for(int i=1;i<=r;i++){
    ret=(ret*pow(i,mod-2))%mod;
  }
  return ret;
}


long long pow(long long a, long long b){ 
  long long r=1LL;
  while(b){
    if(b&1LL)r*=a;
    if(r>=mod)r%=mod;
    a*=a;
    if(a>=mod)a%=mod;
    b>>=1LL;
  }
  return r;
}
