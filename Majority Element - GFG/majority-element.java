// { Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Geeks
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n =sc.nextInt();
            int arr[] = new int[n];
            
            for(int i = 0; i < n; i++)
             arr[i] = sc.nextInt();
             
           System.out.println(new Solution().majorityElement(arr, n)); 
        }
    }
}// } Driver Code Ends


//User function Template for Java

class Solution
{
   static int majorityElement(int a[], int size)
   {
       int m=(int)Math.ceil(size/2);
       Arrays.sort(a);
       int f=1;
       for(int i=1;i<size;i++)
       {
           if(a[i]==a[i-1])
           f++;
           else
           {
               if(f>m)
               return a[i-1];
               else
               f=1;
           }
       }
       if(f>m)
       return a[size-1];
       else
       return -1;
   }
}