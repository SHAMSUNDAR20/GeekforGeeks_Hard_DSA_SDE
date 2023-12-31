

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        
                if(array1.size() > array2.size()){
            return MedianOfArrays(array2, array1);
        }
        
        int x = array1.size();
        int y = array2.size();
        
        int start = 0;
        int end = x;
        
        while(start <= end){
            int partitionX = (start + end) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : array1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : array1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : array2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : array2[partitionY];
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                if((x + y) % 2 == 0){
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                }else{
                    return (double)max(maxLeftX, maxLeftY);
                }
            }else if(maxLeftX > minRightY){
                end = partitionX - 1;
            }else{
                start = partitionX + 1;
            }
        }
        
        throw "Input arrays are not sorted";
    
    }
};