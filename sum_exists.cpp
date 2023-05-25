// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

// Bonus: Can you do this in one pass?

#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
    public:
        bool sum_exists_bruteforce(vector<int> nums, int k) {
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    if (nums[i] + nums[j] == target) {
                        return true;
                    }
                }
            }
            return false;
         }
        
        bool sum_exists_optimized(vector<int> nums, int k) {
            // create map variable (num, index)
            unordered_map<int, int> n;
            // loop through, if k - nums[i] is in map, return true, otherwise add nums[i] to map
            for (int i = 0; i < nums.size(); ++i) {
                if (n.find(k - nums[i]) != n.end()) {
                    return true;
                }
                else {
                    n[nums[i]] = i;
                }
            }
            return false;
        }
}
