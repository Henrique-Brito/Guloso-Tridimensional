#include <bits/stdc++.h>

using namespace std;

vector<int> build( string& p ){

  int n = p.size();
  vector<int> pi(n+1);

  pi[0] = -1;
  int j=0;
  for( int i=1; i<n; i++ ){
    while( j>=0 and p[i] != p[j] ){
      j = pi[j];
    }
    i++, j++;
    pi[i] = j;
  }

  return pi;
}

int match( string& p, string& t ){

  vector<int> pi = build(p);

  int n = t.size();
  int m = p.size();
  int j=0;
  for( int i=0; i<n; i++ ){
    while( j>0 and p[j] != t[i] ){
      j = pi[j];
    }
    i++, j++;
    if( j == m ){
      // j = pi[j];
      return i-j+1;
    }
  }
  return -1;
}

int main(int argc, char const *argv[]) {

  string p, t;
  cin >> p;
  cin >> t;

  cout << match(p, t) << endl;

  return 0;
}
