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

template <typename T> inline T sqrt_(T n){
    T x=sqrtl(n)+1;
    while(x*x>n) x--;
    return x;
}

auto solve()->void{
    i64 a,b; cin>>a>>b;
    i64 x=sqrt_(a-1);
    i64 y=sqrt_(b);
    auto g=[](i64 n){
        return (n*(n+1))/2;
    };
    i64 tot=g(b)-g(a-1);
    i64 imp=y*y-x*x;
    cout<<imp<<LN;
}
auto main()->signed{
    cin.tie(nullptr)->sync_with_stdio(0);
    cin.exceptions(std::ios::failbit | std::ios::badbit);
    cout.tie(nullptr)->sync_with_stdio(0);
    i32 t=1; 
    cin>>t;
    for(;t--;) solve();
    return 0;
}
