/*
* Author: JorgeSLime     
* Problem: Range Update Queries
* Contest: CSES Problem Set
* Judge: CSES
* URL: https://cses.fi/problemset/task/1651
* Memory Limit: 512
* Time Limit: 1000
* Start: jue 18 abr 2024 13:59:06
* */
//THINK ONCE, CODE TWICE
#include "bits/stdc++.h"
#define LN '\n'
using namespace std;
//ENCONTRAR EL VALOR DEL K-SIMO CON SEGMENT  Iteravtivo


const int N=2e5+7; 
int T[N<<1],n,q;
inline void init(){
    for(int i=n-1;i;i--){
        T[i]=T[i<<1]+T[i<<1|1];
    }
}
inline void upd(int I,int V){
    for(T[I+=n]=V;I>1;I>>=1){
        T[I>>1]=T[I]+T[I^1];
    }
}
inline int find_kth(int n,int L, int R,int k){
    if(k>T[n]) return -1;
    if(L==R) return L;
    int M=(L+R)>>1;
    if(T[n<<1]<=k) return find_kth(n<<1,L,M,k);
    else return find_kth(n<<1|1,M+1,R,k-T[n<<1]);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
