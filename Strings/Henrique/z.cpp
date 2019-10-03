#include <bits/stdc++.h>

using namespace std;

const int MAX = (int)1e5 + 10;

vector<int> get_z( string& s ){
  int n = s.size();
  int l=0, r=0;
  vector<int> z(n, 0);

  for( int i=1; i<n; i++ ){
    if( i <= r ){
      z[i] = min(r-i+1, z[i-l]);
    }
    while( i+z[i]<n and s[z[i]] == s[i+z[i]] ){
      z[i]++;
    }
    if( i+z[i]-1 > r ){
      l = i;
      r = i+z[i]-1;
    }
  }
  return z;
}

vector<int> get_burro(string& s){
  int n = s.size();
  vector<int> z(n, 0);
  for( int i=1; i<n; i++ ){
    for( int a=0, b=i; b<n and s[a]==s[b]; a++, b++ ){
      z[i]++;
    }
  }
  return z;
}

const int it=10000;
const int size=100;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char const *argv[]) {

  for( int i=0; i<it; i++ ){
    if( i%1000 == 0 ) cout << i << endl;
    string s;
    for( int j=0; j<size; j++ ){
      s.push_back( (char)((rng()%4)+'a') );
    }
    vector<int> v1 = get_z(s), v2 = get_burro(s);
    if( v1 != v2 ){
      cout << " -> " << i << endl;
      // for( char c : s ){
      //   cout << c << " ";
      // }
      // cout << endl;
      //
      // for( int e : v1 ){
      //   cout << e << " ";
      // }
      // cout << endl;
      //
      // for( int e : v2 ){
      //   cout << e << " ";
      // }
      // cout << endl;
    }
  }

  return 0;
}
