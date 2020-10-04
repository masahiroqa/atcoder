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
  ll X, K, D, min_cnt1, min_cnt2;
  cin >> X >> K >> D;
  min_cnt1 = X / D;
  min_cnt2 = min_cnt1+1;
  if(K % 2 == 0){//Kが偶数の場合
    if(min_cnt1 % 2 == 0){
      if(K<min_cnt1){
        cout << abs(X-K*D) << endl;
      }else{
        cout << abs(X-min_cnt1*D) << endl;
      }
    }else{
      if(K<min_cnt2){
        cout << abs(X-K*D) << endl;
      }else{
        cout << abs(X-min_cnt2*D) << endl;
      }
    }
  }else{//Kが奇数の場合
    if(min_cnt1 % 2 == 1){
      if(K<min_cnt1){
        cout << abs(X-K*D) << endl;
      }else{
        cout << abs(X-min_cnt1*D) << endl;
      }
    }else{
      if(K<min_cnt2){
        cout << abs(X-K*D) << endl;
      }else{
        cout << abs(X-min_cnt2*D) << endl;
      }
    }
  }
  return 0;
}
