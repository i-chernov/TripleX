#include <iostream>

using std::cout;
using std::endl;

int a = 4;
int b = 3;
int c = 2;

int sum = a + b + c;
int product = a * b * c;

int main() {
    cout << "======Triple X game!======" << endl;
    cout << "Уровень: <1>" << endl;
    cout << "Введите секретный код чтобы завершить уровень." << endl;
    cout << "+ Код состоит из <3> чисел" << endl;
    cout << "+ Произведение всех чисел должно быть равным " << product << endl;
    cout << "+ Сумма всех чисел должна быть равна " << sum << endl;
    cout << endl;
    cout << "Код: ";
    return 0;
}