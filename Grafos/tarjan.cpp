
// Tarjan

// Acha todos os componentes fortemente conexos de um grafo

// Complexidade - O(n+m)

int n, m, p=0;
vector<int> g[MAX];
stack<int> s;
vector<int> visited(MAX, 0);
int id[MAX], comp[MAX];

int tarjan( int v ){

  int low = p++;
  id[v] = low;
  visited[v] = 1;

  s.push(v);

  for( int e : g[v] ){
    if( !visited[e] ){
      low = min(low, tarjan(e));
    }else if( visited[e] == 1 ){
      low = min(low, id[e]);
    }
  }

  if( low == id[v] ){
    while(1){
      int u = s.top();
      s.pop();
      visited[u] = 2;
      comp[u] = v;
      if( u == v ){
        break;
      }
    }
  }

  return low;
}
