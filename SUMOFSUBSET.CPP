#include <iostream>
#include <vector>
using namespace std;

void subsetSum(vector<int>& nums, int index, int target, vector<int>& current) {
    if (target == 0) {
        cout << "Subset found: ";
        for (int num : current)
            cout << num << " ";
        cout << endl;
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        if (nums[i] <= target) {
            current.push_back(nums[i]);
            subsetSum(nums, i + 1, target - nums[i], current);
            current.pop_back();
        }
    }
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;
    vector<int> current;
    cout << "Subsets with sum " << target << ":\n";
    subsetSum(nums, 0, target, current);
    return 0;
}
