//https://codeforces.com/group/OyefIGO3t4/contest/447298/problem/A 
/*
 * Author: Jorge_Slime
 * Created: 14-06-2024
 * Time: 15:43:57
*/
// THINK ONCE, CODE TWICE   "写之前要思考"
#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define eb emplace_back
#define LN '\n'

using i32 = int32_t;
using i64 = int64_t;
template<typename T> using V = vector<T>;
const int N = 1e5 + 7;
int n, m;
struct STree {
    i64 T[4 * N];
    const i64 MOD=m;
    i64 modify(int n) {
        return T[n << 1] * T[n << 1 | 1] %MOD;
    }
    void init(const vector<int>& a, int n, int L, int R) {
        if (L == R) {
            T[n] = a[L] % MOD;
            return;
        }
        int M = (L + R) >> 1;
        int x = n << 1;
        init(a, x, L, M);
        init(a, x | 1, M + 1, R);
        T[n] = modify(n);
    }
    void update(int n, int L, int R, int I, int val) {
        if (L == R) {
            T[n] = val % MOD; 
            return;
        }
        int M = (L + R) >> 1;
        int x = n << 1;
        if (I <= M) update(x, L, M, I, val);
        else update(x | 1, M + 1, R, I, val);
        T[n] = modify(n);
    }
    i64 get(int i, int L, int R, int u, int v) { // (1,rango total ,L ,R)
        if (L > v || R < u) return 1; // fuera de rango, retorno el neutro de la multiplicación
        if (L >= u && R <= v) return T[i];  // en rango
        int mid = (L + R) >> 1;
        i64 left = get(i << 1, L, mid, u, v);
        i64 right = get(i << 1 | 1, mid + 1, R, u, v);
        return left * right % MOD;
    }
};

auto solve() -> void {
    cin >> n >> m;
    V<i32> v(n);
    for (i32 i = 0; i < n; i++) {
        cin >> v[i];
    }
    STree st;
    st.init(v, 1, 0, n - 1);
    i32 q; cin >> q;
    for (i32 i = 0; i < q; i++) {
        i32 x; cin >> x;
        if (x == 0) {
            i32 I, V; cin >> I >> V;
            I--;
            st.update(1, 0, n - 1, I, V);
        }
        if (x == 1) {
            i32 l, r; cin >> l >> r;
            l--, r--;
            cout << st.get(1, 0, n - 1, l, r) << LN;
        }
    }
}

auto main() -> signed {
    cin.tie(nullptr)->sync_with_stdio(0);
    cin.exceptions(std::ios::failbit | std::ios::badbit);
    cout.tie(nullptr)->sync_with_stdio(0);
    i32 t = 1;
    // cin >> t;
    for (; t--;) solve();
    return 0;
}

