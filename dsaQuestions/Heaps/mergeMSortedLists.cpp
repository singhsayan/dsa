#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};

class heap {
public:
    int size;
    ListNode* arr[100];

    heap() {
        size = 0;
    }

    void push(ListNode* node) {
        size++;
        arr[size] = node;
        heapifyUp(size);
    }

    void heapifyUp(int idx) {
        if (idx == 1) return;

        int parent = idx / 2;
        if (arr[parent]->val > arr[idx]->val) {
            swap(arr[parent], arr[idx]);
            heapifyUp(parent);
        }
    }

    ListNode* pop() {
        if (size == 0) return nullptr;

        ListNode* top = arr[1];
        arr[1] = arr[size];
        size--;
        heapifyDown(1);
        return top;
    }

    void heapifyDown(int idx) {
        int smallest = idx;
        int left = 2 * idx;
        int right = 2 * idx + 1;

        if (left <= size && arr[left]->val < arr[smallest]->val) {
            smallest = left;
        }
        if (right <= size && arr[right]->val < arr[smallest]->val) {
            smallest = right;
        }

        if (smallest != idx) {
            swap(arr[smallest], arr[idx]);
            heapifyDown(smallest);
        }
    }

    bool empty() {
        return size == 0;
    }
};

ListNode* mergeKSortedLists(ListNode* lists[], int k) {
    heap pq;

    // Insert the first node of each list into the heap
    for (int i = 0; i < k; i++) {
        if (lists[i] != nullptr) {
            pq.push(lists[i]);
        }
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    while (!pq.empty()) {
        ListNode* smallest = pq.pop();
        tail->next = smallest;
        tail = tail->next;

        // If there's a next node in the current list, push it into the heap
        if (smallest->next != nullptr) {
            pq.push(smallest->next);
        }
    }

    return dummy->next;
}

int main() {
    int k;
    cout << "Enter the number of sorted lists: ";
    cin >> k;

    ListNode* lists[k];
    for (int i = 0; i < k; i++) {
        cout << "Enter elements of sorted list " << i + 1 << " (-1 to stop): ";
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        while (true) {
            int val;
            cin >> val;
            if (val == -1) break;
            ListNode* newNode = new ListNode(val);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        lists[i] = head;
    }

    ListNode* result = mergeKSortedLists(lists, k);

    cout << "Merged sorted list: ";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}