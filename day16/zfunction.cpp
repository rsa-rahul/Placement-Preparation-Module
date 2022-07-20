class Solution {
public:
    int strStr(string haystack, string needle) {
     int n=haystack.length();
    int m=needle.length();

    if(m==0){
        return 0;
    }
    int i=0;
    int j=m-1;
    
    while(j<n){
        string s=haystack.substr(i,j-i+1);
        if(s==needle){
            return i;
        }
        j++;
        i++;
    }
    
    return -1;
}
};