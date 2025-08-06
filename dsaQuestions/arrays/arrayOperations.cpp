#include <iostream>
using namespace std;

class ArrayOperations {
private:
    int arr[100]; // Static array for simplicity
    int size;

public:
    ArrayOperations() : size(0) {}

    // Create an array
    void create() {
        cout << "Enter the number of elements: ";
        cin >> size;
        if (size > 100) {
            cout << "Size exceeds maximum limit of 100.\n";
            size = 0;
            return;
        }
        cout << "Enter the elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Display array elements
    void display() {
        if (size == 0) {
            cout << "Array is empty.\n";
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Insert an element at a specified position
    void insert() {
        if (size >= 100) {
            cout << "Array is full. Cannot insert new element.\n";
            return;
        }
        int element, position;
        cout << "Enter the element to insert: ";
        cin >> element;
        cout << "Enter the position (1 to " << size + 1 << "): ";
        cin >> position;

        if (position < 1 || position > size + 1) {
            cout << "Invalid position.\n";
            return;
        }

        // Shift elements to the right
        for (int i = size; i >= position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position - 1] = element;
        size++;
        cout << "Element inserted.\n";
    }

    // Delete an element from a specified position
    void deleteElement() {
        if (size == 0) {
            cout << "Array is empty. Cannot delete.\n";
            return;
        }
        int position;
        cout << "Enter the position to delete (1 to " << size << "): ";
        cin >> position;

        if (position < 1 || position > size) {
            cout << "Invalid position.\n";
            return;
        }

        // Shift elements to the left
        for (int i = position - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element deleted.\n";
    }

    // Perform a linear search for an element
    void linearSearch() {
        if (size == 0) {
            cout << "Array is empty.\n";
            return;
        }
        int element, position = -1;
        cout << "Enter the element to search: ";
        cin >> element;

        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                position = i + 1; // 1-based index
                break;
            }
        }
        if (position != -1) {
            cout << "Element found at position " << position << ".\n";
        } else {
            cout << "Element not found.\n";
        }
    }
};

int main() {
    ArrayOperations arrayOps;
    int choice;

    do {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                arrayOps.create();
                break;
            case 2:
                arrayOps.display();
                break;
            case 3:
                arrayOps.insert();
                break;
            case 4:
                arrayOps.deleteElement();
                break;
            case 5:
                arrayOps.linearSearch();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}