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

// binary search
vector<int> a  = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

bool isOK(int index, int key){
  if(a[index] >= key) return true;
  else return false;
}

int binary_search(int key){
  int left = -1;
  int right = (int)a.size();
  while(right - left > 1){
    int mid = left + (right - left) / 2;
    if(isOK(mid, key)) right = mid;
    else left = mid;
  }
  /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
  return right;
}

int main(void)
{
  cout << binary_search(51) << endl;
  return 0;
}
