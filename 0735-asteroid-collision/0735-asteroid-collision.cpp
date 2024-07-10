class Solution {
public:
//week 11
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //we will solve this using stack

        stack<int> st;
        //as we can see that +nums do not caosue problems, the problem is with -nums only
        //so if the num is + then simply push
        //if the num is - then we have to check, if its able to destroy many asteroids, incase they r + and less than -num
        //if the num is - then we have to check, if its able to destroy the asteroid of its size if its + num
        //else its of no use as the + asteroid in the stack will destroy the - num asteroid if +num asteroid > -num asteroid
        
        for(int asteroid : asteroids)
        {
            bool destroy = false; //innitially nothing is destroyed
            if(asteroid > 0) st.push(asteroid); //so if the num is + then simply push
            else //if the asteroid is -
            {
                if(st.empty()) st.push(asteroid); //incase nothing is there is the stack, then simply push the - asteroid
                else if(!st.empty() && st.top() < 0) st.push(asteroid); //if both the asterod r moving in the right direction (-), nothign can be done, hence simply push it
                else 
                {
                    //collisions can keep on taking place
                    while(!st.empty() && st.top() > 0) //if the stack is not empty and the top of th estack is a + num
                    {
                        if(abs(asteroid) == st.top()) //then it will get destroyed and also destroy the asteroid coming to it
                        {
                            destroy = true;
                            st.pop();
                            break;
                        }
                        else if(abs(asteroid) > st.top()) st.pop(); //then it will keep on destoying asteroids which r less that abs(-num) 
                        
                        else //the + asteroid is > than the - asteroid, hence - asteroid will get destroyed, end of the story
                        {
                            destroy = true;
                            break;
                        }

                    }
                    //if the - asteroids keeps on destring all the + asteroids then, the - asteroid can be pusshed in the stack
                    if(!destroy) st.push(asteroid);
                } 
            }
        }
        //now the asteroids r the stack, we have to pop them and put them in reverse order
         vector<int> ans(st.size());
        //for(int i=0; i<st.size(); i++)
        //{
        //    ans.push_back(st.top()); st.pop();
        //}
        //reverse(ans.begin(), ans.end());
        //u can also do like this to save time
        for(int i=st.size()-1; i>=0; i--)
        {
            ans[i] = st.top(); st.pop();
        }
        return ans;
    }
};