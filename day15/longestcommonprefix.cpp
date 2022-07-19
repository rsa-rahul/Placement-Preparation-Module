class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     int n = strs.size();
        string st  = "";
        if(n==0) 
            return st;
        
        sort(begin(strs), end(strs));//for ex;we sort the string, now we compare least and highest terms only 
        string a = strs[0];
        string b = strs[n-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                st = st + a[i];
            }
            else{
                break;
            }
        }
        
        return st;   
    }
};