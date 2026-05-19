#include <iostream>
using namespace std;

/*
Experiment 33: Fractional Knapsack
*/

int main() {

    int weight[] = {10, 20, 30};
    int profit[] = {60, 100, 120};

    int capacity = 50;
    float totalProfit = 0;

    for (int i = 0; i < 3; i++) {

        // agar pura item fit hota hai
        if (weight[i] <= capacity) {

            totalProfit = totalProfit + profit[i];
            capacity = capacity - weight[i];
        }

        else {

            // fraction of item lo
            totalProfit = totalProfit + (((float)profit[i] / weight[i]) * capacity);

            break;
        }
    }

    cout << "Maximum Profit = " << totalProfit;

    return 0;
}