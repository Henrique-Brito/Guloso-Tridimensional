
// Exponenciaçao Binaria

// (A^B) % MOD

// Complexidade - O(log(b))

typedef long long ll;

ll binpow(ll a, ll b, ll mod){
  a %= mod;
  ll ret = 1;
  while(b > 0){
    if(b & 1){
      ret = (ret*a) % mod;
    }
    a = (a*a) % mod;
    b = b >> 1;
  }
  return ret;
}
