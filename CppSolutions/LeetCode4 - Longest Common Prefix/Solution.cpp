#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }

        int minimalStringLength = INT_MAX;

        for (int i = 0; i < strs.size(); i++){
            if(strs[i].length() < minimalStringLength){
                minimalStringLength = strs[i].length();
            }
        }

        int row = 0;
        int column = 0;
        bool common = true;

        stringstream result("");

        while (row < minimalStringLength && common){
            while (column < strs.size()-1 && common){
                if(strs[column][row] == strs[column+1][row]){
                    column++;
                }
                else{
                    common = false;
                }
            }
            column = 0;
            if(common){
                row++;
                
                result << strs[0][row];
            }

        }

        return result.str();
    }
};

int main(){

    Solution s = Solution();

    const char *vinit[] = {"almeja", "almendra", "guacamole"};

    vector<string> vect(vinit, end(vinit));

    cout << s.longestCommonPrefix(vect) << endl;

    return 0;
}