class Solution {
public:
    vector<int> split(string s,char c){
        vector<int>ans;
        string temp="";
        for(char C:s){
            if(C==c){
                ans.push_back(stoi(temp));
                temp="";
            }else temp+=C;
        }
        ans.push_back(stoi(temp));
        return ans;
    }
    int compareVersion(string version1, string version2) {
        vector<int>one = split(version1,'.');
        vector<int>two = split(version2,'.');
        int i=0,j=0;
        while(i<one.size() && j<two.size()){
            if(one[i]>two[j])return 1;
            if(one[i]<two[j])return -1;
            i++,j++;
        }
        while(i<one.size()){
            if(one[i]>0)return 1;
            i++;
        }
        while(j<two.size()){
            if(two[j]>0)return -1;
            j++;
        }
        return 0;
    }
};