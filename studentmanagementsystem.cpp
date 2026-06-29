#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student
{
public:
    int roll;
    char name[50];
    float marks;

    void input()
    {
        cout << "\nEnter Roll No: ";
        cin >> roll;
        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << "\nRoll No : " << roll;
        cout << "\nName    : " << name;
        cout << "\nMarks   : " << marks << endl;
    }
};

void addStudent()
{
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);

    s.input();
    file.write((char *)&s, sizeof(s));

    file.close();
    cout << "\nStudent Added Successfully!\n";
}

void displayStudents()
{
    Student s;
    ifstream file("students.dat", ios::binary);

    cout << "\n------ Student Records ------\n";

    while (file.read((char *)&s, sizeof(s)))
    {
        s.display();
        cout << "-----------------------------\n";
    }

    file.close();
}

void searchStudent()
{
    Student s;
    int r, found = 0;

    cout << "Enter Roll No to Search: ";
    cin >> r;

    ifstream file("students.dat", ios::binary);

    while (file.read((char *)&s, sizeof(s)))
    {
        if (s.roll == r)
        {
            s.display();
            found = 1;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "\nStudent Not Found.\n";
}

void updateStudent()
{
    Student s;
    int r, found = 0;

    cout << "Enter Roll No to Update: ";
    cin >> r;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    while (file.read((char *)&s, sizeof(s)))
    {
        if (s.roll == r)
        {
            cout << "\nEnter New Details\n";
            s.input();

            file.seekp(-sizeof(s), ios::cur);
            file.write((char *)&s, sizeof(s));

            found = 1;
            cout << "\nRecord Updated Successfully.\n";
            break;
        }
    }

    file.close();

    if (!found)
        cout << "\nStudent Not Found.\n";
}

void deleteStudent()
{
    Student s;
    int r, found = 0;

    cout << "Enter Roll No to Delete: ";
    cin >> r;

    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while (file.read((char *)&s, sizeof(s)))
    {
        if (s.roll != r)
            temp.write((char *)&s, sizeof(s));
        else
            found = 1;
    }

    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        cout << "\nRecord Deleted Successfully.\n";
    else
        cout << "\nStudent Not Found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Student Management System =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            updateStudent();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            cout << "\nThank You!\n";
            break;
        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}