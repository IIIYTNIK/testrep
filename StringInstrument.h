//автор Бородиенко Д.Т.
//Общий класс струновых музыкальных инструментов
#pragma once
#include <string>
#include <iostream>
#include <fstream> 
using namespace std;

class StringInstrument {
protected: // Защищенные поля, доступны производным классам
    string name; //Название инструмента
    string stringMaterial; //материал струн
    string bodyMaterial; //материал корпуса
    int numberOfStrings; //Количество струн
    int attunement;//отвечает за настройку гитары

public:
    StringInstrument();//конструктор по умолчанию

    StringInstrument(const string& name, int numberOfString, const string& stringMaterial, const string& bodyMaterial);//конструктор с параметрами

    void set_name(const string &name);//сеттер
    void set_numberOfStrings(int &numberS);
    void set_stringMaterial(const string &strmaterial);
    void set_bodyMaterial(const string &bodymat);

    string get_name() const { return name; }
    int get_numberOfStrings() const { return numberOfStrings; }
    string get_stringMaterial() const { return stringMaterial; }
    string get_bodyMaterial() const { return bodyMaterial; }

    ///метод возвращает информацию о всех полях класса в строком типе
    virtual string to_string() const;
    virtual void tune(); // Базовый метод настройки
    virtual void play(); // Базовый метод игры

    // Методы для сохранения и загрузки
    virtual void saveToFile(std::ofstream& out) const = 0; //абстрактный метод для сохранения в файл
    virtual void loadFromFile(std::ifstream& in) = 0; //абстрактный метод для загрузки из файла
};