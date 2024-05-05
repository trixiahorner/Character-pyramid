

/*********************************************************************************************
Write a C++ program that displays a Letter Pyramid from a user-provided std::string.
If the user enters 'ABCDEFG', then your program should display:

      A                                                                                                                
     ABA                                                                                                               
    ABCBA                                                                                                              
   ABCDCBA                                                                                                             
  ABCDEDCBA                                                                                                            
 ABCDEFEDCBA                                                                                                           
ABCDEFGFEDCBA 
*************************************************************************************************/




#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string user_string{};
	cout << "Enter a string: ";
	getline(cin, user_string);
	
	//remove whitespace from string
	string pyramid{};
	for (auto c : user_string){
		if(c != ' ')
			pyramid += c;
	}
	
	//loop for each letter in the string 
	int counter{0};
	for(auto char_from_user : pyramid){
		
		//Determine how many blank spaces must be displayed before the current row and display them
		int num_spaces = pyramid.length() - counter;
		while (num_spaces > 0){
			cout << " ";
			--num_spaces; 
		}
		
		//Determine how many letters must be displayed before the current character and display them
		for(int i{0}; i < counter; ++i){
			cout << pyramid.at(i);
		}
		
		//print current character
		cout << char_from_user;	
		
		//print remaining characters in reverse order
		for(int i{counter-1}; i >= 0; --i){
			cout << pyramid.at(i);
		}
		
		//complete row
		cout << "\n";
		counter++;
	}	
	return 0;
}