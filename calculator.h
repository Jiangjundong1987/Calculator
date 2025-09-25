// В этом файле объявления функций.
#include <string>
using Number = double;

bool ReadNumber(Number &result);
std::string ReadComand(std::string comand);
bool DoOperation(Number &cur_sum, Number &right, Number &saved, bool &checked, bool &is_saved);
bool RunCalculatorCycle ();
