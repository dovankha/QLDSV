#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Point
{
    string subject_id;
    int num_of_test;
    float point;

public:
    Point(string subject_id,int num_of_test, float point);
    Point(Point *point);
    string get_subject_id() const;
    void set_subject_id(string subject_id);
    int get_num_of_test() const;
    void set_num_of_test(int num_of_test);
    float get_point() const;
    void set_point(float point);
    void showData();
    bool operator==(Point &other) const;
    friend ofstream &operator<<(ofstream &out, Point &other);
    friend ifstream &operator>>(ifstream &in, Point &other);

    Point();
    ~Point();
};

void Point::showData()
{
    cout << "\nID subject: " << this->subject_id;
    cout << "\nNumber of test:" << this->num_of_test;
    cout << "\nPoint: " << this->point;
}

Point::Point(string subject_id,int num_of_test, float point)
{
    this->subject_id = subject_id;
    this->num_of_test = num_of_test;
    this->point = point;
}

Point::Point(Point *point)
{
    *this = *point;
}

int Point::get_num_of_test() const
{
    return num_of_test;
}

void Point::set_num_of_test(int num_of_test)
{
    this->num_of_test = num_of_test;
}

string Point::get_subject_id() const
{
    return subject_id;
}

void Point::set_subject_id(string subject_id)
{
    this->subject_id = subject_id;
}

float Point::get_point() const
{
    return point;
}

void Point::set_point(float point)
{
    this->point = point;
}

bool Point::operator==(Point &other) const
{
    return (subject_id == other.subject_id) && (point == other.point);
}

Point::Point()
{
}

Point::~Point()
{
}

ofstream &operator<<(ofstream &out, Point &other)
{
    out << other.subject_id << ",";
    out << other.point << "\n";
    return out;
}

ifstream &operator>>(ifstream &in, Point &other)
{
    getline(in, other.subject_id, ',');
    string point;
    getline(in, point);
    other.set_point(atof(point.c_str()));
    return in;
}