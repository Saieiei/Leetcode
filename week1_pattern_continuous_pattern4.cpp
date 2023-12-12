//#include<iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cin>>n;
//    for(int r=0;r<n;r++)
//    {
//        for(int c=0;c<r+2;c++)
//        {
//            if(r==0 || r==n-1)
//            {
//                cout<<c+1;
//             
//               break;
//            }
//            else
//            {
//                if(c==0)
//                    cout<<c+1;
//                if(c==r+1)
//                    cout<<c;
//                for(int i=0;i<r;i++)
//                {
//                    cout<<" ";
//                }
//            }
//        }
//         cout<<endl;
//    }
//}

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int r=0;r<n+1;r++)
    {
        for(int c=0;c<r+1;c++)
        {
            if(r==0 || r==n)
            {
                cout<<c+1;
            }
            else
            {
                cout<<1;

                for(int i=0;i<r;i++)
                {
                    cout<<" ";
                }
                cout<<r+1;
                break;
            }
        }
        cout<<endl;
    }
}