class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestLength = 0 , l=0, r=0;
          std::string seen;
          while(r < s.size()) {
             if(auto found = seen.find(s[r]); found == std::string::npos) {
                  seen += s[r++];
              } else {
                  longestLength = std::max(longestLength, r-l);
                  seen.erase(0,found+1);
                  l+= found+1;
              }
          }
          return std::max(longestLength, r-l);
    }
};