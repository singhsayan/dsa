#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> reverse(queue<int>q){
    stack <int>s;

    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()){
        int ans = s.top();
        s.pop();
        q.push(ans);
    }
    return q;
}


int main() {
    queue<int> q;
    int size, element;

    cout << "Enter the size of the queue: ";
    cin >> size;

    cout << "Enter elements in the queue: ";
    for(int i = 0; i < size; i++) {
        cin >> element;
        q.push(element);
    }
    
    cout << "Original queue: ";
    queue<int> temp = q; 
    while(!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    q = reverse(q);

    cout << "Reversed queue: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}