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
    public TreeNode convertBST(TreeNode root) {
        if(root==null){
            return root;
        }
        gst(root,0);
        return root;
    }
    public int gst(TreeNode root,int ans){
        if(root==null){
            return 0;
        }
        if(root.right!=null){
            root.val+=gst(root.right,ans);
        }
        else{
            root.val+=ans;
        }
       if (root.left != null) {
        return gst(root.left, root.val);
        
       }
        return root.val;
    }
}