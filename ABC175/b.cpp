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
  int N, cnt;
  cin >> N;
  vector <long long int> L(N);
  for(long long int i=0;i<N;i++){
    cin >> L[i];
  }
  sort(L.begin(), L.end());
  cnt = 0;
  for(int i=0;i<N-2;i++){
    for(int j=i+1;j<N-1;j++){
      for(int k=j+1;k<N;k++){
        if((L[i] != L[j] && L[j] != L[k]) && (L[i] + L[j] > L[k])){
          cnt++;
        }
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
