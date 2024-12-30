//автор Бородиенко Д.Т.
//Производный класс для смычковых струнных инструментов
#include "BowedInstrument.h"

// Конструктор по умолчанию. Инициализирует все поля класса значениями по умолчанию.
BowedStringInstrument::BowedStringInstrument() {
    bowMaterial = " "; // Материал смычка
    name = " "; // Название инструмента
    stringMaterial = " "; // Материал струн
    bodyMaterial = " "; // Материал корпуса
    numberOfStrings = 0; // Количество струн
    attunement = 0; // Уровень настройки инструмента
}

// Конструктор с параметрами. Инициализирует поля класса значениями, переданными в качестве аргументов.
BowedStringInstrument::BowedStringInstrument(const string& name, int numberOfString, const string& stringMaterial,
    const string& bodyMaterial, const string bowMaterial) {
    set_name(name);
    set_stringMaterial(stringMaterial);
    set_bodyMaterial(bodyMaterial);
    set_numberOfStrings(numberOfString);
    set_bowMaterial(bowMaterial);
    attunement = 0;
}

/// Сеттер для материала смычка. Если строка пуста, устанавливает значение "None".
void BowedStringInstrument::set_bowMaterial(const string bmat) {
    this->bowMaterial = bmat.empty() ? "None" : bmat;
}

/// Метод, возвращающий строку с информацией об инструменте.
string BowedStringInstrument::to_string() const {
    return("Name: " + name + ", Count of string: " + std::to_string(numberOfStrings) + ", material of string: " + stringMaterial + ", material of body: " + bodyMaterial + ", material of bow:" + bowMaterial);
}

/// Метод для имитации игры на смычковом инструменте. Проверяет настроенность и уменьшает attunement на 10 после игры.
void BowedStringInstrument::play() {
    if (this->attunement > 10) { // Если инструмент настроен
        cout << "Playing on " << name << " this bow made from: " << bowMaterial << "\n"; // Имитация игры
        this->attunement -= 10;
    }
    else {
        cout << "You can`t play. Tune instrument " << "\n"; // Инструмент не настроен
    }
};

/// Метод для настройки инструмента. Устанавливает attunement в 100.
void BowedStringInstrument::tune() {
    cout << "Tuning " << name << "\n";
    this->attunement = 100; // Установка уровня настройки
}

/// Метод для сохранения информации об инструменте в файл.
void BowedStringInstrument::saveToFile(std::ofstream& out) const {
    out << "BowedStringInstrument\n"; // Записываем корректный тип объекта в файл
    out << name << "\n" << stringMaterial << "\n" << bodyMaterial << "\n" << numberOfStrings << "\n"; // Записываем данные объекта
    out << bowMaterial << "\n" << attunement << "\n";
}

/// Метод для загрузки информации об инструменте из файла.
void BowedStringInstrument::loadFromFile(std::ifstream& in) {
    std::getline(in, name); // Читаем название
    std::getline(in, stringMaterial); // Читаем материал струн
    std::getline(in, bodyMaterial); // Читаем материал корпуса
    in >> numberOfStrings; // Читаем количество струн
    in.ignore(); // Игнорируем символ новой строки после чтения числа
    std::getline(in, bowMaterial); // Читаем материал смычка
    in >> attunement; // Читаем параметр настроенности
    in.ignore(); // Игнорируем символ новой строки после чтения числа
}