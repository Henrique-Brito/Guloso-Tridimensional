// Teste de primalidade de Miller-Rabin
// Sempre funciona para numeros ate 2^64
// Complexidade - O(log(n))

ll mul(ll x, ll y, ll mod) {
	if (!y) return 0;

	ll ret = mul(x, y >> 1, mod);
	ret = (ret + ret) % mod;
	if (y & 1) ret = (ret + x) % mod;
	return ret;
}

ll binpow(ll a, ll b, ll mod){
  a %= mod;
  ll ret = 1;
  while(b > 0){
    if(b & 1){
      ret = mul(ret, a, mod);
    }
    a = mul(a, a, mod);
    b = b >> 1;
  }
  return ret;
}

bool composite( ll n, int a, ll d, int r ){
  ll x = binpow(a, d, n);
  if( x == 1 or x == n-1 ){
    return false;
  }
  for( int i=1; i<r; i++ ){
    x = mul(x, x, n);
    if( x == n-1 ){
      return false;
    }
  }
  return true;
}



bool miller_rabin(ll n){

  if( n <= 1 ){
    return false;
  }
  if( n == 2 or n == 3 ){
    return true;
  }
  if( (n&1) == 0 ){
    return false;
  }

  int r=0;
  ll d = n-1;
  while( (n&1) == 0 ){
    d = d >> 1;
  }

  for( int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37} ){
    if( n == a ){
      return true;
    }else if( composite(n, a, d, r) ){
      return false;
    }
  }
  return true;
}
