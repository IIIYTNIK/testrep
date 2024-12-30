//автор Бородиенко Д.Т.
//Производный класс Guitar, описывающий свойства гитары.
#include "Guitar.h"
#include <fstream> 

// Конструктор по умолчанию. Инициализирует все поля класса значениями по умолчанию.
Guitar::Guitar() {
    name = " ";             //название гитары
    stringMaterial = " ";   //материал струн
    bodyMaterial = " ";     //материал корпуса
    numberOfStrings = 0;    //колличество струн
    bodyType = " ";         //тип корпуса
    mediatormaterial = " "; //материал медиатора
    attunement = 0; // Параметр настроенности гитары
}

// Конструктор с параметрами. Инициализирует поля класса значениями, переданными в качестве аргументов.
Guitar::Guitar(const string& name, int numberOfStrings, const string& stringMaterial, const string& bodyMaterial, const string& bodyType, const string& mediatormaterial) {
    set_name(name);
    set_stringMaterial(stringMaterial);
    set_bodyMaterial(bodyMaterial);
    set_numberOfStrings(numberOfStrings);
    set_mediatormaterial(mediatormaterial);
    set_bodyType(bodyType);
    attunement = 0;
}

/// Сеттер для типа корпуса гитары. Если строка пуста, устанавливает значение "None".
void Guitar::set_bodyType(const string& bodytype) {
    this->bodyType = bodytype.empty() ? "None" : bodytype;
}

/// Сеттер для материала медиатора. Если строка пуста, устанавливает значение "None".
void Guitar::set_mediatormaterial(const string& madmat) {
    this->mediatormaterial = madmat.empty() ? "None" : madmat;
}

/// Метод, возвращающий строку с информацией о гитаре.
string Guitar::to_string() const {
    return("Name: " + name + ", Count of string: " + std::to_string(numberOfStrings) + ", material of string: " + stringMaterial + ", material of body: " + bodyMaterial + ", body type: " + bodyType + ", material of mediator: " + mediatormaterial);
}

/// Метод для настройки гитары. Устанавливает параметр attunement в 100.
void Guitar::tune() {
    cout << "Tuning the guitar (" << name << ")..." << "\n";
    this->attunement = 100; // Настройка становится 100
}

/// Метод для игры на гитаре. Проверяет настроенность и уменьшает attunement на 10 после игры.
void Guitar::play() {
    if (attunement > 10) { // Если инструмент расстроен
        cout << "Playing on " << name << " this mediator made from " << mediatormaterial << "\n"; // Играть на инструменте
        this->attunement -= 10;
    }
    else { // Если инструмент не настроен
        cout << "You can`t play. Tune instrument" << "\n";
    }
}

/// Метод для сохранения информации о гитаре в файл.
void Guitar::saveToFile(std::ofstream& out) const {
    out << "Guitar\n"; // Записываем тип объекта в файл
    out << name << "\n" << stringMaterial << "\n" << bodyMaterial << "\n" << numberOfStrings << "\n"; // Записываем данные объекта
    out << mediatormaterial << "\n" << bodyType << "\n" << attunement << "\n";
}

/// Метод для загрузки информации о гитаре из файла.
void Guitar::loadFromFile(std::ifstream& in) {
    std::getline(in, name); // Читаем название
    std::getline(in, stringMaterial); // Читаем материал струн
    std::getline(in, bodyMaterial); // Читаем материал корпуса
    in >> numberOfStrings; // Читаем количество струн
    in.ignore(); // Игнорируем символ новой строки после чтения числа
    std::getline(in, mediatormaterial); // Читаем материал медиатора
    std::getline(in, bodyType); // Читаем тип корпуса
    in >> attunement; // Читаем параметр настроенности гитары
    in.ignore(); // очищаем буфер потока после чтения числа
}