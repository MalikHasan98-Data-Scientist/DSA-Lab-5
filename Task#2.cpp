#include <iostream>
#include <string>
using namespace std;

struct Photo
{
    int id;
    string name;
    string date;
    string location;

    Photo* next;
    Photo* prev;
};

class PhotoAlbum
{
private:
    Photo* current;

public:
    PhotoAlbum()
    {
        current = NULL;
    }

    void addPhoto()
    {
        Photo* newPhoto = new Photo;

        cout << "Enter Photo ID: ";
        cin >> newPhoto->id;

        cin.ignore();

        cout << "Enter Photo Name: ";
        getline(cin, newPhoto->name);

        cout << "Enter Date Taken: ";
        getline(cin, newPhoto->date);

        cout << "Enter Location: ";
        getline(cin, newPhoto->location);

        if (current == NULL)
        {
            newPhoto->next = newPhoto;
            newPhoto->prev = newPhoto;

            current = newPhoto;
        }
        else
        {
            Photo* last = current->prev;

            newPhoto->next = current;
            newPhoto->prev = last;

            last->next = newPhoto;
            current->prev = newPhoto;
        }

        cout << "Photo added.\n";
    }

    void insertAfterCurrent()
    {
        if (current == NULL)
        {
            cout << "Album is empty. Adding photo as first photo.\n";
            addPhoto();
            return;
        }

        Photo* newPhoto = new Photo;

        cout << "Enter Photo ID: ";
        cin >> newPhoto->id;

        cin.ignore();

        cout << "Enter Photo Name: ";
        getline(cin, newPhoto->name);

        cout << "Enter Date Taken: ";
        getline(cin, newPhoto->date);

        cout << "Enter Location: ";
        getline(cin, newPhoto->location);

        newPhoto->next = current->next;
        newPhoto->prev = current;

        current->next->prev = newPhoto;
        current->next = newPhoto;

        cout << "Photo inserted after current photo.\n";
    }

    void removePhoto()
    {
        if (current == NULL)
        {
            cout << "Album is empty.\n";
            return;
        }

        int id;

        cout << "Enter Photo ID to remove: ";
        cin >> id;

        Photo* temp = current;

        do
        {
            if (temp->id == id)
            {
                if (temp->next == temp)
                {
                    current = NULL;
                    delete temp;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    if (temp == current)
                    {
                        current = temp->next;
                    }

                    delete temp;
                }

                cout << "Photo removed.\n";
                return;
            }

            temp = temp->next;

        } while (temp != current);

        cout << "Photo not found.\n";
    }

    void removeCurrent()
    {
        if (current == NULL)
        {
            cout << "Album is empty.\n";
            return;
        }

        Photo* temp = current;

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

        cout << "Current photo removed.\n";
    }

    void moveNext()
    {
        if (current == NULL)
        {
            cout << "Album is empty.\n";
            return;
        }

        current = current->next;

        cout << "Moved to next photo.\n";
    }

    void movePrevious()
    {
        if (current == NULL)
        {
            cout << "Album is empty.\n";
            return;
        }

        current = current->prev;

        cout << "Moved to previous photo.\n";
    }

    void displayPhoto(Photo* photo)
    {
        cout << "ID: " << photo->id << endl;
        cout << "Name: " << photo->name << endl;
        cout << "Date: " << photo->date << endl;
        cout << "Location: " << photo->location << endl;
        cout << "-------------------------\n";
    }

    void displayForward()
    {
        if (current == NULL)
        {
            cout << "Album is empty.\n";
            return;
        }

        Photo* temp = current;

        cout << "\n===== Album Forward =====\n";

        do
        {
            displayPhoto(temp);
            temp = temp->next;

        } while (temp != current);
    }

    void displayBackward()
    {
        if (current == NULL)
        {
            cout << "Album is empty.\n";
            return;
        }

        Photo* temp = current;

        cout << "\n===== Album Backward =====\n";

        do
        {
            displayPhoto(temp);
            temp = temp->prev;

        } while (temp != current);
    }

    void searchPhoto()
    {
        if (current == NULL)
        {
            cout << "Album is empty.\n";
            return;
        }

        int id;

        cout << "Enter Photo ID to search: ";
        cin >> id;

        Photo* temp = current;

        do
        {
            if (temp->id == id)
            {
                cout << "\nPhoto Found\n";
                displayPhoto(temp);
                return;
            }

            temp = temp->next;

        } while (temp != current);

        cout << "Photo not found.\n";
    }

    void countPhotos()
    {
        if (current == NULL)
        {
            cout << "Total Photos: 0\n";
            return;
        }

        int count = 0;

        Photo* temp = current;

        do
        {
            count++;
            temp = temp->next;

        } while (temp != current);

        cout << "Total Photos: " << count << endl;
    }
};

int main()
{
    PhotoAlbum album;

    int number;

    cout << "Enter number of photos: ";
    cin >> number;

    for (int i = 0; i < number; i++)
    {
        cout << "\nEnter details for Photo " << i + 1 << endl;
        album.addPhoto();
    }

    int choice;

    do
    {
        cout << "\n===== Circular Photo Album =====\n";
        cout << "1. Add Photo\n";
        cout << "2. Insert Photo After Current\n";
        cout << "3. Remove Photo\n";
        cout << "4. Remove Current Photo\n";
        cout << "5. Move Next\n";
        cout << "6. Move Previous\n";
        cout << "7. Display Album Forward\n";
        cout << "8. Display Album Backward\n";
        cout << "9. Search Photo\n";
        cout << "10. Count Photos\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            album.addPhoto();
            break;

        case 2:
            album.insertAfterCurrent();
            break;

        case 3:
            album.removePhoto();
            break;

        case 4:
            album.removeCurrent();
            break;

        case 5:
            album.moveNext();
            break;

        case 6:
            album.movePrevious();
            break;

        case 7:
            album.displayForward();
            break;

        case 8:
            album.displayBackward();
            break;

        case 9:
            album.searchPhoto();
            break;

        case 10:
            album.countPhotos();
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