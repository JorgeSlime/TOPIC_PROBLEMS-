/*
* Author: JorgeSLime     
* Problem: B. Water Lily
* Contest: Codeforces Round 576 (Div. 2)
* Judge: Codeforces
* URL: https://codeforces.com/contest/1199/problem/B
* Memory Limit: 256
* Time Limit: 1000
* Start: vie 12 abr 2024 20:00:04
* */
//THINK ONCE, CODE TWICE
#include "bits/stdc++.h"
#define LN '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double H,L; cin>>H>>L;
    double ans=((L*L)-(H*H))/(H*2);
    cout<<fixed<<setprecision(15)<<ans<<LN;
    return 0;
}
