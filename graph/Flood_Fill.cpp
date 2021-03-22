#define M 8
#define N 8
class Solution {
public:
    
    
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        
        int color = image[sr][sc];
        if(color!=newColor)
            flood(image,sr,sc,newColor,color);
        return image;
        
        
        
        
    }
    
    void flood(vector<vector<int>> &images, int sr, int sc, int newColor,int color)
    {
        
        int rows=images.size();
        int cols=images[0].size();
        if(sr>=rows || sr<0 || sc>=cols || sc<0 ||images[sr][sc]!=color)
        {
            return;
        }
        
        
        
        
        images[sr][sc]=newColor;
        
        flood(images,sr+1,sc,newColor,color);
        flood(images,sr-1,sc,newColor,color);
        flood(images,sr,sc+1,newColor,color);
        flood(images,sr,sc-1,newColor,color);
        
        
    
        
    } 
    
    
};
