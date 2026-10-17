import java.util.Vector;
class Solution {
    public boolean checkIfPangram(String sentence) {
        int n=sentence.length();
        int[] vt=new int[26];
        for(int i=0;i<n;i++){
            vt[sentence.charAt(i)-'a']++;
        }
        for(int i=0;i<26;i++){
            if(vt[i]==0){
                return false;
            }
        }
        return true;
    }
}