class Solution {
   public  int lengthOfLongestSubstring(String s) {
        return find("",s,0);
        
    }

    public  int find(String p,String s,int max) {
        max=Math.max(p.length(),max);
        if(s.isEmpty())
        {
            return max;
        }
        char ch=s.charAt(0);
        if(p.length()==0)
        {
            return find(p+ch,s.substring(1),max);
        }
        for (int i=0;i<p.length();i++) {
            if(p.charAt(i)==ch){
                return find(p.substring(i+1,p.length()),s,max);
            }
        }
        return find(p+ch,s.substring(1),max);
    }
}