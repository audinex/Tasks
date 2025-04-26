#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class carro {
    public:

    string fabricante;
    string modelo;
    int ano;
    string placa;



carro ( string f, string m, int a, string p){
    this -> fabricante = f;
    this -> modelo = m;
    this -> ano = a;
    this -> placa = p;

}
void imprime(){
    cout << this ->fabricante;
}
};

int main(){
    carro meuCarro("wolks","nivus","2024", "AN1PH56");
    meuCarro.imprime();
    
    cout << meuCarro.modelo;
    return 0;
}