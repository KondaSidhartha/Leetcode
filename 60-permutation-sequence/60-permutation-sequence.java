class Solution {
    public String getPermutation(int n, int k) {
        k=k-1;
        List<Integer> ls=new ArrayList<>();
        int fact=1;
        for(int i=1;i<=n;i++){
            ls.add(i);
            if(i==n)break;
            fact*=i;
        }
        StringBuilder str = new StringBuilder();
        while(true){
            int index = k/fact;
            str.append(ls.get(index));
            ls.remove(index);
            k=k%fact;
            if(ls.size()==0){
                return str.toString();
            }
            fact=fact/ls.size();
        }
    }
}