
// Prefix Matrix

// Acha a soma dos elementos de um sub-retângulo da matriz

// Matriz identada em 1

// Complexidade
// Build - O(n^2)
// Query - O(1)

#define f first
#define s second
typedef pair<int,int> pii;

const int MAX = (int)1e3+10;

int n;
int m[MAX][MAX];
int pre[MAX][MAX];

void build(){
  for(int i=0; i<=n; i++ ){
      pre[i][0] = pre[0][i] = 0;
  }
  for( int i=1; i<=n; i++ ){
    for( int j=1; j<=n; j++ ){
      pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + m[i][j];
    }
  }
}

int query( pii a, pii b ){
  return pre[b.f][b.s] - pre[b.f][a.s-1] - pre[a.f-1][b.s] + pre[a.f-1][a.s-1];
}
