/*
Experiment 33: Fractional Knapsack Problem
Topic: Greedy
Concepts Used:
- Greedy Algorithm
- Fractional Knapsack
- Sorting by value/weight ratio
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
    double ratio; // value/weight ratio
};

int main() {
    int n, capacity;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> capacity;

    vector<Item> items(n);
    cout << "Enter weight and value of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // ratio ke hisaab se descending order me sort karo
    sort(items.begin(), items.end(), [](Item& a, Item& b) {
        return a.ratio > b.ratio;
    });

    double totalValue = 0;
    int remaining = capacity;

    cout << "\nItems picked:" << endl;
    for (int i = 0; i < n && remaining > 0; i++) {
        if (items[i].weight <= remaining) {
            // poora item le lo
            totalValue += items[i].value;
            remaining  -= items[i].weight;
            cout << "Full item: weight=" << items[i].weight
                 << " value=" << items[i].value << endl;
        } else {
            // fraction le lo
            double fraction = (double)remaining / items[i].weight;
            totalValue += fraction * items[i].value;
            cout << "Fraction (" << fraction * 100 << "%) of item: weight="
                 << items[i].weight << " value=" << items[i].value << endl;
            remaining = 0;
        }
    }

    cout << "\nMaximum value in knapsack: " << totalValue << endl;
    return 0;
}
