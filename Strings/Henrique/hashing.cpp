
//   Complexidade
// Build - O(|s|)
// Get_hash - O(1)
//
//   P e Mod
// Sao primos positivos
//
//   P deve ser parecido ao numero de caracteres
// So letra minuscula -> 31
// Maiuscula e minuscula -> 53
// Toda a ASCII -> 257
//
//   Mod deve ser grande
// 1e9+7 ou 1e9+9
//
// Comparar somente strings do mesmo tamanho para evitar colisao
// Se continuar com colisao, fazer 2 hashs
// Probabilidade de colisao - 1/Mod

typedef long long ll;

ll h[MAX], pwr[MAX];
const ll p = 31, mod = 1e9+7;
int n; string s;

void build(){
  pwr[0] = 1;
  for( int i=1; i<n; i++ ){
    pwr[i] = pwr[i-1]*p % mod;
  }
  h[0] = s[0];
  for( int i=1; i<n; i++ ){
    h[i] = (h[i-1]*p + s[i]) % mod;
  }
}



ll get_hash(int i, int j){
  if ( i == 0 ){
    return h[j];
  }
  return (h[j] - h[i-1]*pwr[j-i+1] % mod + mod) % mod;
}
