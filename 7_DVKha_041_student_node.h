#pragma once
#include "7_DVKha_041_Student.h"

class Student_node
{

public:
    Student data;
    Student_node *next;
    Student_node(Student student);
    Student_node();
    ~Student_node();
};

Student_node::Student_node(Student student)
{
    this->data = student;
    next = nullptr;
}

Student_node::Student_node()
{
}

Student_node::~Student_node()
{
}
