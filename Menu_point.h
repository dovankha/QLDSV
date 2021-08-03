#pragma once
#include "declare_menu.h"


// nhap lop id
// nhap lan thi
// nhap ma sinh vien
// tim co sinh vien : nhap diem cho no


void add_point();
void show_point_list();
void show_average_point_list();
void show_final_point_list();


void menu_point()
{
    while (1)
    {
        system("cls");
        SetColor(Color::LIGHTRED);
        cout << "\n\t+---------------------------------------+";
        cout << "\n\t|        ***** MENU POINT *****         |";
        cout << "\n\t|          1. Add point                 |";
        cout << "\n\t|          2. Show point list           |";
        cout << "\n\t|          3. Show average point list   |";
        cout << "\n\t|          4. Show final point list     |";
        cout << "\n\t|          0. Exit                      |";
        cout << "\n\t+---------------------------------------+";
        SetColor(Color::WHITE);

        cout << "\n\nMake a choice: ";
        cin >> choice;
        if (cin.fail())
        {
            SetColor(Color::RED);
            cout << "\n[Error]: Only numbers!!" << endl;
            getch();
            cin.clear();
            cin.ignore(256, '\n');
        }

        else if (choice < 0 || choice > 6)
        {
            SetColor(Color::RED);
            cout << "\n[Error]: Incorrect choice!!" << endl;
            getch();
        }
        else if (choice == 1)
        {
            add_point();
        }
        else if (choice == 2)
        {
            show_point_list();
        }
        else if (choice == 3)
        {
            
        }
        else if (choice == 4)
        {
            
        }
        else
        {
            break;
        }
    }
}

void add_point()
{
    string class_id;
    cout << "\nEnter class ID to add point for student: ";
    cin.ignore();
    getline(cin, class_id);
    string student_id;
    cout << "\nEnter student ID: ";
    cin.ignore();
    getline(cin, student_id);

    try 
    {
        if (class_list->contain_id(class_id) == -1)
        {
            throw string("Class id doesn't exist!!");
        }
        Student_linked_list *studentList = class_list->get_students_linked(class_id);
        point.addData();
        studentList->add_point(student_id, point);
        SetColor(Color::GREEN);
        cout << "\nSuccessful!" << endl;
        SetColor(Color::WHITE);
    }

    catch (string &e)
    {
        SetColor(Color::RED);
        cout << "error: " << e << "\n";
        SetColor(Color::WHITE);
    }
    getch();
}

void show_point_list()
{
    point.showData();
    // point_list->show_data();
    getch();
}