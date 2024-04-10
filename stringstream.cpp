#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;

// 假设有输入:
// 1 2 3
// 4 3
// 1 2 2 2 2
// 每一行都是独立长度的数字
// 采用如下写法

int main() {
    IOS;
    string str;
    int n = 3;
    while(n--) {
        getline(cin, str); // 遇到换行符停止输出字符串
        stringstream s(str); // 创建一个字符串流容器(可以自动消除空格)
        int temp;
        while(s >> temp) { // 将s里面的元素移出, 自动转换类型
            cout << temp << " ";
        }
        cout << "\n";
    }
}
