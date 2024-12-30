//����� ���������� �.�.
//����������� ����� Guitar, ����������� �������� ������.
#include "Guitar.h"
#include <fstream> 

// ����������� �� ���������. �������������� ��� ���� ������ ���������� �� ���������.
Guitar::Guitar() {
    name = " ";             //�������� ������
    stringMaterial = " ";   //�������� �����
    bodyMaterial = " ";     //�������� �������
    numberOfStrings = 0;    //����������� �����
    bodyType = " ";         //��� �������
    mediatormaterial = " "; //�������� ���������
    attunement = 0; // �������� ������������� ������
}

// ����������� � �����������. �������������� ���� ������ ����������, ����������� � �������� ����������.
Guitar::Guitar(const string& name, int numberOfStrings, const string& stringMaterial, const string& bodyMaterial, const string& bodyType, const string& mediatormaterial) {
    set_name(name);
    set_stringMaterial(stringMaterial);
    set_bodyMaterial(bodyMaterial);
    set_numberOfStrings(numberOfStrings);
    set_mediatormaterial(mediatormaterial);
    set_bodyType(bodyType);
    attunement = 0;
}

/// ������ ��� ���� ������� ������. ���� ������ �����, ������������� �������� "None".
void Guitar::set_bodyType(const string& bodytype) {
    this->bodyType = bodytype.empty() ? "None" : bodytype;
}

/// ������ ��� ��������� ���������. ���� ������ �����, ������������� �������� "None".
void Guitar::set_mediatormaterial(const string& madmat) {
    this->mediatormaterial = madmat.empty() ? "None" : madmat;
}

/// �����, ������������ ������ � ����������� � ������.
string Guitar::to_string() const {
    return("Name: " + name + ", Count of string: " + std::to_string(numberOfStrings) + ", material of string: " + stringMaterial + ", material of body: " + bodyMaterial + ", body type: " + bodyType + ", material of mediator: " + mediatormaterial);
}

/// ����� ��� ��������� ������. ������������� �������� attunement � 100.
void Guitar::tune() {
    cout << "Tuning the guitar (" << name << ")..." << "\n";
    this->attunement = 100; // ��������� ���������� 100
}

/// ����� ��� ���� �� ������. ��������� ������������� � ��������� attunement �� 10 ����� ����.
void Guitar::play() {
    if (attunement > 10) { // ���� ���������� ���������
        cout << "Playing on " << name << " this mediator made from " << mediatormaterial << "\n"; // ������ �� �����������
        this->attunement -= 10;
    }
    else { // ���� ���������� �� ��������
        cout << "You can`t play. Tune instrument" << "\n";
    }
}

/// ����� ��� ���������� ���������� � ������ � ����.
void Guitar::saveToFile(std::ofstream& out) const {
    out << "Guitar\n"; // ���������� ��� ������� � ����
    out << name << "\n" << stringMaterial << "\n" << bodyMaterial << "\n" << numberOfStrings << "\n"; // ���������� ������ �������
    out << mediatormaterial << "\n" << bodyType << "\n" << attunement << "\n";
}

/// ����� ��� �������� ���������� � ������ �� �����.
void Guitar::loadFromFile(std::ifstream& in) {
    std::getline(in, name); // ������ ��������
    std::getline(in, stringMaterial); // ������ �������� �����
    std::getline(in, bodyMaterial); // ������ �������� �������
    in >> numberOfStrings; // ������ ���������� �����
    in.ignore(); // ���������� ������ ����� ������ ����� ������ �����
    std::getline(in, mediatormaterial); // ������ �������� ���������
    std::getline(in, bodyType); // ������ ��� �������
    in >> attunement; // ������ �������� ������������� ������
    in.ignore(); // ������� ����� ������ ����� ������ �����
}