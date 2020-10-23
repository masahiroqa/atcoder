#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>


using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

#include <iostream>
#include <algorithm>

using namespace std;

using ll =  long long;

int main() {
    ll n, u, v;
    cin >> n;
    ll ans = (n * (n+1) * (2*n+1) / 6 + n * (n+1) / 2) / 2;
    for(int i=0;i<n-1;++i) {
        cin >> u >> v;
        ans -= min(u, v) * (n - max(u, v) + 1);
    }
    cout << ans << endl;
}
