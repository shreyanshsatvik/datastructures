class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="/" || tokens[i]=="-" || tokens[i]=="*")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c;
                if(tokens[i]=="+")
                {
                    c = b + a;
                }
                else if(tokens[i]=="*")
                {
                    c = b * a;
                }
                else if(tokens[i]=="/")
                {
                    c = b / a;
                }
                else if(tokens[i]=="-")
                {
                    c = b - a;
                }
                st.push(c);
                
            }
            else
            {
                int n = stoi(tokens[i]);
                st.push(n);   
            }
            
        }
    
        return st.top();
        
        
    }
};
