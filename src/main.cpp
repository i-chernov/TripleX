#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int a = 4;
int b = 3;
int c = 2;

int sum = a + b + c;
int product = a * b * c;

int playerGuess = 0;

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

int main() {
    cout << "======Triple X game!======" << endl;
    cout << "Уровень: <1>" << endl;
    cout << "Введите секретный код чтобы завершить уровень." << endl;
    cout << "+ Код состоит из <3> целых чисел" << endl;
    cout << "+ Произведение всех чисел должно быть равным " << product << endl;
    cout << "+ Сумма всех чисел должна быть равна " << sum << endl;
    cout << endl;
    cout << "Код: ";

    cin >> playerGuess;
    cout << checkGuess(playerGuess, sum, product) << endl;
    return 0;
}