#include "Student.h"
#include <conio.h>

void menu();

int main()
{
    menu();
    getch();
    return 0;
}

void menu()
{
    Student *A = new Student;
    int choice;
    while (true)
    {
        system("cls");
        cout << "\t\t+-----------------------------------------+" << endl
             << "\t\t|               ****MENU****              |" << endl
             << "\t\t|    1. Get Info Student                  |" << endl
             << "\t\t|    2. Show Info Student                 |" << endl
             << "\t\t|    3. ABCD                              |" << endl
             << "\t\t|    4. ABCD                              |" << endl
             << "\t\t|    0. Exit                              |" << endl
             << "\t\t+-----------------------------------------+" << endl
             << endl
             << endl;
        cout << "\nMake a choice: ";
        cin >> choice;
        if (choice < 0 || choice > 4)
            cout << "Unhappy choice!" << endl;

        else if (choice == 1)
        {
            A->getDataFromInput();
        }
        else if (choice == 2)
        {
            A->showData();
            getch();
        }
        else
        {
            break;
        }
    }
}