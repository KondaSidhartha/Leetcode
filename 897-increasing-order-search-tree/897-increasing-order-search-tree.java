/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode increasingBST(TreeNode root) {
        return helper(root,null);
    }
    private TreeNode helper(TreeNode node,TreeNode next){
    if(next!=null){
        next.left=null;
    }
    if(node==null){
        return next;
    }
    node.right=helper(node.right,next);
    return helper(node.left,node);
}
}