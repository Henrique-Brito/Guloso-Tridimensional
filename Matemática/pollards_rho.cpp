
// Pollard's rho

// Fatora um numero
// Fatores nao estao ordenados

// Complexidade - O(rapidao)

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

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

ll rho(ll n) {
	if (n == 1 || miller_rabin(n)) return n;
	if (n % 2 == 0) return 2;

	while (1) {
		ll x = 2, y = 2;
		ll ciclo = 2, i = 0;

		ll c = (rng() / (double) RAND_MAX) * (n - 1) + 1;
		ll d = 1;

		while (d == 1) {
			if (++i == ciclo) ciclo *= 2, y = x;
			x = (mul(x, x, n) + c) % n;

			if (x == y) break;

			d = __gcd(abs(x - y), n);
		}

		if (x != y) return d;
	}
}

void fact(ll n, vector<ll>& v) {
	if (n == 1) return;
	if (miller_rabin(n)){
    v.pb(n);
  }
	else {
		ll d = rho(n);
		fact(d, v);
		fact(n / d, v);
	}
}
