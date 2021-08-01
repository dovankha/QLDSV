#include <conio.h>
#include "Graphic.h"
#include "Database_Manager.h"

int choice; // choice of menu

string class_list_file_path = "Data/Classes/classes_list.csv";
string subject_list_file_path = "Data/subject_list.csv";
Database_Manager DM;
Classes_list *class_list = DM.read_classes_list(class_list_file_path);
Subject subject;

void menu_class();
void menu_student();
void menu_subject();
void menu_point();
void insertSubject();
void deleteSubject();
void insertStudent();
void deleteStudent();
void show_student_by_class();

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
        else
        {
            break;
        }
    }
}

void menu_class()
{
    Class clas;
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
        else if (choice == 2)
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
        else if (choice == 3)
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
        else if (choice == 4)
        {
            class_list->show_data();
            getch();
        }
        else
        {
            break;
        }
    }
}

void menu_student()
{
    while (1)
    {
        system("cls");
        SetColor(Color::YELLOW);
        cout << "\n\t+---------------------------------------+";
        cout << "\n\t|       ***** MENU STUDENT *****        |";
        cout << "\n\t|            1. Add student             |";
        cout << "\n\t|            2. Delete student          |";
        cout << "\n\t|            3. Modify student          |";
        cout << "\n\t|            4. Show student list       |";
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
            insertStudent();
            DM.save_classes_list(class_list);
            getch();
        }
        else if (choice == 2)
        {
            deleteStudent();
            cout << "\nSuccessful!" << endl;
            getch();
        }

        else if (choice == 4)
        {
            // bị bug - chỗ đọc file (có id lop nhung ko doc duoc sinh vien).
            show_student_by_class();
            getch();
        }
        else
        {
            break;
        }
    }
}

void menu_subject()
{
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
            insertSubject();
        }
        else if (choice == 4)
        {
            subject.showData();
            getch();
        }

        else
        {
            break;
        }
    }
}

// nhap lop id
// nhap lan thi
// nhap ma sinh vien
// tim co sinh vien : nhap diem cho no

void insertSubject()
{
    try
    {
        Subject_tree *subject_tree = new Subject_tree();
        if (subject_tree->get_size() == 0)
        {
            cout << "\nSubject list is empty!\n";
            // studentList = new Student_linked_list();
        }
        subject.getDataFromInput();
       

        // if ()
        // {
        //     throw string("id existed!!");
        // }

        subject_tree->insert(subject_tree, subject);
    }
    catch (string &e)
    {
        cout << "error: " << e << "\n";
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
        studentList->ssort();
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

        if (studentList->is_contain_id(student.get_id()) != -1)
        {
            throw string("id existed!!");
        }

        studentList->push_back(student);
        class_list->set_students_linked(classId, studentList);

        Student_linked_list *studentList2 = class_list->get_students_linked(classId);
        studentList2->ssort();
    }
    catch (string &e)
    {
        cout << "error: " << e << "\n";
    }
}

void deleteStudent()
{
    string classId;
    cout << "Enter class ID: ";
    cin.ignore();
    getline(cin, classId);
    string student_ID;
    cout << "\nEnter class ID to delete: ";
    cin.ignore();

    try
    {
        Student_linked_list *studentList = class_list->get_students_linked(classId);
        if (studentList == nullptr)
        {
            cout << "\nStudent list is empty!\n";
            studentList = new Student_linked_list();
        }
        studentList->remove_by_id(student_ID);
        class_list->set_students_linked(classId, studentList);

        Student_linked_list *studentList2 = class_list->get_students_linked(classId);
    }
    catch (string &e)
    {
        SetColor(Color::RED);
        cout << "error: " << e << "\n";
    }
    SetColor(Color::WHITE);
}