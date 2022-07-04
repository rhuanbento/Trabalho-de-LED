//Diego de Souza Camillo e Rhuan Bento Fabiano

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(){
    ifstream arquivo;
    string leitura;
    vector<int> lab;
    int tam, c = 0;

    arquivo.open("labirinto.txt");
    
    while(getline(arquivo, leitura)){
        tam = leitura.size();
    }

    arquivo.close();

    arquivo.open("labirinto.txt");

    int matriz[tam][tam], i = 0;

    while(getline(arquivo, leitura)){
            for(int j = 0; j < leitura.size(); j++){
                if(leitura[j] == '#'){
                    matriz[i][j] = -1;
                }
                else if(leitura[j] == '.'){
                    matriz[i][j] = 0;
                }
                
            }
        i++;
    }

    for(int lin = 0; lin < tam; lin++){
        for(int colum = 0; colum < tam; colum++){
            printf ("%2d ", matriz[lin][colum]);
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;

    queue<int> fila;

    matriz[1][1] = 1;

    fila.push(1);

    while(!fila.empty()){

        for(int lin = 0; lin < tam; lin++){
             for(int colum = 0; colum < tam; colum++){
                if(matriz[lin][colum] == fila.front()){

                    if(matriz[lin + 1][colum] == 0){
                            matriz[lin + 1][colum] = matriz[lin][colum]+1;
                            fila.push(matriz[lin + 1][colum]);
                    }
                    if(matriz[lin - 1][colum] == 0){
                            matriz[lin - 1][colum] = matriz[lin][colum] + 1;
                            fila.push(matriz[lin - 1][colum]);
                    }
                    if(matriz[lin][colum + 1] == 0){
                            matriz[lin][colum + 1] = matriz[lin][colum] + 1;
                            fila.push(matriz[lin][colum + 1]);
                    }
                    if(matriz[lin][colum - 1] == 0){
                            matriz[lin][colum - 1] = matriz[lin][colum] + 1;
                            fila.push(matriz[lin][colum - 1]);
                    }
                    
                    fila.pop();   
                }
              
            }
       
        }

    }

    for(int lin = 0; lin < tam; lin++){
        for(int colum = 0; colum < tam; colum++){
            printf ("%3d ", matriz[lin][colum]);
        }
        cout << endl;
    }
     
    return 0;
}