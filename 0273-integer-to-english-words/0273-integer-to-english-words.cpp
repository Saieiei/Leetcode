class Solution {
public:
    vector<pair<int, string>> mp = {{1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, 
    {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

    string numberToWords(int num) {
        //to solve this using recursion, we will deivide this into 3 parts
        //later on we will add these parts
        //for example 3201 = three thousand - two hundreed - one
        //later on we will club then together (a + b + c)
        //a will be used to get the highest part 1st, only for >=100
        //b will be used to get the quick part 1st
        //c will be used to get the remaining parts
        //for tagging we will use vector<pair<int, string>>, and make it global

        //bc
        if(num == 0){
            return "Zero";
        }

        //traverse through the map
        for(pair<int, string>& pairData: mp){
            //we will consider those where the number >= to the mapping
            if(num >= pairData.first){
                //since this num >= .first we will break it down
                //future
                string a = "";
                if(num >= 100){
                    a  = numberToWords(num/pairData.first) + ' ';
                }
                //present
                string b;
                b = pairData.second;
                //past (remaining)
                string c = "";
                if(num % pairData.first != 0){
                    c = ' ' + numberToWords(num % pairData.first);
                }
                return a + b + c;
            }
        }
        //not possible 
        return "";
    }
};