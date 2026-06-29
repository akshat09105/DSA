class Solution {
public:
    bool rotateString(string s, string goal) {
        int x=s.size();int y=goal.size();
        if(x!=y){
            return false;
        }
        if((s+s).contains(goal)){
            return true;
        }
        return false;
    }
};