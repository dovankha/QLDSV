#pragma once
#include "7_DVKha_041_Declare_menu.h"

void add_subject();
void remove_subject();
void modify_subject();
void show_subject();

void menu_subject()
{
    int choice;
    while (1)
    {
        system("cls");
        SetColor(Color::MAGENTA);
        cout << "\n\t+---------------------------------------+";
        cout << "\n\t|       ***** MENU SUBJECT *****        |";
        cout << "\n\t|            1. Add subject             |";
        cout << "\n\t|            2. Delete subject          |";
        cout << "\n\t|            3. Modify subject          |";
        cout << "\n\t|            4. Show subject list       |";
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

        else if (choice < 0 || choice > 5)
        {
            SetColor(Color::RED);
            cout << "\n[Error]: Incorrect choice!!" << endl;
            getch();
        }

        else if (choice == 1)
        {
            add_subject();
        }
        else if (choice == 2)
        {
            remove_subject();
        }
        else if (choice == 3)
        {
            modify_subject();
        }
        else if (choice == 4)
        {
            show_subject();
        }
        else
        {
            break;
        }
    }
}

void add_subject()
{
        if (subject_tree->get_size() == 0)
        {
            SetColor(Color::RED);
            cout << "\nSubject list is empty!\n";
        }
        Subject subject;
        subject.getDataFromInput();
        subject_tree->insert(subject);
        DM.save_subject_tree(subject_tree);
        getch();
}

void remove_subject()
{
    Subject subject;
    string subject_id;
    cout << "\nEnter subject ID to delete: ";
    cin.ignore();
    getline(cin, subject_id);
    try
    {
        if (subject_tree->get_size() == 0)
        {
            throw string ("Subject list is empty!\n");
        }
        if ((subject_tree->contain_id(subject_id)) == -1)
        {
            throw string("Subject doesn't exist!!");
        }

        subject_tree->remove(subject_id);
        DM.save_subject_tree(subject_tree);
        SetColor(Color::GREEN);
        cout << "\nSuccessful!!";
    }
    catch (string &e)
    {
        SetColor(Color::RED);
        cout << "\n[Error]: " << e << "\n";
    }
    getch();
}

void modify_subject()
{
    string subject_id;
    cout << "\nEnter subject ID: ";
    cin.ignore();
    getline(cin, subject_id);

    try
    {
        if (subject_tree->get_size() == 0)
        {
            throw string("Subject list is empty!!!");
        }
        Subject subject;
        subject.set_subject_id(subject_id);

        if (subject_tree->contain_id(subject.get_subject_id()) == -1)
        {
            throw string("Subject ID doesn't exist!!");
        }
        subject_tree->replace_subject_by_id(subject_id, subject);
        DM.save_subject_tree(subject_tree);
    }
    catch (string &e)
    {
        SetColor(Color::RED);
        cout << "\n[Error]: " << e << "\n";
    }
    getch();
}

void show_subject()
{
    subject_tree->showTree();
    getch();
}