#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        string str = to_string(x);
        int init = 0;
        int fin = str.length()-1;
        bool palindrome = true;
        while(init < fin && palindrome){
            if(str[init] == str[fin]){
                init++;
                fin--;
            }
            else{
                palindrome = false;
            }

        }

        cout << (palindrome ? "true" : "false") << endl;

        return palindrome;
    }
};

int main(){

    Solution s = Solution();

    bool result = s.isPalindrome(500);
    result = s.isPalindrome(000);
    result = s.isPalindrome(505);
    result = s.isPalindrome(506);
    result = s.isPalindrome(5005);


    return 0;
}