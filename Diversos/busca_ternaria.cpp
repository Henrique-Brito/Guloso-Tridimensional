
// Acha max/min em uma função unimodal

// A função deve ser estritamente crescente e depois estritamente decrescente (max) ou
// estritamente decrescente e depois estritamente crescente (min)

// Complexidade - O(log(r-l))

const double eps = 1e-9;

// Com ponto flutuante - max
double ts( double l, double r ){
	while( r-l > eps ){
		double m1 = l + ((r-l)/3);
		double m2 = r - ((r-l)/3);
		double f1 = f(m1);
		double f2 = f(m2);
		if( f1 < f2 ){  // min -> f1 > f2
			l = m1;
		}else{
			r = m2;
		}
	}
	return f(l);
}

// Com inteiros - max
int ts( int l, int r ){
  while( l < r ){
    int m = (l + r)/2;
      if( f(m) > f(m+1) ) {  // min -> f(m) < f(m+1)
        r = m;
      }else{
        l = m+1;
      }
   }
   return f(l+1); // min -> f(l)
}
