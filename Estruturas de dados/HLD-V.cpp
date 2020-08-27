
// Heavy-Light Decomposition - vertice
//
// SegTree de soma
// query / update de soma dos vertices
//
// Complexidades:
// build - O(n)
// query_path - O(log^2 (n))
// update_path - O(log^2 (n))
// query_subtree - O(log(n))
// update_subtree - O(log(n))
// lca - O(log(n))

struct SegTree{

	int n;
	vector<int> v;
	vector<ll> lazy, seg;

	SegTree(){}

	ll make_node(int x){
		return x;
	}
	ll make_neutro(){
		return 0;
	}
	ll combina(ll a, ll b){
		return a+b;
	}

	void build(int at, int l, int r){
		lazy[at]=0;
		if( l==r ){
			seg[at] = make_node(v[l]);
			return;
		}
		int m = (l+r)/2;
		build(2*at, l, m);
		build(2*at +1, m+1, r);
		seg[at] = combina(seg[2*at], seg[2*at +1]);
	}

	void build(){
		build(1, 0, n-1);
	}

	SegTree( int _n, vector<int> _v ) : n(_n), v(_v){
		lazy.resize(4*n +10);
		seg.resize(4*n +10);
		build();
	}

	void propaga(int at, int l, int r){
		seg[at] += lazy[at]*(r-l+1);
		if(l != r){
			lazy[2*at] += lazy[at];
			lazy[2*at+1] += lazy[at];
		}
		lazy[at] = 0;
	}

	ll query(int ql, int qr, int at, int l, int r){
		propaga(at, l, r);
		if( l>r || ql>r || qr<l ){
			return make_neutro();
		}
		if( ql<=l && r<=qr ){
			return seg[at];
		}
		int m = (l+r)/2;
		return combina(query(ql, qr, 2*at, l, m), query(ql, qr, 2*at +1, m+1, r));
	}

	ll query(int ql, int qr){
		return query(ql, qr, 1, 0, n-1);
	}

	void update(int ul, int ur, int x, int at, int l, int r){
		propaga(at, l, r);
		if( l>r || ul>r || ur<l ){
			return;
		}
		if( ul<=l and r<=ur ){
			lazy[at] += x;
			propaga(at, l, r);
			return;
		}
		int m = (l+r)/2;
		update(ul, ur, x, 2*at, l, m);
		update(ul, ur, x, 2*at +1, m+1, r);
		seg[at] = combina(seg[2*at], seg[2*at +1]);
	}

	void update(int ul, int ur, int x){
		update(ul, ur, x, 1, 0, n-1);
	}
};

struct HLD{

	int n, root, t;
	vector<vector<int>> g;
	vector<int> w, sz, pos, parent, head;
	vector<int> v;

	SegTree seg;

	HLD(){}

	int get_size( int u, int p=-1 ){

		sz[u] = 1;
		for( int& e : g[u] ){
			if( e == p ) continue;
			sz[u] += get_size(e, u);
			if( sz[e] > sz[g[u][0]] or g[u][0] == p ) swap(e, g[u][0]);
		}
		return sz[u];
	}

	void build( int u, int p=-1 ){

		pos[u] = t++;
		v[pos[u]] = w[u];

		for( int e : g[u] ){
			if( e == p ) continue;
			parent[e] = u;
			head[e] = (e == g[u][0] ? head[u] : e);
			build(e, u);
		}
	}

	HLD(int _n, vector<vector<int>> _g, vector<int> _w) : n(_n), g(_g), w(_w){
		t=0;
		root=0;
		v.resize(n);
		sz.resize(n);
		pos.resize(n);
		parent.resize(n);
		head.resize(n);

		head[root] = root;
		get_size(root);
		build(root);

		seg = SegTree(n, v);
	}

	ll query_path(int a, int b){
		if( pos[a] < pos[b] ) swap(a, b);

		if( head[a] == head[b] ){
			return seg.query(pos[b], pos[a]);
		}
		return seg.query(pos[head[a]], pos[a]) + query_path(parent[head[a]], b);
	}

	void update_path(int a, int b, int x){
		if( pos[a] < pos[b] ) swap(a, b);

		if( head[a] == head[b] ){
			seg.update(pos[b], pos[a], x);
			return;
		}
		seg.update(pos[head[a]], pos[a], x);
		update_path(parent[head[a]], b, x);
	}

	int lca( int a, int b ){
		if( pos[a] < pos[b] ) swap(a, b);
		if( head[a] == head[b] ) return b;
		return lca(parent[head[a]], b);
	}

	ll query_subtree(int u){
		return seg.query(pos[u], pos[u]+sz[u]-1);
	}

	void update_subtree(int u, int x){
		seg.update(pos[u], pos[u]+sz[u]-1, x);
	}
};

