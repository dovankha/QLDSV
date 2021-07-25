#pragma once
#include <fstream>
#include <iostream>
#include <string>

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

    friend ifstream &operator>>(ifstream &in, Subject &other);
    friend ofstream &operator<<(ofstream &out, Subject &other);

    Subject();
    ~Subject();
};


Subject::Subject()
{
}

Subject::~Subject()
{
}
