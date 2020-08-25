
//  LCA - Lowest Common Ancestor
//  Usando Binary Lifting

//  Complexidade
//    Build - O(n*log(n))
//    lca - O(log(n))
//    dist - O(log(n))
//    anc - O(1)

struct Tree{

	int n, t, log;
	vector<vector<int>> g, dp;
	vector<int> in, out, dt;

	Tree(){}

	void get_parent( int u=0, int p=0 ){
		in[u] = t++;
  		for( int e : g[u] ){
			if( e == p ) continue;
			dp[e][0] = u;
			get_parent(e, u);
		}
		out[u] = t;
	}

	void get_dt( int u=0, int p=0, int d=0 ){
		dt[u] = d;
		for( int e : g[u] ){
			if( e == p ) continue;
			get_dt(e, u, d+1);
		}
	}

	Tree( int _n, vector<vector<int>> _g ) : n(_n), g(_g){

		t = 0;
		log = 32;
		in.resize(n);
		out.resize(n);
		dt.resize(n);

		dp = vector<vector<int>>(n, vector<int>(log));

		for( int i=0; i<n; i++ ){
			dp[i][0] = i;
		}

		get_parent();
		get_dt();

		for( int k=1; k<log; k++ ){
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

  		for( int k=log-1; k>=0; k-- ){
			if( !anc(dp[u][k], v) ){
				u = dp[u][k];
			}
		}

  		return dp[u][0];
	}

	int dist( int a, int b ){
		return dt[a]+dt[b]-2*dt[lca(a, b)];
	}
};
