//THINK ONCE, CODE TWICE
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
//DEBUGGER ULTRA PREMIUM XD
//==============================================
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(std::cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define deb(...) debug()<<imie(__VA_ARGS__)
inline void uwu(int x){cin>>x;}
//=====================================================================

void solve(){
    int n,x; cin>>n>>x; 
    V<int> v(n,0); 
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll ans=0,sum=v[1];
    for(int l=0,r=1;l<=r&&r<=n;){
        if(sum<=x){
            if(sum==x){
                ans++;
            }
            sum+=v[++r];
        }
        if(l==r||l>n) break;
        if(sum>x) sum-=v[l++];
        debug()<<imie(l)<<imie(r);
        deb(sum);
    }
    cout<<ans<<LN;
}
auto main()->int32_t{
    cin.tie(nullptr)->sync_with_stdio(0);
    cin.exceptions(std::ios::failbit | std::ios::badbit);
    cout.tie(nullptr)->sync_with_stdio(0);
    ll t=1; 
    //cin>>t;
    for(;t--;) solve();
    return 0;
}
