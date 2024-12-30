//автор Бородиенко Д.Т.
//Производный класс Guitar, описывающий свойства гитары.
#pragma once

#include <string>
#include "StringInstrument.h"
#include <iostream>
#include <fstream> 

//Общий класс струнных музыкальных инстументов
class Guitar : public StringInstrument {
private:
    string bodyType; // Добавлен тип корпуса
    string mediatormaterial; //добавлен тип медиатора для гитары

public:
    //конструктор по умолчанию
    Guitar();

    //конструктор с параметрами
    Guitar(const string& name, int numberOfStrings, const string& stringMaterial, const string& bodyMaterial, const string &bodyType, const string &mediatormaterial);

    //сеттеры
    ///установка типа корпуса
    void set_bodyType(const string& bodytupe);
    ///установка типа медиатора
    void set_mediatormaterial(const string& madmat);

    //геттеры
    ///возвращает тип корпуса в строке 
    string get_bodyType() const { return bodyType; }
    ///возвращает материал медиатора в строке 
    string get_mediatormaterial() const { return mediatormaterial; }

    //метод, описывающий объект
    string to_string() const override;
    /// Специфический метод для гитары
    void play() override; 
    /// Переопределённый метод настройки
    void tune() override; 

    // Методы для сохранения и загрузки
    /// Переопределяем метод для сохранения в файл
    void saveToFile(std::ofstream& out) const override; 
    /// Переопределяем метод для загрузки из файла
    void loadFromFile(std::ifstream& in) override; 
};
