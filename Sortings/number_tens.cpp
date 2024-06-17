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

auto solve()->void{
    i32 n; cin>>n; 
    i32 d=n%100;
    cout<<d/10<<LN;
}
auto main()->signed{
    cin.tie(nullptr)->sync_with_stdio(0);
    cin.exceptions(std::ios::failbit | std::ios::badbit);
    cout.tie(nullptr)->sync_with_stdio(0);
    i32 t=1; 
    //cin>>t;
    for(;t--;) solve();
    return 0;
}
