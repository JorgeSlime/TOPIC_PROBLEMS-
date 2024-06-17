//THINK ONCE, CODE TWICE
#include "bits/stdc++.h"
#define LN '\n'
using namespace std;
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

const int blockSize=450;
struct Query {
    int l , r , idx;
    bool operator < (Query &o) const {
        return make_pair(l / blockSize, r) < make_pair(o.l / blockSize, o.r);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Query q1={2,7,0};
    Query q2={4,9,1};
    vector<Query> v;
    v.emplace_back(q2);
    v.emplace_back(q1);
    if(q1<q2) cout<<q1.l<<" "<<q1.r<<LN;
    else cout<<q2.l<<" "<<q2.r<<LN;
    for(auto [a,b,c]:v){
        cout<<a<<" "<<b<<LN;
    }
    return 0;
}
