#pragma once
#include "declare_menu.h"

void add_class();
void modify_class();
void remove_class();
void show_class();

void menu_class()
{
    while (1)
    {
        system("cls");
        SetColor(Color::BROWN);
        cout << "\n\t+---------------------------------------+";
        cout << "\n\t|         ***** MENU CLASS *****        |";
        cout << "\n\t|            1. Add class               |";
        cout << "\n\t|            2. Delete class            |";
        cout << "\n\t|            3. Modify class            |";
        cout << "\n\t|            4. Show class list         |";
        cout << "\n\t|            0. Exit                    |";
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

        else if (choice < 0 || choice > 4)
        {
            SetColor(Color::RED);
            cout << "\n[Error]: Incorrect choice!!" << endl;
            getch();
        }
        else if (choice == 1)
        {
            add_class();
        }
        else if (choice == 2)
        {
            remove_class();
        }
        else if (choice == 3)
        {
            modify_class();
        }
        else if (choice == 4)
        {
            show_class();
        }
        else
        {
            break;
        }
    }
}

void add_class()
{
    clas.getInfoFromInput();
    try
    {
        if (class_list->contain_id(clas.get_id()) != -1)
        {
            throw string("id existed!!");
        }
        class_list->push_back(clas);
        DM.save_classes_list(class_list);
        SetColor(Color::GREEN);
        cout << "\nSuccessful!" << endl;
        SetColor(Color::WHITE);
    }
    catch (string &e)
    {
        SetColor(Color::RED);
        cout << "error: " << e << "\n";
    }
    SetColor(Color::WHITE);
    getch();
}

void modify_class()
{
    string classID;
    cout << "\nEnter class ID to modify: ";
    cin.ignore();
    getline(cin, classID);

    try
    {
        if (class_list->contain_id(classID) == -1)
        {
            throw string("Class id doesn't exist!!");
        }
        clas.getInfoFromInput(true); // true khong cho phep sua id
        class_list->replace_class_by_ID(classID, clas);
        DM.save_classes_list(class_list);
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

void remove_class()
{
    // bị bug - xóa lớp nhưng ngoài file student ko xóa
    string classID;
    cout << "\nEnter class ID to delete: ";
    cin.ignore();
    getline(cin, classID);

    try
    {
        if (class_list->contain_id(classID) == -1)
        {
            throw string("Class id doesn't exist!!");
        }
        class_list->delete_by_id(classID);
        DM.save_classes_list(class_list);
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

void show_class()
{
    class_list->show_data();
    getch();
}
