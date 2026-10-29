//cypherlist.hpp -- Encryption and Decryption Function File
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

namespace encr{
	void runEncrypt(char& choice);
	string caesar(const string& STR, int& SHIFT);
	string hexLock(const string& STR);
	string gridLock(const string& STR, const int shift = 0, const bool vert_orient = false); // Shift and orient funtcionality currently disabled
	
	void runEncrypt(char& choice){
		//Variables:
		string str;
		int shift;
		
		//Logic:
		cin.ignore(); //Empty out input
		cout << "Enter string to encode: "; getline(cin, str); cout << endl;
		
		switch (choice) { 
			case 'C':
				shift = 5;
				cout << "Enter shift distance (standard = 5): "; cin >> shift; cout << endl;
				cout << "Encrypted string: " << caesar(str, shift) << endl;
				break;
			case 'H':
				cout << "Encrypted string: " << hexLock(str) << endl;
				break;
			case 'G':
				cout << "Encrypted string: " << gridLock(str) << endl;
				break;
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
		
		for (int i = 0; i < STR.length(); i++){
			if (i + SHIFT >= 90){//certain edge cases may slip through, this is to prevent them from crashing the program
				new_STR += shift_set[distance(begin(shift_set), find(begin(shift_set), end(shift_set), STR[i])) + SHIFT - 90];
			}
			else {
				new_STR += shift_set[distance(begin(shift_set), find(begin(shift_set), end(shift_set), STR[i])) + SHIFT];
			}// shift_set[char_index_finder(shift_set_start, iterator(shift_set_start, shift_set_end, current_STR_char_index)) + SHIFT] 
		}
		
		return new_STR;
	}
	
	string hexLock(const string& STR){
		//Variables:
		stringstream new_STR;
		
		//Logic:
		for (int i = 0; i < STR.length(); i++){
			new_STR << hex << setw(2) << setfill('0') << static_cast<int>(STR[i]);
		}// new_STR << hex conversion << witdh formatting << blanks as 0 << explicit converstion to int (current character)
		
		return new_STR.str();
	}

	string gridLock(const string& STR, const int shift, const bool vert_orient){
		//Variables:
		char row[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
		char col[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
		string grid_code[9][9];
		char grid_plain[9][9] = {
			{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'}, {'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S'},
			{'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b'}, {'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'}, 
			{'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'}, {'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3'}, 
			{'4', '5', '6', '7', '8', '9', '0', ',', '.'}, {'!', '@', '#', '$', '%', '^', '&', '*', '('}, 
			{')', ';', ':', '\'', '\"', '/', '\\', '?', ' '}};
		map<char, string> grid_final;
		string new_STR;

		//Logic:
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				grid_code[i][j] = string(1, row[i]) + col[j]; //Assigning the value of each grid square
			}
		}
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				grid_final[grid_plain[i][j]] = grid_code[i][j]; //assigning key-value pairs within map grid_final
			}
		}

		for (int i = 0; i < STR.length(); i++){
			new_STR += grid_final[STR[i]]; //encoding
		}

		return new_STR;
	}
}

namespace decr{
	void runDecrypt(char& choice);
	string caesar(const string& STR, int& SHIFT);
	string hexKey(const string& STR);
	string gridKey(const string& STR, const int shift = 0, const bool vert_orient = false); //Shift and Orient functionality currently disabled
	
	void runDecrypt(char& choice){
		//Variables:
		string str;
		int shift;
		
		//Logic:
		cin.ignore();
		cout << "Enter string to decode: "; getline(cin, str); cout << endl;
		
		switch (choice) {
			case 'C':
				shift = 5;
				cout << "Enter shift distance (standard = 5): "; cin >> shift; cout << endl;
				cout << "Decrypted string: " << caesar(str, shift) << endl;
				break;
			case 'H':
				cout << "Decrypted string: " << hexKey(str) << endl;
				break;
			case 'G':
				cout << "Decrypted string: " << gridKey(str) << endl;
				break;
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
		
		for (int i = 0; i < STR.length(); i++){
			if (i + SHIFT >= 90){//certain edge cases may slip through, this is to prevent them from crashing the program
				new_STR += shift_set[distance(begin(shift_set), find(begin(shift_set), end(shift_set), STR[i])) - SHIFT + 90];
			}
			else {
				new_STR += shift_set[distance(begin(shift_set), find(begin(shift_set), end(shift_set), STR[i])) - SHIFT];
			}// shift_set[char_index_finder(shift_set_start, iterator(shift_set_start, shift_set_end, current_STR_char_index)) + SHIFT] 
		}
		
		return new_STR;
	}
	
	string hexKey(const string& STR){
		//Variables:
		string new_STR;
		
		//Logic:
		for (int i = 0; i < STR.length(); i += 2){
			new_STR += static_cast<char>(stoi(STR.substr(i, 2), nullptr, 16));
		}// new_STR += explicit type conversion to char (int interpretation (substring, nullptr -- v imp., numeral base))
		
		return new_STR;
	}
	
	string gridKey(const string& STR, const int shift, const bool vert_orient){
		//Variables:
		char row[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
		char col[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
		string grid_code[9][9];
		char grid_plain[9][9] = {
			{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'}, {'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S'},
			{'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b'}, {'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'}, 
			{'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'}, {'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3'}, 
			{'4', '5', '6', '7', '8', '9', '0', ',', '.'}, {'!', '@', '#', '$', '%', '^', '&', '*', '('}, 
			{')', ';', ':', '\'', '\"', '/', '\\', '?', ' '}};
		map<string, char> grid_final;
		string new_STR;
		
		//Logic:
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				grid_code[i][j] = string(1, row[i]) + col[j]; //Assigning the value of each grid square
			}
		}
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				grid_final[grid_code[i][j]] = grid_plain[i][j]; // key-value pairs, reversed for decryption
			}
		}
		
		for (int i = 0; i < STR.length(); i += 2){
			new_STR += grid_final[STR.substr(i, 2)]; // substring instead of index, since the map is reversed and 2 chars = 1 char
		}
		
		return new_STR;
	}
}