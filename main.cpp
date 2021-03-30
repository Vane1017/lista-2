#include <iostream>
#include <math.h>
#include <limits>
#include <stack>

using namespace std;

// questão 1 - Implementar o algoritmo Bubble Sort
// recebe como entrada uma lista e o tamanho da lista
void bubble_sort (int *lista, int n) {
    int ii, jj, aux;
    for (ii = 1; ii < n; ii++) {
        for (jj = ii; jj > 0; jj--) {
            // comparao valor com todos os valores anteriores
            if (lista[jj] < lista[jj-1]) {
                aux  = lista[jj-1];
                lista[jj-1] = lista[jj];
                lista[jj] = aux;
            }
        }
    }
}

// questão 2 - Implementar o algoritmo Selection Sort
// recebe como entrada uma lista e o tamanho da lista
void selection_sort (int *lista, int n) {
    int ii, jj, aux, indice;
    //para cada posição na lista
    for (ii = 0; ii < n; ii++) {
        // encontra  n-esimo menor valor
        indice = ii;
        for (jj = ii+1; jj < n; jj++) {
            if (lista[jj] < lista[indice]) {
                indice = jj;
            }
        }
        // coloca n-esimo menor valor na n-esima posição
        aux = lista[ii];
        lista[ii] = lista[indice];
        lista[indice] = aux;
    }
}

// questão 3 - Implementar o algoritmo SequentialSearch2 apresentado na Secao 3.2 do Capitulo 31
// recebe como entrada uma lista, o tamanho da lista e a chave de pesquisa K
int SequentialSearch2 (int *lista,int n, int K) {
    lista[n]= K;
    int ii = 0;
    while(lista[ii] != K){
        ii++;
    }
    if(ii < n){
        return ii;
    }
    else{
        return -1;
    }
}

// questão 4 - Implementar o algoritmo BruteForceStringMatch apresentado na Secao 3.2 do Capitulo 3
// recebe como entrada duas listas e os tamanhos
int BruteForceStringMatch (char *lista1,int n, char *lista2,int m) {
    int ii, jj;
    for (ii=0;ii<n-m;ii++){
        jj=0;
        while((jj<m)&&(lista2[jj]==lista1[ii+jj])){
            jj++;
        }
        if(jj==m){
            return ii;
        }
    }
    return -1;
}

//questão 5 - Implementar o algoritmo BruteForceClosestPair apresentado na Secao 3.2 do Capitulo 3
// recebe como entrada uma lista de pontos e o número de pontos
double BruteForceClosestPair(int lista[100][2], int n) {
    int ii, jj;
    double d = std::numeric_limits<double>::infinity();
    for (ii=1;ii<n-1;ii++){
        for (jj=ii+1;jj<n;jj++){
            d = min(d,sqrt(pow((lista[ii][0]-lista[jj][0]),2)+pow((lista[ii][1]-lista[jj][1]),2)));
        }
    }
    return d;
}


//questão 6 - Implementar um algoritmo que dado um conjunto de pontos S calcule sua casca convexa (convexhull)
// recebe como entrada uma lista de pontos, número de pontos e a lista de pontos de saida
int convexHull(int lista[100][2], int n, int pontos_casca[100][2]) {

    int a,b,c,jj,ii,kk,pp,aux,ladoa,ladob,casca,existe_igual, zz = 0;
    for (ii=0;ii<n-1;ii++){
        for (jj=ii+1;jj<n;jj++){
            // calcula plano entre os pontos
            a = lista[ii][1] - lista[jj][1];
            b = lista[jj][0] - lista[ii][0];
            c = lista[jj][0] * lista[ii][1] - lista[jj][1] * lista[ii][0];
            ladoa = 0;
            ladob = 0;
            casca = 1;
            // verificar se separa todos os outros pontos
            for (kk=0;kk<n;kk++){
                aux = a * lista[kk][0] + b * lista[kk][1] - c;
                if(aux > 0){
                    ladoa = 1;
                }
                else if(aux < 0){
                    ladob = 1;
                }

                if ((ladoa == 1)&&(ladob == 1)){
                    casca = 0;
                    break;
                }
            }
            if(casca == 1){
                existe_igual=0;
                for (pp=0;pp<zz;pp++){
                    if((pontos_casca[pp][0] == lista[ii][0])&&
                        (pontos_casca[pp][1] == lista[ii][1])){
                            existe_igual = 1;
                            break;
                        }
                }
                if(existe_igual == 0){
                    pontos_casca[zz][0] = lista[ii][0];
                    pontos_casca[zz][1] = lista[ii][1];
                    zz++;
                }

                existe_igual=0;
                for (pp=0;pp<zz;pp++){
                    if((pontos_casca[pp][0] == lista[jj][0])&&
                        (pontos_casca[pp][1] == lista[jj][1])){
                            existe_igual = 1;
                            break;
                        }
                }
                if(existe_igual == 0){
                    pontos_casca[zz][0] = lista[jj][0];
                    pontos_casca[zz][1] = lista[jj][1];
                    zz++;
                }
            }

        }
    }
    return zz;

}

void addEdge(int ii, int jj, int matrizAdjacencias[100][100])
{
    matrizAdjacencias[ii][jj] = 1; // add edge a lista
    matrizAdjacencias[jj][ii] = 1; // add edge a lista
}

int dfs_recursive(int v, int contador,int matrizAdjacencias[100][100], int visitados[100], int numVertices){
    int ii;

    contador++;
    visitados[v] = contador;

    for(ii=0;ii<numVertices;ii++){
        if((visitados[ii] == 0)&&
           (matrizAdjacencias[v][ii] == 1)){
            contador = dfs_recursive(ii, contador, matrizAdjacencias, visitados, numVertices);
        }
    }
    return contador;
}
//questão 9 - Implemente o algoritmo de busca em largura
void DFS(int matrizAdjacencias[100][100], int numVertices){
    int visitados[numVertices] = {0}, ii;
    int contador =0;
    for(ii=0;ii<numVertices;ii++){
        if(visitados[ii] == 0){
            contador = dfs_recursive(ii, contador, matrizAdjacencias, visitados, numVertices);
        }
    }
    for(ii=0;ii<numVertices;ii++){
        cout << ii << " - " << visitados[ii] << endl;
    }
}



int bfs_recursive(int v, int contador,int matrizAdjacencias[100][100], int visitados[100], int numVertices){
    int ii, w;
    //initialize a queue with v
    stack<int> fila;
    fila.push(v);
    //mark v with count
    contador++;
    visitados[v] = contador;

    while (!fila.empty()) {
        w = fila.top();
        for(ii=0;ii<numVertices;ii++){
            if((visitados[w] == 0)&&
               (matrizAdjacencias[v][w] == 1)){
                contador++;
                visitados[w] = contador;
            }
        }
		fila.pop();
	}
	return contador;
}
//questão 10 - Implemente o algoritmo de busca em profundidade
void BFS(int matrizAdjacencias[100][100], int numVertices){
    int visitados[numVertices] = {0}, ii;
    int contador =0;
    for(ii=0;ii<numVertices;ii++){
        if(visitados[ii] == 0){
            contador = bfs_recursive(ii, contador, matrizAdjacencias, visitados, numVertices);
        }
    }
    for(ii=0;ii<numVertices;ii++){
        cout << ii << " - " << visitados[ii] << endl;
    }
}

int main(){
    int lista1[100] = {101,10,20,55,30,1,9,10,99,35};
    int tamanho_lista1 = 10;
    int ii;
    cout << "1 - Implementar o algoritmo Bubble Sort!" << endl;
    bubble_sort(lista1,tamanho_lista1);
    cout << "Lista ordenada:" << endl;
    for (ii = 0; ii < tamanho_lista1; ii++) {
        cout << lista1[ii] << endl;
    }


    int lista2[100] = {101,10,20,55,30,1,9,10,99,35};
    int tamanho_lista2 = 10;

    cout << "2 - Implementar o algoritmo Selection Sort!" << endl;
    selection_sort(lista2,tamanho_lista2);
    cout << "Lista ordenada:" << endl;
    for (ii = 0; ii < tamanho_lista2; ii++) {
        cout << lista2[ii] << endl;
    }


    int lista3[100] = {101,10,20,55,30,1,9,10,99,35};
    int tamanho_lista3 = 10;
    int K = 55;
    cout << "3 - Implementar o algoritmo SequentialSearch2!" << endl;
    int indice = SequentialSearch2(lista3,tamanho_lista3,K);
    cout << "Resultado:"<< indice << endl;


    char lista4[100] = "Ola, estou fazendo os exercicios da lista!";
    char lista5[100] = "exercicios";
    int tamanho_lista4 = 41;
    int tamanho_lista5 = 10;
    cout << "4 - Implementar o algoritmo BruteForceStringMatch!" << endl;
    indice = BruteForceStringMatch(lista4,tamanho_lista4,lista5,tamanho_lista5);
    cout << "Resultado:"<< indice << endl;


    int lista6[100][2] = {{101,17},{27,55},{30,15},{99,19},{98,37}};
    int tamanho_lista6 = 5;
    cout << "5 - Implementar o algoritmo BruteForceClosestPair!" << endl;
    double distancia = BruteForceClosestPair(lista6,tamanho_lista6);
    cout << "Resultado:"<< distancia << endl;

    int lista7[100][2] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                          {0, 0}, {1, 2}, {3, 1}, {3, 3},{2,7}};
    int tamanho_lista7 = 9;
    int pontos_casca [100][2] = {0},num_pontos=0;

    cout << "6 - Implementar um algoritmo que dado um conjunto de pontos S calcule sua casca convexa!" << endl;
    num_pontos = convexHull(lista7, tamanho_lista7,pontos_casca);
    cout << "Resultado:" << endl;
    for (ii=0;ii<num_pontos;ii++){
        cout << "(" << pontos_casca[ii][0] << ", " << pontos_casca[ii][1] <<")" << endl;
    }
    cout << "9 - Implementar o algoritmo de busca em largura!" << endl;
    int numVertices = 6;
    int matrizAdjacencias[100][100] = {0};
    //addEdge
    addEdge(0,1,matrizAdjacencias);
    addEdge(0,2,matrizAdjacencias);
    addEdge(1,3,matrizAdjacencias);
    addEdge(2,4,matrizAdjacencias);
    addEdge(2,5,matrizAdjacencias);

    DFS(matrizAdjacencias, numVertices);


    cout << "10 - Implementar o algoritmo de busca em profundidade!" << endl;
    BFS(matrizAdjacencias, numVertices);

    return 0;
}
