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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
         ListNode ans = new ListNode(-1) ;
         ListNode node = ans ;
         while(list1 != null && list2 != null){
             if(list1.val > list2.val){
                 node.next = list2 ;
                 list2 = list2.next ;
             }else{
                 node.next = list1 ;
                 list1 = list1.next ;
             }
             node = node.next ;
         }
        
        ListNode surplus = list1 == null ? list2 : list1 ;
        node.next = surplus ;       
        return ans.next ;       
    }
}