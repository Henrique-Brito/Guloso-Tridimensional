
// Bellman-Ford

// Acha o menor caminho de um vertice a todos os outros,
// permitindo pesos negativos
// Acha ciclos negativos

// Complexidade - O( n*m )

int n, m;
vector<int> d; // Distance from v
vector<int> p; // Parent in min distance tree
vector<pair<int, pair<int, int> > > edges;
int last; // Last element updated - use to find negative cycle

bool bellman_ford( int v ){
	d = vector<int>(n, INF);
	d[v] = 0;

	p = vector<int> (n, -1);

  bool flag;
	for( int i=0; i<n; i++ ){
		flag = false;
		for( auto e : edges ){
			int a = e.s.f;
			int b = e.s.s;
			int w = e.f;
			if( d[a] < INF ){
				if( d[b] > d[a] + w ){
					flag = true;
					d[b] = d[a] + w;
					p[b] = a;
					last = b;
				}
			}
		}
		if( !flag ){
			break;
		}
	}

  return flag; // true if negative cycle exists
}
