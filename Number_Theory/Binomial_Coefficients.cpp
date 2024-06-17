/*
* Author: JorgeSLime     
* Problem: Binomial Coefficients
* Contest: CSES Problem Set
* Judge: CSES
* URL: https://cses.fi/problemset/task/1079
* Memory Limit: 512
* Time Limit: 1000
* Start: jue 30 may 2024 23:34:33
* */
//THINK ONCE, CODE TWICE   "写之前要思考"
#include "bits/stdc++.h"
using namespace std;

#define sz(x)       (int)x.size()
#define all(x)    begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define eb           emplace_back
#define LN                   '\n'

using i32=int32_t;
using i64=int64_t;
template<typename T> using V=vector<T>;
//simple print 
template <class Head, class... Tail>
inline void print(Head &&head, Tail &&...tail) {
    cout << head;
    if constexpr (sizeof...(tail) == 0) cout << '\n';
    else {cout << ' ';print(std::forward<Tail>(tail)...);}
}
//print Vector
template<typename T> inline void print(vector<T>&v){for(int i=0;i<(int)v.size();i++) cout<<v[i]<<" \n"[i==(int)v.size()-1];}
template<typename T> inline void print(vector<T>&v,int n){for(int i=0;i<n;i++) cout<<v[i]<<" \n"[i==(int)v.size()-1];}
template<typename T> inline void print(T v[],int n){for(int i=0;i<n;i++) cout<<v[i]<<" \n"[i==n-1];}

constexpr i64 MOD=1e9+7;
constexpr i32 N=1e6+1;
i32 F[N];
void fact(){
    i64 prod=1,p=0;
    for(i64 i=2;i<=N;i++){
        F[p++]=prod%MOD;
        prod=(prod*(i%MOD))%MOD;
    }
}
auto solve()->void{
    i32 a,b; cin>>a>>b; 
    i64 ans=(F[a-1]/(F[b-1]*F[(a-b)-1]));
    print(F[a-1],F[b-1],F[(a-b)-1]);
    print(ans);
}
auto main()->signed{
    cin.tie(nullptr)->sync_with_stdio(0);
    cin.exceptions(std::ios::failbit | std::ios::badbit);
    cout.tie(nullptr)->sync_with_stdio(0);
    fact();
    i32 t=1; 
    cin>>t;
    for(;t--;) solve();
    return 0;
}
