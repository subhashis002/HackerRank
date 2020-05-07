#include<bits/stdc++.h>

using namespace std;

int minimumNumber(int n, string password) {
	// Return the minimum number of characters to make the password strong
	string	numbers = "0123456789";
	string lower_case = "abcdefghijklmnopqrstuvwxyz";
	string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string special_characters = "!@#$%^&*()-+";
	bool numbers_flag = false;
	bool lower_case_flag = false;
	bool upper_case_flag = false;
	bool special_characters_flag = false;

	int password_length = 6;
	int specialCharCount = 4;
	for(int i = 0 ;i<n;i++){
		if(numbers.find(password[i]) != -1 && (!numbers_flag)) {specialCharCount--; numbers_flag = true; }
		if(lower_case.find(password[i]) != -1 && (!lower_case_flag)) {specialCharCount--; lower_case_flag = true;}
		if(upper_case.find(password[i]) != -1 && (!upper_case_flag)) {specialCharCount--; upper_case_flag = true; }
		if(special_characters.find(password[i]) != -1 &&(!special_characters_flag)) {specialCharCount--; special_characters_flag = true; }	
	}

	if(n >= 6){
		return specialCharCount;
	}
	if(n < 6){
		return std::max(specialCharCount,password_length-n);
	}
}

int main(){
	int n;
	string password;
	cin>>n;
	cin>>password;
	cout<<minimumNumber(n,password);
	return 0;
}
