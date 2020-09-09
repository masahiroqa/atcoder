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

// bfs template
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

// bfs template end

int main(void)
{
  int N, M;
  cin >> N >>M;
  int a[M], b[M];
  for(int i=0;i<M;i++){
    cin >> a[i] >> b[i];
  }
  int dist[N];
  bfs(dist, N, a, M, b, M, N, M, 1);
  for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
  return 0;
}
