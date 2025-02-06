#include <iostream>
#include <vector>
// algorithm is a library used to sort the array
#include <algorithm>
using namespace std;

// Structure to represent an item with weight and profit per kg
struct Item {
    int wt;
    double ppk; // profit per kg
};

// Comparator function to sort items by profit density (ppk)
bool compare(Item a, Item b) {
    return (a.ppk > b.ppk);
}

// Function to solve the fractional knapsack problem
void knapsack(int W, vector<Item> items) {
    // Sort items by profit density
    sort(items.begin(), items.end(), compare);

    vector<double> amount(items.size(), 0.0); // Amount of each item taken
    int current_wt = 0; // Current weight of the knapsack
    double tpr = 0.0; // Total profit in the knapsack

    for (int i = 0; i < items.size(); i++) {
        if (current_wt + items[i].wt <= W) {
            // Take the whole item
            amount[i] = 1.0;
            current_wt += items[i].wt;
            tpr += items[i].ppk * items[i].wt;
        } else {
            // Take a fraction of the item
            double fraction = (double)(W - current_wt) / items[i].wt;
            amount[i] = fraction;
            current_wt += fraction * items[i].wt;
            tpr += items[i].ppk * items[i].wt * fraction;
            break; // Knapsack is full
        }
    }

    cout << "Total profit in the knapsack: " << tpr << endl;
    cout << "Amounts of each item taken: ";
    for (double a : amount) {
        cout << a << " ";
    }
    cout << endl;
}

int main() {
    int W = 500; // Maximum weight of knapsack
    vector<Item> items = {{100, 20}, {200, 30}, {150, 50}, {250, 40}}; // Items with weights and profit per kg

    knapsack(W, items);

    return 0;
}
