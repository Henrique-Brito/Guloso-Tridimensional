
// Merge sort tree

// Quantos números <= k existem em um intervalo

// Complexidade
// Espacial - O(nlog(n))
// Build - O(nlog(n))
// Query - O(log(n)^2)

const int MAX = (int)1e5;

int n, k;
vector<int> tree[4*MAX];
int v[MAX];

void merge( vector<int>& v1, vector<int>& v2, vector<int>& ret ){
	int i=0;
	int j=0;

	while( i<v1.size() and j<v2.size() ){
		if( v1[i] < v2[j] ){
			ret.pb(v1.at(i));
			i++;
		}else{
			ret.pb(v2.at(j));
			j++;
		}
	}
	while( i<v1.size() ){
		ret.pb(v1.at(i));
		i++;
	}
	while( j<v2.size() ){
		ret.pb(v2.at(j));
		j++;
	}

}



void build(int at=1, int b=0, int e=n-1){
  if( b==e ){
		tree[at].pb(v[b]);
	  return;
  }
  int m = (b+e)/2;
  build(2*at, b, m);
  build(2*at +1, m+1, e);
  merge(tree[2*at], tree[2*at +1], tree[at]);
}

int query(int qb, int qe, int at=1, int b=0, int e=n-1){
  if( b>e || qb>e || qe<b ){
    return 0;
  }
  if( qb<=b && e<=qe ){
		return upper_bound(tree[at].begin(), tree[at].end(), k)-tree[at].begin();
  }
  int m = (b+e)/2;
  return query(qb, qe, 2*at, b, m) + query(qb, qe, 2*at +1, m+1, e);
}
