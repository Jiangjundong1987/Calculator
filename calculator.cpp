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
                 bool &checked, bool &is_saved) {

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
        is_saved = true;
        return true;
    } else if (operation == 'l') {
        if (!is_saved) {
            std::cout << "Error: Memory is empty" << std::endl;
        }
        cur_sum = saved;
        std::cout << cur_sum << std::endl;
        return true;
    } else if (operation == ':') {
        std::cin >> left;
        cur_sum = 0;
        return true;
    } else if (operation == '=') {
        cur_sum += left;
        left = 0;
        std::cout << cur_sum << std::endl;
        return true;
    } else if (operation == '+') {
        checked = ReadNumber(right);

        if (checked == false) {
            return false;
        }
        cur_sum += left;
        left = right;
    } else if (operation == '-') {
        checked = ReadNumber(right);

        if (checked == false) {
            return false;
        }
        cur_sum += left;
        left = -right;
    } else if (operation == '*') {
        char ch;
        std::cin >> ch;
        if (ch == '*') {
            is_pow = true;
        } else {
            std::cin.putback(ch);
        }

        checked = ReadNumber(right);

        if (checked == false) {
            return false;
        }

        if (is_pow) {
            left = pow(left, right);
        } else {
            left *= right;
        }
    } else if (operation == '/') {
        checked = ReadNumber(right);

        if (checked == false) {
            return false;
        }
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
    bool is_saved = false;
    bool checked = true;
    char cmd;

    checked = ReadNumber(left);

    while (checked) {
        checked = DoOperation(cur_sum, left, right, saved, checked, is_saved);
    }

    return true;
}
