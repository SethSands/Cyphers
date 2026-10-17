//main.cpp -- Main Executable File for Cypher
#include <iostream>
#include <string>
#include "cypherlist.hpp"
using namespace std;

int main(){
	//Variables:
	char enc_dec_choice;
	char enc_method_choice;
	char dec_method_choice;
	
	//Logic:
	cout << "Welcome to Cypher! (v3, C++ Edition)" << endl;
	do {
		cout << "Are we Encrypting (E) or Decrypting (D)?: "; cin >> enc_dec_choice; cout << endl;
		if (enc_dec_choice == 'E'){
			cout << "Available ciphers: Ceasar (C) ; Hexadecimal (H)" << endl;
			cout << "Choose method of encryption: "; cin >> enc_method_choice; cout << endl;
			encr::runEncrypt(enc_method_choice);
		}
		else if (enc_dec_choice == 'D'){
			cout << "Available ciphers: Ceasar (C) ; Hexadecimal (H)" << endl;
			cout << "Choose method of decryption: "; cin >> dec_method_choice; cout << endl;
			decr::runDecrypt(dec_method_choice);
		}
		else{
			cout << "Invalid entry made. Please choose from the above given options, entering 'E' or 'D', or 'Q' to quit. Remember that the entry is case sensitive." << endl;
		}
	}	while (enc_dec_choice != 'Q')
	
	return 0;
}