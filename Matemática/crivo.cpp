
// Crivo de Erástones

// Acha todos os primos ate certo numero (lim)

// Complexidade - O(n*log(log(n)))

int lim;
vector<bool> is_prime;

void crivo(){
  is_prime.resize(lim+1, 1);
  is_prime[0] = is_prime[1] = 0;

  for(int i=2; i<=lim; i++){
    if(is_prime[i]){
      for(int j=i*i; j<=lim; j+=i){
        is_prime[j] = 0;
      }
    }
  }

}
