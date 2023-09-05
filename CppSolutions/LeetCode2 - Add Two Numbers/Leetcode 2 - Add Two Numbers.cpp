
#include <iostream>
#include <math.h>
#include <stack>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

            ListNode* aux1 = l1;
            ListNode *aux2 = l2;
            ListNode *aux3;
            ListNode *result = new ListNode();

            int contL1 = 0;
            int contL2 = 0;
            int rest = 0;
            result->val = 0;
            result->next = NULL;
            aux3 = result;

            while(aux1!= NULL || aux2 != NULL){
                if(aux1!=NULL){
                    contL1 = aux1->val;
                    aux1 = aux1->next;
                }
                else {
                    contL1 = 0;
                }
                if(aux2!= NULL){
                    contL2 = aux2->val;
                    aux2 = aux2->next;
                }
                else{
                    contL2 = 0;
                }

                int sum = contL1 + contL2 + rest;
                if (sum >= 10){
                    rest = 1;
                    sum = sum - 10;
                }
                else{
                    rest = 0;
                }

                aux3->val = sum;
                aux3->next = new ListNode();
                if(aux2 != NULL || aux1 != NULL)
                    aux3 = aux3->next;
            }

            aux3 -> next = NULL;
            if(rest != 0){
                aux3->next = new ListNode(rest);
            }


            return result;
        }
};

int main(){

        Solution s = Solution();

        // ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3, NULL)));
        // ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4, NULL)));

        // ListNode* l1 = new ListNode(0, NULL);
        // ListNode* l2 = new ListNode(0, NULL);

        ListNode* l1 = new ListNode(
                        9, new ListNode(
                            9, new ListNode(
                                9, new ListNode(
                                    9, new ListNode(
                                        9, new ListNode(
                                            9, new ListNode(
                                                9, NULL)))))));
        ListNode* l2 = new ListNode(9, new ListNode(9, new ListNode(9, NULL)));

        s.addTwoNumbers(l1, l2);

        return 0;
}