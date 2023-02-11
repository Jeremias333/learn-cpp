#include<iostream>

using namespace std;


int main (){
    cout << "******************************************" << endl;
    cout << "|  BEM VINDO AO PROGRAMA PARA ADIVINHAR  |" << endl;
    cout << "******************************************" << endl;

    int secrete_num = 45;

    cout << "O número secreto é: " << secrete_num << ", não conte a ninguém!" << endl;

    int choice;

    cin >> choice;

    cout << "o seu chute foi: " << choice << endl;

    if(choice == secrete_num){
        cout << "Parabéns você acertou o número secreto: " << secrete_num << endl;

    }
    else if(choice < secrete_num){
        cout << "O número secreto é maior que o número digitado" << endl;
    }
    else if(choice > secrete_num){
        cout << "O número secreto é menor que o número digitado" << endl;
    }

}