
// Kruskal - Minimum Spanning Tree

// Usando Union Find com path compression em O(log(n))

// Complexidade - O(m*(log(n)+log(m))

#define mp make_pair
#define pb push_back
#define f first
#define s second

const ll MAX = (ll)3e5 + 10;

vector<pair<int,pair<int,int> > > art;
vector<bool> mst;
int n, m, id[MAX];

void build(){
	for( int i=0; i<n; i++ ) id[i] = i;
}

int find(int k){
	return id[k] == k ? k : id[k] = find(id[k]);
}

void unite(int a, int b){
	id[find(a)] = find(b);
}

void kruskal(){

	build();
	sort(art.begin(), art.end());
	for( auto e : art ){
		if( find(e.s.f) != find(e.s.s) ){
			unite(e.s.f, e.s.s);
			mst.pb(1);
		}else{
			mst.pb(0);
		}
	}
}
