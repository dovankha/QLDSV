#pragma once
#include "7_DVKha_041_Declare_menu.h"
#include "7_DVKha_041_Subject_tree.h"

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
            show_average_point_list();
        }
        else if (choice == 4)
        {
            show_final_point_list();
        }
        else
        {
            break;
        }
    }
}

void add_point()
{
    try
    {
        string class_id;
        cout << "\nEnter class ID: ";
        cin.ignore();
        getline(cin, class_id);
        if (class_list->contain_id(class_id) == -1)
        {
            throw string("Class id doesn't exist!!");
        }
        Student_linked_list *studentList = class_list->get_students_linked(class_id);
        string student_id;
        cout << "Enter student ID: ";
        getline(cin, student_id);
        if ((studentList->is_contain_id(student_id)) == -1)
        {
            throw string("Student id doesn't exist!!");
        }
        point.addData();
        studentList->add_point(student_id, point);
        DM.save_classes_list(class_list);

        SetColor(Color::GREEN);
        cout << "\nSuccessful!" << endl;
    }
    catch (string &e)
    {
        SetColor(Color::RED);
        cout << "\n[Error]: " << e << "\n";
        SetColor(Color::WHITE);
    }
    getch();
}

void show_point_list()
{
    try
    {
        string class_id;
        cout << "\nEnter class id: ";
        cin.ignore();
        getline(cin, class_id);
        if (class_list->contain_id(class_id) == -1)
        {
            throw string("Class id doesn't exist!!");
        }
        string subject_id;
        cout << "Enter subject id: ";
        getline(cin, subject_id);
        string time;
        cout << "Enter time: ";
        getline(cin, time);
        while (cin.fail() || time < "1")
        {
            SetColor(Color::RED);
            cout << "\n[Error]: Time > 0, please!!\n"
                 << endl;
            SetColor(Color::WHITE);
            cin.ignore(256, '\n');
            cout << "Enter time: ";
            getline(cin, time);
        }

        Student_linked_list *student_list = class_list->get_students_linked(class_id);

        if (student_list == nullptr)
        {
            throw string("Student list empty\n");
        }
        cout << "\n\t\t   ====== POINT LIST BY SUBJECT ======\n"
             << endl;
        cout << "\t\tCLASS ID: " << class_id << "\tSUBJECT ID: " << subject_id << "\tTIME: " << time << endl;
        cout << "\t+----------+------------+----------------------+---------+" << endl;
        cout << "\t|    ID    | Frist Name |      Last Name       |  Point  |" << endl;
        cout << "\t+----------+------------+----------------------+---------+" << endl;
        for (Student_node *studentNode = student_list->get_head(); studentNode != nullptr; studentNode = studentNode->next)
        {
            if (studentNode->data.point_list == nullptr)
            {
                continue;
            }
            for (Point_node *pointNode = studentNode->data.point_list->get_head(); pointNode != nullptr; pointNode = pointNode->next)
            {
                if (pointNode->data.get_subject_id() == subject_id && pointNode->data.get_time() == time)
                {
                    cout << "\t|" << left << setw(10) << studentNode->data.get_id()
                         << "|" << left << setw(12) << studentNode->data.get_first_name()
                         << "|" << left << setw(22) << studentNode->data.get_last_name()
                         << "|" << left << setw(9) << pointNode->data.get_point() << "|\n";
                }
            }
        }
        cout << "\t+----------+------------+----------------------+---------+" << endl;
    }
    catch (string &e)
    {
        SetColor(Color::RED);
        cout << "\n[Error]: " << e << "\n";
        cin.ignore();
    }
    getch();
}

void show_average_point_list()
{
    float sum_point = 0;
    float summ = 0;
    float averange_point = 0;
    int count = 0;
    try
    {
        string class_id;
        cout << "\nEnter class id: ";
        cin.ignore();
        getline(cin, class_id);
        if (class_list->contain_id(class_id) == -1)
        {
            throw string("Class id doesn't exist!!");
        }

        Student_linked_list *student_list = class_list->get_students_linked(class_id);

        if (student_list == nullptr)
        {
            throw string("Student list empty\n");
        }
        cout << "\n\t\t   ====== POINT AVERAGE LIST ======\n"
             << endl;
        cout << "\t\tCLASS ID: " << class_id << "\tYEAR: " << "2019" << endl;
        cout << "\t+----------+------------+----------------------+---------+" << endl;
        cout << "\t|    ID    | Frist Name |      Last Name       |  Point  |" << endl;
        cout << "\t+----------+------------+----------------------+---------+" << endl;
        for (Student_node *studentNode = student_list->get_head(); studentNode != nullptr; studentNode = studentNode->next)
        {
            if (studentNode->data.point_list == nullptr)
            {
                continue;
            }
            for (Point_node *pointNode = studentNode->data.point_list->get_head(); pointNode != nullptr; pointNode = pointNode->next)
            {
                for (Point_node *pointNode2 = pointNode->next; pointNode2 != nullptr; pointNode2 = pointNode2->next)
                {
                    if (pointNode->data.get_subject_id() == pointNode2->data.get_subject_id())
                        sum_point = pointNode->data.get_point() + pointNode2->data.get_point();
                    else
                        sum_point = pointNode->data.get_point();
                    summ += sum_point;
                    count++;
                }
            }
            averange_point = summ/count;
            for (Point_node *pointNode = studentNode->data.point_list->get_head(); pointNode != nullptr; pointNode = pointNode->next)
            {
                {
                    cout << "\t|" << left << setw(10) << studentNode->data.get_id()
                         << "|" << left << setw(12) << studentNode->data.get_first_name()
                         << "|" << left << setw(22) << studentNode->data.get_last_name()
                         << "|" << left << setw(9) << averange_point << "|\n";
                }
            }
        }
        cout << "\t+----------+------------+----------------------+---------+" << endl;
    }
    catch (string &e)
    {
        SetColor(Color::RED);
        cout << "\n[Error]: " << e << "\n";
        cin.ignore();
    }
    getch();
}

void show_final_point_list()
{
    string class_id;
    cout << "\nEnter class id: ";
    cin.ignore();
    getline(cin, class_id);

    Student_linked_list *student_list = class_list->get_students_linked(class_id);

    if (student_list == nullptr)
    {
        throw string("Student list empty\n");
    }

    for (Student_node *studentNode = student_list->get_head(); studentNode != nullptr; studentNode = studentNode->next)
    {
        if (studentNode->data.point_list == nullptr)
        {
            continue;
        }
        for (Point_node *pointNode = studentNode->data.point_list->get_head(); pointNode != nullptr; pointNode = pointNode->next)
        {
            if ((class_list->contain_id(class_id)) != -1)
            {
                cout << "\n\t\t ====== POINT LIST BY CLASS ======" << endl;
                cout << "\t+----------+------------+----------------------+---------+" << endl;
                cout << "\t|    ID    | Frist Name |      Last Name       |  Point  |" << endl;
                cout << "\t+----------+------------+----------------------+---------+" << endl;
                cout << "\t| " << left << setw(10) << studentNode->data.get_id()
                     << "| " << left << setw(12) << studentNode->data.get_first_name()
                     << "| " << left << setw(22) << studentNode->data.get_last_name()
                     //  << "| " << left << setw(9) << pointNode->data.get_point()
                     // dung vong for de hien thi cac ma mon hoc ra
                     << "|\n";
                cout << "\t+----------+------------+----------------------+---------+" << endl;
            }
        }
    }
    getch();
}