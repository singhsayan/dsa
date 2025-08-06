#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

class Solution{
  public:
  
    // Function to find the starting point where the truck can start
    // to get through the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n) {
        int deficit = 0;    // This will store the total petrol shortage
        int balance = 0;    // This will store the current petrol balance
        int start = 0;      // This will store the starting point
        
        for(int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;
            
            // If balance becomes negative, reset the start point
            if(balance < 0) {
                start = i + 1;
                deficit += balance;  // Add the shortage to deficit
                balance = 0;         // Reset balance
            }
        }
        
        // If total balance and deficit are non-negative, return the start index
        if(balance + deficit >= 0) 
            return start;
        return -1;  // Otherwise, no solution exists
    }
};

int main() {
    int t;
    cin >> t;  // Number of test cases
    while(t--) {
        int n;
        cin >> n;  // Number of petrol pumps
        
        petrolPump p[n];
        
        // Input petrol and distance for each petrol pump
        for(int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        
        Solution obj;
        // Print the starting point for the truck
        cout << obj.tour(p, n) << endl;
    }
    
    return 0;
}