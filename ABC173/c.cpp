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

int main(void)
{
  int H, W, K, ans, cnt;
  cin >> H >> W >> K;
  char c[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      char ci;
      cin >> ci;
      c[i][j] = ci;
    }
  }
  ans = cnt = 0;
  for(int m=0;m<pow(2, H);m++){
    for(int n=0;n<pow(2, W);n++){
      cnt = 0;
      for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
          if((((m>>i)&1)==0) && (((n>>j)&1)==0)){
            if(c[i][j] == '#')cnt++;
          }
        }
      }
      if(cnt == K)ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
