#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int a = 4;
int b = 3;
int c = 2;

string getASCIIArt() {
    return R"(
     _______   _       _       __   __
    |__   __| (_)     | |      \ \ / /
       | |_ __ _ _ __ | | ___   \ V / 
       | | '__| | '_ \| |/ _ \   > <  
       | | |  | | |_) | |  __/  / . \ 
       |_|_|  |_| .__/|_|\___| /_/ \_\
                | |                   
                |_|                   
    )";
}

bool checkGuess(int guess, int correctSum, int correctProduct) {
    int temp = guess;
    int number = 0;
    int sum = 0;
    int product = 1;
    
    while (temp != 0) {
        number = temp % 10; // Получаем нижний разряд числа
        sum += number;
        product *= number;
        temp /= 10; // Сдвигаем число на один разряд вправо
    }

    if (sum == correctSum && product == correctProduct) return true;
    return false;
}

void promptDetails(int level, int numbersAmount, int sum, int product) {
    cout << "Уровень: " << level << " из 20" << endl;
    cout << "Введите секретный код чтобы завершить уровень." << endl;
    cout << "+ Код состоит из " << numbersAmount << " целых чисел" << endl;
    cout << "+ Произведение всех чисел должно быть равным " << product << endl;
    cout << "+ Сумма всех чисел должна быть равна " << sum << endl;
    cout << endl;
    cout << "Код: ";
}

int main() {
    int currentLevel = 1;
    int maxLevel = 20;
    int numbersAmount = 2;

    int sum = 0;
    int product = 0;

    int playerGuess = 0;

    cout << getASCIIArt() << endl;
    
    while (currentLevel <= maxLevel) {
        cout << endl;
        promptDetails(currentLevel, numbersAmount, sum, product);
        
        cin.clear();
        cin.ignore();
        cin >> playerGuess;

        if (checkGuess(playerGuess, sum, product)) cout << "Верно" << endl;
        else {
            cout << "Неверно" << endl;
            continue;
        }
        ++currentLevel;
    }

    cout << "\nВы прошли все уровни!" << endl; 
    return 0;
}            
