#include<bits/stdc++.h>

class TrieNode{
    
    public:
        
        int data;
        TrieNode* children[2];
    
    
    TrieNode(int d){
        
        this->data = d;
        
      children[0] = NULL;
      children[1] = NULL;
      
    }
    
};

class Trie{
    
    public:
    
    TrieNode* root;
    
    Trie(){
        root = new TrieNode(5);
    }
    
    
    void insertUtil(TrieNode* root , int &num){
       TrieNode* curr = root;
        
        for(int i=31 ; i>=0 ; i--){   // insert
            
            int bit = (num >> i) & 1;   
            
            if( curr->children[bit] == NULL){
                    curr->children[bit] = new TrieNode(bit);
            }
            
            curr = curr->children[bit];
        }   
        
    }
    
    
    void insert(int &num){
        insertUtil(root ,  num);
    }
    
    
    
    int MaxXorAns(TrieNode* root , int x ){
            int ans = 0;
            
             TrieNode* curr = root;
        
            for(int i=31;i>=0;i--){
                
                int bit = (x >> i) & 1;
                int opp = !bit;
                
                if( curr->children[opp] ){         
                    ans = ans + (1<<i);   // 1<<i  = 2^i  
                    curr = curr->children[opp];
                }
            
                else{
                    curr = curr->children[bit];
                }
           
            }  //  for loop
            
            return ans;
            
    }
    
    
    int maxXor(int x ){
        return MaxXorAns(root , x ); 
    }
    
    
   
};   // class  Trie



vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	
    Trie* t = new Trie();
    
    int n = arr.size();
    int m = queries.size();
    
     // 1st Step : 
    
        sort(arr.begin() , arr.end());
    
    
    // 2nd step 
    
    vector< pair< int , pair<int,int> > > ofpair;    //  ai  ,  xi,querIdx  
    
    
    for(int i=0;i<m;i++){
        ofpair.push_back( { queries[i][1]  , { queries[i][0],i } }  );
        
    }
    
    sort(ofpair.begin() , ofpair.end() );
    
    
    // 3rd  Step : 

        vector<int> vecAns(m);  
        int k=0;
    
    for(int i=0;i<m;i++){
        
        int ai = ofpair[i].first;
        int xi = ofpair[i].second.first;
        int Storeindex = ofpair[i].second.second;

//         cout<<ai <<"  : "<<xi<<","<<Storeindex<<endl;
        
        while(k<n && arr[k] <= ai){
               t->insert(arr[k]);
                k++;
        }
        
        
        if(k==0){
            vecAns[Storeindex] = -1;
        }
        
        else{
              vecAns[Storeindex] = t->maxXor(xi);
        }
        
        
   }
    
    
    return vecAns;
    
}