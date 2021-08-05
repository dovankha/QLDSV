#pragma once
#include <stack>
#include <fstream>
#include "Point.h"
#include "Point_linked_list.h"
#include "Student.h"
#include "Student_linked_list.h"
#include "Class.h"
#include "Class_list.h"
#include "Subject.h"
#include "Subject_tree.h"
#include "Graphic.h"

class Database_Manager
{

    string subject_list_file_path = "Data/subject_list.csv";
    string point_list_file_path = "Data/Classes/Students/points_list/";
    string student_list_file_path = "Data/Classes/Students/";
    string class_list_file_path = "Data/Classes/classes_list.csv";

public:
    void save_class(Class &clas, ofstream &file);
    Class read_class(ifstream &file);
    void save_classes_list(Classes_list *class_list);
    Classes_list *read_classes_list(string file_path);

    void save_student(Student &student, ofstream &file);
    Student read_student(ifstream &file);
    void save_students_linked_list(Student_linked_list *students_linked_list, string file_path);
    Student_linked_list *read_student_linked_list(string file_path);

    void save_point(Point &point, ofstream &file);
    Point read_point(ifstream &file);
    void save_points_linked_list(Point_linked_list *point_linked_list, string file_path);
    Point_linked_list *read_points_linked_list(string file_path);

    void save_subject(Subject &subject, ofstream &file);
    Subject read_subject(ifstream &file);
    void save_subject_tree(Subject_tree *subject_tree);
    Subject_tree *read_subject_tree(string file_path);

    Database_Manager();
    ~Database_Manager();
};

void Database_Manager::save_subject(Subject &subject, ofstream &file)
{
    file << subject;
}

Subject Database_Manager::read_subject(ifstream &file)
{
    Subject n;
    file >> n;
    return n;
}

void Database_Manager::save_subject_tree(Subject_tree *subject_tree)
{
    ofstream file(subject_list_file_path);
    stack<Subject_node *> my_stack;
    auto root = subject_tree->get_root();
    file << subject_tree->get_size() << '\n';
    while (true)
    {
        while (root)
        {
            my_stack.push(root);
            root = root->left;
        }
        if (my_stack.empty())
        {
            break;
        }
        else
        {
            root = my_stack.top();
            save_subject(root->data, file);
            my_stack.pop();
            root = root->right;
        }
    }
}

Subject_tree *Database_Manager::read_subject_tree(string file_path)
{
    ifstream file(file_path);
    if (!file.is_open())
    {
        return new Subject_tree();
    }

    int size = 0;
    string line;

    file >> size;
    getline(file, line);

    if (size == 0)
    {
        return nullptr;
    }

    Subject_tree *subject_tree = new Subject_tree();

    for (int i = 0; i < size; i++)
    {
        Subject subject = read_subject(file);
        subject_tree->insert(subject);
    }
    file.close();

    return subject_tree;
}

void Database_Manager::save_point(Point &point, ofstream &file)
{
    file << point;
}

Point Database_Manager::read_point(ifstream &file)
{
    Point n;
    file >> n;
    return n;
}

void Database_Manager::save_points_linked_list(Point_linked_list *point_linked_list, string file_path)
{
    ofstream file(file_path);
    file << point_linked_list->get_size() << "\n";
    for (auto temp = point_linked_list->get_head(); temp != nullptr; temp = temp->next)
    {
        save_point(temp->data, file);
    }
    file.close();
}

Point_linked_list *Database_Manager::read_points_linked_list(string file_path)
{
    ifstream file(file_path);
    if (!file.is_open())
        return nullptr;
    int size;
    file >> size;
    string line;
    getline(file, line);
    Point_linked_list *point_linked_list = new Point_linked_list;
    for (int i = 0; i < size; i++)
    {
        auto new_point = read_point(file);
        point_linked_list->push_front(new_point);
    }
    file.close();
    return point_linked_list;
}

void Database_Manager::save_student(Student &student, ofstream &file)
{
    file << student;
    file << endl;
}

Student Database_Manager::read_student(ifstream &file)
{
    Student s;
    file >> s;
    return s;
}

void Database_Manager::save_students_linked_list(Student_linked_list *students_linked_list, string file_path)
{
    ofstream file(file_path);
    file << students_linked_list->get_size() << "\n";
    for (auto temp = students_linked_list->get_head(); temp != nullptr; temp = temp->next)
    {
        save_student(temp->data, file);
        string path = point_list_file_path + temp->data.get_id() + ".csv";
        if (temp->data.get_points_list() != nullptr)
        {
            save_points_linked_list(temp->data.get_points_list(), path);
        }
    }
    file.close();
}

Student_linked_list *Database_Manager::read_student_linked_list(string file_path)
{
    ifstream file(file_path);

    if (!file.is_open())
        return nullptr;

    int size;
    file >> size;
    string line;
    getline(file, line);

    Student_linked_list *student_linked_list = new Student_linked_list;

    for (int i = 0; i < size; i++)
    {
        Student student = read_student(file);
        student_linked_list->push_front(student);

        string path = point_list_file_path + student.get_id() + ".csv";
        Point_linked_list *points = read_points_linked_list(path);
        if (points != nullptr)
        {
            student_linked_list->set_points_linked_list(points, 0);
        }
        else
        {
            delete points;
        }
    }
    file.close();

    return student_linked_list;
}

void Database_Manager::save_class(Class &clas, ofstream &file)
{
    file << clas;
}

Class Database_Manager::read_class(ifstream &file)
{
    Class c;
    file >> c;
    return c;
}

void Database_Manager::save_classes_list(Classes_list *class_list)
{
    ofstream file(class_list_file_path);

    file << class_list->get_size() << '\n';

    for (int i = 0; i < class_list->get_size(); i++)
    {
        save_class(*class_list->get_data()[i], file);
        string path = student_list_file_path + class_list->get_data()[i]->get_id() + ".csv";
        if (class_list->get_data()[i]->get_student_list() != nullptr)
        {
            save_students_linked_list(class_list->get_data()[i]->get_student_list(), path);
        }
    }
    file.close();
}

Classes_list *Database_Manager::read_classes_list(string file_path)
{
    ifstream file(class_list_file_path);

    if (!file.is_open())
        return new Classes_list();

    int size = 0;
    file >> size;
    string line;
    getline(file, line);

    Classes_list *classes_list = new Classes_list();

    for (int i = 0; i < size; i++)
    {
        Class c = read_class(file);
        classes_list->push_back(c);

        string path = student_list_file_path + c.get_id() + ".csv";
        Student_linked_list *students = read_student_linked_list(path);
        if (students != nullptr)
        {
            classes_list->set_students_linked_list(students, i);
        }
        else
        {
            delete students;
        }
    }

    file.close();

    return classes_list;
}

Database_Manager::Database_Manager()
{
}

Database_Manager::~Database_Manager()
{
}
