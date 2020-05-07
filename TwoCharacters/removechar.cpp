#include<bits/stdc++.h>
using namespace std;

int main(){
   string str("(555) 555-5555");

   char chars[] = "()-";

   for (unsigned int i = 0; i < strlen(chars); ++i)
   {
      // you need include <algorithm> to use general algorithms like std::remove()
      str.erase (std::remove(str.begin(), str.end(), chars[i]), str.end());
   }

   // output: 555 5555555
   cout << str << endl;
	return 0;
}
