#include <iostream>
using namespace std;
int main() {
int n;
for (n = 5; n >= 0; n--){
cout << n;
if(n==3) break;
}
return 0;
}