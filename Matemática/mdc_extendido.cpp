
// Complexidade - O(log min(a,b))

// Acha o mdc de a e b (retorno da função)
// e os coeficientes x e y tais que:
// a*x + b*y = mdc(a, b)

int mdc_ext(int a, int b, int &x, int &y){
  int x1, y1;
  int d;
  if( a==0 ){
    x = 0;
    y = 1;
    return b;
  }
  d = mdc_ext(b%a, a, x1, y1);
  x = y1 - (b/a) *x1;
  y = x1;
  return d;
}

int inv_mod(int a, int b){
	return 1<a ? b - inv(b%a,a)*b/a : 1;
}
