#include <conio.h>
#include "Database_Manager.h"

Classes_list *class_list = nullptr;

void insertStudent();
void show_student_by_class();

void menu()
{
    string class_list_file_path = "Data/Classes/classes_list.csv";

    Database_Manager DM;

    class_list = DM.read_classes_list(class_list_file_path);

    int choice;
    while (1)
    {
        system("cls");
        cout << "\t\t+---------------------------------------+" << endl
             << "\t\t|             ****MENU****              |" << endl
             << "\t\t|               1. Class                |" << endl
             << "\t\t|               2. Student              |" << endl
             << "\t\t|               3. Point                |" << endl
             << "\t\t|               4. ABCD                 |" << endl
             << "\t\t|               0. Exit                 |" << endl
             << "\t\t+---------------------------------------+" << endl
             << endl
             << endl;

        do
        {
            cout << "\n\nMake a choice: ";
            cin >> choice;
            if (choice < 0 || choice > 5)
            {
                cout << "Unhappy choice!" << endl;
                getch();
            }
        } while (choice < 0 || choice > 5);

        if (choice == 1)
        {
            Class clas;
            while (1)
            {
                system("cls");
                cout << "\n\t+---------------------------------------+";
                cout << "\n\t|         ***** MENU CLASS *****        |";
                cout << "\n\t|            1. Add class               |";
                cout << "\n\t|            2. Delete class            |";
                cout << "\n\t|            3. Modify class            |";
                cout << "\n\t|            4. Show class list         |";
                cout << "\n\t|            0. Exit                    |";
                cout << "\n\t+---------------------------------------+";

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
                    clas.getInfoFromInput();
                    class_list->push_back(clas);
                    DM.save_classes_list(class_list);
                    cout << "\nSuccessful!" << endl;
                    getch();
                }
                else if (choice == 4)
                {
                    cout << "\n\t====== CLASS LIST =======" << endl;
                    class_list->show_data();
                    getch();
                }
                else
                {
                    break;
                }
            }
        }
        else if (choice == 4)
        {
            insertStudent();
            DM.save_classes_list(class_list);
            cout << "\nSuccessful!" << endl;
            getch();
        }
        else if (choice == 5)
        {
            show_student_by_class();
            getch();
        }
        else
        {
            break;
        }
    }
}

void show_student_by_class()
{
    string classId;
    cout << "Enter class id: ";
    cin.ignore();
    getline(cin, classId);
    try
    {
        Student_linked_list *studentList = class_list->get_students_linked(classId);
        if (studentList == nullptr)
        {
            cout << "\nStudent list is empty!\n";
            studentList = new Student_linked_list();
        }
        studentList->show_data();
    }
    catch (string &e)
    {
        std::cout << e << "\nID class don't exist.\n";
    }
}

void insertStudent()
{
    string classId;
    cout << "Enter class ID: ";
    cin.ignore();
    getline(cin, classId);

    try
    {
        Student_linked_list *studentList = class_list->get_students_linked(classId);
        if (studentList == nullptr)
        {
            cout << "\nStudent list is empty!\n";
            studentList = new Student_linked_list();
        }
        Student student;
        student.getDataFromInput();
        // if (student.get_id() == class_list->contain_id(student.get_id()))
        // {
        //     throw string("Student ID is exist!");
        // }
        studentList->push_back(student);

        class_list->set_students_linked(classId, studentList);

        Student_linked_list *studentList2 = class_list->get_students_linked(classId);
        getch();
    }
    catch (string &e)
    {
        cout << "error: " << e << "\n";
    }
}