#pragma once
#include "declare_menu.h"

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
    getline(cin, student_id);

    cout << "student_id : " << student_id << endl;

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

        DM.save_classes_list(class_list);
        // luu class
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
    try
    {
        string subject_id;
        cout << "\nEnter subject id: ";
        cin.ignore();
        getline(cin, subject_id);
        string class_id;
        cout << "\nEnter class id: ";
        getline(cin, class_id);
        int time;
        cout << "\nEnter time of the test: ";
        cin >> time;

        cout << "student list class :" << class_id << "\n"; 
        // lay dnh sinh vien cua lop hoc ra
        Student_linked_list *student_list = class_list->get_students_linked(class_id);

        if(student_list == nullptr){
            throw string("student list empty\n");
        }
     
        // duyet danh sach sv
        // duyet danh sach diem cua tung sinh vien
        for(Student_node *studentNode = student_list->get_head();studentNode != nullptr;studentNode = studentNode->next){
            if( studentNode->data.point_list == nullptr){
                continue;
            }

            for(Point_node* pointNode = studentNode->data.point_list->get_head();pointNode != nullptr;pointNode = pointNode->next){
                if(pointNode->data.get_subject_id() == subject_id && pointNode->data.get_time() ==  time){
                    cout << studentNode->data.get_first_name() << " :  " << pointNode->data.get_point() << "\n";
                }
            }
        }



        // diuet danh sach sv
        // tinh dim trung binh
        // in ra


        // duyt danh sach lop
        // duyet sinh vien cua tung lop
        // duyet diem cua tung sinh vien
      
    }catch(string &e){
        cout << e << "\n";
    }
    
    getch();
}