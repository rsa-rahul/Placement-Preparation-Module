class Solution {
public:
    
    void floodFill2(vector<vector<int>>& image, int sr, int sc, int new_color, int old_color, int row_size, int col_size) {
        
        image[sr][sc] = new_color;
        
        //Fill the left cell, if it exists
        if(sc > 0) {
            if(image[sr][sc-1] == old_color) floodFill2(image, sr, sc-1, new_color, old_color, row_size, col_size);
        }
        
        //Fill the right cell, if it exists
        if(sc < col_size) {
            if(image[sr][sc+1] == old_color) floodFill2(image, sr, sc+1, new_color, old_color, row_size, col_size);
        }
            
        //Fill the above cell, if it exists
        if(sr > 0) {
            if(image[sr-1][sc] == old_color) floodFill2(image, sr-1, sc, new_color, old_color, row_size, col_size);
        }
            
        //Fill the below cell, if it exists
        if(sr < row_size) {
            if(image[sr+1][sc] == old_color) floodFill2(image, sr+1, sc, new_color, old_color, row_size, col_size);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        floodFill2(image, sr, sc, color, image[sr][sc], image.size()-1, image[0].size()-1);
        return image;
    }
};