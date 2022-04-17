class Solution {
    public long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long ans=0;
        for(int i=0;i<=total;i=i+cost1){
            int temp=total-i;
            int n=(temp/cost2)+1;
            ans+=n;
        }
        return ans;
    }
}