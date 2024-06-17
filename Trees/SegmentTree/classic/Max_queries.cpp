//THINK ONCE, CODE TWICE   "写之前要思考"
#include <bits/stdc++.h>
using namespace std;

#define sz(x)     ((int)x.size())
#define all(x)    begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define pb              push_back
#define eb           emplace_back
#define LN                   '\n'

template<typename T> using V=vector<T>;
const int N=1e5+7;
//multitype INF
using ll=long long;
template <class T> constexpr T INF = 0;
template <> constexpr int INF<int> = 1'000'000'000;
template <> constexpr ll INF<ll> = ll(INF<int>) * INF<int> * 2;
template <> constexpr unsigned long long INF<unsigned long long> = INF<ll>;
template <> constexpr __int128 INF<__int128> = __int128(INF<ll>) * INF<ll>;
template <> constexpr double INF<double> = INF<ll>;
template <> constexpr long double INF<long double> = INF<ll>;
struct node{
    ll total; 
    ll pre; 
    ll suf;
    ll mx;
};
struct STree{
    node T;
    void init(const vector<ll> &a,int n,int L,int R){
        if(L==R){
            T.T[n]=a[L];
            return;
        }
        int M=(L+R)>>1;
        int x=n<<1;
        init(a,x,L,M); 
        init(a,x|1,M+1,R);
        modify(n);
    }
    void update(int n,int L,int R,int I, ll val){
        if(L==R){
            T[n]=val;
            return;
        }
        int M=(L+R)>>1;
        int x=n<<1;
        if(I<=M) update(x,L,M,I,val);
        else update(x|1,M+1,R,I,val);
        modify(n);
    }
    int get(int i, int L, int R, int u, int v) { // (1,rango total ,L ,R)
        if (L > v || R < u) return -INF<int>; //fuera de rango
        if (L >= u && R <= v) return T[i];  //en rango 
        int mid = (L + R) >> 1;
        int left= get(i << 1, L, mid, u, v);
        int right = get(i << 1 | 1, mid + 1, R, u, v);
        return max<ll>(0,left+right);
    }
};
void solve(){
    int n; cin>>n; 
    STree ST; 
    V<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ST.init(v,1,0,n-1);
    int m; cin>>m; 
    for(int i=0;i<m;i++){
        int l,r; cin>>l>>r; 
        l--,r--;
        cout<<ST.get(1,0,n-1,l,r)<<LN;
    }
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
