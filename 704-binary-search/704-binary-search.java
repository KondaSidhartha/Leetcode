class Solution {
    public int search(int[] a, int target) {
     int s=0;
     int e=a.length-1;
     while(s<=e){
      int mid=(s+e)/2;
      if(a[mid]==target){
        return mid;
      }
      else if(a[mid]>target){
        e=mid-1;
      }
      else{
        s=s=mid+1;
      }
     }
     return -1;
    }
}