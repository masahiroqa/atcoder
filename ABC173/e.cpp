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

#define div_num 1000000007

int main(void)
{
  ll N, K, ans;
  int minus_flag = 0;
  ans = 1;
  cin >> N >> K;
  std::vector<ll> v;
  for(ll i=0;i<N;i++){
    ll a;
    cin >> a;
    if(a > 0)minus_flag = 1;
    v.push_back(a);
  }
  if(N == K){
    for(ll i=0;i<N;i++){
      ans = ans * v[i] % div_num;
    }
  }else{
    if((minus_flag == 0) && (K % 2 == 1)){ //数が小さい方が正解
      sort(v.begin(), v.end(), greater<ll>());
      for(ll i=0;i<K;i++){
        ans = ans * v[i] % div_num;
      }
    }else{
      sort(v.begin(), v.end(), [](ll i, ll j) -> bool {
        return abs(i) > abs(j);});
      int cnt = 0;
      for(ll i=0;i<K;i++){
        if(v[i] < 0)cnt++;
      }
      if(cnt % 2 == 0){
        for(ll i=0;i<K;i++){
          ans = ans * v[i] % div_num;
        }
      }else{
        int min_minus = -1;
        int min_plus = 1;
        for(ll i=0;i<K;i++){
          if(v[i] >= 0)min_plus = v[i];
          else{min_minus = v[i];}
        }
        int max_minus = 1;
        int max_plus = -1;
        for(ll i=K;i<N;i++){
          if(v[i] >= 0 && max_plus == -1)max_plus = v[i];
          if(v[i] < 0 && max_minus == 1)max_minus = v[i];
        }
        if(min_plus == -1){
          v.erase(std::remove(v.begin(), v.end(), min_minus), v.end());
          for(ll i=0;i<K-1;i++){
            ans = ans * v[i] % div_num;
          }
          ans = ans * max_plus % div_num;
        }else if(min_minus == 1){
          v.erase(std::remove(v.begin(), v.end(), min_plus), v.end());
          for(ll i=0;i<K-1;i++){
            ans = ans * v[i] % div_num;
          }
          ans = ans * max_minus % div_num;
        }else if(min_plus * max_plus >= min_minus * max_minus){
          v.erase(std::remove(v.begin(), v.end(), min_minus), v.end());
          for(ll i=0;i<K-1;i++){
            ans = ans * v[i] % div_num;
          }
          ans = ans * max_plus % div_num;
        }else{
          v.erase(std::remove(v.begin(), v.end(), min_plus), v.end());
          for(ll i=0;i<K-1;i++){
            ans = ans * v[i] % div_num;
          }
          ans = ans * max_minus % div_num;
        }
      }
    }
  }if(ans < 0){
    ans = div_num + ans;
  }
  cout << ans << endl;
  return 0;
}
