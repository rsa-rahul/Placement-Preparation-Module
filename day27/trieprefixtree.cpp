class TrieNode {
public:
    char letter;
    unordered_map<char, TrieNode*> map; 
    bool isWord = false;
};

class Trie {
public:

    TrieNode* root; 
    
    Trie() { root = new TrieNode; }
    
    void insert(string word) {
        TrieNode* nodePtr = root;
        
        for(const auto& c : word){
            if(nodePtr->map.find(c) == nodePtr->map.end()){
                TrieNode* cNode = new TrieNode;
                nodePtr->map[c] = cNode;
                nodePtr = nodePtr->map[c];
            } else
                nodePtr = nodePtr->map[c];
        }
        nodePtr->isWord = true;
    }        
    
    bool search(string word) {
        TrieNode* nodePtr = root;
        return traverse(nodePtr, word) && nodePtr->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* nodePtr = root;
        return traverse(nodePtr, prefix);
    }
    
    bool traverse(TrieNode*& nodePtr, std::string& s){
        for(const char& c : s){
            if(nodePtr->map.find(c) == nodePtr->map.end())
                return false;
            nodePtr = nodePtr->map[c];
        } 
        return true;
    }
};