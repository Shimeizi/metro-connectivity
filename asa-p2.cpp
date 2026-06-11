#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

struct Vertice {
    string color;   //White = nao visitado; Grey = marcado para visitar; Black = visitado
    int d;          //mudancas de linha = distancia a start
};

bool x_y_inset(const set<int>& set, int x, int y) {
    return set.find(x) != set.end() || set.find(y) != set.end();
}

/* Esta função preenche a matriz com os valores de input para matriz */
int input_matrizes(vector<set<int>>& linhas, vector<set<int>>& ligacoes, int m, int n, int lm) {
    int x, y, l_in;
    vector<bool> pontos(n, false);
    for (int i = 0; i < m; i++) {   
        scanf("%d %d %d", &x, &y, &l_in);
        l_in --;
        linhas[l_in].insert(x);
        linhas[l_in].insert(y); //colocar ambos os valores na lista da sua linha
        for(int j = 0; j < lm; j++){
            if(j != l_in && x_y_inset(linhas[j], x, y)){
                ligacoes[j].insert(l_in);
                ligacoes[l_in].insert(j);
            }
        }
        pontos[x - 1] = true;
        pontos[y - 1] = true;
    }

    for(int i = 0; i < n; i++){
        if(pontos[i] == false){
            return -1;
        }
    }


    for (int i = 0; i < lm; i++){
        if(linhas[i].size() == (size_t)n){
            return 0;
        }
    }
    return 1;
}

void overlapping_Lines(vector<set<int>>& linhas, vector<int>& linhas_sobrepostas, int l) {
    for (int i = 0; i < l; ++i) { 
        for (int j = i + 1; j < l; ++j) { 
            if (includes(linhas[j].begin(), linhas[j].end(), linhas[i].begin(), linhas[i].end())) {
                linhas_sobrepostas.push_back(i);
                break; 
            
            }
        }
    }
}

int BFS(vector<set<int>> ligacoes, vector<int>& linhas_sobrepostas, int start, int l){
    vector<Vertice> v(l);

    //iniciar dados
    for(int i = 0; i < l; i++){
        v[i].color = "White";
        v[i].d = 0;
    }

    for(int i : linhas_sobrepostas){ //ignora as que estao sobrepostas
        v[i].color = "Black";
        v[i].d = 0;
    }


    v[start].color = "Grey";
    v[start].d = 0;  

    //fila para BFS (FIFO)
    queue<int> fila;
    fila.push(start);

    int maior_d = 0;

    //executar BFS
    //o codigo acaba quando nao ha vertice para visitar
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for (int w : ligacoes[u]) {
            if (v[w].color == "White") {
                v[w].color = "Grey"; 
                v[w].d = v[u].d + 1;
                fila.push(w);
            }
        }
        v[u].color = "Black";

        if (v[u].d > maior_d) {
            maior_d = v[u].d;
        }
    }

    for (int i = 0; i < l; i++) { //verifica se existem linhas que nao estao ligadas a outras
        if (v[i].color == "White") {
            return -1;
        }
    }

    return maior_d;
}

int max_BFS(vector<set<int>>& ligacoes, vector<int>& linhas_sobrepostas, int l){
    int max = 0; 
    int d = 0; //distancia calculada no BFS
    for(int i = 0; i < l; i++){
        d = BFS(ligacoes, linhas_sobrepostas, i, l);
        if(d > max){
            max = d;
        }
    }
    return max;
}

int main() {
    //inputs
    int n , m, l, max;
    scanf("%d %d %d", &n, &m, &l);

    vector<set<int>> linhas(l);
    vector<set<int>> ligacoes(l);
    int res = input_matrizes(linhas, ligacoes, m, n, l);

    if(res == -1 || res == 0){
        printf("%d\n", res);
        return 0;
    }

    //"limpar" linhas desnecessarias
    vector<int> linhas_sobrepostas;
    overlapping_Lines(linhas, linhas_sobrepostas, l);

    //Algoritmo
    max = max_BFS(ligacoes, linhas_sobrepostas, l);
    printf("%d\n", max);

    return 0;
}
