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
            
            getch();
        }
        else if (choice == 2)
        {
            
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
    getline(cin, class_id);

    try
    {
        if (class_list->contain_id(classID) == -1)
        {
            throw string("Class id doesn't exist!!");
        }

        // class_list->delete_by_id(classID);
        // DM.save_classes_list(class_list);
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