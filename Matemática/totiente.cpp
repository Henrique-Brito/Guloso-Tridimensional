
// Funcao totiente de Euler

// Usando fatoração

// Complexidade - O(sqrt(n))

ll phi(ll n){
  ll result = n;
  for( ll i=2; i*i<=n; i++ ){
    if( n%i == 0 ){
      while( n%i == 0 ){
        n /= i;
      }
      result -= result/i;
    }
  }
  if( n>1 ){
    result -= result/n;
  }
  return result;
}
