#include <iostream>
#include <vector>
#include "BowedInstrument.h"
#include "Guitar.h"
#include "StringInstrument.h"
#include <cassert> 
using namespace std;


// Функция для тестирования сохранения в файл
void testSaveToFile() {
    std::ofstream outFile("test_save.txt"); // Открываем файл для записи
    assert(outFile.is_open()); // Проверяем, что файл открыт

    Guitar guitar("Electric Guitar", 6, "steel", "Alder", "Jumbo", "Wood"); // Создаем объект Guitar
    guitar.saveToFile(outFile); // Сохраняем объект в файл
    outFile.close(); // Закрываем файл

    // Проверяем, что файл был создан и содержит данные
    std::ifstream inFile("test_save.txt"); // Открываем файл для чтения
    assert(inFile.is_open()); // Проверяем, что файл открыт

    std::string line; // Переменная для хранения строки
    std::getline(inFile, line); // Читаем первую строку
    assert(line == "Guitar"); // Проверяем тип объекта
    std::getline(inFile, line); // Читаем название гитары
    assert(line == "Electric Guitar"); // Проверяем название гитары
    std::getline(inFile, line); // Читаем материал струн
    assert(line == "steel" ); // Проверяем материал струн
    std::getline(inFile, line); // Читаем материал корпуса
    assert(line == "Alder"); // Проверяем материал корпуса
    std::getline(inFile, line); // Читаем колличество струн
    assert(line == "6"); // Проверяем колличество струн
    std::getline(inFile, line); // Читаем тип корпуса
    assert(line == "Wood"); // Проверяем тип корпуса
    std::getline(inFile, line); // Читаем материал медиатора
    assert(line == "Jumbo"); // Проверяем материал медиатора
    std::getline(inFile, line); // Читаем Параметр настроенности гитары
    assert(line == "0"); // Параметр настроенности гитары

    inFile.close(); // Закрываем файл
}

// Функция для тестирования загрузки из файла
void testLoadFromFile() {
    std::ofstream outFile("test_load.txt"); // Открываем файл для записи
    outFile << "Electric Guitar\n";
    outFile << "Steel\n"; // Материал струн
    outFile << "Mahogany\n"; // Материал корпуса
    outFile << "6\n"; // Количество струн
    outFile << "Plastic\n"; // Материал медиатора
    outFile << "Dreadnought\n"; // Тип корпуса
    outFile << "0\n"; // Настройка
    outFile.close(); // Закрываем файл

    std::ifstream inFile("test_load.txt"); // Открываем файл для чтения
    assert(inFile.is_open()); // Проверяем, что файл открыт

    Guitar guitar; // Создаем объект Guitar
    guitar.loadFromFile(inFile); // Загружаем данные из файла
    inFile.close(); // Закрываем файл

    // Проверяем, что данные загрузились корректно
    assert(guitar.get_name() == "Electric Guitar"); // Проверяем название гитары
    assert(guitar.get_numberOfStrings() == 6); // колличество струн
}

// Функция для тестирования to_string
void testToString() {
    Guitar guitar("Electric Guitar", 6, "steel", "Alder", "Jumbo", "Wood"); // Создаем объект Guitar
    std::string outputstring = "Name: Electric Guitar, Count of string: 6, material of string: steel, material of body: Alder, body type: Jumbo, material of mediator: Wood"; // Ожидаемый вывод
    assert(guitar.to_string() == outputstring); // Проверяем, что вывод совпадает с ожидаемым
}




int main() {

    testSaveToFile();
    testLoadFromFile();
    testToString();


    //создание двух объктов класса гитары и 2 объекта класса смычковых инстумента

    std::vector<StringInstrument*> instrument;

    instrument.push_back(new Guitar("Bass Guitar", 4, "steel", "Mahagony", "Jumbo", "Wood"));

    instrument.push_back(new BowedStringInstrument("Double bass", 4, "gut", "wood", "Carbon"));

    std::ofstream outFile("Instrument.txt"); // Открываем файл для записи
    for (const auto& StringInstrument : instrument) { // Проходим по всем объектам в векторе
        StringInstrument->saveToFile(outFile); // Сохраняем каждый объект в файл
    }
    outFile.close();

    // Освобождаем память
    for (auto& education : instrument) { // Проходим по всем объектам в векторе
        delete education; // Освобождаем память, занятую объектами
    }
    instrument.clear(); // Очищаем вектор


    // Загрузка данных из файла
    std::ifstream inFile("Instrument.txt"); // Открываем файл для чтения
    if (inFile.is_open()) { // Проверяем, успешно ли открыт файл
        std::string type; // Переменная для хранения типа объекта
        while (std::getline(inFile, type)) { // Читаем строки из файла
            if (type == "Guitar") { // Если тип объекта - Guitar
                Guitar* guitar = new Guitar; // Создаем новый объект Guitar
                guitar->loadFromFile(inFile); // Загружаем данные из файла
                instrument.push_back(guitar); // Добавляем объект в вектор
            }
            else if (type == "BowedStringInstrument") { // Если тип объекта - BowedStringInstrument
                BowedStringInstrument* Sinstrument = new BowedStringInstrument; // Создаем новый объект BowedStringInstrument
                Sinstrument->loadFromFile(inFile); // Загружаем данные из файла
                instrument.push_back(Sinstrument); // Добавляем объект в вектор
            }
        }
        inFile.close(); // Закрываем файл
    }


    // Демонстрация полиморфизма
    std::cout << "Demonstration of polymorphism:\n";
    for (const auto& musical_tool : instrument) { // Проходим по всем объектам в векторе
        std::cout << musical_tool->to_string() << std::endl; // Выводим строковое представление каждого объекта
    }


    // Пример, когда полиморфизм не работает
    std::cout << "\nAn example where polymorphism doesn't work:\n";
    for (const auto& musical_tool : instrument) {
        // Попытка вызвать метод, специфичный для Guitar
        Guitar* GuitarPtr = dynamic_cast<Guitar*>(musical_tool);
        if (GuitarPtr) {
            std::cout << "This is the Guitar object: " << GuitarPtr->get_mediatormaterial() << std::endl; // Успешный вызов
        }
        else {
            std::cout << "This is not a Guitar object." << std::endl; // Неудачный вызов
        }
    }

    // Освобождаем память
    for (auto& musical_tool : instrument) { // Проходим по всем объектам в векторе
        delete musical_tool; // Освобождаем память, занятую объектами
    }

    return 0;
}