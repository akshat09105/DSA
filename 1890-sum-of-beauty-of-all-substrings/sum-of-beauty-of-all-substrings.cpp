class Solution {
public:
    int beautySum(string s) {
        int n=s.size();int beauty=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int maxfreq=INT_MIN;
                int minfreq=INT_MAX;
                for(int k=0;k<26;k++){
                    if(freq[k]>maxfreq){
                        maxfreq=freq[k];
                    }
                    if(freq[k]<minfreq && freq[k]>0){
                        minfreq=freq[k];
                    }
                }
                beauty+=(maxfreq-minfreq);
            }
        }   
        return beauty;
    }
};