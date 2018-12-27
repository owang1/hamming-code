#include <iostream>
#include <string>
#include <set>
#include <bitset>
#include <algorithm>
using namespace std;

// Try to correct parity bit to match the datastring's parity bit
string correctParity(string parity, string ds){
		
	// Default result is original parity
	string result = parity;

	// Generate all possible options by flipping 1 bit	
	string temp;
	string bit;
	for(int i = 0; i < parity.length(); i++){
		temp = parity;
		bit = parity[i];

		// Flip the bit at position i
		if(bit.compare("1") == 0){
			temp = parity.substr(0,i) + "0" + parity.substr(i+1);
		}else{
			temp = parity.substr(0,i) + "1" + parity.substr(i+1);
		}

		// Check if there is a match and return
		if(temp == ds){
			result = temp;
			return result;
		}		
		
	}
	// No match found, but still return
	return result; 
	
}

string char_to_str(char ch){
	bitset<8> temp(ch);
	return temp.to_string();
}

// Converts bitarray to string
string bit_to_str(string s) {
	string str;
	string c;
	for(int i = 0; i < s.length(); i+= 8){
          bitset<8> temp(string(s.substr(i,8)));
	  c+= char(temp.to_ulong());	  

	}
	return c;
}

// convert 8 bits to 1 ascii
int bit_to_int(string s){
  bitset<8> temp(s);
  return temp.to_ulong();
}

// Check if a number is power of 2
bool pow_2(int num) {

	bool result = false;
	if ((num != 0) && ((num &(num - 1)) == 0)) {
		result = true;
	}
	return result;
}

// Check if ith least significant digit is "1"
bool least_sig(string s, int i) {
	bool result = false;
	int count = 0;		// counter to track position from the end
						// Iterate through the string s backwards
	for (int it = s.length() - 1; it >= 0; it--) {
		count++;
		if (count == i) {
			if (s.at(it) == '1') {
				// true if ith least significant digit is 1
				result = true;
				return result;
			}
			else {
				result = false;
				return result;
			}

		}
	}
	return result;
}

// XOR operation to find parity bit, given vector M of locations and string H 
// even # of 1's -> 0
// odd  # of 1's -> 1
int XOR(vector<string> M, int M_size, string H) {
	int parity;
	int count = 0;
	int pos;
	for (int i = 0; i < M_size; i++) {
		pos = bit_to_int(M[i]);
		if (H.at(pos - 1) == '1') {
			count++;
		}
	}
	// Return 0 if even, 1 if odd
	if (count % 2 == 0) {
		return parity = 0;
	}
	else {
		return parity = 1;
	}
}


// Get the parity bits of a string
string getParity(string input){
	
	int parity;
	string parityStr;
	string H;
	vector<string> B;
	// Convert input to a bitstring
	for(int i = 0; i < input.length(); i++){
		H.append(char_to_str(input[i]));
	}
	// Intersperse with parity bits
	for (int k = 0; k < H.length(); k++) {
		if (pow_2(k + 1)) {			
			H.insert(k, "p");
		}
	}
	
	// Make a bits vector with binary values of 1 to h 	
	for (int it = 1; it <= H.length(); it++) {
		B.push_back(char_to_str(it));
	}

	// Find Mi from i = 0 to the position of the last p
	int count = 0;
	vector<string> M;
	for (int m = 0; m < H.length(); m++) {
		if (H.at(m) == 'p') {		// at a parity bit
			int M_size = 0;
			count++;

			for (int n = m; n < H.length(); n++) {
				// check if least ith significant bit is 1
				if (least_sig(B.at(n), count)) {
					if (n != m) {
						// push back locations to Mi, except i itself
						M.push_back(B[n]);
						M_size++;
					}
				}
			}

			// Calculate the parity bit for current M
			parity = XOR(M, M_size, H);
			parityStr += to_string(parity);
			// clear vector M
			M.clear();
		}
	}
	return parityStr;
}

int main(int argc, char* argv[]){
	string parity;
	string dataString;
	string newParity;
	string parityMatch;
	set<string>::iterator it;
	if(argc != 3){
		cout << "Usage ./a3b 01011 ac" << endl;
		return 1;
	}
	// Take in arguments
	parity = argv[1];
	dataString = argv[2];
	newParity = getParity(dataString);
	
	// Check if parity matches newParity -> no more calculation needed
	if(parity == newParity){
		cout << parity << endl;
		cout << dataString << endl;
		return 0;
	}	

	// Try to correct the parity by 1 bit to match newParity
	parityMatch = correctParity(parity, newParity);
	if(parityMatch == newParity){
		cout << parityMatch << endl;
		cout << dataString << endl;
		return 0;
	}
  
  
	// Try to correct dataString
	string bitstring, temp, tempParity;
   
	// convert input to binary
	for(int i = 0; i < dataString.length(); i++){
		bitstring.append(char_to_str(dataString[i]));
	}
  
	for(int i = 0; i < bitstring.length(); i++){
 
		string bit = bitstring.substr(i,1);
		temp = bitstring;
		// Flip the bit at position i
		if(bit.compare("1") == 0){
			temp = bitstring.substr(0,i) + "0" + bitstring.substr(i+1);
		}else{
			temp = bitstring.substr(0,i) + "1" + bitstring.substr(i+1);
		}
		tempParity = getParity(bit_to_str(temp));
   
		// Check if there is a match and return
		if(tempParity == parity){
			cout << parity << endl;
			cout << bit_to_str(temp) << endl;  
			return 0;
		}
	} 
	cout << "Uncorrectable Error" << endl;
    return 1;
 }
       
