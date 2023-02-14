#include "iostream"
#include "string"
#include "map"
#include "vector"

using namespace std;

map<char, bool> hitted;
vector<char> miss_hits;
const string SECRET_WORD = "MELANCIA";
char hit;

bool letter_exists(char hit, string SECRET_WORD){

    //for (int i = 0; i < SECRET_WORD.size(); i++){
    //    if (hit == SECRET_WORD[i]){
    //        return true;
    //    }
    //}

    for (char letter : SECRET_WORD){
        if (hit == letter){
            return true;
        }
    }
    return false;
}

bool aint_correct(string SECRET_WORD){
    for(char letter : SECRET_WORD){
        if(!hitted[letter]){
            return true;
        }
    }
    return false;
}

bool didnt_hang(){
    return miss_hits.size() < 5;
}

void print_header(){
    cout << "************************" << endl;
    cout << "**** JOGO DA FORCA *****" << endl;
    cout << "************************" << endl;
    cout << endl;
}

void print_wrong_hits(){
    cout << "Chutes errados: ";

    for (char letter : miss_hits){
        cout << letter << " ";
    }

    cout << endl;
}

void print_correct_letters(){
    for (char letter : SECRET_WORD){
        if(hitted[letter]){
            cout << letter << " ";
        }
        else {
            cout << "_ ";
        }
    }

    cout << endl;
}

void processing_hits(){
    cout << "Seu chute: ";
    cin >> hit;

    hitted[hit] = true;
    //cout << "O seu chute foi: " << hit << endl;

    if (letter_exists(hit, SECRET_WORD)){
        cout << "Você acertou! Seu chute está na palavra." << endl;
    }else{
        cout << "Você errou! Seu chute não está na palavra." << endl;
        miss_hits.push_back(hit);
    }

    cout << endl;
}

int main(){
    print_header();

    while(aint_correct(SECRET_WORD) && didnt_hang()){

        print_wrong_hits();

        print_correct_letters();

        processing_hits(); 
    }

    cout << "Game Over!" << endl;
    cout << "A palavra secreta era: " << SECRET_WORD << endl;

    if (aint_correct(SECRET_WORD)){
        cout << "Você perdeu, tente novamente!" << endl;
    }
    else{
        cout << "Parabéns você acertou!" << endl;
    }
}