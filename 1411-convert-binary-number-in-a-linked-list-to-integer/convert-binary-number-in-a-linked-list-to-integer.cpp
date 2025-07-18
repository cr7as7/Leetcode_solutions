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
    int getDecimalValue(ListNode* head) {
        int l =0;
        ListNode * temp = head;
        while(temp != NULL){
            l++;
            temp = temp->next;
        }
        temp = head;
        int ans = 0;
        while(temp !=NULL){
            if(temp->val == 1){
                ans+=pow(2,l-1);
            }
            temp = temp->next;
            l--;
        }
        return ans;
    }
};