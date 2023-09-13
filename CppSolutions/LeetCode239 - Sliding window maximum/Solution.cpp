#include <iostream>
#include <math.h>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{

    using int2 = pair<int, int>; //(nums[i], i)

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<int2> pq;
        vector<int> solution;

        for (int i = 0; i < k; i++)
            pq.push({nums[i], i});

        solution.push_back(pq.top().first);
        for (int i = k; i < n; i++)
        {
            while (!pq.empty() && pq.top().second <= (i - k))
                pq.pop();
            pq.push({nums[i], i});
            solution.push_back(pq.top().first);
        }

        return solution;
    }
};

int main(int argc, char const *argv[])
{

    Solution s = Solution();
    int vinit[] = {1, 3, -1, -3, 5, 3, 6, 7};

    vector<int> vect(vinit, end(vinit));

    vector<int> solution = s.maxSlidingWindow(vect, 3);

    for (std::vector<int>::iterator it = solution.begin(); it != solution.end(); ++it)
        std::cout << ' ' << *it;

    return 0;
}
