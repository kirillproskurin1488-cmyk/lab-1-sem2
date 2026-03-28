#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Функция для выравнивания длины строк
string alignLength(string num1, string num2) {
    int diff = abs((int)num1.length() - (int)num2.length());
    if (num1.length() < num2.length())
        num1 = string(diff, '0') + num1;
    else if (num2.length() < num1.length())
        num2 = string(diff, '0') + num2;
    return num1 + " " + num2;
}

// Сложение двоичных чисел
string addBinary(string num1, string num2) {
    string aligned = alignLength(num1, num2);
    size_t spacePos = aligned.find(' ');
    num1 = aligned.substr(0, spacePos);
    num2 = aligned.substr(spacePos + 1);

    string res = "";
    int overflow = 0;

    for (int pos = (int)num1.length() - 1; pos >= 0; --pos) {
        int digit1 = num1[pos] - '0';
        int digit2 = num2[pos] - '0';
        int total = digit1 + digit2 + overflow;

        res.insert(res.begin(), (total % 2) + '0');
        overflow = total / 2;
    }

    if (overflow) res.insert(res.begin(), '1');
    return res;
}

// Вычитание двоичных чисел
string subtractBinary(string num1, string num2) {
    string aligned = alignLength(num1, num2);
    size_t spacePos = aligned.find(' ');
    num1 = aligned.substr(0, spacePos);
    num2 = aligned.substr(spacePos + 1);

    string res = "";
    int loan = 0;

    for (int pos = (int)num1.length() - 1; pos >= 0; --pos) {
        int digit1 = num1[pos] - '0' - loan;
        int digit2 = num2[pos] - '0';

        if (digit1 < digit2) {
            res.insert(res.begin(), (digit1 + 2 - digit2) + '0');
            loan = 1;
        }
        else {
            res.insert(res.begin(), (digit1 - digit2) + '0');
            loan = 0;
        }
    }
    return res;
}

// Сложение восьмеричных чисел
string addOctal(string num1, string num2) {
    string aligned = alignLength(num1, num2);
    size_t spacePos = aligned.find(' ');
    num1 = aligned.substr(0, spacePos);
    num2 = aligned.substr(spacePos + 1);

    string res = "";
    int overflow = 0;

    for (int pos = (int)num1.length() - 1; pos >= 0; --pos) {
        int digit1 = num1[pos] - '0';
        int digit2 = num2[pos] - '0';
        int total = digit1 + digit2 + overflow;

        res.insert(res.begin(), (total % 8) + '0');
        overflow = total / 8;
    }

    if (overflow) res.insert(res.begin(), overflow + '0');
    return res;
}

// Вычитание восьмеричных чисел
string subtractOctal(string num1, string num2) {
    string aligned = alignLength(num1, num2);
    size_t spacePos = aligned.find(' ');
    num1 = aligned.substr(0, spacePos);
    num2 = aligned.substr(spacePos + 1);

    string res = "";
    int loan = 0;

    for (int pos = (int)num1.length() - 1; pos >= 0; --pos) {
        int digit1 = num1[pos] - '0' - loan;
        int digit2 = num2[pos] - '0';

        if (digit1 < digit2) {
            res.insert(res.begin(), (digit1 + 8 - digit2) + '0');
            loan = 1;
        }
        else {
            res.insert(res.begin(), (digit1 - digit2) + '0');
            loan = 0;
        }
    }
    return res;
}

// Основная программа
int main() {
    setlocale(LC_ALL, "Russian");

    bool continueWork = true;

    while (continueWork) {
        int systemChoice;
        string firstNum, secondNum;

        cout << "=== Калькулятор систем счисления ===" << endl;
        cout << "Выберите систему: 2 (двоичная) или 8 (восьмеричная): ";
        cin >> systemChoice;

        if (systemChoice == 2 || systemChoice == 8) {
            cout << (systemChoice == 2 ? "Двоичная" : "Восьмеричная") << " система счисления" << endl;
            cout << "Первое число: ";
            cin >> firstNum;
            cout << "Второе число: ";
            cin >> secondNum;

            if (systemChoice == 2) {
                cout << "\n" << firstNum << " + " << secondNum << " = " << addBinary(firstNum, secondNum) << endl;
                cout << firstNum << " - " << secondNum << " = " << subtractBinary(firstNum, secondNum) << endl;
            }
            else {
                cout << "\n" << firstNum << " + " << secondNum << " = " << addOctal(firstNum, secondNum) << endl;
                cout << firstNum << " - " << secondNum << " = " << subtractOctal(firstNum, secondNum) << endl;
            }
        }
        else {
            cout << "Неверный выбор! Доступны только 2 или 8." << endl;
        }

        cout << "\nПродолжить работу? (1 - да, 0 - нет): ";
        int repeatChoice;
        cin >> repeatChoice;
        continueWork = (repeatChoice == 1);
        cout << endl;
    }

    cout << "Завершение программы. До свидания!" << endl;
    return 0;
}