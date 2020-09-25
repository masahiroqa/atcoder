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


//segment tree template

const int INF=1000000000;
const int MAX_N=2097152;
int n;  // nは2のべき乗
int dat[MAX_N*2-1];

void init(){
  for(int i=0;i<2*n-1;i++)dat[i]=INF;
}

void update(int i, int x){
  i += n-1;
  dat[i] = x;
  while(i>0){
    i = (i-1) / 2;
    dat[i] = min(dat[i*2+1], dat[i*2+2]);
  }
}

int query(int a, int b, int k, int l, int r){  // [a, b)の最小値 l, rにはノードkに対応づく区間を与える
  if(r <= a || b <= l) return INF;
  if(a <= l && r <= b) return dat[k];
  else{
    int vl = query(a, b, k*2+1, l, (l+r)/2);
    int vr = query(a, b, k*2+2, (l+r)/2, r);
    return min (vl, vr);
  }
}


int main(void)
{
  printf("hello\n");
  return 0;
}
