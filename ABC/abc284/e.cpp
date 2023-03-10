// clang-format off
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
template <class T> using V = std::vector<T>;
template <class T, class E> using P = std::pair<T, E>;
#define rep(i, n, m) for (int i = n; i < (int)(m); ++i)
#define rrep(i, n, m) for (int i = n - 1; i >= (int)(m); --i)
#define fore(i, a) for (auto &i : a)
#define veccin(x) for (auto &i : x) std::cin >> i                                                          
#define veccout(x) for (auto &i : x) std::cout << i << " "
#define all(v) v.begin(), v.end()
#define chmax(a, b) ((a) < (b) ? (a = b, true) : false)
#define chmin(a, b) ((a) > (b) ? (a = b, true) : false)
#define INF 1e9
#define LINF 1e18
#define MOD 998244353
// clang-format on
void sol() {
    // code
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    V<V<int>> g(n, V<int>(0));
    V<bool> flg(n, false);
    rep(i, 0, m) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    auto dfs = [&](auto &&self, int pos) {
        flg[pos] = true;
        cnt++;
        if (cnt == 1e6)
            return true;
        fore(v, g[pos]) {
            if (flg[v])
                continue;
            if (self(self, v))
                return true;
        }
        flg[pos] = false;
        return false;
    };
    dfs(dfs, 0);
    cout << cnt << endl;
    return 0;
}