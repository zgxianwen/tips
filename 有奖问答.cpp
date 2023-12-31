#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;

/**
 * 求出[l, r] 之前能被k整除的数的个数
 */

int main() {
    IOS;
    int l, r, k;
    cin >> l >> r >> k;
    cout << r / k - (l - 1) / k << "\n";
    return 0;
}