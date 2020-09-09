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
#include <list>


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

using Graph = std::vector<std::vector<int>　>;

void bfs(int dist[], size_t dsize, int a[], size_t a_size, int b[],
  size_t b_size, int N, int M, int fnode){
    Graph G(N);
    for(int i=0;i<M;i++){
      G[a[i]].push_back(b[i]);
      G[b[i]].push_back(a[i]);
    }
    for(int i=0;i<dsize;i++){
      dist[i] = -1;
    }
    queue<int> que;
    dist[fnode] = 0;
    que.push(fnode);
    while(!que.empty()){
      int v = que.front();
      que.pop();
      for(int nv : G[v]){
        if (dist[nv] != -1) continue;
        dist[nv] = dist[v] + 1;
        que.push(nv);
      }
    }
  }


int main(void)
{
  int N, M;
  vector<int> num;
  cin >> N >> M;
  int A[M], B[M];
  for(int i=0;i<M;i++){
    int a, b;
    cin >> a >> b;
    A[i] = a-1;
    B[i] = b-1;
    num.push_back(A[i]);
    num.push_back(B[i]);
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
  }

  int max_num=0;
  while(num.size() != 0){
    int dist[N];
    int cnt =0;
    auto itr = num.begin();
    int fnode;
    fnode = *itr;
    num.erase(itr);
    bfs(dist, N, A, M, B, M, N, M, fnode);
    for(int i=0;i<N;i++){

      if(dist[i] != -1){
        cnt++;
        for(auto itr=num.begin();itr != num.end();itr++){
          if(*itr == i){
            num.erase(itr);
            break;
          }
        }
      }
    }
    if(max_num < cnt)max_num = cnt;
  }
  printf("%d\n", max_num);

  return 0;
}
