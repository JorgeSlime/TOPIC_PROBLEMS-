/*
* Author: JorgeSLime     
* Problem: Range Updates and Sums
* Contest: CSES Problem Set
* Judge: CSES
* URL: https://cses.fi/problemset/task/1735
* Memory Limit: 512
* Time Limit: 1000
* Start: lun 15 abr 2024 23:12:29
* */

//THINK ONCE, CODE TWICE
#include "bits/stdc++.h"
#define LN '\n'
using namespace std;
const int N=1e6+7,N1=2e5+7;
long long T[N<<1],v[N1],n,q;

inline void init(){
    for(int i=n-1;i;--i){
        T[i]=T[i<<1]+T[i<<1|1];
    }
}
inline void upd(int p,int v){
    for(T[p+=n]=v;p>1;p>>=1){
        T[p>>1]=T[p]+T[p^1];
    }
}
inline long long query(int l,int r){
    long long res=0; 
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) res+=T[l++];
        if(r&1) res+=T[--r];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q; 
    for(int i=0;i<n;i++){
        cin>>T[i+n];
        v[i]=T[i+n];
    }
    init();
    while(q--){
        int x; cin>>x; 
        if(x==1){
            long long a,b,V; cin>>a>>b>>V;
            a--;
            for(int i=a;i<b;i++){
                upd(i,v[i]+V);
            }
        }
        if(x==2){
            long long a,b,V; cin>>a>>b>>V;
            a--;
            for(int i=a;i<b;i++){
                upd(i,V);
            }
        }
        if(x==3){
            long long l,r; cin>>l>>r;
            l--;
            cout<<query(l,r)<<LN;
        }
    }
    return 0;
}
