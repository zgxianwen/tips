#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    IOS;
    string str;
    int n = 3;
    while(n--) {
        getline(cin, str);
        stringstream s(str);
        int temp;
        while(s >> temp) {
            cout << temp << " ";
        }
        cout << "\n";
    }
}