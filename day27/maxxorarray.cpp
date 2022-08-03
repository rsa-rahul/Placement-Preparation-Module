class Solution {
public:
struct Node 
{
    int val=0;
    Node* link[2];
    
    bool containKey(char ch){ 
        return (link[ch-'0']!=NULL);
    }
    void createKey (char ch, Node* node){
        link[ch-'0']=node;
    }
    Node* next(char ch){
        return link[ch-'0'];
    }
    void setEnd(int val_s){
        val=val_s;
    }
    int isEnd(){
        return val;
    }
};
    
    Node* root= new Node();
    
    void insert(int n) 
    {
        Node* node=root;
        for (int i = 31; i >= 0; i--) 
        {
            int k = n >> i;
            char ch;
            if (k & 1)
            ch='1';
            else
            ch='0';
                
            if(!node->containKey(ch))
            { 
                node->createKey(ch, new Node());
            }
            node=node->next(ch);     
        }
        node->setEnd(n); 
    }
    
    int maxsame(int n)    
    {
        Node* node=root;
        for (int i = 31; i >= 0; i--) 
        {
            int k = n >> i;
            char ch;
            if (k & 1)
            ch='1';
            else
            ch='0';
                
            if(!node->containKey(ch))
            { 
                if(ch=='1')
                node=node->next('0');
                else if(ch=='0')
                node=node->next('1');
            }
            else
            node=node->next(ch);     
        }
        return node->isEnd();
    }
    
    static bool sortbysec(const vector<int> &a, const vector<int> &b)
    {
        return (a[1]<b[1]);
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int> ans(queries.size(),0);
        
        int i=0;
        for(vector<int> &v : queries)
        v.push_back(i++);
            
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(),nums.end());
        sort(queries.begin(),queries.end(),sortbysec);
        
        int flag=0;
        for(vector<int> v : queries)
        {
            while(!pq.empty() and pq.top()<=v[1])
            {
                flag=1;
                insert(pq.top());
                pq.pop();
            }
            int xor_val = flag==1 ? maxsame(~v[0])^v[0] : -1;
            ans[v[2]]=xor_val;
        }
        return ans;
    }
};