
// Segment Tree

// Acha a soma de um segmento qualquer
// e faz o update in range

// Complexidade
// Build  -> O(n)
// Query  -> O(log(n))
// Update -> O(log(n))

const int MAX = (int)1e5 + 10;

namespace seg{

  int n;
  int vec[MAX];
  ll seg[4*MAX], lazy[4*MAX];

  ll make_node(int v){
    return v;
  }
  ll make_neutro(){
    return 0;
  }
  ll combina(ll a, ll b){
    return a+b;
  }

  void build(int at=1, int l=0, int r=n-1){
    lazy[at]=0;
    if( l==r ){
      seg[at] = make_node(vec[l]);
  	  return;
    }
    int m = (l+r)/2;
    build(2*at, l, m);
    build(2*at +1, m+1, r);
    seg[at] = combina(seg[2*at], seg[2*at +1]);
  }

  void propaga(int at, int l, int r){
		seg[at] += lazy[at]*(r-l+1);
		if(l != r){
      lazy[2*at] += lazy[at];
      lazy[2*at+1] += lazy[at];
    }
		lazy[at] = 0;
  }

  ll query(int ql, int qr, int at=1, int l=0, int r=n-1 ){
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

  void update(int ul, int ur, int x, int at=1, int l=0, int r=n-1){
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
}
