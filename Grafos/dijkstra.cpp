
//  Dijkstra
//  Acha a menor distancia entre um vertice ate todos os outros

//  Complexidade - O(m log(n))

#define mp make_pair
#define f first
#define s second
const int INF = 0x3f3f3f3f;
const int MAX = (int)1e5+10;

vector<pair< int, int > > g[MAX];
int n, d[MAX];

void dijkstra( int v ){
  for( int i=0; i<n; i++ ){
    d[i] = INF;
  }
  d[v] = 0;

  priority_queue<pair<int, int> > q;
  q.push(mp(0, v));

  while( !q.empty() ){
    int u = q.top().s;
    int dist = -q.top().f;
    q.pop();

    if( dist > d[u] )continue;
    for( auto e : g[u] ){
      if( d[e.f] > d[u] + e.s ){
        d[e.f] = d[u] + e.s;
        q.push(mp(-d[e.f], e.f));
      }
    }
  }
}
