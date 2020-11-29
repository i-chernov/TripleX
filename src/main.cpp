#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::srand;
using std::rand;
using std::time;

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

void getNewLevel(int level, int& sum, int& product, int& numbersAmount) {
    sum = 0;
    product = 1;
    int number = 0;

    if (level % 5 == 0) ++numbersAmount;
    for (int i = 0; i < numbersAmount; i++) {
        number = 1 + (rand() % 9);
        // cout << number; // Сгенерированное число
        sum += number;
        product *= number; 
    }
    // cout << endl;
}

int main() {
    int currentLevel = 0;
    int maxLevel = 20;
    
    int numbersAmount = 2;
    int levelSum, levelProduct;
    int playerGuess = 0;
    bool nextLevel = true;

    srand(time(NULL));

    system("CHCP 65001"); // UTF-8 кодировка для windows
    system("cls"); // Очищаем консоль (Windows)
    cout << getASCIIArt() << endl;
    
    while (currentLevel < maxLevel) {
        cout << endl;
        if (nextLevel) {
            ++currentLevel;
            getNewLevel(currentLevel, levelSum, levelProduct, numbersAmount);
        }
        promptDetails(currentLevel, numbersAmount, levelSum, levelProduct);
        
        cin >> playerGuess;
        cin.clear();
        cin.ignore();
        nextLevel = checkGuess(playerGuess, levelSum, levelProduct);
        if (!nextLevel) cout << "---Неверно---" << endl;
        else system("cls");
    }

    cout << "\nОго! Вы прошли все уровни! Поздравляю:)" << endl;
    system("pause");
    return 0;
}            
