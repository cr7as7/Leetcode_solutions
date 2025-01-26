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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * dNode = new ListNode(-1);
        ListNode * tmp = dNode;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                dNode->next = list1;
                dNode = dNode->next;
                list1 = list1->next;
            }
            else{
                dNode->next = list2;
                dNode = dNode->next;
                list2 = list2->next;
            }
        }
        while(list1){
            dNode->next = list1;
                dNode = dNode->next;
                list1 = list1->next;
        }
        while(list2){
            dNode->next = list2;
                dNode = dNode->next;
                list2 = list2->next;
        }
        return tmp->next;
    }
};