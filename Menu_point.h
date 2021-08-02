#pragma once
#include "declare_menu.h"


void add_point();
void show_point_list();
void show_average_point();


void menu_point()
{
    while (1)
    {
        system("cls");
        SetColor(Color::LIGHTRED);
        cout << "\n\t+---------------------------------------+";
        cout << "\n\t|        ***** MENU POINT *****         |";
        cout << "\n\t|          1. Add point                 |";
        cout << "\n\t|          2. Delete point              |";
        cout << "\n\t|          3. Modify point              |";
        cout << "\n\t|          4. Show point list           |";
        cout << "\n\t|          5. Show average point list   |";
        cout << "\n\t|          6. Show final point list     |";
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
            cout << "Hello!";
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
        else if (choice == 5)
        {

        }
        else if (choice == 6)
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

}