// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.

#include "calculator.h"
#include <iostream>
#include <math.h>

using Number = double;

<<<<<<< HEAD
=======

>>>>>>> 262dfad (like final)
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

<<<<<<< HEAD
bool DoOperation(Number &cur_sum, Number &left, Number &right, Number &saved,
                 bool &checked, bool &is_saved) {
=======
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
>>>>>>> 262dfad (like final)

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
<<<<<<< HEAD
        std::cin >> left;
        cur_sum = 0;
        return true;
    } else if (operation == '=') {
        cur_sum += left;
        left = 0;
=======
        RunCalculatorCycle();
        return true;
    } else if (operation == '=') {
>>>>>>> 262dfad (like final)
        std::cout << cur_sum << std::endl;
        return true;
    } else if (operation == '+') {
        checked = ReadNumber(right);

        if (checked == false) {
            return false;
        }
<<<<<<< HEAD
        cur_sum += left;
        left = right;
=======
        cur_sum += right;
>>>>>>> 262dfad (like final)
    } else if (operation == '-') {
        checked = ReadNumber(right);

        if (checked == false) {
            return false;
        }
<<<<<<< HEAD
        cur_sum += left;
        left = -right;
=======
        cur_sum -= right;
>>>>>>> 262dfad (like final)
    } else if (operation == '*') {
        char ch;
        std::cin >> ch;
        if (ch == '*') {
            is_pow = true;
<<<<<<< HEAD
        } else {
            std::cin.putback(ch);
        }

        checked = ReadNumber(right);

        if (checked == false) {
            return false;
        }

        if (is_pow) {
            left = pow(left, right);
=======
>>>>>>> 262dfad (like final)
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
<<<<<<< HEAD
        left /= right;
=======
        cur_sum /= right;
>>>>>>> 262dfad (like final)
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
<<<<<<< HEAD
    Number left = 0, right = 0;
    bool is_saved = false;
    bool checked = true;
=======
    Number right = 0;
    bool is_saved = false;
>>>>>>> 262dfad (like final)
    char cmd;
    bool checked;

    checked = ReadNumber(cur_sum);

    while (checked) {
<<<<<<< HEAD
        checked = DoOperation(cur_sum, left, right, saved, checked, is_saved);
=======
        checked = DoOperation(cur_sum, right, saved, checked, is_saved);
>>>>>>> 262dfad (like final)
    }
    return true;
}
