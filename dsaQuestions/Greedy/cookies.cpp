#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cout << "Enter size of student array:" << endl;
    cin >> n;

    int m;
    cout << "Enter size of cookie array:" << endl;
    cin >> m;

    vector<int>student(n);
    vector<int>cookie(m);

    cout << "Enter value in student array:" << endl;
    for(int i = 0; i < n; i++){
        cin >> student[i];
    }

    cout << "Enter value in cookie array:" << endl;
    for(int i = 0; i < m; i++){
        cin >> cookie[i];
    }

    sort(student.begin(), student.end());
    sort(cookie.begin(), cookie.end());

    int i = 0, j = 0;
    while(i < n && j < m){
        if(cookie[j] >= student[i]){
            i++;
        }
        j++;
    }
    cout << "Maximum students assigned cookie are:" << endl;
    cout << i << endl;


    return 0;
}