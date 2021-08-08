#pragma one
#include "7_DVKha_041_Menu_class.h"
#include "7_DVKha_041_Menu_student.h"
#include "7_DVKha_041_Menu_subject.h"
#include "7_DVKha_041_Menu_point.h"

void menu()
{
    while (1)
    {
        system("cls");
        SetColor(Color::CYAN);
        cout << "\t\t+---------------------------------------+" << endl
             << "\t\t|             ****MENU****              |" << endl
             << "\t\t|               1. Class                |" << endl
             << "\t\t|               2. Student              |" << endl
             << "\t\t|               3. Subject              |" << endl
             << "\t\t|               4. Point                |" << endl
             << "\t\t|               0. Exit                 |" << endl
             << "\t\t+---------------------------------------+" << endl
             << endl
             << endl;
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
        else if (choice < 0 || choice > 4)
        {
            SetColor(Color::RED);
            cout << "\n[Error]: Incorrect choice!!" << endl;
            getch();
        }
        else if (choice == 1)
        {
            menu_class();
        }
        else if (choice == 2)
        {
            menu_student();
        }
        else if (choice == 3)
        {
            menu_subject();
        }
        else if (choice == 4)
        {
            menu_point();
        }
        else
        {
            break;
        }
    }
}
