#include "bits/stdc++.h"
using namespace std;

#define LN '\n'
using i32 = int32_t;
using i64 = int64_t;
template<typename T> using V = vector<T>;
const int N = 1e5 + 7;
int n,m;
struct Node {
    int total_sum;
    int prefix_sum;
    int suffix_sum;
    int max_sum;
};

struct STree {
    Node T[4 * N];
    Node modify(Node left, Node right) {
        Node parent;
        parent.total_sum = left.total_sum + right.total_sum;
        parent.prefix_sum = max(left.prefix_sum, left.total_sum + right.prefix_sum);
        parent.suffix_sum = max(right.suffix_sum, right.total_sum + left.suffix_sum);
        parent.max_sum = max({left.max_sum, right.max_sum, left.suffix_sum + right.prefix_sum});
        return parent;
    }

    void init(const vector<int>& a, int n, int L, int R) {
        if (L == R) {
            int val = a[L] ;
            T[n] = {val, val, val, val};
            return;
        }
        int M = (L + R) >> 1;
        int x = n << 1;
        init(a, x, L, M);
        init(a, x | 1, M + 1, R);
        T[n] = modify(T[x], T[x | 1]);
    }

    void update(int n, int L, int R, int I, int val) {
        if (L == R) {
            T[n] = {val, val, val, val};
            return;
        }
        int M = (L + R) >> 1;
        int x = n << 1;
        if (I <= M) update(x, L, M, I, val);
        else update(x | 1, M + 1, R, I, val);
        T[n] = modify(T[x], T[x | 1]);
    }

    Node get(int i, int L, int R, int u, int v) {
        if (L > v || R < u) return {0, INT_MIN, INT_MIN, INT_MIN};
        if (L >= u && R <= v) return T[i];
        int mid = (L + R) >> 1;
        Node left = get(i << 1, L, mid, u, v);
        Node right = get(i << 1 | 1, mid + 1, R, u, v);
        return modify(left, right);
    }

    int get_max_subarray_sum(int l, int r) {
        Node result = get(1, 0, n - 1, l, r);
        return result.max_sum;
    }
};

auto solve() -> void {
    cin >> n;
    V<i32> v(n);
    for (i32 i = 0; i < n; i++) {
        cin >> v[i];
    }
    STree st;
    st.init(v, 1, 0, n - 1);
    i32 q; cin >> q;
    for (i32 i = 0; i < q; i++) {
            i32 l, r; cin >> l >> r;
            l--, r--;
            cout << st.get_max_subarray_sum(l, r) << LN;
    }
}

auto main() -> signed {
    cin.tie(nullptr)->sync_with_stdio(0);
    cin.exceptions(std::ios::failbit | std::ios::badbit);
    cout.tie(nullptr)->sync_with_stdio(0);
    i32 t = 1;
    //cin >> t;
    for (; t--;) solve();
    return 0;
}

