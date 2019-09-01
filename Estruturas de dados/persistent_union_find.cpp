
// Union-find persistente

// Union-find com union by rank mais 2 funções

// Union e find_current
//   Complexidade - O(log(n))

// Find_time -> executa o find depois no tempo t
//   Complexidade - O(log(n))

// Roll_back -> retorna ao estado anterior
//   Complexidade - O(1)

struct persistent_dsu{

  int dsu_size, tempo, num_comp;
  vector<int> comp_size;
  vector<pii> id;
  stack<int> stk;

  persistent_dsu(int in){
    num_comp = dsu_size = in;
    tempo = 0;
    id.resize(dsu_size);
    comp_size.resize(dsu_size);
    for( int i=0; i<dsu_size; i++ ){
      id[i] = {i, tempo};
      comp_size[i] = 1;
    }
  }

	persistent_dsu() : persistent_dsu(10){}

  int find_current(int k){
  	return id[k].f == k ? k : find_current(id[k].f);
  }

  int find_time(int k, int t){
    if( t < id[k].s ) return k;
    return id[k].f == k ? k : find_time(id[k].f, t);
  }

  void roll_back(){
    if( stk.empty() ) return;
    int u = stk.top(); stk.pop();
    if( id[u].f == u ) return;
		id[u] = {u, --tempo};
  }

  void unite(int a, int b){
  	a = find_current(a);
  	b = find_current(b);
  	if( comp_size[a] > comp_size[b] ){
  		swap(a, b);
  	}
		if( a == b ){
			tempo++;
			stk.push(a);
			return;
		}
		num_comp--;
  	id[a] = {b, ++tempo};
  	comp_size[b] += comp_size[a];
    stk.push(a);
  }

	int size(){
		return num_comp;
	}

};
