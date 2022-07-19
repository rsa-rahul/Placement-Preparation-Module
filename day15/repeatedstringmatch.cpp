class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        string s = a;
        int moves=1;
        while(a.length()<b.length())
        {
            a+=s;
            moves++;
        }
        if(a.find(b)!=-1)
            return moves;
        a+=s;
        moves++;
        if(a.find(b)!=-1)
            return moves;
        else
            return -1;
        
    }
};