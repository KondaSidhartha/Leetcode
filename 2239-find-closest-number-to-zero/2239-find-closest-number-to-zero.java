
class Solution{
    public int findClosestNumber(int[] data) {
       int ans=data[0];
        for ( int i=1; i < data.length;i++){
            if(Math.abs(ans)>=Math.abs(data[i])){
                if(Math.abs(ans)==Math.abs(data[i])){
                    ans=Math.max(ans,data[i]);
                }
                else{
                    ans=data[i];
                }
            }
        }

        return ans;
    }
}