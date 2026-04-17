class Solution {
public:
    void reverse(vector<int>&arr){
        int left=0;
        int right=arr.size()-1;
        while(left<=right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        for(int i=0;i<n-1;i++){//making transpose
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i]);
        }
    }
};