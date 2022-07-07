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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=new ListNode(0);
        temp->next=head;
        ListNode* f=temp;
        ListNode* s=temp;
        while(n--){
            f=f->next;
        }
        while(f->next!=NULL){
            f=f->next;
            s=s->next;
        }
        s->next=s->next->next;
        return temp->next;
    }
};