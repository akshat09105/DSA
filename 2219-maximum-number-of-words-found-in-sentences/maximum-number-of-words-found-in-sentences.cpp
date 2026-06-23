class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n=sentences.size();
        int max_count=INT_MIN;int ans=-1;
        for(int i=0;i<n;i++){
            int count=0;
            string s=sentences[i];
            for(int j=0;j<s.size();j++){
                if(s[j]==' '){
                    count++;
                }
                if(count>max_count){
                    max_count=count;
                }
            }
        }
        return max_count+1;
    }
};