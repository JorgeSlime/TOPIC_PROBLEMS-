//THINK ONCE, CODE TWICE
#include <bits/stdc++.h>
using namespace std;

#define sz(x)     ((int)x.size())
#define all(x)    begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define pb              push_back
#define eb           emplace_back
#define V                  vector
#define LN                   '\n'
#define turbo_PA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
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
 #define _(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 #define debu debug()
 #define deb(...) debu<<_(__VA_ARGS__)
 inline void uwu(int x){cin>>x;}
 //=====================================================================
  
void solve(){
    int n; cin>>n; 
    debu<<_(n);
}
int main(){turbo_PA;
    ll TT=1; 
    //cin>>TT;
    for(;TT--;) solve();
    return 0;
}
