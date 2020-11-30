#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

// Function to convert char to bitarray string
string char_to_str(char ch){
  bitset<8> temp(ch);
    return temp.to_string();
}

// Converts bits to int
int bit_to_int(string s){
  bitset<8> temp(s);
    return temp.to_ulong();		
}

// Check if a number is power of 2
bool pow_2(int num){
	
  bool result = false;
  if((num != 0) && ((num &(num-1)) == 0)){
    result = true;
  }
    return result;
}

// Check if ith least significant digit is "1"
bool least_sig(string s, int i){
  bool result = false;
  int count = 0;		// counter to track position from the end

  // Iterate through the string s backwards
  for(int it = s.length() - 1; it >= 0; it--){
    count++;
  if(count == i){
    if(s.at(it) == '1'){

    // true if ith least significant digit is 1
      result = true;
      return result;
    }else{
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
int XOR(vector<string> M, int M_size, string H){
  int parity;
  int count = 0;
  int pos;

  for(int i = 0; i < M_size; i++){
    pos = bit_to_int(M[i]);

  if(H.at(pos-1) == '1'){
    count++;
		}
  }

  // Return 0 if even, 1 if odd
  if(count % 2 == 0){
    return parity = 0;
  }else{
    return parity = 1;
  }
}

int main(int argc, char** argv){

  int parity;
  string input;			// ASCII input data string
  string H;			// binary bitstring representation
  vector<string> B;
	
  if(argc != 2){
    cout << "Usage ./a3a ab" << endl;
    return 1;
  }
	
  // First argument is the input string
	
  input = argv[1];
  
  // Convert input to a bitstring
  for(int i = 0; i < input.length(); i++){
  H += char_to_str(input[i]);
  }
	
  // Intersperse with parity bits so that the ith parity bit pi
  // is followed by exactly (2^(i-1))-1 data bits
		
  for(int k = 0; k < H.length(); k++){
    if(pow_2(k+1)){
      H.insert(k, "p");
    }			
  }
		
  // Make a bits vector with binary values of 1 to H 	
  for(int it = 1; it <= H.length(); it++){
    B.push_back(char_to_str(it));
  }	

  // Find Mi from i = 0 to the position of the last p
  int count = 0;
  vector<string> M;

  for(int m = 0; m < H.length(); m++){

    if(H.at(m) == 'p'){		// at a parity bit

      int M_size = 0;
      count++;      
      for(int n = m; n < H.length(); n++){
      // Check if least ith significant bit is 1
        if(least_sig(B.at(n), count)){
          if(n != m){		
            M.push_back(B[n]);
              M_size++;
          }	
        }	
			
	// Calculate the parity bit for current M
	}
        parity = XOR(M,M_size, H);
	cout << parity;
	M.clear();
      }
    }
   
    cout << endl;		
	
    return 0;
}
