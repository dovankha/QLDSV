#include "declare_menu.h"

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
        do
        {
            cout << "\n\nMake a choice: ";
            cin >> choice;
            if (choice < 0 || choice > 4)
            {
                cout << "Unhappy choice!" << endl;
                getch();
            }
        } while (choice < 0 || choice > 4);

        if (choice == 1)
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
    try
    {
        if (subject_tree->get_size() == 0)
        {
            cout << "\nSubject list is empty!\n";
        }
        Subject subject;
        subject.getDataFromInput();

        // if ()
        // {
        //     throw string("id existed!!");
        // }

        subject_tree->insert(subject);
    }
    catch (string &e)
    {
        cout << "error: " << e << "\n";
    }
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
            cout << "\nSubject list is empty!\n";
        }
        else
        {
            // Subject_node *node = new Subject_node();
            // for (int i = 0; i < subject_tree->get_size(); i++)
            // {
            //     if (subject_id == node->data.get_subject_id())
            //         subject_tree->remove(node->data.get_subject_id());
            // }
            subject_tree->remove(subject_id);
            // chua tim subject_id
            cout << "\nSuccessful!!";
        }
    }
    catch (string &e)
    {
        SetColor(Color::RED);
        cout << "error: " << e << "\n";
    }
    SetColor(Color::WHITE);
    DM.save_subject_tree(subject_tree);
    getch();
}

void modify_subject()
{
    string subject_id;
    cout << "\nEnter subject ID to modify: ";
    cin.ignore();
    getline(cin, subject_id);
    try
    {
        if (subject_tree->get_size() == 0)
        {
            throw string("\nSubject list is empty!!!");
        }
        Subject subject;
        subject.getDataFromInput();
        subject_tree->replace_subject_by_id(subject_id, subject);

        if (subject_tree->contain_id(subject.get_subject_id()) == -1)
        {
            throw string("Subject ID doesn't exist!!");
        }

        subject_tree->insert(subject);
    }
    catch (string &e)
    {
        cout << "error: " << e << "\n";
    }
    getch();
}

void show_subject()
{
    subject_tree->showTree();
    getch();
}