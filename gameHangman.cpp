#include "iostream"
#include "string"
#include "map"
#include "vector"
#include "fstream"
#include "ctime"
#include "cstdlib"

using namespace std;

map<char, bool> hitted;
vector<char> miss_hits;
//const string SECRET_WORD = "MELANCIA";
string secret_word = "MELANCIA";
char hit;
ifstream file;

bool letter_exists(char hit, string secret_word){

    //for (int i = 0; i < secret_word.size(); i++){
    //    if (hit == secret_word[i]){
    //        return true;
    //    }
    //}

    for (char letter : secret_word){
        if (hit == letter){
            return true;
        }
    }
    return false;
}

bool aint_correct(string secret_word){
    for(char letter : secret_word){
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
    for (char letter : secret_word){
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

    if (letter_exists(hit, secret_word)){
        cout << "Você acertou! Seu chute está na palavra." << endl;
    }else{
        cout << "Você errou! Seu chute não está na palavra." << endl;
        miss_hits.push_back(hit);
    }

    cout << endl;
}

void print_game_over(){
    cout << "Game Over!" << endl;
    cout << "A palavra secreta era: " << secret_word << endl;

    if (aint_correct(secret_word)){
        cout << "Você perdeu, tente novamente!" << endl;
    }
    else{
        cout << "Parabéns você acertou!" << endl;
    }
}

vector<string> read_file(string path="words.txt"){
    file.open(path);


    if (file.is_open()){
        int qtd_words;
        vector<string> words_of_file;

        file >> qtd_words;

        //cout << "O Arquivo possui " << qtd_words << " palavras" << endl;

        for (int i = 0; i<qtd_words; i++){
            string word_read;
            file >> word_read;
            //cout << "Na linha " << i << ": " << word_read << endl;

            words_of_file.push_back(word_read);
        }

        file.close();
        return words_of_file;
    }else{
        cout << "Não foi possível acessar o banco de palavras." << endl;
        exit(0);
    }
}

void random_word(){
    vector<string> words = read_file("words.txt");

    srand(time(NULL));
    int index_rand = rand() % words.size();

    secret_word = words[index_rand];
}

int main(){
    print_header();

    random_word();

    cout << endl;

    while(aint_correct(secret_word) && didnt_hang()){

        print_wrong_hits();

        print_correct_letters();

        processing_hits(); 
    }

    print_game_over();
}