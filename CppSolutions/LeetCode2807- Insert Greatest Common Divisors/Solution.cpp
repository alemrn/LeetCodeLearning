#include <iostream>
#include <math.h>
#include <stack>
#include <string>
#include <chrono>
#include <unistd.h>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {

        ListNode *a = head;
        ListNode *b = head->next;
        int gcd = 1;

        while (b != NULL)
        {
            gcd = __gcd(a->val, b->val);
            a->next = new ListNode(gcd, b);
            a = b;
            b = b->next;
            cout << gcd << endl;
        }

        return head;
    }
};

int main(int argc, char const *argv[])
{

    Solution s = Solution();

    ListNode *t1 = new ListNode(18, new ListNode(6, new ListNode(10, new ListNode(3, NULL))));
    auto start = chrono::steady_clock::now();

    s.insertGreatestCommonDivisors(t1);

    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in milliseconds: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}
