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
  int N;
  cin >> N;
  char c[N];
  int r_pos=-1, r_num=0;
  int w_pos=-1;
  for(int i=0;i<N;i++){
    cin >> c[i];
    if(c[i] == 'R'){
      r_pos=i;
      r_num++;
    }
    else if(c[i] == 'W')w_pos=i;
    // printf("%c, %d %d\n", c[i], r_pos, w_pos);
  }
  if(r_pos == -1 or w_pos == -1)printf("%d\n", 0);
  else{
    int cnt = 0;
    for(int i=r_num;i < N;i++){
      if(c[i] == 'R')cnt++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
