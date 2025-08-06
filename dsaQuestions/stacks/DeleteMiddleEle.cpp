#include<iostream>
#include<stack>
using namespace std;

void removeEle(stack<int>& s, int count, int size){
    if(count == size / 2){
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    removeEle(s, count + 1, size);

    s.push(num);
}



int main(){
    stack<int> s;
    int size, element;
    cout << "Enter size of stack" << endl;
    cin >> size;

    cout << "Enter elements in a stack" << endl;
    for(int i = 0; i < size; i++){
        cin >> element;
        s.push(element);
    }

    removeEle(s, 0, size);

    cout << "Stack after removing middle element:" << endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;

}