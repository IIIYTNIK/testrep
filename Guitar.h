//����� ���������� �.�.
//����������� ����� Guitar, ����������� �������� ������.
#pragma once

#include <string>
#include "StringInstrument.h"
#include <iostream>
#include <fstream> 

//����� ����� �������� ����������� �����������
class Guitar : public StringInstrument {
private:
    string bodyType; // �������� ��� �������
    string mediatormaterial; //�������� ��� ��������� ��� ������

public:
    //����������� �� ���������
    Guitar();

    //����������� � �����������
    Guitar(const string& name, int numberOfStrings, const string& stringMaterial, const string& bodyMaterial, const string &bodyType, const string &mediatormaterial);

    //�������
    ///��������� ���� �������
    void set_bodyType(const string& bodytupe);
    ///��������� ���� ���������
    void set_mediatormaterial(const string& madmat);

    //�������
    ///���������� ��� ������� � ������ 
    string get_bodyType() const { return bodyType; }
    ///���������� �������� ��������� � ������ 
    string get_mediatormaterial() const { return mediatormaterial; }

    //�����, ����������� ������
    string to_string() const override;
    /// ������������� ����� ��� ������
    void play() override; 
    /// ��������������� ����� ���������
    void tune() override; 

    // ������ ��� ���������� � ��������
    /// �������������� ����� ��� ���������� � ����
    void saveToFile(std::ofstream& out) const override; 
    /// �������������� ����� ��� �������� �� �����
    void loadFromFile(std::ifstream& in) override; 
};
