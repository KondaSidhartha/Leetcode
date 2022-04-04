/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        ListNode temp1=head;
        int size=0;
        while(temp1!=null){
        	temp1=temp1.next;
        	size++;
        }
        temp1=head;
        ListNode temp2=head;
        int i=1;
        int j=1;
        while(i<k||j<=size-k){
        	if(i<k){
        		temp1=temp1.next;
        		i++;
        	}
        	if(j<=size-k){
        		temp2=temp2.next;
        		j++;
        	}
        }
        int temp=temp1.val;
        temp1.val=temp2.val;
        temp2.val=temp;
        return head;
    }
}