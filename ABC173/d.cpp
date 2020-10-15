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

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

int main(void)
{
  ll N, comf, now, max_num;
  cin >> N;
  ll A[N];
  std::vector<ll> tmp;
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  sort(A, A+SIZE_OF_ARRAY(A), greater<ll>());
  comf = 0;
  if((N-1)%2 == 1){
    comf += A[0];
    for(ll i= 1;i<=(N-1)/2;i++){
      comf += A[i]*2;
    }
  }else{
    comf += A[0];
    ll j=0;
    for(j=1;j<(N-1)/2;j++){
      comf += A[j]*2;
    }
    comf += A[j];
  }
  cout << comf << endl;
  return 0;
}
