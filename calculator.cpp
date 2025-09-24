// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.
//  Функция ReadNumber, которая будет читать число и выводить сообщение об ошибке в std::cerr в случае неудачи.
//  Функция RunCalculatorCycle, которая будет содержать всю логику калькулятора.
#include "calculator.h"
#include <iostream>

using Number = double;

// Возвращает true, если удалось прочитать число
// и сохранить его в Number.

bool ReadNumber(Number& result){

    Number n;
    std::cin >> n;

    if (std::cin.good()){
        result = n;
        return true;
    } else {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
}

bool DoOperation(Number& cur_sum, Number& left, Number& right, Number& saved, bool& checked){

    char operation;
    std::cin >> operation;

    if (operation == '=') {
        cur_sum += left;
        left=0;
        std::cout << cur_sum << std::endl;
    } else if (operation == '+') {
        cur_sum += left;
        left = right;
    } else if (operation == '-') {
        cur_sum += left;
        left = -right;
    } else if (operation == '*') {
        left *= right;
    } else if (operation == '/') {
        left /= right;
    } else if (operation == 'c'){
        saved=0;
    } else if (operation =='q'){
        checked = false;
    } else if (operation =='s'){
        saved = cur_sum;
    } else if (operation =='l'){
        cur_sum = saved;
    } else if (operation ==':'){
        std::cin >> cur_sum;
    } else {
        std::cerr << "Error: Unknown token " << operation << std::endl;
        return false;
    }
    return true;
}



// Возвращает true, если работа завершилась штатно
// командой q. Если из-за ошибки, возвращает false.
bool RunCalculatorCycle (){

    Number saved=0;
    Number cur_sum = 0;
    Number left=0, right=0;

    bool checked = true;
    char cmd;

    ReadNumber(left);

    while (checked) {
        DoOperation(cur_sum,left,right,saved, checked);
        ReadNumber(right);
    }

    return true;
}
