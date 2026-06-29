#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool issued;

    void addBook()
    {
        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;
    }

    void displayBook()
    {
        cout << "\nBook ID      : " << id;
        cout << "\nTitle        : " << title;
        cout << "\nAuthor       : " << author;
        cout << "\nStatus       : ";

        if (issued)
            cout << "Issued";
        else
            cout << "Available";

        cout << "\n---------------------------";
    }
};

int main()
{
    Book books[100];
    int count = 0;
    int choice;

    do
    {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            books[count].addBook();
            count++;
            cout << "\nBook Added Successfully!\n";
            break;
        }

        case 2:
        {
            if (count == 0)
            {
                cout << "\nNo Books Available!\n";
            }
            else
            {
                for (int i = 0; i < count; i++)
                    books[i].displayBook();
            }
            break;
        }

        case 3:
        {
            cin.ignore();
            string key;
            cout << "\nEnter Book Title or Author: ";
            getline(cin, key);

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (books[i].title == key || books[i].author == key)
                {
                    books[i].displayBook();
                    found = true;
                }
            }

            if (!found)
                cout << "\nBook Not Found!\n";

            break;
        }

        case 4:
        {
            int id;
            cout << "\nEnter Book ID to Issue: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (books[i].id == id)
                {
                    found = true;

                    if (!books[i].issued)
                    {
                        books[i].issued = true;
                        cout << "\nBook Issued Successfully!\n";
                    }
                    else
                    {
                        cout << "\nBook Already Issued!\n";
                    }
                }
            }

            if (!found)
                cout << "\nBook ID Not Found!\n";

            break;
        }

        case 5:
        {
            int id;
            cout << "\nEnter Book ID to Return: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (books[i].id == id)
                {
                    found = true;

                    if (books[i].issued)
                    {
                        books[i].issued = false;
                        cout << "\nBook Returned Successfully!\n";
                    }
                    else
                    {
                        cout << "\nBook is Already Available!\n";
                    }
                }
            }

            if (!found)
                cout << "\nBook ID Not Found!\n";

            break;
        }

        case 6:
            cout << "\nThank You for Using Library Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}