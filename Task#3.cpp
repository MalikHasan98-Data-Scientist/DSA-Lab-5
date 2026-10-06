#include <iostream>
#include <string>
using namespace std;

struct Coach
{
    int number;
    string type;
    int capacity;
    int passengers;

    Coach* next;
    Coach* prev;
};

class Train
{
private:
    Coach* current;

public:
    Train()
    {
        current = NULL;
    }

    void addCoach()
    {
        Coach* newCoach = new Coach;

        cout << "Enter Coach Number: ";
        cin >> newCoach->number;

        cin.ignore();

        cout << "Enter Coach Type: ";
        getline(cin, newCoach->type);

        cout << "Enter Passenger Capacity: ";
        cin >> newCoach->capacity;

        cout << "Enter Current Passengers: ";
        cin >> newCoach->passengers;

        if (current == NULL)
        {
            newCoach->next = newCoach;
            newCoach->prev = newCoach;

            current = newCoach;
        }
        else
        {
            Coach* last = current->prev;

            newCoach->next = current;
            newCoach->prev = last;

            last->next = newCoach;
            current->prev = newCoach;
        }

        cout << "Coach added.\n";
    }

    void insertCoach()
    {
        if (current == NULL)
        {
            cout << "Train is empty. Adding coach as first coach.\n";
            addCoach();
            return;
        }

        int afterNumber;

        cout << "Enter coach number after which to insert: ";
        cin >> afterNumber;

        Coach* temp = current;
        bool found = false;

        do
        {
            if (temp->number == afterNumber)
            {
                found = true;
                break;
            }

            temp = temp->next;

        } while (temp != current);

        if (!found)
        {
            cout << "Coach not found.\n";
            return;
        }

        Coach* newCoach = new Coach;

        cout << "Enter New Coach Number: ";
        cin >> newCoach->number;

        cin.ignore();

        cout << "Enter Coach Type: ";
        getline(cin, newCoach->type);

        cout << "Enter Passenger Capacity: ";
        cin >> newCoach->capacity;

        cout << "Enter Current Passengers: ";
        cin >> newCoach->passengers;

        newCoach->next = temp->next;
        newCoach->prev = temp;

        temp->next->prev = newCoach;
        temp->next = newCoach;

        cout << "Coach inserted.\n";
    }

    void removeCoach()
    {
        if (current == NULL)
        {
            cout << "Train is empty.\n";
            return;
        }

        int number;

        cout << "Enter Coach Number to remove: ";
        cin >> number;

        Coach* temp = current;

        do
        {
            if (temp->number == number)
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

                cout << "Coach removed.\n";
                return;
            }

            temp = temp->next;

        } while (temp != current);

        cout << "Coach not found.\n";
    }

    void moveForward()
    {
        if (current == NULL)
        {
            cout << "Train is empty.\n";
            return;
        }

        current = current->next;

        cout << "Moved forward.\n";
    }

    void moveBackward()
    {
        if (current == NULL)
        {
            cout << "Train is empty.\n";
            return;
        }

        current = current->prev;

        cout << "Moved backward.\n";
    }

    void displayCoach(Coach* coach)
    {
        cout << "Coach Number: " << coach->number << endl;
        cout << "Coach Type: " << coach->type << endl;
        cout << "Passenger Capacity: " << coach->capacity << endl;
        cout << "Current Passengers: " << coach->passengers << endl;
        cout << "Available Seats: "
             << coach->capacity - coach->passengers << endl;

        cout << "-------------------------\n";
    }

    void displayClockwise()
    {
        if (current == NULL)
        {
            cout << "Train is empty.\n";
            return;
        }

        Coach* temp = current;

        cout << "\n===== Train Clockwise =====\n";

        do
        {
            displayCoach(temp);

            temp = temp->next;

        } while (temp != current);
    }

    void displayAntiClockwise()
    {
        if (current == NULL)
        {
            cout << "Train is empty.\n";
            return;
        }

        Coach* temp = current;

        cout << "\n===== Train Anti-clockwise =====\n";

        do
        {
            displayCoach(temp);

            temp = temp->prev;

        } while (temp != current);
    }

    void searchCoach()
    {
        if (current == NULL)
        {
            cout << "Train is empty.\n";
            return;
        }

        int number;

        cout << "Enter Coach Number to search: ";
        cin >> number;

        Coach* temp = current;

        do
        {
            if (temp->number == number)
            {
                cout << "\nCoach Found\n";
                displayCoach(temp);
                return;
            }

            temp = temp->next;

        } while (temp != current);

        cout << "Coach not found.\n";
    }

    void maximumAvailableCapacity()
    {
        if (current == NULL)
        {
            cout << "Train is empty.\n";
            return;
        }

        Coach* temp = current;
        Coach* best = current;

        int maximum = current->capacity - current->passengers;

        do
        {
            int available = temp->capacity - temp->passengers;

            if (available > maximum)
            {
                maximum = available;
                best = temp;
            }

            temp = temp->next;

        } while (temp != current);

        cout << "\nCoach with Maximum Available Capacity\n";
        displayCoach(best);
    }

    void displayCurrent()
    {
        if (current == NULL)
        {
            cout << "Train is empty.\n";
            return;
        }

        cout << "\n===== Current Coach =====\n";

        displayCoach(current);
    }

    void reverseTrain()
    {
        if (current == NULL)
        {
            cout << "Train is empty.\n";
            return;
        }

        if (current->next == current)
        {
            cout << "Train direction reversed.\n";
            return;
        }

        Coach* temp = current;

        do
        {
            Coach* oldNext = temp->next;

            temp->next = temp->prev;
            temp->prev = oldNext;

            temp = oldNext;

        } while (temp != current);

        cout << "Train direction reversed.\n";
    }
};

int main()
{
    Train train;

    int number;

    cout << "Enter number of coaches: ";
    cin >> number;

    for (int i = 0; i < number; i++)
    {
        cout << "\nEnter details for Coach " << i + 1 << endl;
        train.addCoach();
    }

    int choice;

    do
    {
        cout << "\n===== Train Coach Navigation =====\n";
        cout << "1. Add Coach\n";
        cout << "2. Insert Coach\n";
        cout << "3. Remove Coach\n";
        cout << "4. Move Forward\n";
        cout << "5. Move Backward\n";
        cout << "6. Display Train Clockwise\n";
        cout << "7. Display Train Anti-clockwise\n";
        cout << "8. Search Coach\n";
        cout << "9. Find Maximum Available Capacity\n";
        cout << "10. Display Current Coach\n";
        cout << "11. Reverse Train Direction\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            train.addCoach();
            break;

        case 2:
            train.insertCoach();
            break;

        case 3:
            train.removeCoach();
            break;

        case 4:
            train.moveForward();
            break;

        case 5:
            train.moveBackward();
            break;

        case 6:
            train.displayClockwise();
            break;

        case 7:
            train.displayAntiClockwise();
            break;

        case 8:
            train.searchCoach();
            break;

        case 9:
            train.maximumAvailableCapacity();
            break;

        case 10:
            train.displayCurrent();
            break;

        case 11:
            train.reverseTrain();
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