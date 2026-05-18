class Solution {
public:
    void dfs(int r ,int c, vector<vector<int>>& image,int color,int oldcolor)  {
        int m=image.size(),n=image[0].size();

        if(r<0 ||r>=m || c<0 ||c>=n|| image[r][c]!=oldcolor)
            return ;
        image[r][c]=color;
        dfs(r-1,c,image,color,oldcolor);
        dfs(r+1,c,image,color,oldcolor);
        dfs(r,c-1,image,color,oldcolor);
        dfs(r,c+1,image,color,oldcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor=image[sr][sc];

        if(oldcolor == color)
            return image;
    
        dfs(sr,sc,image,color,oldcolor);
    
        return image;
    }
};