class Solution {
public:
    void dfs (vector<vector<int>>& image,int i, int j, int intial , int newC ){
        if (i<0 || j <0 || i>=image.size() || j>=image[0].size() || image[i][j]!= intial)
            return;
        image[i][j]=newC;
        dfs (image,i+1,j,intial,newC);
        dfs (image,i-1,j,intial,newC);
        dfs (image,i,j+1,intial,newC);
        dfs (image,i,j-1,intial,newC);
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!= newColor)dfs(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};