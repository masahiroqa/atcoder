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

// sparse_table template
/*
SparseTable(v) : vの配列で初期化する
rmq(l, r): 区間[l, r)の最小値を返す
*/

template< typename T >
struct SparseTable{
  vector< vector< T > > st;
  vector< int > lookup;
  SparseTable(const vector< T > &v){
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
      printf("%d", st[0][i]);
    }
    printf("\n");
    // それぞれの開始位置(i) から2^k (k = 1 << (i - 1))だけ離れた最小値を記録しておく
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        printf("%d(%d,%d) ", st[i][j], i, j + (1 << (i - 1)));
      }
      printf("\n");
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < lookup.size(); i++) { //i番目を満たす最大の2の冪乗
        lookup[i] = lookup[i >> 1] + 1;
    }
  }
  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return min(st[b][l], st[b][r - (1 << b)]);
  }
};


int main(void)
{
  int N, Q;
  scanf("%d", &N);
  vector< int > vs(N);
  for(int i = 0; i < N; i++) scanf("%d", &vs[i]);
  SparseTable< int > table(vs);
  scanf("%d", &Q);
  while(Q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", table.rmq(x, y + 1));
  }
  return 0;
}
