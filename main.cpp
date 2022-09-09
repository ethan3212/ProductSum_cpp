#include <iostream>
#include <any>
#include <vector>
using namespace std;

// O(n) time | O(depth) space
int productSum(vector<any> array, int depth = 1) {
    int runningSum = 0;
    for(auto object : array) {// O(n) time
        if(object.type() == typeid(vector<any>)) {
            runningSum += productSum(any_cast<vector<any>>(object), depth + 1);// O(n) time | O(depth) space
        }else {
            runningSum += any_cast<int>(object);
        }
    }
    return runningSum * depth;
}

int main() {
    // [5, 2, [7, -1], 3, [6, [-13, 8], 4]]
    vector<any> test =
            {5, 2,
            vector<any>
                    {7, -1},
                3,
                vector<any>
                        {6,
                         vector<any>
                                 {-13, 8},
                                 4
                        }
            };

    // [(1) * 5, 2, [(2) * 6], 3, [(2) * 6, [(3) * -5], 4]]
    // [(1) * 7, [12], 3, [(2) * 6, [-15], 4]]
    // [(1) * 10, 12, [(2) * 10, -15]]
    // [(1) * 22, [(2) * -5]]
    // [22, [-10]]
    // [12]
    cout << productSum(test);
    return 0;
}
