/*
Experiment 34: Job Sequencing with Deadlines
Topic: Greedy
Concepts Used:
- Greedy Algorithm
- Job Scheduling
- Profit Maximization
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job id, deadline, profit:" << endl;
    for (int i = 0; i < n; i++)
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;

    // profit ke hisaab se descending sort karo
    sort(jobs.begin(), jobs.end(), [](Job& a, Job& b) {
        return a.profit > b.profit;
    });

    // max deadline nikalo
    int maxDeadline = 0;
    for (auto& j : jobs) maxDeadline = max(maxDeadline, j.deadline);

    // slot array: -1 matlab free
    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0;
    int jobsDone = 0;

    cout << "\nSelected Jobs:" << endl;
    for (auto& job : jobs) {
        // deadline se pehle khali slot dhundho
        for (int t = job.deadline; t >= 1; t--) {
            if (slot[t] == -1) {
                slot[t] = job.id;
                totalProfit += job.profit;
                jobsDone++;
                cout << "Job " << job.id << " scheduled at slot " << t
                     << " (profit: " << job.profit << ")" << endl;
                break;
            }
        }
    }

    cout << "\nTotal Jobs: " << jobsDone << endl;
    cout << "Total Profit: " << totalProfit << endl;
    return 0;
}
