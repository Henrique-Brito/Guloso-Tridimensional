
// Acha pontes do grafo

// Complexidade - O(n + m)

int n, timer=0;
vector<int> g[MAX];
int tin[MAX], low[MAX];
bool vist[MAX];
vector<pair<int, int> > bridges;

void dfs( int u=0, int p=0 ){
  vist[u] = true;
  low[u] = tin[u] = timer++;
  for( int e : g[u] ) if( e!=p ){
    if( vist[e] ){
      low[u] = min(low[u], tin[e]);
    }else{
      dfs(e, u);
      low[u] = min(low[u], low[e]);
      if( low[e] > tin[u] ){
        bridges.pb({u, e});
      }
    }
  }
}
