class StockSpanner {
public:
StockSpanner() {

}

int next(int price) {
    int result=0;
    stocks.push_back(price);
    while(stk.size() && stocks[stk.top()] <= stocks[day]) stk.pop();
    if(stk.size()==0) result = day+1;
    else result = day-stk.top();
    stk.push(day);
    day++;
    return result;
}
private:
vector stocks;
stack stk;
int day=0;
};