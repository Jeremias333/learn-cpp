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

int main(){
    cout << "************************" << endl;
    cout << "**** JOGO DA FORCA *****" << endl;
    cout << "************************" << endl;

    while(aint_correct(SECRET_WORD) && didnt_hang()){
        cout << "Chutes errados: ";

        for (char letter : miss_hits){
            cout << letter << " ";
        }

        cout << endl;

        for (char letter : SECRET_WORD){
            if(hitted[letter]){
                cout << letter << " ";
            }
            else {
                cout << "_ ";
            }
        }

        cout << endl;

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
}