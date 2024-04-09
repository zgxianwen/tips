// 1、为什么最短路只能在正权图上使用？
// 因为保证 dijkstra算法的贪心确认了每个点只会被更新一次，如果是最短路的话正权图 dist
// 只会越来越大，所以能保证这个性质。但是对于负权图， dist不一定是单调增大的，因此这个点不能被确认已经是最终 dist最小的情况。
// 总结：最短路使用 dijkstra算法要保证边权全部为正才能保证每个点只被更新一次

// 2、对于最长路，能否使用dijkstra算法？
// 只要理解了 dijkstra算法的贪心原理，就能发现对于最长路也是可以运算的。
// 对于最短路，我们要保证边是正的递增，才能保证每次找到的最小的 dist再也不会被更新掉那么对于最长路，我们只要保证 dist
// 是越来小的，才能保证每次我们找到的最大的距离点再也不会被更新掉那么边权的加肯定是不满足的，什么是满足的？
// 本题的边权的乘积，而且是 0∼10∼1的边权，才能保证 dist越来越小。

// 那么 SPFA算法是否可以处理最长路问题？
// 答案是可以的，因为SPFA比较牛逼，因为 SPFA算法的正确性来源于松弛操作，也就是那个三角不等式迭代更新所有的边，这个操作不管正的负的乘的都可以实现，所以最长路也是照样能做的！

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;

const int N = 2000;
int n, m;
int s, t;
double g[N][N], dis[N];
bool vis[N];

void dijkstra() {
    // vis[s] = true;
    dis[s] = 1;
    for(int i = 1; i <= n; i++) {
        int v = -1;
        for(int j = 1; j <= n; j++) {
            if((v == -1 || dis[j] > dis[v]) && !vis[j]) {
                v = j;
            }
        }
        vis[v] = true;
        for(int j = 1; j <= n; j++) {
            dis[j] = max(dis[j], g[v][j] * dis[v]);
        }
    }
}

int main() {
    IOS;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = max((100 - c) * 1.0 / 100 * 1.0, g[b][a]);
        cout << g[a][b] << "\n";
    }
    
    cin >> s >> t;
    dijkstra();
    cout << fixed << setprecision(8) << 100 / dis[t] << "\n";
    
    return 0;
}
