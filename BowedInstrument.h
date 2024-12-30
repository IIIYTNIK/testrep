//����� ���������� �.�.
//����������� ����� ��� ��������� �������� ������������
#pragma once
#include <string>
#include <iostream>
#include <fstream> 
#include "StringInstrument.h"


class BowedStringInstrument : public StringInstrument {
private:
    string bowMaterial; //�������� ������

public:

    // ����������� �� ���������. �������������� ��� ���� ������ ���������� �� ���������.
    BowedStringInstrument();

    // ����������� � �����������. �������������� ���� ������ ����������, ����������� � �������� ����������.
    BowedStringInstrument(const string& name, int numberOfString, const string& stringMaterial, const string& bodyMaterial, const string bowMaterial);

    /// ������ ��� ��������� ������. ���� ������ �����, ������������� �������� "None".
    void set_bowMaterial(const string bmat);

    ///���������� �������� ������ � ������ 
    string get_bowMaterial() { return bowMaterial; };
    
    /// �����, ������������ ������ � ����������� �� �����������.
    string to_string() const override;

    /// ����� ��� �������� ���� �� ��������� �����������. ��������� ������������� � ��������� attunement �� 10 ����� ����.
    void play() override;// ������������� ����� ���� �� ��������� �����������
    /// ����� ��� ��������� �����������. ������������� attunement � 100.
    void tune() override;// ��������������� ����� ���������

    /// ������ ��� ���������� � ��������
    /// ����� ��� ���������� ���������� �� ����������� � ����.
    void saveToFile(std::ofstream& out) const override; 
    /// ����� ��� �������� ���������� �� ����������� �� �����.
    void loadFromFile(std::ifstream& in) override; 
};