vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    int res=0;
    int set_bit=0;
    int x=0,y=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        res^=A[i];
        res^=(i+1);
    }
   
    set_bit=res & ~(res-1);
   
    for(int i=0;i<n;i++)
    {
        if(set_bit & A[i])
        {
            x^=A[i];
        }
        else
        {
            y^=A[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(set_bit & i)
        {
            x^=i;
        }
        else
        {
            y^=i;
        }
    }
   
    int x_count=0;
    for(int i=0;i<n;i++)
    {
        if(x==A[i])
        {
            x_count++;
        }
    }
   
    if(x_count>0)
    {
        return {x,y};
    }
   

    return{y,x};

}