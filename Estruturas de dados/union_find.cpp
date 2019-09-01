
// Union Find com path compression e union by rank
// Complexidade
// Build - O(n)
// Find - O(1)
// Union - O(1)

const ll MAX = (ll)3e5 + 10;

int n, id[MAX], size[MAX];

void build(){
	for( int i=0; i<n; i++ ){
		id[i] = i;
		size[i] = 1;
	}
}

int find(int k){
	return id[k] == k ? k : id[k] = find(id[k]);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if( size[a] > size[b] ){
		swap(a, b);
	}
	id[a] = b;
	size[b] += size[a];
}
