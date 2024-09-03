class Solution {
public:
    string transformAddition(string& indexBasedString)
    {
        //take the first char
        int sum = 0;
        for(char ch: indexBasedString)
        {
            //convrt the char in to its integer
            int ele = ch - '0';
            sum = sum + ele;
        }
        //now convrt that integer into string
        return to_string(sum);
    }

    int getLucky(string s, int k) {
        //1t we will convrt the string to index based string
        string indexBasedString = "";
        for(char ch:  s)
        {
            int index = ch - 'a' +1;
            indexBasedString = indexBasedString + to_string(index);
        }
        //cout<<indexBasedString<<endl;
        
        //now we will convert the string to a number by adding the digits
        string transform1 = transformAddition(indexBasedString);
        //cout<<transform1<<endl;
        //now repeat the preocess based on the number k -1 because we have already done once
        for(int i=1;  i<k; i++)
        {
            transform1 = transformAddition(transform1);
        }
        //now return it as a integer
        return stoi(transform1);
    }
};