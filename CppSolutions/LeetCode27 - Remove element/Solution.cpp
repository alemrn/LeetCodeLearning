#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0;

        while (count < nums.size())
        {
            if (nums[count] == val)
            {
                for (int i = count; i < nums.size() - 1; i++)
                {
                    int temp = nums[i + 1];
                    nums[i] = temp;
                }
                nums.pop_back();
            }
            else
            {
                count++;
            }
        }
        return nums.size();
    }
};

int main()
{

    Solution s = Solution();

    const int vinit[] = {3, 2, 2, 3};

    vector<int> vect(vinit, end(vinit));

    cout << s.removeElement(vect, 3) << endl;

    return 0;
}