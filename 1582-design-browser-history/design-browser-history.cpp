class BrowserHistory {
public:
stack<string> past,future;
string cur;
    BrowserHistory(string homepage) {
        cur=homepage;
    }
    
    void visit(string url) {
        future=stack<string>(); // clear future
        past.push(cur);
        cur=url;
    }
    
    string back(int steps) {
        while(steps-- && !past.empty())
        {
            future.push(cur);
            cur=past.top();
            past.pop();
        }

        return cur;
    }
    
    string forward(int steps) {
        while(steps-- && !future.empty())
        {
            past.push(cur);
            cur=future.top();
            future.pop();
        }

        return cur;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */