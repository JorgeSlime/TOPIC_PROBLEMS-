#include <bits/stdc++.h>
#define LN '\n'
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

template <class T>
constexpr T INF = numeric_limits<T>::max();

struct STree {
    int T[N << 1];
    
    void modify(int n) {
        T[n] = min(T[n << 1], T[n*2+1]);
    }
    
    void init(const vector<int> &a, int n, int L, int R) {
        if (L == R) {
            T[n] = a[L];
            return;
        }
        int M = (L + R) >> 1;
        int x = n << 1;
        init(a, x, L, M);
        init(a, x | 1, M + 1, R);
        modify(n);
    }
    
    void update(int n, int L, int R, int I, int val) {
        if (L == R) {
            T[n] = val;
            return;
        }
        int M = (L + R) >> 1;
        int x = n << 1;
        if (I <= M)
            update(x, L, M, I, val);
        else
            update(x + 1, M + 1, R, I, val); // Aquí está el cambio
        modify(n);
    }
    
    int get(int i, int L, int R, int u, int v) {
        if (L > v || R < u)
            return INF<int>;
        if (L >= u && R <= v)
            return T[i];
        int mid = (L + R) >> 1;
        int Left = get(i << 1, L, mid, u, v);
        int Right = get(i << 1 | 1, mid + 1, R, u, v);
        return min(Left, Right);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    STree T;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        T.update(1,0,n-1,i,a[i]);
    }
    for(int i=0;i<n<<1;i++){
        cout<<T.T[i]<<" ";
    }
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int i, v;
            cin >> i >> v;
            i--;
            T.update(1, 0, n-1, i, v);
        }
        if (x == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            cout << (T.get(1, 0, n-1, l, r)) << LN;
        }
    }
    cout<<LN;
    for(int i=0;i<n<<1;i++){
        cout<<T.T[i]<<" ";
    }
    return 0;
}

