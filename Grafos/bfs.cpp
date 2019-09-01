
// BFS

// Complexidade - O(n+m)

const int MAX = (int)1e5+10;

int n;
vector<int> g[MAX];
vector<bool> v(MAX, 0);
vector<int> d(MAX, -1);

void bfs(int s){

  queue<int> q;
  d[s] = 0;
  v[s] = 1;
  q.push(s);

  while(q.size()){
    int u = q.front();
    q.pop();
    for( auto e : g[u] ){
      if( !v[e] ){
        v[e] = 1;
        d[e] = d[u]+1;
        q.push(e);
      }
    }
  }

}
