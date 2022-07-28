class Solution {
public:
    int getr(string &s,int i,vector<int> &mn,vector<int> &mx)
    {
        int r=mx[s[i]-'a'];
        for(int k=i;k<=r;k++)
        {
            if(mn[s[k]-'a']<i) return -1;
            r=max(r,mx[s[k]-'a']);
        }
        return r;
    }
    vector<string> maxNumOfSubstrings(string s) 
    {
        int n=s.length();
        vector<int> mn(26,1e9),mx(26,-1e9);
        for(int i=0;i<n;i++)
            mn[s[i]-'a']=min(mn[s[i]-'a'],i),mx[s[i]-'a']=max(mx[s[i]-'a'],i);
        
        int r=-1;
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            if(mn[s[i]-'a']==i)
            {
                int nwr=getr(s,i,mn,mx);
                if(nwr==-1) continue;
                if(i>r) ans.push_back("");
                r=nwr;
                ans.back()=s.substr(i,nwr-i+1);
            }
        }
        return ans;
    }
};