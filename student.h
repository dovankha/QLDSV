#pragma once
#include "Point_linked_list.h"
#include <iomanip>

class Student
{
    
    string id;
    string first_name;
    string last_name;
    string sex;
    string number_phone;
   

public:
    Point_linked_list *point_list;
    Student(string id, string first_name, string last_name, string sex);
    Student(Student *Student);
    string get_id() const;
    void set_id(string id);
    string get_first_name() const;
    void set_first_name(string first_name);
    string get_last_name() const;
    void set_last_name(string last_name);
    string get_sex() const;
    void set_sex(string sex);
    Point_linked_list *get_points_list();
    void set_points_list(Point_linked_list *points_list);

    void getDataFromInput(bool);
    void showData();
    void showPoint();
    friend ofstream &operator<<(ofstream &out, Student &Student);
    friend ifstream &operator>>(ifstream &in, Student &Student);

    Student();
    ~Student();
};

Student::Student(string id, string first_name, string last_name, string sex)
{
    this->id = id;
    this->first_name = first_name;
    this->last_name = last_name;
    this->sex = sex;
    this->point_list = nullptr;
}

Student::Student(Student *Student)
{
    *this = *Student;
}

string Student::get_id() const
{
    return id;
}

void Student::set_id(string id)
{
    this->id = id;
}

string Student::get_first_name() const
{
    return first_name;
}

void Student::set_first_name(string first_name)
{
    this->first_name = first_name;
}

string Student::get_last_name() const
{
    return last_name;
}

void Student::set_last_name(string last_name)
{
    this->last_name = last_name;
}

string Student::get_sex() const
{
    return sex;
}

void Student::set_sex(string sex)
{
    this->sex = sex;
}

Point_linked_list *Student::get_points_list()
{
    return point_list;
}

void Student::set_points_list(Point_linked_list *point_list)
{
    this->point_list = point_list;
}

ofstream &operator<<(ofstream &out, Student &Student)
{
    out << Student.id << ",";
    out << Student.first_name << ",";
    out << Student.last_name << ",";
    out << Student.sex << ",";
    out << Student.number_phone<< ",";
    return out;
}

ifstream &operator>>(ifstream &in, Student &Student)
{
    getline(in, Student.id, ',');
    getline(in, Student.first_name, ',');
    getline(in, Student.last_name, ',');
    getline(in, Student.sex, ',');
    getline(in, Student.number_phone, ',');
    // doc ca dau enter
    string temp;
    getline(in, temp);
    return in;
}

void Student::getDataFromInput(bool isModify = false)
{
    cin.ignore();
    if(!isModify){
        cout << "\nEnter your ID number: ";
        getline(cin, this->id);

    }
    cout << "Enter your first name: ";
    getline(cin, this->first_name);
    cout << "Enter your last name: ";
    getline(cin, this->last_name);
    cout << "Enter your sex: ";
    getline(cin, this->sex);
    cout << "Enter your number phone: ";
    getline(cin, this->number_phone);
}

void Student::showData()
{
    cout << "\t|" << left << setw(11) << this->id;
    cout << "|" << left << setw(15) << this->first_name;
    cout << "|" << left << setw(19) << this->last_name;
    cout << "|" << left << setw(7) << this->sex;
    cout << "|" << left << setw(13) << this->number_phone << "|";
}

Student::Student()
{
    this->point_list = nullptr;
}

Student::~Student()
{
    delete point_list;
}
