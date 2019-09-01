// Topological sorting

// Ordem dos vertices em um DAG

// Complexidade - O(n+m)

int n;
vector<int> g[MAX];
vector<bool> vis(MAX, 0);
vector<int> ts;

void dfs( int at ){
	vis[at] = 1;
	for( int e : g[at] ) if( !vis[e] ){
		dfs(e);
	}
	ts.pb(at);
}

void topo_sort(){
	for( int i=0; i<n; i++ ){
		if( !vis[i] ){
			dfs(i);
		}
	}
	reverse(ts.begin(), ts.end());
}
