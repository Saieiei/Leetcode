//week5_ass_9
class Solution {
public:
    int compress(vector<char>& s) {
        //we will use 2 pointers
        int index=0; //this is where we will mkae changes in teh string
        int count=1; //we will count the number of repeating chars
        char prev=s[0]; // we will start i with 1 (2 pointers)

        for(int i=1;i<s.size();i++) //traverse through the characters
        {
            if(prev==s[i]) //if both chars same
            {
                count++;
            }
            else //if both chars not same
            {
                //update the ans
                s[index]=prev;
                index++; //move tthe index to the next position
                if(count>1)
                {
                    //if ur count is more than 1 digit or whatever
                    int start=index; //here we will insert the number
                    while(count>0)
                    {
                        s[index]=(count%10)+'0';
                        index++;
                        count=count/10;
                    }
                    //now we will reverse the number because
                    //for example it is a132
                    //but it will inserta231
                    //so we need to reverse from (s[0] to s[3])
                    reverse(s.begin()+start, s.begin()+index);
                }
                //now we will update both the pointers and count=1;
                //i is auto updated
                prev=s[i];
                count=1;
            }
            
        }

        //we have to do it again for the last same element
        s[index]=prev;
        index++; //move tthe index to the next position
        if(count>1)
        {
            //if ur count is more than 1 digit or whatever
            int start=index; //here we will insert the number
            while(count>0)
            {
                s[index]=(count%10)+'0';
                index++;
                count=count/10;
            }
            //now we will reverse the number because
            //for example it is a132
            //but it will inserta231
            //so we need to reverse from (s[0] to s[3])
            reverse(s.begin()+start, s.begin()+index);
        }
        return index; 
    }
};