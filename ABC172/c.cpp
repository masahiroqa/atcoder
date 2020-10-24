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
  ll ans, N, M ,K;
  ans = 0;
  cin >> N >> M >> K;
  ll A[N], B[M];
  ll SUM_A[N+1], SUM_B[N+1];
  SUM_A[0] = SUM_B[0] = 0;
  for(ll i=0;i<N;i++){
    SUM_A[i+1] = SUM_A[i] + A[i];
    SUM_B[i+1] = SUM_B[i] + B[i];
  }
  ll j = M;
  for(ll i=0;i<N+1;i++){
    if(SUM_A[i]>K)break;
    while((SUM_B[j] > K - SUM_A[i]) && (j>0))j--;
    ans = max(ans, i+j);
  }
  printf("%lld\n", ans);
  return 0;
}
