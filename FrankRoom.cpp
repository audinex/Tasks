#include <iostream>
using namespace std;


int main(){
    // declarando as constantes
    double taxa {3.06};
    int SmallRoom;
    int BigRoom;
    const int Bcost{30};
    const int Scost{20};

    // fazendo as perguntas sobre os quartos
    cout << "Quantos quartos grandes voce deseja" << endl;
    cin >> BigRoom;

    cout << "Quantos quartos pequenos voce deseja" << endl;
    cin >> SmallRoom;

    double Tcostb = BigRoom*taxa*Bcost;
    double Tcosts = SmallRoom*taxa*Scost;

    cout << Tcostb << "$ esse é o custo dos seus quartos grandes" << endl;
    cout << Tcosts << "$ esse é o custo dos seus quartos pequenos" << endl;

    cout <<"===================================================" << endl;

    cout << endl << Tcostb + Tcosts << "$ esse é o preço total" << endl;

    return 0;
}