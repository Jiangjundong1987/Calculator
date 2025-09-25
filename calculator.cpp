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

std::string ReadComand(std::string comand) {

    std::string cmd;
    for (size_t i = 0; i < comand.size(); i++) {
        if (((comand[i] >= 48) && (comand[i] <= 57))) {
            break;
        } else {
            cmd.push_back(comand[i]);
        }
    }
    return cmd;
}

bool DoOperation(Number &cur_sum, Number &right, Number &saved, bool &checked,
                 bool &is_saved) {

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
        RunCalculatorCycle();
        return true;
    } else if (operation == '=') {
        std::cout << cur_sum << std::endl;
        return true;
    } else if (operation == '+') {
        checked = ReadNumber(right);

        if (checked == false) {
            return false;
        }
        cur_sum += right;
    } else if (operation == '-') {
        checked = ReadNumber(right);

        if (checked == false) {
            return false;
        }
        cur_sum -= right;
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
            cur_sum = pow(cur_sum, right);
        } else {
            cur_sum *= right;
        }
    } else if (operation == '/') {
        checked = ReadNumber(right);

        if (checked == false) {
            return false;
        }
        cur_sum /= right;
    } else {
        std::string token;
        std::cin >> token;
        std::cerr << "Error: Unknown token " << operation << ReadComand(token) << std::endl;
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {

    Number saved = 0;
    Number cur_sum = 0;
    Number right = 0;
    bool is_saved = false;
    char cmd;
    bool checked;

    checked = ReadNumber(cur_sum);

    while (checked) {
        checked = DoOperation(cur_sum, right, saved, checked, is_saved);
    }
    return true;
}
