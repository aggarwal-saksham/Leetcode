// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long low = 0, high = x;
        while(low <= high){
            long long mid = (low + high)/2;
            if((mid * mid ) <= x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        return high;
    }
};
