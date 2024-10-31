/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        int over = 0;
        while(l1 || l2 || over){
            int a = 0, b = 0;
            ListNode* next_node = new ListNode();
            if(l1) {
                a = l1->val;
                l1 = l1->next;
            }
            if(l2){
                b= l2->val;
                l2 = l2->next;
            }
            int c = a+b+over;
            if(c>9){
                next_node->val = c%10;
                over = c/10;
            }
            else{
                next_node->val = c;
                over = 0;
            }
            curr->next = next_node;
            curr = next_node;
        }
        return ans->next;
    }
};