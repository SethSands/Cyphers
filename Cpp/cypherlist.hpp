//cypherlist.hpp -- Encryption and Decryption Function File
#include <iostream>
#include <string>
using namespace std;

namespace encr{
	void runEncrypt(char& choice){
		//Variables:
		string str;
		
		//Logic:
		cout << "Enter string to encode: "; cin >> str; cout << endl;
		
		switch (choice) {
			case 'C':
				int shift = 5;
				cout << "Enter shift distance (standard = 5): "; cin >> shift; cout << endl;
				cout << "Encrypted string: " << caesar(str, shift) << endl;
				break;
			case 'H':
				cout << "Encrypted string: " << hexlock(str) << endl;
				break;
			default:
				cout << "No valid option has been selected. Aborting..." << endl;
				break;
		}
	}
	
	string caesar(string& STR, int& SHIFT){
		return "Rome"; //Placeholder return
	}
	
	string hexlock(string& STR){
		return "B16"; //Placeholder return
	}
}

namespace decr{
	void runDecrypt(char& choice){
		//Variables:
		string str;
		
		//Logic:
		cout << "Enter string to decode: "; cin >> str; cout << endl;
		
		switch (choice) {
			case 'C':
				int shift = 5;
				cout << "Enter shift distance (standard = 5): "; cin >> shift; cout << endl;
				cout << "Decrypted string: " << caesar(str, shift) << endl;
				break;
			case 'H':
				cout << "Decrypted string: " << hexlock(str) << endl;
				break;
			default:
				cout << "No valid option has been selected. Aborting..." << endl;
				break;
		}
	}
	
	string caesar(string& STR){
		return "Italy"; //Placeholder return
	}
	
	string hexkey(){
		return "B16 -> 0"; //Placeholder return
	}
}