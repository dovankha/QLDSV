#pragma once
#include "7_DVKha_041_Class.h"
#include <iomanip>

class Classes_list
{
    int size;
    int capacity;
    Class **data;

private:
    void resize();

public:
    Classes_list(int capacity);
    Class *operator[](int x);

    bool empty();
    bool full();
    bool can_resize();
    int contain_id(string id);
    int contain_id(string id, int except);
    void insert_at(int position, Class new_class);
    void delete_at(int position);
    void delete_by_id(string id);
    void pop_back();
    void push_back(Class new_class);
    void show_data();
    void set_students_linked_list(Student_linked_list *student_list, int index);
    Student_linked_list *get_students_linked(int index);
    Student_linked_list *get_students_linked(string classId);
    void set_students_linked(string classId, Student_linked_list *student_list);
    void replace_subject_name(string name, int index);
    void replace_subject_id(string id, int index);
    void replace_class_by_ID(string id, Class clas);
    
    int get_size() const;
    void set_size(int size);
    int get_capacity() const;
    void set_capacity(int capacity);
    Class **get_data() const;
    void set_data(Class **data);

    Classes_list();
    ~Classes_list();
};

void Classes_list::replace_class_by_ID(string id, Class clas)
{
    int i = 0;
    for (i; i < size; i++)
    {
        if (data[i]->get_id() == id)
        {
           break;
        }
    }
    data[i]->set_name(clas.get_name());
    data[i]->set_year(clas.get_year());
}

void Classes_list::delete_by_id(string classId)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i]->get_id() == classId)
        {
            delete data[i];
            for (int j = i; j < size - 1; j++)
            {
                data[j] = data[j + 1];
            }
            size--;
        }
    }
}

void Classes_list::set_students_linked(string classId, Student_linked_list *student_list)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i]->get_id() == classId)
            data[i]->set_student_list(student_list);
    }
}

Classes_list::Classes_list(int capacity)
{
    size = 0;
    this->capacity = capacity;
    data = new Class *[capacity];
}

Class *Classes_list::operator[](int x)
{
    return data[x];
}

void Classes_list::pop_back()
{
    delete data[size - 1];
    size--;
}

void Classes_list::push_back(Class new_class)
{
    if (full())
    {
        if (can_resize())
        {
            resize();
        }
        else
        {
            cout << "Class list's max size reached";
        }
    }

    data[size] = new Class(new_class);
    size++;
}

bool Classes_list::full()
{
    return size == capacity;
}

bool Classes_list::empty()
{
    return size == 0;
}

bool Classes_list::can_resize()
{
    return capacity * 2 < 20000;
}

void Classes_list::insert_at(int position, Class new_class)
{
    if (position < 0 || position > size)
    {
        cout << "invalid range of list";
    }
    if (full())
    {
        if (can_resize())
        {
            resize();
        }
        else
        {
            cout << "Subjects list's max size reached";
        }
    }

    for (int i = size - 1; i >= position; i--)
    {
        data[i + 1] = data[i];
    }
    size++;
    data[position + 1] = new Class(new_class);
}

void Classes_list::delete_at(int position)
{
    if (position < 0 || position > size - 1)
    {
        cout << "invalid range of list";
    }
    if (empty())
    {
        cout << "list is empty";
    }

    if (size == 1)
    {
        cout << "c";
    }

    delete data[position];
    for (int i = position; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
}

int Classes_list::contain_id(string id)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i]->get_id() == id)
        {
            return i;
        }
    }
    return -1;
}

void Classes_list::show_data()
{
    cout << "\n\t\t======= CLASS LIST =======\n\n";
    cout << "\t" << "+-----------+--------------------+--------+" << endl;
    cout << "\t" << left << setw(12) << "| Class ID" << left << setw(21) << "|       Name" << left << setw(10) << "|  Year  |\n";
    cout << "\t" << "+-----------+--------------------+--------+" << endl;

    if (empty())
        cout << "\nClass list is empty!" << endl;
    else
    {
        for (int i = 0; i < size; i++)
        {
            data[i]->showData();
            cout << endl;
        }
        cout << "\t" << "+-----------+--------------------+--------+" << endl;
    }
    
}

void Classes_list::set_students_linked_list(Student_linked_list *student_linked_list, int index)
{
    data[index]->set_student_list(student_linked_list);
}

Student_linked_list *Classes_list::get_students_linked(int index)
{
    return data[index]->get_student_list();
}

Student_linked_list *Classes_list::get_students_linked(string classID)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i]->get_id() == classID)
            return data[i]->get_student_list();
    }
    throw string(" Student list not found!!");
    
}

void Classes_list::replace_subject_name(string name, int index)
{
    data[index]->set_name(name);
}

void Classes_list::replace_subject_id(string id, int index)
{
    data[index]->set_id(id);
}

int Classes_list::get_size() const
{
    return size;
}

int Classes_list::get_capacity() const
{
    return capacity;
}

void Classes_list::set_capacity(int capacity)
{
    this->capacity = capacity;
}

Class **Classes_list::get_data() const
{
    return data;
}

void Classes_list::set_data(Class **data)
{
    this->data = data;
}

void Classes_list::resize()
{
    Class **temp = data;

    capacity *= 2;
    data = new Class *[capacity];

    for (int i = 0; i < size; i++)
    {
        data[i] = temp[i];
    }
    delete[] temp;
}

Classes_list::Classes_list()
{
    size = 0;
    capacity = 2;
    data = new Class *[capacity];
}

Classes_list::~Classes_list()
{
    for (int i = 0; i < size; i++)
    {
        delete data[i];
    }
    delete[] data;
}
