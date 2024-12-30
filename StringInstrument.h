//����� ���������� �.�.
//����� ����� ��������� ����������� ������������
#pragma once
#include <string>
#include <iostream>
#include <fstream> 
using namespace std;

class StringInstrument {
protected: // ���������� ����, �������� ����������� �������
    string name; //�������� �����������
    string stringMaterial; //�������� �����
    string bodyMaterial; //�������� �������
    int numberOfStrings; //���������� �����
    int attunement;//�������� �� ��������� ������

public:
    StringInstrument();//����������� �� ���������

    StringInstrument(const string& name, int numberOfString, const string& stringMaterial, const string& bodyMaterial);//����������� � �����������

    void set_name(const string &name);//������
    void set_numberOfStrings(int &numberS);
    void set_stringMaterial(const string &strmaterial);
    void set_bodyMaterial(const string &bodymat);

    string get_name() const { return name; }
    int get_numberOfStrings() const { return numberOfStrings; }
    string get_stringMaterial() const { return stringMaterial; }
    string get_bodyMaterial() const { return bodyMaterial; }

    ///����� ���������� ���������� � ���� ����� ������ � ������� ����
    virtual string to_string() const;
    virtual void tune(); // ������� ����� ���������
    virtual void play(); // ������� ����� ����

    // ������ ��� ���������� � ��������
    virtual void saveToFile(std::ofstream& out) const = 0; //����������� ����� ��� ���������� � ����
    virtual void loadFromFile(std::ifstream& in) = 0; //����������� ����� ��� �������� �� �����
};