#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;



class Solution {
    public:

vector<int> solutionOne(vector<int>& nums, int target){
    int i = 0;
        int j = 1;
        bool encontrado = false;
        vector<int> result;

        while ( i < nums.size() && !encontrado){
            while(j< nums.size() && !encontrado){
                if(nums[i]+nums[j] == target){
                    encontrado = true;
                }
                else{
                    j++;
                }
            }
            if(!encontrado){
                i++;
                j = i + 1;
            }
        }

        result.push_back(i);
        result.push_back(j);
        return result;
}

    vector<int> solutionTwo(vector<int>& nums, int target){

        map<int, int> solution;
        int i = 0;
        bool found = false;

        vector<int> result;

        while(i<nums.size() && !found){
            if(solution.find(nums[i])!=solution.end()){
                found = true;
                result.push_back(solution[nums[i]]);
                result.push_back(i);
            }
            else{
                
                int minus = target - nums[i];
                solution[minus] = i;
                i++;
            }

        }
        cout << result[0] << ", " << result[1] << endl;
        return result;
    }


    vector<int> twoSum(vector<int>& nums, int target){

        // return solutionOne(nums, target);
        return solutionTwo(nums, target);
    }
};

int main(){
    Solution s = Solution();
    // vector<int> vec{2, 7, 11, 15};
    // s.twoSum(vec, 9);
    // vector<int> vec1{3,2,4};
    // s.twoSum(vec1, 6);
    // vector<int> vec2{3,3};
    // s.twoSum(vec2, 6);
    vector<int> vec3{5,75,25};
    s.twoSum(vec3, 100);
    return 0;
}