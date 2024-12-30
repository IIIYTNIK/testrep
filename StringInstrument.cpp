//����� ���������� �.�.
//����� ����� ��������� ����������� ������������
#include "StringInstrument.h"


//����������� �� ���������
StringInstrument::StringInstrument() {
	name = " ";
    stringMaterial = " ";
    bodyMaterial = " ";
    numberOfStrings = 0; 
    attunement = 0;
}

//����������� � �����������
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

///����� ���������� ���������� � ���� ����� ������ � ������� ����
string StringInstrument::to_string() const {
    return("Name: " + name + ", Count of string: " + std::to_string(numberOfStrings) + ", material of string: " + stringMaterial + ", material of body: " + bodyMaterial + "\n");
}
/// ������� ����� ���������
void StringInstrument::tune() {
    cout << "Tuning " << name << "\n";
    this->attunement = 100; //��������� ���������� 100
}
/// ������� ����� ����
void StringInstrument::play() {

    if (attunement < 10) { //���� ���������� ���������
        cout << "Playing on: " << name << "\n"; //������ �� ����������
        this->attunement -= 10;
    }
    else { //�� �� �� ������ ������
        cout << "You can`t play. Tune instrument" << "\n";
    }
}