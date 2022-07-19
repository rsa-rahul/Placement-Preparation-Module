string reverseWords(string s) {
        int n = s.size();
		vector<string> words;             // To store the words
        string t = "";
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                if(t.size() == 0){       // If the string is null i.e ' ' the do not push into the array
                    t = "";
                }
                else{
                    words.push_back(t);
                    t = "";
                }
            }
            else{
                t += s[i];
            }
        }   

        if(t.size() != 0)                // Same condition as above
            words.push_back(t);

        string ans;    // Iterate the array and concatenate the strings together
        for(int i=words.size()-1; i>=1; i--){
                ans += (words[i] + ' ');
        }
		
        ans+=words[0]; // Last word to be pushed seperately since we do not want any space after the word
        
        return ans;
    }