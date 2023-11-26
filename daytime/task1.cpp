#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <getopt.h>
#include <cmath>

using namespace std;

double decimalLog(vector<double> operands) {
    if (operands.size() != 1) {
        cout << "Десятичный логарифм требует только одного операнда" << endl;
        return 0;
    }
    double operand = operands[0];
    if (operand <= 0.0) {
        cout << "Недопустимый операнд для логарифма" << endl;
        return 0;
    }
    return log10(operand);
}

double naturalLog(vector<double> operands) {
    if (operands.size() != 2) {
        cout << "Натуральный логарифм требует два операнда" << endl;
        return 0;
    }
    double base = operands[0];
    double number = operands[1];
    if (base <= 0.0 || number <= 0.0 || base == 1.0) {
        cout << "Недопустимые операнды для логарифма" << endl;
        return 0;
    }
    return log(number) / log(base);
}

void printHelp() {
    cout << "Использование: калькулятор -о операция [операнды]" << endl;
    cout << "Опции:" << endl;
    cout << " -o операция устанавливает операцию (decimalLog или naturallLog)" << endl;
    cout << " -h отображает это справочное сообщение" << endl;
    cout << "Операнды:" << endl;
    cout << " Для decimalLog требуется один операнд" << endl;
    cout << " Для naturallLog требуется два операнда" << endl;
}

int main(int argc, char* argv[]) {
    int option;
    string operation;
    vector<double> operands;

    while ((option = getopt(argc, argv, "o:h")) != -1) {
        switch (option) {
            case 'o':
                operation = optarg;
                break;
            case 'h':
                printHelp();
                return 0;
            default:
                cout << "Неизвестная опция" << endl;
                return 1;
        }
    }
    
    for (int i = optind; i < argc; ++i) {
        double operand = stod(argv[i]);
        operands.push_back(operand);
    }
    
    if (operation.empty() || (operation != "decimalLog" && operation != "naturallLog")) {
        cout << "Недопустимая или отсутствующая операция" << endl;
        return 1;
    }
    
    double result;
    
    if (operation == "decimalLog") {
        result = decimalLog(operands);
    } else if (operation == "naturallLog") {
        result = naturalLog(operands);
    } else {
        cout << "Неизвестная операция" << endl;
        return 1;
    }
    
    cout << "Результат: " << result << endl;
    return 0;
}
