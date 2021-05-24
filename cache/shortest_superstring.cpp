class Solution {
public:
    int flag = 0;
    //function to count prefix-suffix
    
    int match_length(string word1,string word2)
    {
        for(int i=0;i<word1.length();i++)
        {
            string str1 = word1.substr(i,word1.length()-1);
            string str2 = word2.substr(0,str1.size());
            if(str1==str2)
            {
                return str1.size();
            }
        }
        return 0;
    }
    //function to merge two string 
    string merge(string word1,string word2,int n)
    {
        
        string new_str2 = word2.substr(n,word2.size());
        return word1+new_str2;
    }
    //creation of dictionary of count
    void convt_dictionary(vector<string> &words, map <int,map<string,string>> &mp ,int &net_match)
    {
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i==j)
                {
                    continue;
                }
                int k = match_length(words[i],words[j]);
                int l = match_length(words[j],words[i]);
                
                net_match +=k;
                
                if(k<=0)
                {
                    
                    continue;
                    
                }
                if(k>l)
                {
                     mp[k].insert(make_pair(words[i],words[j]));
                }
                else
                {
                    mp[l].insert(make_pair(words[j],words[i]));
                }
            }
        }
    }
    
    
    string shortestSuperstring(vector<string>& words) {
        
        //cout<<match_length("catg","atgcatc");
        if(words.size()==1)
        {
            return words[0];
        }
       
        int net_match = 0;
        
        map <int,map<string,string>> mp;
        map<int, map<string, string>>:: reverse_iterator itr;
        map<string, string>::iterator ptr;
        
        convt_dictionary(words,mp,net_match);
        
        if(net_match==0)
        {
            string ans = "";
            for(int i=0;i<words.size();i++)
            {
                ans += words[i];
            }
            return ans;
        }
        for(itr=mp.rbegin();itr!=mp.rend();itr++)
        {
            for(ptr=itr->second.begin();ptr!=itr->second.end();ptr++)
            {
                cout<<itr->first<<" "<<ptr->first<<" "<<ptr->second<<endl;
            }
        }
        cout<<"Done"<<endl;
        for(itr=mp.rbegin();itr!=mp.rend();itr++)
        {
            for(ptr=itr->second.begin();ptr!=itr->second.end();ptr++)
            {
                //cout<<itr->first<<" "<<ptr->first<<" "<<ptr->second<<endl;
                
                int n = itr->first;
                string s_new = merge(ptr->first,ptr->second,n);
                cout<<ptr->first<<" "<<ptr->second<<" "<<s_new<<" "<<n<<endl;
                words.erase(remove(words.begin(), words.end(), ptr->first), words.end());
                words.erase(remove(words.begin(), words.end(), ptr->second), words.end());
                
                words.push_back(s_new);
                
               
                break;
            }
            break;
        }
      
        return shortestSuperstring(words);
    }
};
