#include <iostream>
#include <algorithm>
using namespace std;

bool isNStraightHand(int hand[], int size, int groupSize) {
    // If size is not divisible by groupSize, return false
    if (size % groupSize != 0) {
        return false;
    }

    // Sort the hand array
    sort(hand, hand + size);

    // Frequency array for counting occurrences of cards
    int maxCard = hand[size - 1];
    int count[10001] = {0}; // Assuming card values do not exceed 10000

    // Count the frequency of each card
    for (int i = 0; i < size; i++) {
        count[hand[i]]++;
    }

    // Check if the hand can be divided into groups
    for (int i = 0; i <= maxCard; i++) {
        if (count[i] > 0) {
            int frequency = count[i];
            // Try to form groups of size `groupSize`
            for (int j = 0; j < groupSize; j++) {
                if (count[i + j] < frequency) {
                    return false;
                }
                count[i + j] -= frequency;
            }
        }
    }

    return true;
}

int main() {
    int size, groupSize;
    
    cout << "Enter the number of cards: ";
    cin >> size;

    int hand[10001]; // Input array for cards

    cout << "Enter the cards: ";
    for (int i = 0; i < size; i++) {
        cin >> hand[i];
    }

    cout << "Enter the group size: ";
    cin >> groupSize;

    // Check if it's possible to divide the hand into groups
    if (isNStraightHand(hand, size, groupSize)) {
        cout << "Yes, it's possible to divide the hand into groups of " << groupSize << endl;
    } else {
        cout << "No, it's not possible to divide the hand into groups of " << groupSize << endl;
    }

    return 0;
}