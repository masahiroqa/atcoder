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
  string s;
  int cnt=0;
  int mx = 0;
  int flag=0;
  cin >> s;
  for(int i=0;i<3;i++){
    if(s[i] == 'R' and flag == 0){
      cnt = 1;
      flag = 1;
    }else if(s[i] == 'R' and flag == 1){
      cnt++;
    }else if(s[i] == 'S'){
      mx = max(cnt, mx);
      cnt = 0;
      flag = 0;
    }
    mx = max(cnt, mx);
  }
  printf("%d\n", mx);
  return 0;
}
