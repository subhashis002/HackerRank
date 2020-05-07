#include<bits/stdc++.h>

using namespace std;

string caesarCipher(string s, int k) {
	char o;
	for(auto &c: s){
		if(isalpha(c)){
			o = islower(c)? 'a': 'A';
			c = o + (c-o + k)%26;
		}
	}
	return s;
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
