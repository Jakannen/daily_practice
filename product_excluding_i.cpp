// Given an vector of integers, return a new vector such that each element at index i 
// of the new vector is the product of all the numbers in the original vector except the one at i.

// For example, if our input was [1, 2, 3, 4, 5], 
// the expected output would be [120, 60, 40, 30, 24]. 
// If our input was [3, 2, 1], the expected output would be [2, 3, 6].

// Follow-up: what if you can't use division?

#include <vector>
using namespace std;


class Solution {
    public:
        // NOTE: This is the most naive approach
        //       O(n^2) and uses division
        vector<int> product_excluding_i_bruteforce(vector<int> nums) {
            vector<int> result;
            int product;
            for (int i = 0; i < nums.size() - 1; ++i) {
                product = 1;
                for (int j = 0; j < nums.size() - 1; ++j) {
                    product *= nums[j];
                }
                product = product / nums[i];
                result.push_back(product);
            }
            return result;
         }
        // NOTE: This is another naive approach but without division
        //       O(n^2)
        vector<int> product_excluding_i_nodivision(vector<int> nums) {
            vector<int> result;
            int product;
            for (int i = 0; i < nums.size() - 1; ++i) {
                product = 1;
                for (int j = 0; j < nums.size() - 1; ++j) {
                    if (j != i) {
                        product *= nums[j];
                    }
                }
                result.push_back(product);
            }
            return result;
        }
        // NOTE: This is the optimized approach
        //       O(n)
        //       Its a bit funky so I am going to try to explain it here:
        //          - create a left, right, and result vector
        //          - resize them to the size of the input vector
        //          - set the leftmost item in the left vector to 1 and the rightmost item in the right vector to 1
        //          - iterate through the left vector starting at index 1, multiplying the previous item from index in left by the previous item in input by the item behind it
        //          - do the same for the right vector, but instead of behind, you go one in front
        //          - multiply the left vector by the right vector and store it in the result vector
        //          - return result
        vector<int> product_excluding_i_optimized(vector<int> nums) {
            vector<int> left;
            vector<int> right;
            vector<int> result;
            left.resize(nums.size());
            right.resize(nums.size());
            result.resize(nums.size());
            left[0] = 1;
            right[right.size() - 1] = 1;

            for (int i = 1; i < nums.size() - 1; ++i) {
                left[i] = left[i-1] * nums[i-1];
            }

            for (int j = nums.size() - 2; j >= 0; --j) {
                right[j] = right[j+1] * nums[j+1];
            }

            for (int k = 0; k < nums.size() - 1; ++k) {
                result[k] = left[k] * right[k];
            }
            return result;
        }
}
