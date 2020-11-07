// Segment Tree

// Acha a soma de um segmento qualquer
// e faz o update de um elemento por vez

// Complexidade
// Build  -> O(n)
// Query  -> O(log(n))
// Update -> O(log(n))

struct seg_tree{

	int n;
	vector<ll> vec, seg;

	seg_tree(){}

	ll make_node(ll v){
		return v;
	}
	ll make_neutro(){
		return 0;
	}
	ll combina(ll a, ll b){
		return a+b;
	}

	void build(int at, int l, int r){
		if( l==r ){
			seg[at] = make_node(vec[l]);
			return;
		}
		int m = (l+r)/2;
		build(2*at, l, m);
		build(2*at +1, m+1, r);
		seg[at] = combina(seg[2*at], seg[2*at +1]);
	}

	seg_tree(int n_, vector<ll> vec_){
		n = n_;
		vec = vec_;
		seg.resize(4*n);
		build(1, 0, n-1);
	}

	ll query(int ql, int qr, int at, int l, int r){
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

	void update(int pos, int x, int at, int l, int r){
		if( l==r ){
			seg[at] = make_node(x);
			return;
		}
		int m = (l+r)/2;
		if( pos <= m ){
			update(pos, x, 2*at, l, m);
		}else{
			update(pos, x, 2*at +1, m+1, r);
		}
		seg[at] = combina(seg[2*at], seg[2*at +1]);
	}

	void update(int pos, int x){
		update(pos, x, 1, 0, n-1);
	}

};
