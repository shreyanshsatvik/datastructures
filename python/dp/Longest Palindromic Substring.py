class Solution:
    
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        max_len = 0
        if len(s)==1:
            return s
        for i in range(0,len(s)):
            #odd length
            l,r = i,i
            
            while(l>=0 and r<len(s) and s[l]==s[r]):
                if len(s[l:r+1])>max_len:
                    ans = s[l:r+1]
                    max_len = r-l+1
                l -= 1
                r += 1
            l,r = i,i+1
            while(l>=0 and r<len(s) and s[l]==s[r]):
                if len(s[l:r+1])>max_len:
                    ans = s[l:r+1]
                    max_len = r-l+1
                l -= 1
                r += 1
            
        return ans
                
        
        
