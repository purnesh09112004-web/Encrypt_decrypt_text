#include<iostream>
#include<string>
#include<cctype>

using namespace std;

string encrypt(string text, int shift){
   string result = " ";
   
   int letterShift = (shift % 26 + 26) %26;
   int digitShift = (shift %10 + 10) %10;
   
   for(char c : text){
      if(isalpha(c)){
        char base = isupper(c) ? 'A' : 'a';
        result += (c - base + letterShift) %26 + base;
      }
      else if (isdigit(c)) {
            result += (c - '0' + digitShift) % 10 + '0';
        } 
      else {
            result += c;
      }
   }
   return result;
}
string decrypt(string text, int shift){
   string result = " ";
   
   int letterShift = (26 - (shift % 26 )) %26;
   int digitShift = (10 - (shift % 10 )) %10;
   
   for(char c : text){
      if(isalpha(c)){
        char base = isupper(c) ? 'A' : 'a';
        result += (c - base + letterShift) %26 + base;
      }
      else if (isdigit(c)) {
            result += (c - '0' + digitShift + 10) % 10 + '0';
        } 
      else {
            result += c;
      }
   }
   return result;
}

int main() {
    string message;
    cout << "Enter your Plain text : ";
    getline(cin, message);
    
    string encrypted = encrypt(message, 4);

    cout << "Encrypted: " << encrypted << endl; // clean and simple

    string message1;
    cout << "Enter your encrypted text : ";
    getline(cin, message1);
    
    string decrypted = decrypt(message1,4);
    cout << "Decrypted : " << decrypted ;
    return 0;
}