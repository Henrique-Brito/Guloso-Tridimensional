
// Acha pontos de articulação

// Complexidade - O( n+m )

int n, m, timer=0;
vector<int> g[MAX];
bool vist[MAX];
int tin[MAX], low[MAX];
set<int> cut;

void dfs( int u=0, int p=-1 ){
  vist[u] = true;
  tin[u] = low[u] = timer++;
  int child=0;
  for( int e : g[u] ) if( e!=p ){
    if( vist[e] ){
      low[u] = min(low[u], tin[e]);
    }else{
      dfs(e, u);
      low[u] = min(low[u], low[e]);
      if( low[e] >= tin[u] and p!=-1 ){
        cut.insert(u);
      }
      child++;
    }
  }
  if( p==-1 and child>1 ){
    cut.insert(u);
  }
}
