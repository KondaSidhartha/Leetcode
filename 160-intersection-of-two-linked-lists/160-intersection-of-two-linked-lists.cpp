/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //see this is the way just see start at head1 and head2 and start traversing  and if any one is null then assign that to opposite head so that the extra length larger ll be will covered
        //just see with some example u will understand dont panic just see the code and understand
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=temp2){
            temp1=(temp1==NULL)?headB:temp1->next;
             temp2=(temp2==NULL)?headA:temp2->next;
        }
        return temp1;
    }
};