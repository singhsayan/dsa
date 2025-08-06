#include <iostream>
using namespace std;

// Function to convert uppercase to lowercase
char toLower(char uppercaseChar) {
    // Check if the character is uppercase
    if (uppercaseChar >= 'A' && uppercaseChar <= 'Z') {
        // Convert to lowercase by adding 32 (ASCII difference)
        return uppercaseChar + 32;
    }
    // If not an uppercase character, return it as is
    return uppercaseChar;
}

int main() {
    char uppercaseChar;

    // Input an uppercase character
    cout << "Enter an uppercase character: ";
    cin >> uppercaseChar;

    // Convert to lowercase
    char lowercaseChar = toLower(uppercaseChar);

    // Display the result
    cout << "Lowercase character: " << lowercaseChar << endl;

    return 0;
}