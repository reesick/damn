#include <iostream>
using namespace std;

/*
Experiment 34: Job Sequencing with Deadlines
*/

int main() {

    // already sorted by profit descending
    int profit[] = {100, 50, 20};
    int deadline[] = {2, 1, 2};

    int slots[2] = {-1, -1};   // -1 means empty
    int totalProfit = 0;

    // each job check karo
    for (int i = 0; i < 3; i++) {

        // deadline ke last slot se check karo
        for (int j = deadline[i] - 1; j >= 0; j--) {

            // slot empty hai
            if (slots[j] == -1) {

                slots[j] = i;

                totalProfit = totalProfit + profit[i];

                break;
            }
        }
    }

    cout << "Selected Jobs: ";

    for (int i = 0; i < 2; i++) {

        if (slots[i] != -1) {
            cout << "Job" << slots[i] << " ";
        }
    }

    cout << endl;
    cout << "Maximum Profit = " << totalProfit;

    return 0;
}