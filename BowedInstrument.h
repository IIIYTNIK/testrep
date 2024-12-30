//автор Бородиенко Д.Т.
//Производный класс для смычковых струнных инструментов
#pragma once
#include <string>
#include <iostream>
#include <fstream> 
#include "StringInstrument.h"


class BowedStringInstrument : public StringInstrument {
private:
    string bowMaterial; //материал смычка

public:

    // Конструктор по умолчанию. Инициализирует все поля класса значениями по умолчанию.
    BowedStringInstrument();

    // Конструктор с параметрами. Инициализирует поля класса значениями, переданными в качестве аргументов.
    BowedStringInstrument(const string& name, int numberOfString, const string& stringMaterial, const string& bodyMaterial, const string bowMaterial);

    /// Сеттер для материала смычка. Если строка пуста, устанавливает значение "None".
    void set_bowMaterial(const string bmat);

    ///возвращает материал смычка в строке 
    string get_bowMaterial() { return bowMaterial; };
    
    /// Метод, возвращающий строку с информацией об инструменте.
    string to_string() const override;

    /// Метод для имитации игры на смычковом инструменте. Проверяет настроенность и уменьшает attunement на 10 после игры.
    void play() override;// Специфический метод игры на смычковых инстументах
    /// Метод для настройки инструмента. Устанавливает attunement в 100.
    void tune() override;// Переопределённый метод настройки

    /// Методы для сохранения и загрузки
    /// Метод для сохранения информации об инструменте в файл.
    void saveToFile(std::ofstream& out) const override; 
    /// Метод для загрузки информации об инструменте из файла.
    void loadFromFile(std::ifstream& in) override; 
};