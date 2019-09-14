
//  LCA - Lowest Common Ancestor
//  Usando Binary Lifting

//  Complexidade
//    Build - O(n*log(n))
//    Query - O(log(n))

const int LOG = (int)32;
const int MAX = (int)1e3+10;

int n, t=0;
int in[MAX], out[MAX];
int dp[MAX][LOG];
vector<int> g[MAX];

void dfs( int u, int p ){
  in[u] = t++;
  for( int e : g[u] ) if( e != p ){
    dp[e][0] = u;
    dfs(e, u);
  }
  out[u] = t;
}

void build(){
  for( int i=0; i<n; i++ ){
    dp[i][0] = i;
  }
  t = 0;
  dfs(0, 0);
  for( int k=1; k<LOG; k++ ){
    for( int i=0; i<n; i++ ){
      dp[i][k] = dp[dp[i][k-1]][k-1];
    }
  }
}

bool anc( int p, int f ){
  return in[p] <= in[f] and out[f] <= out[p];
}

int lca( int u, int v ){
  if( anc(u, v) ){
    return u;
  }
  if( anc(v, u) ){
    return v;
  }
  for( int k=LOG-1; ~k; k-- ){
    if( !anc(dp[u][k], v) ){
      u = dp[u][k];
    }
  }
  return dp[u][0];
}
