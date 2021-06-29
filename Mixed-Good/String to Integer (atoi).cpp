class Solution {
public:
    int myAtoi(string s) {
        
        map<char,int> mp;
        mp.insert(make_pair('0',0));
        mp.insert(make_pair('1',1));
        mp.insert(make_pair('2',2));
        mp.insert(make_pair('3',3));
        mp.insert(make_pair('4',4));
        mp.insert(make_pair('5',5));
        mp.insert(make_pair('6',6));
        mp.insert(make_pair('7',7));
        mp.insert(make_pair('8',8));
        mp.insert(make_pair('9',9));
        
        
        string num = "";
        bool zero = false;
        bool flag = true;
        bool digit = false;
        bool got_digit = false;
        int got_char = false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' '&& digit==false && zero==false &&got_char==false)
            {
                continue;
            }
            else if(zero==true && digit==false && mp.find(s[i])==mp.end())
            {
                
                break;
            }
            else if(s[i]=='+' && digit==false)
            {
                if(got_digit)
                {
                    break;
                }
                got_char = true;
                got_digit = true;
                
            }
            else if(s[i]=='-' && digit==false)
            {
                flag = false;
                if(got_digit)
                {
                    break;
                }
                got_digit = true;
            }
            else if(s[i]=='0' && digit==false)
            {
                zero = true;
                continue;
            }
            
            else if(mp.find(s[i])!=mp.end())
            {
                digit = true;
                num +=s[i];
            }
            else
            {
                break;
            }
        }
        if(num=="")
        {
            return 0;
        }
        if(num.size()>9)
        {
            
            
            if(num.size()==10)
            {
                
                stringstream geek(num);
 
            // The object has the value 12345 and stream
            // it to the integer x
                int x = 0;
                geek >> x;
                if(!flag)
                {
                    x= -x;
                    num = "-"+num;
                    if(num!=to_string(x))
                    {
                        return -2147483648;
                    }
                }
                
                
                
                if(x>=2147483647)
                {
                    return 2147483647;
                }
                if(x<-2147483648)
                {
                    return -2147483648;
                }
                
                else
                {
                    return x;
                }
            }  
            
            
               
            
            if(flag==true)
            {
                return 2147483647;
            }
            else
            {
                return -2147483648;
            }
            
        }
        if(flag)
        {
            return stoi(num);
        }
        
        return -1*stoi(num);
    }
};
