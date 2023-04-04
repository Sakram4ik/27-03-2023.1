#include <iostream>
#include <string>
using namespace std;

int main() {
    // Зчитуємо перший рядок, який містить пари "ім'я=значення"
    string values;
    getline(std::cin, values);
    
    // Зчитуємо другий рядок, який містить шаблон
    string templates;
    getline(std::cin, templates);
    
    // Замінюємо місця-тримачі у шаблоні на відповідні значення з першого рядка
    string output = templates;
    size_t pos = 0;
    while ((pos = output.find("[")) != std::string::npos) {
        size_t end_pos = output.find("]", pos);
        if (end_pos != string::npos) {
            // Витягуємо ім'я з місця-тримача
            string name = output.substr(pos + 1, end_pos - pos - 1);
            // Знаходимо позицію ім'я=значення у першому рядку
            size_t comma_pos = values.find("," + name + "=");
            if (comma_pos != string::npos) {
                comma_pos += 1;
                // Знаходимо позицію знака "=" та витягуємо значення
                size_t eq_pos = comma_pos + name.length() + 1;
                size_t next_comma_pos = values.find(",", eq_pos);
                string value = (next_comma_pos !=string::npos) ?
                    values.substr(eq_pos, next_comma_pos - eq_pos) :
                    values.substr(eq_pos);
                // Замінюємо місце-тримач на значення
                output.replace(pos, end_pos - pos + 1, values);
            }
        }
    }
    
    // Виводимо результат
    cout << output << '\n';
    
    return 0;
}
