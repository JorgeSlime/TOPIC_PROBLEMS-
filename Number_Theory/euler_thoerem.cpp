//SIRVA CALCUALR EL ÚLTIMO DIGITO DE a^b
//THINK ONCE, CODE TWICE   "写之前要思考"
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
template<typename T>
T binpow(T a, T b, T m) {
    a %= m;
    T res = 1;
    while (b > 0) {
        if (b & 1) res=res*a%m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
const int N=10;
void solve(){
    int a,b; cin>>a>>b; 
    if(__gcd(a,b)!=1){ //como el gcd no es 1 es decir que no son coprimos
        cout<<(binpow(a,b,N))<<LN;
        return;
    }
    int phi=4;// totiente de euler dado que es la formula de la descomposision en factores primos 
    //reducimos exponte haciendo b = phi mod 
    int r=b%phi;
    if(r==0&&b>=phi) r=phi;
    cout<<binpow(a,r,N)<<LN;
}
int main(){turbo_PA;
    ll TT=1; 
    cin>>TT;
    for(;TT--;) solve();
    return 0;
}

