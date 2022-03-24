class Solution {
    public int numRescueBoats(int[] a, int max) {
        Arrays.sort(a);
        int ans=0;
        int i=0;
        int j=a.length-1;
        while(i<=j)
            {
            if(a[i]+a[j]<=max)
               {
                   i++;
                   j--;
                   ans++;
                   }
           else{
               ans++;
                   j--;
                   }
               }
               return ans ;
        
        
    }
}