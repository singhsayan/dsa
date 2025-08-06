#include <iostream>
using namespace std;

class StockSpan {
public:
    int size;
    int* prices;
    int* spans;

    StockSpan(int n) {
        size = n;
        prices = new int[n];
        spans = new int[n];
    }

    void calculateSpan() {
        for (int i = 0; i < size; i++) {
            spans[i] = 1; // Default span is 1 (current day)

            // Check previous prices to calculate span
            for (int j = i - 1; j >= 0 && prices[j] <= prices[i]; j--) {
                spans[i]++;
            }
        }
    }

    void printSpans() {
        for (int i = 0; i < size; i++) {
            cout << spans[i] << " ";
        }
        cout << endl;
    }

    ~StockSpan() {
        delete[] prices;
        delete[] spans;
    }
};

int main() {
    int n;
    cout << "Enter the number of stock prices: ";
    cin >> n;

    StockSpan stockSpan(n);
    cout << "Enter the stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> stockSpan.prices[i];
    }

    stockSpan.calculateSpan();
    cout << "Stock spans are:\n";
    stockSpan.printSpans();

    return 0;
}