#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Point
{
    string subject_id;
    int time; // lan thi 
    float point;

public:
    Point(string subject_id,int time, float point);
    Point(Point *point);
    string get_subject_id() const;
    void set_subject_id(string subject_id);
    int get_time() const;
    void set_time(int time);
    float get_point() const;
    void set_point(float point);
    void addData();
    void showData();
    bool operator==(Point &other) const;
    friend ofstream &operator<<(ofstream &out, Point &other);
    friend ifstream &operator>>(ifstream &in, Point &other);
    

    Point();
    ~Point();
};

void Point::addData()
{
    cin.ignore();
    cout << "Enter ID subject: ";
    getline(cin, subject_id);
    cout << "Enter time of the test: ";
    cin >> time;
    cout << "Enter point of subject: ";
    cin >> point;
}

void Point::showData()
{
    cout << "\nID subject: " << this->subject_id;
    cout << "Number of test:" << this->time;
    cout << "Point: " << this->point;
}

Point::Point(string subject_id,int time, float point)
{
    this->subject_id = subject_id;
    this->time = time;
    this->point = point;
}

Point::Point(Point *point)
{
    *this = *point;
}

int Point::get_time() const
{
    return time;
}

void Point::set_time(int time)
{
    this->time = time;
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

ofstream &operator<<(ofstream &out, Point &other)
{
    out << other.subject_id << ",";
    out << other.time << ",";
    out << other.point << "\n";
    return out;
}

ifstream &operator>>(ifstream &in, Point &other)
{
    getline(in, other.subject_id, ',');
    in >> other.time;
    string point;
    getline(in, point);
    other.set_point(atof(point.c_str()));
    return in;
}

Point::Point()
{
}

Point::~Point()
{
}
