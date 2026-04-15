/*
 * Problem #1352: Product of the Last K Numbers
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/11/2025, 9:30:19 PM
 * Link: https://leetcode.com/problems/product-of-the-last-k-numbers/
 */

class ProductOfNumbers
{
    public:	//0 0 40 20 4
        vector<int> arr;
    ProductOfNumbers()
    {
        vector<int> arr;
    }

    void add(int num)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] *= num;
        }
        arr.push_back(num);
    }

    int getProduct(int k)
    {
        return arr[arr.size() - k];
    }
};

/**
 *Your ProductOfNumbers object will be instantiated and called as such:
 *ProductOfNumbers* obj = new ProductOfNumbers();
 *obj->add(num);
 *int param_2 = obj->getProduct(k);
 */
