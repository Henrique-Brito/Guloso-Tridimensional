
// Complexidade - O(log min(a,b))

int mdc(int a, int b){
  if( !b ){
    return a;
  }else{
    return mdc(b, a%b);
  }
}

int mdc(int a, int b){
  while( b ){
    a = a%b;
    int aux = a;
    a = b;
    b = aux;
  }
  return b;
}
