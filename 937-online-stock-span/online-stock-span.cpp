class StockSpanner {
public:
vector<int> prices;
stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && prices[st.top()]<=price)
        {
            st.pop();
        }

        int pge=(!st.empty())? st.top():-1;
        prices.push_back(price);
        st.push(prices.size()-1);
        
        return st.top()-pge;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */