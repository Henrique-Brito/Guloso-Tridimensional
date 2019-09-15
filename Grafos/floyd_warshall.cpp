
// Floyd-Warshall

// Calcula o caminho mínimo para todos os pares de vértices em um grafo não direcionado

// Complexidade - O(n^3)

// Antes da k-ésima iteração, já foi calculado o
// caminho minímo de todos os pares utilizando apenas
// os vértices {1, 2, ..., k-1} como vértices internos  

for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}
