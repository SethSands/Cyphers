//cypherlist.hpp -- Encryption and Decryption Function File
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

namespace encr{
	void runEncrypt(char& choice);
	string caesar(const string& STR, int SHIFT);
	
	void runEncrypt(char& choice){
		//Variables:
		string str;
		
		//Logic:
		cout << "Enter string to encode: "; cin >> str; cout << endl;
		
		switch (choice) { 
			case 'C':{
				int shift = 5;
				cout << "Enter shift distance (standard = 5): "; cin >> shift; cout << endl;
				cout << "Encrypted string: " << caesar(str, shift) << endl;
				break;
			}//IMPORTANT NOTE: the brackets introduce a block scope to keep cross initialisation errors from popping up (int shift = 5)
			case 'H':{
				cout << "Encrypted string: " << hexlock(str) << endl;
				break;
			}
			default:
				cout << "No valid option has been selected. Aborting..." << endl;
				break;
		}
	}
	
	string caesar(const string& STR, int SHIFT){
		//Variables:
		string new_STR;
		char shift_set[90] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
		's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', '?', '!', ',', '@', '#',
		'$', '%', '^', '&', '*', '(', ')', '[', ']', '{', '}', '/', ';', ':', '\'', '\"', '\\', '-', '_', '+', '=', ' '};
		
		//Logic:
		if (SHIFT >= 90){
			SHIFT -= 90; //Ensure that shift remains in the string bounds of shift_set
		}
		
		for (int i = 0; i <= STR.length(); i++){
			if (i + SHIFT >= 90){//certain edge cases may slip through, this is to prevent them from crashing the program
				new_STR += shift_set[distance(begin(shift_set), find(begin(shift_set), end(shift_set), STR[i])) + SHIFT - 90];
			}
			else {
				new_STR += shift_set[distance(begin(shift_set), find(begin(shift_set), end(shift_set), STR[i])) + SHIFT];
			}// shift_set[char_index_finder(shift_set_start, iterator(shift_set_start, shift_set_end, current_STR_char_index)) + SHIFT] 
		}
		
		return new_STR;
	}
	
	string hexlock(string& STR){
		return "B16"; //Placeholder return
	}
}

namespace decr{
	void runDecrypt(char& choice);
	string caesar(const string& STR, int& SHIFT);
	
	void runDecrypt(char& choice){
		//Variables:
		string str;
		
		//Logic:
		cout << "Enter string to decode: "; cin >> str; cout << endl;
		
		switch (choice) {
			case 'C':{
				int shift = 5;
				cout << "Enter shift distance (standard = 5): "; cin >> shift; cout << endl;
				cout << "Decrypted string: " << caesar(str, shift) << endl;
				break;
			}
			case 'H':{
				cout << "Decrypted string: " << hexlock(str) << endl;
				break;
			}
			default:
				cout << "No valid option has been selected. Aborting..." << endl;
				break;
		}
	}
	
	string caesar(const string& STR, int& SHIFT){
		//Variables:
		string new_STR;
		char shift_set[90] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
		's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', '?', '!', ',', '@', '#',
		'$', '%', '^', '&', '*', '(', ')', '[', ']', '{', '}', '/', ';', ':', '\'', '\"', '\\', '-', '_', '+', '=', ' '};
		
		//Logic:
		if (SHIFT >= 90){
			SHIFT -= 90; //Ensure that shift remains in the string bounds of shift_set
		}
		
		for (int i = 0; i <= STR.length(); i++){
			if (i + SHIFT >= 90){//certain edge cases may slip through, this is to prevent them from crashing the program
				new_STR += shift_set[distance(begin(shift_set), find(begin(shift_set), end(shift_set), STR[i])) - SHIFT + 90];
			}
			else {
				new_STR += shift_set[distance(begin(shift_set), find(begin(shift_set), end(shift_set), STR[i])) - SHIFT];
			}// shift_set[char_index_finder(shift_set_start, iterator(shift_set_start, shift_set_end, current_STR_char_index)) + SHIFT] 
		}
		
		return new_STR;
	}
	
	string hexkey(){
		return "B16 -> 0"; //Placeholder return
	}
}