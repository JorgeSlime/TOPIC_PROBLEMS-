//THINK ONCE, CODE TWICE
#include "bits/stdc++.h"
#define LN '\n'
using namespace std;
using ll=long long;
template <class T> constexpr T INF = 0;
template <> constexpr int INF<int> = 1'000'000'000;
template <> constexpr ll INF<ll> = ll(INF<int>) * INF<int> * 2;
template <> constexpr unsigned long long INF<unsigned long long> = INF<ll>;
template <> constexpr __int128 INF<__int128> = __int128(INF<ll>) * INF<ll>;
template <> constexpr double INF<double> = INF<ll>;
template <> constexpr long double INF<long double> = INF<ll>;
const int N=2e5+7;
int T[N<<1],n,q;
inline void init(){
    for(int i=n-1;i;i--){
        T[i]=min(T[i<<1],T[i<<1|1]);
    }
}

inline void upd(int I,int V){
    for(T[I+=n]=V;I>>=1;){
        T[I]=min(T[I<<1],T[I<<1|1]);
    }
}
inline int query(int l,int r){
    int L=INF<int>,R=INF<int>;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) L=min(L,T[l++]);
        if(r&1) R=min(R,T[--r]);
    }
    return min(L,R);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q; 
    for(int i=0;i<n;i++){
        cin>>T[n+i];
    }
    init();
   // for(int i=0;i<(n<<1)+7;i++){
   //     cout<<T[i]<<" ";
   // }
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int i, v;
            cin >> i >> v;
            i--;
            upd(i, v);
        }
        if (x == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            cout << (query(l,r)) << LN;
        }
    }
   // cout<<LN;
   // for(int i=0;i<(n<<1)+7;i++){
   //     cout<<T[i]<<" ";
   // }
    return 0;
}
