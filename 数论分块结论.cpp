#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n;

ll quickPower(ll base, ll exp) {
    ll res = 1;
    while(exp) {
        if(exp & 1) {
            res = res * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

ll cal(ll n, ll inv) {
    return n * (n + 1) % mod * (2 * n + 1) % mod * inv % mod;
}
// 对于常数使得式子 n/i=n/j,成立的最大的满足i<=j<=n的值为n/(n/i),即n/i所在的块的右端点为n/(n/i)
int main() {
    IOS;
    cin >> n;
    int inv = quickPower(6, mod - 2);
    // cout << "inv " << inv << "\n";
    ll ans = 0;
    for(int l = 1; l <= n; ) {
        int x = n / l, R = n / (n / l);
        ans = (ans + (cal(R, inv) - cal(l - 1, inv) + mod) % mod * x % mod) % mod;
        // ans = ((ans + L * (cal(R, inv) - cal(l - 1))) % MOD + MOD) % MOD;
        l = R + 1;
    }
    cout << ans << "\n";
    return 0;
}
