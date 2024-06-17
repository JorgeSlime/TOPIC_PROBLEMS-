//THINK ONCE, CODE TWICE   "写之前要思考"
#include <bits/stdc++.h>
using namespace std;

#define sz(x)     ((int)x.size())
#define all(x)    begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define pb              push_back
#define eb           emplace_back
#define LN                   '\n'

using ll=int64_t;
template<typename T> using V=vector<T>;
const int N=1e6+7;
V<ll> prime,T;
bool vis[N];
//Criba de Eratosthenes O(N*Log(N))
void criba(int n) {
    for (int i=2;i<n;++i) {
        if (!vis[i]) prime.emplace_back(i);
        for (int j=2;i*j<n;++j)
            vis[i * j]=1;
    }
}
//Criba Lineal O(N);
void criba_lineal(int n) {
    for (auto i = 2; i < n; ++i) {
        if (!vis[i]) prime.emplace_back(i);
        for (auto j = 0; j < prime.size () && i * prime[j] < n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for(auto &&i:prime){
        T.eb(i*i*1LL);
    }
}
void solve(){
    ll x; cin>>x; 
    cout<<(binary_search(all(T),x)?"YES":"NO")<<LN;
}
auto main()->int32_t{
    cin.tie(nullptr)->sync_with_stdio(0);
    cin.exceptions(std::ios::failbit | std::ios::badbit);
    cout.tie(nullptr)->sync_with_stdio(0);
    criba_lineal(N);
    ll t=1; 
    cin>>t;
    for(;t--;) solve();
    return 0;
}
