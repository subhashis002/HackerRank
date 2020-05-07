#include<bits/stdc++.h>

using namespace std;

string caesarCipher(string s, int k) {
    string result;
    int temp;
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i])){
            //temp = s[i]+k;
	    temp = s[i];
            if(islower(s[i])){
//                if(temp>=123){
                     //temp = (temp % 123 ) + 97;
                     temp = (temp % 123 );
		     temp = (temp + k) % 26;
		     temp = temp + 97;
  //              }               
            }
            if(isupper(s[i])){
    //            if(temp >=91){
                    //temp = (temp % 91 ) + 65;
                    temp = (temp % 91 );
		    temp = (temp + k) % 26;
		    temp = temp + 65;
      //          }
            }
	    //cout<<temp<<endl;
	    printf("%d %c\n",temp,temp);
            result += (char)temp;
        }else{
            result += s[i];
        }
    }
    return result;
}

int main(){
	int n,k;
	string str;
	cin>>n;
	cin>>str;
	cin>>k;
	cout<<caesarCipher(str,k)<<endl;
	return 0;
}
