#include<bits/stdc++.h>
using namespace std;
//DEBUGGER ULTRA PREMIUM XD
//==============================================
//=====================================================================

typedef long long ll;
typedef vector<int> vi;
const int blockSize = 450 , N = 2e5 + 1;
struct Query {
    int l , r , idx;
    bool operator < (Query &o) const {
        return make_pair(l / blockSize, r) < make_pair(o.l / blockSize, o.r);
    }
};
 
vi v(N);
vector<Query> queries(N);
vector<int> answer(N);
int cnt = 0;
int fr[N];
void add(ll idx) {
    if (v[idx] >= N) return;
    if (fr[v[idx]] == v[idx]) cnt--;
    fr[v[idx]] ++;
    if (fr[v[idx]] == v[idx]) cnt++;
}
void remove(ll idx) {
    if (v[idx] >= N) return;
    if (fr[v[idx]] == v[idx]) cnt--;
    fr[v[idx]]--;
    if (fr[v[idx]] == v[idx]) cnt++;
}
void mo() {
    answer = vi(queries.size());
    sort(queries.begin(), queries.end());
    int currL = 0 , currR = -1;
    for (auto q : queries) {
        while(currL > q.l) currL--, add(currL);
        while(currR < q.r) currR++, add(currR);
        while(currL < q.l) remove(currL), currL++;
        while(currR > q.r) remove(currR), currR--;
        answer[q.idx] = cnt;
    }
}
 
 
void code() {
    int n , q;
    cin >> n >> q;
 
    for (int i = 0 ; i < n ; i++) cin >> v[i];
    for (int i = 0 ; i < q ; i++) {
        int l , r;
        cin >> l >> r;
        l--; r--;
        queries[i].l = l;
        queries[i].r = r;
        queries[i].idx = i;
    }
    for(auto &&[a,b,c]:queries){
        cout<<a<<" "<<b<<" "<<c<<'\n';
    }    
    mo();
    //for (int i = 0 ; i < q ; i++) cout << answer[i] << endl;

}
 
int32_t main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        code();
    }
     return 0;
}
