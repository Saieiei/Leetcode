class ProductOfNumbers {
public:
    vector<long long>prefixProd;
    //i will tell u later y we r maintaing the prefixProd array
    // prefixProd will store the prefix products since the last zero.
    // prefixProd[i] = product of the stream elements from the last zero up to index i
    // (i.e., if the last zero was at position p, then prefixProd[i] = product of numbers in [p+1 ... i])
    ProductOfNumbers() {
        // Initially empty
        prefixProd.clear();
    }
    
    void add(int num) {
        //its simple. if no elements are there in prefixProd, then simple push
        //else just multiply with the last element in the prefixProd and push in
        //but if num == 0 then just clear the prefixProd array, because there is no point as, whaty ever u multiply with 0 is always 0, 
        //so if our prefixProd is empty, that means our last element (num) is 0, so if they ask getProduct, just return 0

        if(num == 0)
            prefixProd.clear();
        else
        {
            if(prefixProd.empty())
                prefixProd.push_back(num);
            else
                prefixProd.push_back(num*prefixProd.back());
        }
    }
    
    int getProduct(int k) {
        //here is where a formula comes which idk how it comes
        ////so if our prefixProd is empty, that means our last element (num) is 0, so if they ask getProduct, just return 0 (refer add)
        //if out k is exactly the size of prefixProd,then, clearly, the last element of the prefixProd is the ans
        //cuz think about it logically, they basically want to multiply all the elemnts, hence they last element of prefixProd is the ans
        //else, then u have to apply this formual to get ans prefixProd.back()/(PrefixProd[PrefixProd.size()-1-k])
        if(k> (int)prefixProd.size()) return 0;

        if(k == (int)prefixProd.size()) return (int)prefixProd.back();
        else
        {
            return (int)(prefixProd.back()/(prefixProd[prefixProd.size()-1-k]));
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */