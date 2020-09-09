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

vector<long long>enum_divisors(long long N){
  vector<long long> res;
  for(long long i=1;i*i<N;i++){
    if(N % i == 0){
      res.push_back(i);
      if(N / i != i) res.push_back(N/i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main(void)
{
  long long N;
  cin >> N;
  const auto &res = enum_divisors(N);
  for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
  cout << endl;
  return 0;
}
