#include<iostream>

using namespace std;


int main (){
    cout << "******************************************" << endl;
    cout << "|  BEM VINDO AO PROGRAMA PARA ADIVINHAR  |" << endl;
    cout << "******************************************" << endl;

    //Vars
    const int SECRET_NUM = 45;
    int choice;
    bool aint_correct = true;
    int tries = 0;
    double points = 1000.0;
    double lost_points = 0.0;

    //while user ain't send a correct awnser
    while(aint_correct){
        tries ++;

        //Request a value to user
        cout << "Digite um número para tentar adivinhar o número secreto: ";
        cin >> choice;

        //Subtract points based in try
        lost_points = abs(choice - SECRET_NUM)/2.0;
        points -= lost_points;

        //Calculating how near is user of secret number
        cout << "o seu chute foi: " << choice << endl;
        bool correct_answer = choice == SECRET_NUM;
        bool most = choice > SECRET_NUM;
        bool least = choice < SECRET_NUM;

        cout << "Tentativas: " << tries << endl;

        if(correct_answer)
        {
            cout << "Parabéns você acertou o número secreto: " << SECRET_NUM << endl;
            aint_correct = false;
        }
        else if(least)
        {
            cout << "O número secreto é MAIOR que o número digitado" << endl;
        }
        else if(most)
        {
            cout << "O número secreto é MENOR que o número digitado" << endl;
        }
    }
    //cout << "O número secreto é: " << secrete_num << ", não conte a ninguém!" << endl;
    cout << "GAME OVER! Você acertou em " << tries << " tentativas" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuação foi de: " << points << endl;
}