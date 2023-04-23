/*
Creator: Mohsin Zia.
Registration Number: 2020244.
*/

#include <iostream>
#include <string.h>

using namespace std;


string Encryption(string inputText, int shift){
	
	char cipherText[BUFSIZ];
	
	int inputTextLength = inputText.length();
	
	memset(cipherText, '\0', inputTextLength+1);
		
	for(int i=0; i<inputTextLength; ++i){
		if(inputText[i] == ' '){
			cipherText[i] = ' ';
			continue;
		}					  //65					//90
		else if(inputText[i] >= 'A' && inputText[i] < 'Z' && int(inputText[i] + shift) <= 90){
			cipherText[i] = char(inputText[i]+shift);			
		}					  //97                  //122
		else if(inputText[i] >= 'a' && inputText[i] < 'z' && int(inputText[i] + shift) <= 122){
			cipherText[i] = char(inputText[i]+shift);			
		}
		else if(inputText[i] == 'Z' && shift != 0){
			cipherText[i] = char(inputText[i] - 90 + 65 + shift - 1);			
		}		
		else if(inputText[i] == 'z' && shift != 0){
			cipherText[i] = char(inputText[i] - 122 + 97 + shift - 1);			
		}
		else if(int(inputText[i] + shift) > 90 && inputText[i] >= 'A' && inputText[i] < 'Z'){
			cipherText[i] = char(inputText[i] - 90 + 65 + shift - 1);						
		}
		else if(int(inputText[i] + shift) > 122 && inputText[i] >= 'a' && inputText[i] < 'z'){
			cipherText[i] = char(inputText[i] - 122 + 97 + shift - 1);			
		}
		else{
			cipherText[i] = inputText[i];
		}		
	}	
	cout<<"\n\n\t--------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t\tCipher Text: "<<cipherText<<endl;
	
	return cipherText;
	
//	Decryption(cipherText, shift);

}


void Decryption(string cipherText, int shift){
	
	char plainText[BUFSIZ];
	
	int cipherTextLength = cipherText.length();
	
	memset(plainText, '\0', cipherTextLength+1);
		
	for(int i=0; i<cipherTextLength; ++i){
		if(cipherText[i] == ' '){
			plainText[i] = ' ';
			continue;
		}					    //65				   //90
		else if(cipherText[i] > 'A' && cipherText[i] <= 'Z' && int(cipherText[i] - shift) >= 65){
			plainText[i] = char(cipherText[i] - shift);			
		}					    //97                  //122
		else if(cipherText[i] > 'a' && cipherText[i] <= 'z' && int(cipherText[i] - shift) >= 97){
			plainText[i] = char(cipherText[i] - shift);	
		}
		else if(cipherText[i] == 'A' && shift != 0){
			plainText[i] = char(cipherText[i] + 90 - 65 - shift + 1);			
		}		
		else if(cipherText[i] == 'a' && shift != 0){
			plainText[i] = char(cipherText[i] + 122 - 97 - shift + 1);			
		}
		else if(int(cipherText[i] - shift) < 65 && cipherText[i] > 'A' && cipherText[i] <= 'Z'){
			plainText[i] = char(cipherText[i] + 90 - 65 - shift + 1);						
		}
		else if(int(cipherText[i] - shift) < 97 && cipherText[i] > 'a' && cipherText[i] <= 'z'){
			plainText[i] = char(cipherText[i] + 122 - 97 - shift + 1);			
		}
		else{
			plainText[i] = cipherText[i];
		}		
	}	
	
	cout<<endl<<"\t\t\tPlain Text: "<<plainText<<endl;
	cout<<"\t--------------------------------------------------------------------------------------------------------\n\n\n";

}


int main(){
	
	string inputText;
	string cipherText;
	int inputTextLength;
	
	cout<<endl<<endl<<"\tWelcome to the Encryption and Decryption Program by Mohsin Zia - 2020244"<<endl<<endl;
	
	while(true){
		
		cout<<"\tPlease choose the plaintext on which you have to perform the operations\n"
			  "\t1. Stay at home stay safe.\n"
			  "\t2. Enigma was a machine used for cryptography.\n"
			  "\t3. Encryption and decryption are used in cryptography.\n"
			  "\t4. Enter my own custom plain text.\n"
			  "\t5. Exit.\n\n"
			  "\tYour choice (1-5): ";
			  		
		int choice;cin>>choice;

		if(choice >=5){
			cout<<"\n\tThankyou for using my program! "<<endl;
			exit(0);
		}

		cout<<"\n\tEnter the shift(k): ";
		int shift; cin>>shift;
		shift = shift < 0 ? (shift % 26) + 26 : (shift % 26);
		
		switch(choice){
			
			case 1:
				inputText = "Stay at home stay safe.";	
				cout<<"\n\tPlain text: "<<inputText<<endl;

				cipherText = Encryption(inputText, shift);
				Decryption(cipherText, shift);

				break;
	
			case 2:
				inputText = "Enigma was a machine used for cryptography.";	
				cout<<"\n\tPlain text: "<<inputText<<endl;

				cipherText = Encryption(inputText, shift);
				Decryption(cipherText, shift);

				break;

			case 3:
				inputText = "Encryption and decryption are used in cryptography.";	
				cout<<"\n\tPlain text: "<<inputText<<endl;

				cipherText = Encryption(inputText, shift);
				Decryption(cipherText, shift);

				break;
			
			case 4:
				cout<<"\n\tEnter plain text: ";
				fflush(stdin);
				getline(cin, inputText);

				cipherText = Encryption(inputText, shift);
				Decryption(cipherText, shift);

				break;
			
			default:
				cout<<"\n\tThankyou for using my program! "<<endl;
				exit(0);
				
		}
		system("pause");
		system("cls");
	}

			
	
	return 0;
}

