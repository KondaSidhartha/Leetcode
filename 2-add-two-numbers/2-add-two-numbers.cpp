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
       ListNode* prev=new ListNode(0);
        ListNode* head=prev;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0 ){
            ListNode* cur=new ListNode(0);
            int sum=((l1==NULL)?0:l1->val)+((l2==NULL)?0:l2->val)+carry;
            cur->val=sum%10;
            carry=sum/10;
            prev->next=cur;
            prev=cur;
            l1=(l1==NULL)?l1:l1->next;
            l2=(l2==NULL)?l2:l2->next;
        }
        return head->next;
    }
};