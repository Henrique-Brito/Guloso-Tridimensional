
// Edmonds-Karp

// Resolve max flow / min cut de um grafo dirigido

// Complexidade - O( n * m^2 )

const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class EK{
	private:
  struct node{
		int v, r;
		ll c;
		node( int _v, int _r, ll _c ){
			v = _v; r = _r; c = _c;
		}
	};
	int n;
	vector< vector<node> > g;

	public:
	EK( int _n ){
	    n = _n;
	    g.resize(n);
  }

	void add_edge( int a, int b, ll c ){
		g[a].push_back(node(b, (int)g[b].size(), c));
		g[b].push_back(node(a, (int)g[a].size()-1, 0));
	}

	ll bfs( int s, int t, vector<pair<int, int> >& parent ){

		queue<pair<int, ll> > q;
		q.push({s, LINF});

		parent = vector<pair<int, int> >(n, {-1, -1});
		parent[s] = {-2, -2};

		while( q.size() ){
			int u = q.front().first;
			ll flow = q.front().second;
			q.pop();

			for( int i=0; i<(int)g[u].size(); i++ ){
				node e = g[u][i];
				if( parent[e.v].first == -1 and e.c > 0 ){
					parent[e.v] = {u, i};
					flow = min(flow, e.c);
					if( e.v == t ){
						return flow;
					}
					q.push({e.v, flow});
				}
			}
		}

		return 0;
	}

	ll max_flow( int s, int t ){
		vector<pair<int, int> > parent;
		ll flow=0, add;

		while( (add = bfs(s, t, parent)) ){
			flow += add;
			int at=t;
			while( at != s ){
				pair<int, int> p = parent[at];
				int u  = g[p.first][p.second].v;
				int id = g[p.first][p.second].r;
				g[p.first][p.second].c -= add;
				g[u][id].c += add;
				at = p.first;
			}
			parent.clear();
		}

		return flow;
	}
};
