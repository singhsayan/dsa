#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// This is also space optimised

int climbStairs(int n){
    if (n <= 1){
        return 1; // Base cases: 1 way to climb 0 or 1 step
    }

    int sum = 0;
    int zero_step = 1;
    int first_step = 1;

    for(int i = 2; i < n; i++){
        sum = zero_step + first_step;
        zero_step = first_step;
        first_step = sum;
    }

    return sum;
}

int main(){
    int n;
    cout << "No of steps taken to reach the top:" << endl;
    cin >> n;

    if(n < 0){
        cout << "Invalid" << endl;
    }

    else{
        cout << "No of distinct ways to reach top are:" << climbStairs(n) << endl;
    }
    
    return 0;
}