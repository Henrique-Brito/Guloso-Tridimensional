
// Centroid decomposition

// Complexidade - O(n*log(n))

const int MAX = (int)1e5+10;
int n;
vector<int> g[MAX];
int pai[MAX];
int sizet[MAX];
bool rev[MAX];
int lvl[MAX];

int centroid( int u, int p, int size ){
  for( int e : g[u] ) if( e!=p and !rev[e] ){
    if( sizet[e] > size/2 ){
      return centroid(e, u, size);
    }
  }
  return u;
}
int get_size( int u, int p ){
  sizet[u] = 1;
  for( int e : g[u] ) if( e!=p and !rev[e] ){
    sizet[u] += get_size(e, u);
  }
  return sizet[u];
}
void decomp( int u, int p ){
  get_size(u, u);
  int c = centroid(u, u, sizet[u]);
  rev[c] = true;
  if( u==p ){
    pai[c] = c;
  }else{
    pai[c] = p;
  }
  for( int e : g[c] ) if( !rev[e] ){
    decomp(e, c);
  }
}

int get_lvl( int u ){
  if( lvl[u] != -1 ){
    return lvl[u];
  }
  if( pai[u] == u ){
    return lvl[u] = 0;
  }
  return lvl[u] = get_lvl(pai[u])+1;
}

void build_centroid(){
  for( int i=0; i<n; i++ ){
    rev[i] = 0;
    lvl[i] = -1;
  }
  decomp(0, 0);
  for( int i=0; i<n; i++ ){
    get_lvl(i);
  }
}
