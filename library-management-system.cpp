#include <iostream>
#include <string>

using namespace std;

class LibraryItem
{

private:
    string title, author, dueDate;
    bool isAvailable = true;

public:
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    LibraryItem()
    {
        this->title = "";
        this->author = "";
        this->dueDate = "";
        this->isAvailable = true;
    }

    LibraryItem(string title, string author, string dueDate)
    {
        this->title = title;
        this->author = author;
        this->dueDate = dueDate;
        this->isAvailable = true;
    };

    virtual ~LibraryItem() {}

    void setTitle(string title) { this->title = title; }
    void setAuthor(string author) { this->author = author; }
    void setDueDate(string dueDate) { this->dueDate = dueDate; }
    void setAvailable(bool status) { this->isAvailable = status; }

    string getTitle() const { return this->title; }
    string getAuthor() const { return this->author; }
    string getDueDate() const { return this->dueDate; }
    bool getAvailable() const { return this->isAvailable; }
};

class Book : public LibraryItem
{
private:
    long long ISBNnum;

public:
    Book(string title, string author, string dueDate, long long ISBN) : LibraryItem(title, author, dueDate)
    {
        this->ISBNnum = ISBN;
    }

    void checkOut()
    {
        if (getAvailable())
        {
            cout << "Book is issued ...." << endl;
            setAvailable(false);
        }
        else
        {
            cout << "Book is not available." << endl;
        }
    }

    void returnItem()
    {
        if (!getAvailable())
        {
            cout << "Book is Returned ...." << endl;
            setAvailable(true);
        }
        else
        {
            cout << "Book is not issued ...." << endl;
        }
    }

    void displayDetails() const
    {
        cout << "\n---------------------------------------" << endl;
        cout << "Type : Book" << endl;
        cout << "Title : " << getTitle() << endl;
        cout << "Author : " << getAuthor() << endl;
        cout << "ISBN Number : " << this->ISBNnum << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "Available : " << (getAvailable() ? "Yes" : "No") << endl;
        cout << "---------------------------------------\n"
             << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string title, string author, string dueDate, int duration) : LibraryItem(title, author, dueDate)
    {
        this->duration = duration;
    }

    void checkOut()
    {
        if (getAvailable())
        {
            cout << "DVD is issued ...." << endl;
            setAvailable(false);
        }
        else
        {
            cout << "DVD is not available." << endl;
        }
    }

    void returnItem()
    {
        if (!getAvailable())
        {
            cout << "DVD is Returned ...." << endl;
            setAvailable(true);
        }
        else
        {
            cout << "DVD is not issued ...." << endl;
        }
    }

    void displayDetails() const
    {
        cout << "\n---------------------------------------" << endl;
        cout << "Type : DVD" << endl;
        cout << "Title : " << getTitle() << endl;
        cout << "Author : " << getAuthor() << endl;
        cout << "DVD Duration : " << this->duration << " Minutes" << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "Available : " << (getAvailable() ? "Yes" : "No") << endl;
        cout << "---------------------------------------\n"
             << endl;
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string title, string author, string dueDate, int number) : LibraryItem(title, author, dueDate)
    {
        this->issueNumber = number;
    }

    void checkOut()
    {
        if (getAvailable())
        {
            cout << "Magazine is issued ...." << endl;
            setAvailable(false);
        }
        else
        {
            cout << "Magazine is not available." << endl;
        }
    }

    void returnItem()
    {
        if (!getAvailable())
        {
            cout << "Magazine is Returned ...." << endl;
            setAvailable(true);
        }
        else
        {
            cout << "Magazine is not issued ...." << endl;
        }
    }

    void displayDetails() const
    {
        cout << "\n---------------------------------------" << endl;
        cout << "Type : Magazine" << endl;
        cout << "Title : " << getTitle() << endl;
        cout << "Author : " << getAuthor() << endl;
        cout << "Issue Number : " << this->issueNumber << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "Available : " << (getAvailable() ? "Yes" : "No") << endl;
        cout << "---------------------------------------\n"
             << endl;
    }
};

int main()
{
    LibraryItem *libraryItems[10];

    libraryItems[0] = new Book("The Alchemist", "Paulo Coelho", "25-05-2026", 9780061122415);
    libraryItems[1] = new Book("Clean Code", "Robert C. Martin", "12-04-2026", 9780132350884);
    libraryItems[2] = new Book("Atomic Habits", "James Clear", "15-04-2026", 9780735211292);
    libraryItems[3] = new DVD("Inception", "Christopher Nolan", "10-04-2026", 148);
    libraryItems[4] = new DVD("Interstellar", "Christopher Nolan", "12-04-2026", 169);
    libraryItems[5] = new DVD("Avengers: Endgame", "Russo Brothers", "15-04-2026", 181);
    libraryItems[6] = new Magazine("National Geographic", "Various", "10-04-2026", 202);
    libraryItems[7] = new Magazine("Time", "Various", "12-04-2026", 315);
    libraryItems[8] = new Magazine("Forbes", "Various", "15-04-2026", 128);

    int choice;
    cout << "---------------- Library Management System ----------------" << endl;

menu:
    cout << "\n---- Menu ----" << endl;
    cout << "Press 1 to Show Item List" << endl;
    cout << "Press 2 for Searching Item" << endl;
    cout << "Press 3 for Checkout Item" << endl;
    cout << "Press 4 for Returning Item" << endl;
    cout << "Press 5 for exit" << endl;

    cout << "\nPlease Enter Your Choice : ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {

    // display all items 
    case 1:
    {
        for (int i = 0; i < 9; i++)
        {
            libraryItems[i]->displayDetails();
        }
        goto menu;
    }

    // search item
    case 2:
    {
        string title;
        cin.ignore();
        cout << "Enter Title (please enter title with proper capital-small latters) : ";
        getline(cin, title);

        int found = -1;

        for (int i = 0; i < 9; i++)
        {
            if (libraryItems[i]->getTitle() == title)
            {
                found = i;
                break;
            }
        }

        if (found == -1)
        {
            cout << "\nNo records With title : " << title << endl;
            goto menu;
        }

        libraryItems[found]->displayDetails();
        goto menu;
    }

    // checkout
    case 3:
    {
        string title;
        cin.ignore();
        cout << "Enter Title (please enter title with proper capital-small latters) : ";
        getline(cin, title);

        int found = -1;

        for (int i = 0; i < 9; i++)
        {
            if (libraryItems[i]->getTitle() == title)
            {
                found = i;
                break;
            }
        }

        if (found == -1)
        {
            cout << "\nNo records With title : " << title << endl;
            goto menu;
        }

        libraryItems[found]->checkOut();

        goto menu;
    }

    // returning
    case 4:
    {
        string title;
        cin.ignore();
        cout << "Enter Title (please enter title with proper capital-small latters) : ";
        getline(cin, title);

        int found = -1;

        for (int i = 0; i < 9; i++)
        {
            if (libraryItems[i]->getTitle() == title)
            {
                found = i;
                break;
            }
        }

        if (found == -1)
        {
            cout << "\nNo records With title : " << title << endl;
            goto menu;
        }

        libraryItems[found]->returnItem();

        goto menu;
    }

    case 5:
        cout << "Exiting ...." << endl;
        break;

    default:
        cout << "Invalid Choice" << endl;
        goto menu;
    }

    return 0;
}