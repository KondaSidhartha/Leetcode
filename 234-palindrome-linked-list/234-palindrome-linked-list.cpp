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
    ListNode* reverse(ListNode* slow){
        if(slow==NULL || slow->next==NULL){
            return slow;
        }
        ListNode* prev=NULL;
        ListNode* pres=slow;
        ListNode* nxt=slow->next;
        while(pres){
            pres->next=prev;
            prev=pres;
            pres=nxt;
            if(nxt){
                nxt=nxt->next;
            }
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* h2=reverse(slow);
        while(h2 && head){
            if(h2->val!=head->val)return false;
            h2=h2->next;
            head=head->next;
        }
        return true;
    }
};