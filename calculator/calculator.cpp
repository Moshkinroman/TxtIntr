#include <iostream>
#include <string>
#include <cmath>
#include <vector>

const double PI = std::acos(-1.0);

void print_help() {
    std::cout << "Использование: calculator --operation <операция> [--mode <режим>] <значение>\n"
              << "\nОперации:\n"
              << "  arctan  - Арктангенс\n"
              << "  arccot  - Арккотангенс\n"
              << "\nРежимы (необязательно, по умолчанию rad):\n"
              << "  rad     - Радианы\n"
              << "  deg     - Градусы\n"
              << "\nПримеры:\n"
              << "  calculator --operation arctan --mode deg 1.0\n"
              << "  calculator -o arccot -m rad 0.5\n";
}

int main(int argc, char* argv[]) {
    // Если нет параметров, выводим справку
    if (argc < 2) {
        print_help();
        return 0;
    }

    std::string operation = "";
    std::string mode = "rad";
    std::vector<std::string> operands;

    // Парсинг аргументов командной строки
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-o" || arg == "--operation") {
            if (i + 1 < argc) {
                operation = argv[++i];
            }
        } else if (arg == "-m" || arg == "--mode") {
            if (i + 1 < argc) {
                mode = argv[++i];
            }
        } else {
            operands.push_back(arg);
        }
    }

    // Проверка корректности ввода (для 11 варианта нужен ровно 1 операнд)
    if (operation.empty() || operands.size() != 1) {
        std::cerr << "Ошибка: Неверные аргументы.\n";
        print_help();
        return 1;
    }

    double x = std::stod(operands[0]);
    double result = 0.0;

    // Вычисление
    if (operation == "arctan") {
        result = std::atan(x);
    } else if (operation == "arccot") {
        // Арккотангенс определяется как PI/2 - arctan(x) для непрерывности на всей числовой прямой
        result = PI / 2.0 - std::atan(x);
    } else {
        std::cerr << "Ошибка: Неизвестная операция '" << operation << "'\n";
        return 1;
    }

    // Конвертация в градусы, если требуется
    if (mode == "deg") {
        result = result * 180.0 / PI;
    } else if (mode != "rad") {
        std::cerr << "Ошибка: Неизвестный режим '" << mode << "'. Используйте 'rad' или 'deg'.\n";
        return 1;
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}
