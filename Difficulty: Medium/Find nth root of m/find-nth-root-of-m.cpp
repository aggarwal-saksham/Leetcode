class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        if (m == 0) return 0;
        int low = 1, high = m;
	    while (low <= high)
	    {
	        int mid = (low + high)/2;
	        long long ans = 1;
    	    for(int i =1; i <= n; i++ )
    	    {
    	        ans = ans * mid;
    	        if(ans > m) break;
    	    }
    	    
	        if(ans == m)
	        { 
	            return mid;
	        }
	        else if(ans > m) 
	        {
	            high = mid - 1;
	        }
	        
	        else 
	        {
	            low = mid + 1;
	        }
	    }
	    return -1;
    }
};