/*
* Author: JorgeSLime     
* Problem: Easy Prime!
* Contest: unknown_contest
* Judge: Toph
* URL: https://toph.co/p/easy-prime
* Memory Limit: 512
* Time Limit: 1000
* Start: vie 12 abr 2024 20:30:22
* */
//THINK ONCE, CODE TWICE
#include "bits/stdc++.h"
#define LN '\n'
using namespace std;
const int N=1e5+7,NMAX=1e7+7;
int BIT[N],v[N]; 
bool vis[NMAX];
//Criba de Eratosthenes O(N*Log(N))
void criba(int n) {
    for (int i=2;i<n;++i) {
        //if (!vis[i]) prime.emplace_back(i);
        for (int j=2;i*j<n;++j)
            vis[i * j]=1;
    }
}
void upd(int i0, int v){ 	
	for(int i=i0+1;i<=N;i+=i&-i) BIT[i]+=v;
}
int get(int i0){ 
	int r=0;
	for(int i=i0;i;i-=i&-i) r+=BIT[i];
	return r;
}
int get_sum(int i0, int i1){ 
	return get(i1)-get(i0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    criba(NMAX);
    int n; cin>>n; 
    for(int i=0;i<n;i++){
        cin>>v[i];
        upd(i+1,v[i]);
    }
    if(!vis[3]&&!vis[5]) cout<<"OK"<<LN;
    return 0;
}
