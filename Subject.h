#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Subject
{

    string subject_id;
    string subject_name;
    int STCLT;
    int STCTH;

public:
    Subject(string subject_id, string subject_name, int STCLT, int STCTH);
    Subject(Subject *subject);

    string get_subject_id() const;
    void set_subject_id(string subject_id);
    string get_subject_name() const;
    void set_subject_name(string subject_name);
    int get_STCLT() const;
    void set_STCLT(int STCLT);
    int get_STCTH() const;
    void set_STCTH(int STCTH);

    void getDataFromInput();
    void showData();

    // int get_id() const;
	// void set_id(int id);

    friend ifstream &operator>>(ifstream &in, Subject &other);
    friend ofstream &operator<<(ofstream &out, Subject &other);

    Subject();
    ~Subject();
};


void Subject::getDataFromInput()
{
    cin.ignore();
    cout << "\nEnter ID of subject: ";
    getline(cin, this->subject_id);
    cout << "Enter the name of subject: ";
    getline(cin, this->subject_name);
    cout << "Enter number of STCLT: ";
    cin >> this->STCLT;
    cout << "Enter number of STCTH: ";
    cin >> this->STCTH;
}

// void Subject::showData()
// {
//     // cout << "\nSubject ID: " << this->subject_id;
//     // cout << "\nSubject name: " << this->subject_name;
//     // cout << "\nSTCLT of subject: " << this->STCLT;
//     // cout << "\nSTCTH of subject: " << this->STCTH;
// }

Subject::Subject(string subject_id, string subject_name, int STCLT, int STCTH)
{
    this->subject_id = subject_id;
    this->subject_name = subject_name;
    this->STCLT = STCLT;
    this->STCTH = STCTH;
}

Subject::Subject(Subject *subject)
{
    *this = *subject;
}

string Subject::get_subject_id() const
{
    return subject_id;
}

void Subject::set_subject_id(string subject_id)
{
    this->subject_id = subject_id;
}

string Subject::get_subject_name() const
{
    return subject_name;
}

void Subject::set_subject_name(string subject_name)
{
    this->subject_name = subject_name;
}

int Subject::get_STCLT() const
{
    return STCLT;
}

void Subject::set_STCLT(int STCLT)
{
    this->STCLT = STCLT;
}

int Subject::get_STCTH() const
{
    return STCTH;
}

void Subject::set_STCTH(int STCTH)
{
    this->subject_name = subject_name;
}

ifstream &operator>>(ifstream &in, Subject &other)
{
    string line;

    getline(in, other.subject_id, ',');
    getline(in, other.subject_name, ',');
    in >> other.STCLT;
    getline(in, line, ',');
    in >> other.STCTH;
    getline(in, line);
    return in;
}

ofstream &operator<<(ofstream &out, Subject &other)
{
    out << other.subject_id << ',';
    out << other.subject_name << ',';
    out << other.STCLT << ',';
    out << other.STCTH << '\n';
    return out;
}

Subject::Subject()
{
}

Subject::~Subject()
{
}
