class Solution {
    public boolean rotateString(String s, String goal) {
       if(s.length() != goal.length()){
        return false;
    }
    
    for(int i=0;i<s.length();i++){
        if(goal.charAt(0) == s.charAt(i)
          && s.substring(0,i).equals(goal.substring(s.length()-i,s.length()))
           && s.substring(i,s.length()).equals(goal.substring(0,s.length()-i))
          ){
                return true;
        }
    }
    return false;  
    }
}