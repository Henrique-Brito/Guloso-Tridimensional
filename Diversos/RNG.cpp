// vector com numeros aleatorios

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
using namespace std;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int main(){
    ios::sync_with_stdio(false);

    uniform_int_distribution<int> dist {0,1}; // intervalo dos numeros gerados
    auto gen = [&dist]() { return dist(rng); };

    vector<int> X(10);
    generate(X.begin(), X.end(), gen);

    for(int x : X) cout << x << ' ';
    cout << '\n';

    return 0;
}
