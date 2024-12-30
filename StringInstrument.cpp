//автор Бородиенко Д.Т.
//Общий класс струновых музыкальных инструментов
#include "StringInstrument.h"


//конструктор по умолчанию
StringInstrument::StringInstrument() {
	name = " ";
    stringMaterial = " ";
    bodyMaterial = " ";
    numberOfStrings = 0; 
    attunement = 0;
}

//конструктор с параметрами
StringInstrument::StringInstrument(const string& name, int numberOfString, const string& stringMaterial, const string& bodyMaterial) {
    set_name(name);
    set_stringMaterial(stringMaterial);
    set_bodyMaterial(bodyMaterial);
    set_numberOfStrings(numberOfString);
    attunement = 0;
}

void StringInstrument::set_name(const string& name) {
    this->name = name.empty() ? "Nonanme" : name;
}
void StringInstrument::set_numberOfStrings(int& numberS) {
    this->numberOfStrings = numberS < 0 ? 0 : numberS;
}
void StringInstrument::set_stringMaterial(const string& strmaterial) {
    this->stringMaterial = strmaterial.empty() ? "None" : strmaterial;
}
void StringInstrument::set_bodyMaterial(const string& bodymat) {
    this->bodyMaterial = bodymat.empty() ? "None" : bodymat;
}

///метод возвращает информацию о всех полях класса в строком типе
string StringInstrument::to_string() const {
    return("Name: " + name + ", Count of string: " + std::to_string(numberOfStrings) + ", material of string: " + stringMaterial + ", material of body: " + bodyMaterial + "\n");
}
/// Базовый метод настройки
void StringInstrument::tune() {
    cout << "Tuning " << name << "\n";
    this->attunement = 100; //настройка становится 100
}
/// Базовый метод игры
void StringInstrument::play() {

    if (attunement < 10) { //если инструмент расстроен
        cout << "Playing on: " << name << "\n"; //играть на инстументе
        this->attunement -= 10;
    }
    else { //то на нём нельзя играть
        cout << "You can`t play. Tune instrument" << "\n";
    }
}