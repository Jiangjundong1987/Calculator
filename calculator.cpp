// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.

#include "calculator.h"
#include <iostream>
#include <math.h>

using Number = double;

bool ReadNumber(Number &result) {

    Number n;
    std::cin >> n;

    if (std::cin.good()) {
        result = n;
        return true;
    } else {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
}

bool DoOperation(Number &cur_sum, Number &left, Number &right, Number &saved,
                 bool &checked) {

    char operation;
    std::cin >> operation;
    bool is_pow = false;

    if (operation == 'q') {
        checked = false;
        return false;
    } else if (operation == 'c') {
        saved = 0;
        return true;
    } else if (operation == 's') {
        saved = cur_sum;
        return true;
    } else if (operation == 'l') {
        cur_sum = saved;
        return true;
    } else if (operation == ':') {
        std::cin >> cur_sum;
        return true;
    } else if (operation == '*') {
        char ch;
        std::cin >> ch;
        if (ch == '*') {
            is_pow = true;
        }
    } else if (operation == '=') {
        cur_sum += left;
        left = 0;
        std::cout << cur_sum << std::endl;
        return true;
    }

    checked = ReadNumber(right);

    if (operation == '+') {
        cur_sum += left;
        left = right;
    } else if (operation == '-') {
        cur_sum += left;
        left = -right;
    } else if (operation == '*') {
        if (is_pow == true) {
            left = pow(left, right);
        } else {
            left *= right;
        }
    } else if (operation == '/') {
        left /= right;
    } else if (operation == '/') {
        left /= right;
    } else {
        std::cerr << "Error: Unknown token " << operation << std::endl;
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {

    Number saved = 0;
    Number cur_sum = 0;
    Number left = 0, right = 0;

    bool checked = true;
    char cmd;

    checked = ReadNumber(left);

    while (checked) {
        checked = DoOperation(cur_sum, left, right, saved, checked);
    }

    return true;
}
