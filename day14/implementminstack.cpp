class MinStack {
public:
	long long mini;
	stack<long long> st;
	MinStack() {
		mini = INT_MAX;
	}

	void push(int value) {
		long long val = value;
		if(st.empty())
		{
			mini = val;
			st.push(val);
		}
		else
		{
			if(val<mini)
			{
				st.push(2*val*1LL - mini);
				mini = val;
			}
			else   st.push(val);
		}
	}

	void pop() {
		if(!st.empty())
		{
			long long ele = st.top();
			st.pop();
			if(ele<mini)    mini = 2*mini-ele;
		}
	}

	int top() {
		if(st.empty())  return -1;
		long long ele = st.top();
		if(ele<mini)    return mini;
		return ele;
	}

	int getMin() {
		return mini;
	}
};