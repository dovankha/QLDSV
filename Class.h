#pragma once
#include "Student_linked_list.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

class Class
{
    string id;
    string name;
    int year;
    Student_linked_list *student_list;

public:
    Class(string id, string name, int year);
    Class(Class *other);

    string get_id() const;
    void set_id(string id);
    string get_name() const;
    void set_name(string name);
    int get_year() const;
    void set_year(int year);
    void getInfoFromInput(bool);
    void showData();
    Student_linked_list *get_student_list() const;
    void set_student_list(Student_linked_list *student_list);

    friend ofstream &operator<<(ofstream &out, Class &clas);
    friend ifstream &operator>>(ifstream &in, Class &clas);

    Class();
    ~Class();
};

Class::Class(string id, string name, int year)
{
    this->id = id;
    this->name = name;
    this->student_list = nullptr;
}

Class::Class(Class *other)
{
    *this = *other;
}

string Class::get_id() const
{
    return id;
}

void Class::set_id(string id)
{
    this->id = id;
}

string Class::get_name() const
{
    return name;
}

void Class::set_name(string name)
{
    this->name = name;
}

int Class::get_year() const
{
    return year;
}

void Class::set_year(int year)
{
    this->year = year;
}

Student_linked_list *Class::get_student_list() const
{
    return student_list;
}

void Class::set_student_list(Student_linked_list *student_list)
{
    this->student_list = student_list;
}

void Class::getInfoFromInput(bool isModify = false)
{
    if (!isModify)
    {
        cin.ignore();
        cout << "\nEnter class ID: ";
        getline(cin, this->id);
        while (!((this->id >= "A" && this->id <= "Z") || (this->id >= "0" && this->id <= "9") || (this->id >= "a" && this->id <= "z")))
        {
            cout << "\n[Error]: Only Number or Alphabet!!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "\nEnter class ID: ";
            getline(cin, this->id);
        }
    }
    cout << "Enter class name: ";
    getline(cin, this->name);
    while (!((this->name >= "A" && this->name <= "Z") || (this->name >= "0" && this->name <= "9") || (this->name >= "a" && this->name <= "z")))
    {
        cout << "\n[Error]: Only Number or Alphabet!!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter class name: ";
        getline(cin, this->name);
    }
    while (1)
    {
        cout << "Enter school year begin: ";
        cin >> this->year;
        if (cin.fail())
        {
            cout << "\n[Error]: Only numbers!!" << endl;
            getch();
            cin.clear();
            cin.ignore(256, '\n');
        }
        else
        {
            break;
        }
    }
    cin.ignore(256, '\n');
}

void Class::showData()
{
    cout << "\t|" << left << setw(11) << this->id;
    cout << "|" << left << setw(20) << this->name;
    cout << "|" << left << setw(8) << this->year << "|";
}

ofstream &operator<<(ofstream &out, Class &clas)
{
    out << clas.id << ',';
    out << clas.name << ',';
    out << clas.year << "\n";
    return out;
}

ifstream &operator>>(ifstream &in, Class &clas)
{
    getline(in, clas.id, ',');
    getline(in, clas.name, ',');
    in >> clas.year;

    string temp;
    getline(in, temp);
    return in;
}

Class::Class()
{
    this->student_list = nullptr;
}

Class::~Class()
{
    delete student_list;
}
