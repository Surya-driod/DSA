#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a task
struct Task {
    float arrival;   // Arrival time in hours and minutes (e.g., 1.30 for 1:30)
    float departure; // Departure time in hours and minutes (e.g., 4.45 for 4:45)
    float duration;
};

// Comparator function to sort tasks by their departure time
bool compareByDeparture(const Task &a, const Task &b) {
    return a.departure < b.departure;
}

// Function to find the maximum number of tasks
vector<Task> findMaxTasks(vector<Task> &tasks) {
    sort(tasks.begin(), tasks.end(), compareByDeparture);

    vector<Task> maxTasks;
    float currentTime = 0;

    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].arrival >= currentTime && tasks[i].departure <= 24) {
            maxTasks.push_back(tasks[i]);
            currentTime = tasks[i].departure;
        }
    }

    return maxTasks;
}

int main() {
    // Example array of tasks with arrival time, departure time, and duration
    vector<Task> tasks = {{1.00, 4.00, 3.00}, {3.15, 5.30, 2.15}, {0.00, 6.00, 6.00}, {5.45, 7.00, 1.15}, {5.30, 9.00, 3.30}, {8.00, 9.15, 1.15}, {8.00, 12.00, 4.00}, {2.00, 14.00, 12.00}, {12.30, 16.00, 3.30}};
    
    // Find the maximum number of tasks that can be executed
    vector<Task> maxTasks = findMaxTasks(tasks);

    // Print the result
    cout << "Max number of tasks executed: " << maxTasks.size() << "\n";
    cout << "Arrival and Departure times of tasks:\n";
    for (size_t i = 0; i < maxTasks.size(); ++i) {
        cout << "Arrival: " << maxTasks[i].arrival << ", Departure: " << maxTasks[i].departure << "\n";
    }

    return 0;
}
