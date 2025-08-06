#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue length is not even." << endl;
        return;
    }

    // Create two temporary queues
    queue<int> firstHalf;
    queue<int> secondHalf;

    // Step 1: Fill the first half into firstHalf queue
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Fill the second half into secondHalf queue
    while (!q.empty()) {
        secondHalf.push(q.front());
        q.pop();
    }

    // Step 3: Interleave the two halves back into the original queue
    while (!firstHalf.empty() && !secondHalf.empty()) {
        q.push(firstHalf.front()); // Add from the first half
        firstHalf.pop();

        q.push(secondHalf.front()); // Add from the second half
        secondHalf.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}