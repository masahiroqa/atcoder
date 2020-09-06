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
  ull N;
  cin >> N;
  ull A[N];
  ull sm, a2, sum_mod, a, ans;
  sm = a2 = sum_mod = a = 0;
  for(ull i=0;i<N;i++){
    cin >> A[i];
    sm += A[i];
    a2 += A[i] * A[i];
  }
  // printf("%llu %llu\n", sm, a2);
  a = pow(sm , 2);
  ans = ((a-a2) / 2) % (ull)(pow(10,9)+7);
  printf("%llu\n", ans);
  return 0;
}
