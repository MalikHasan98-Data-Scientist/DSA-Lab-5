#include <iostream>
#include <string>
using namespace std;

struct Tab
{
    int id;
    string title;
    string url;

    Tab* next;
    Tab* prev;
};

class Browser
{
private:
    Tab* current;

public:
    Browser()
    {
        current = NULL;
    }

    void openTab()
    {
        Tab* newTab = new Tab;

        cout << "Enter Tab ID: ";
        cin >> newTab->id;

        cin.ignore();

        cout << "Enter Website Title: ";
        getline(cin, newTab->title);

        cout << "Enter URL: ";
        getline(cin, newTab->url);

        if (current == NULL)
        {
            newTab->next = newTab;
            newTab->prev = newTab;

            current = newTab;
        }
        else
        {
            newTab->next = current->next;
            newTab->prev = current;

            current->next->prev = newTab;
            current->next = newTab;

            current = newTab;
        }

        cout << "Tab opened successfully.\n";
    }

    void closeCurrent()
    {
        if (current == NULL)
        {
            cout << "No tabs are open.\n";
            return;
        }

        Tab* temp = current;

        if (current->next == current)
        {
            current = NULL;
            delete temp;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;

            current = current->next;

            delete temp;
        }

        cout << "Current tab closed.\n";
    }

    void moveNext()
    {
        if (current == NULL)
        {
            cout << "No tabs are open.\n";
            return;
        }

        current = current->next;

        cout << "Moved to next tab.\n";
    }

    void movePrevious()
    {
        if (current == NULL)
        {
            cout << "No tabs are open.\n";
            return;
        }

        current = current->prev;

        cout << "Moved to previous tab.\n";
    }

    void displayCurrent()
    {
        if (current == NULL)
        {
            cout << "No tabs are open.\n";
            return;
        }

        cout << "\nCurrent Tab\n";
        cout << "ID: " << current->id << endl;
        cout << "Title: " << current->title << endl;
        cout << "URL: " << current->url << endl;
    }

    void displayForward()
    {
        if (current == NULL)
        {
            cout << "No tabs are open.\n";
            return;
        }

        Tab* temp = current;

        cout << "\nTabs Forward:\n";

        do
        {
            cout << "ID: " << temp->id
                 << " | Title: " << temp->title
                 << " | URL: " << temp->url << endl;

            temp = temp->next;

        } while (temp != current);
    }

    void displayBackward()
    {
        if (current == NULL)
        {
            cout << "No tabs are open.\n";
            return;
        }

        Tab* temp = current;

        cout << "\nTabs Backward:\n";

        do
        {
            cout << "ID: " << temp->id
                 << " | Title: " << temp->title
                 << " | URL: " << temp->url << endl;

            temp = temp->prev;

        } while (temp != current);
    }

    void searchTab()
    {
        if (current == NULL)
        {
            cout << "No tabs are open.\n";
            return;
        }

        int searchID;

        cout << "Enter Tab ID to search: ";
        cin >> searchID;

        Tab* temp = current;

        do
        {
            if (temp->id == searchID)
            {
                cout << "\nTab Found\n";
                cout << "ID: " << temp->id << endl;
                cout << "Title: " << temp->title << endl;
                cout << "URL: " << temp->url << endl;
                return;
            }

            temp = temp->next;

        } while (temp != current);

        cout << "Tab not found.\n";
    }
};

int main()
{
    Browser browser;

    int choice;

    do
    {
        cout << "\n===== Browser Tab Manager =====\n";
        cout << "1. Open New Tab\n";
        cout << "2. Close Current Tab\n";
        cout << "3. Move Next\n";
        cout << "4. Move Previous\n";
        cout << "5. Display Current Tab\n";
        cout << "6. Display All Tabs Forward\n";
        cout << "7. Display All Tabs Backward\n";
        cout << "8. Search Tab\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            browser.openTab();
            break;

        case 2:
            browser.closeCurrent();
            break;

        case 3:
            browser.moveNext();
            break;

        case 4:
            browser.movePrevious();
            break;

        case 5:
            browser.displayCurrent();
            break;

        case 6:
            browser.displayForward();
            break;

        case 7:
            browser.displayBackward();
            break;

        case 8:
            browser.searchTab();
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}