#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int quantum;
};

struct ComparePriority {
    bool operator()(const Process& p1, const Process& p2) const {
        return p1.priority > p2.priority;
    }
};

struct CompareArrivalTime {
    bool operator()(const Process& p1, const Process& p2) const {
        return p1.arrival_time > p2.arrival_time;
    }
};

int main() {
    int num_processes;
    cout << "Enter the number of processes: ";
    cin >> num_processes;

    vector<Process> processes(num_processes);
    for (int i = 0; i < num_processes; i++) {
        cout << "Enter the arrival time, burst time, and priority for process " << i + 1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time >> processes[i].priority;
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].quantum = 2;
    }
