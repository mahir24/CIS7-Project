/* 
 * File:   main.cpp
 * Author: Mahir Rahman & Shane Osgood
 * Created on February 13, 2018, 12:05 PM
 * Purpose: C++ Template
 */
//System Libraries
#include<bits/stdc++.h> 
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>

using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes


//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    ofstream filelog;
    int choices;
    string mssg;
    string keyy;
    
    string convert;
    //Initial Variables
    
    //Map/Process Inputs to Outputs
    cout<<"Enter message to encrypt or decrypt(MESSAGE MUST BE SINGLE STRING WITH NO SPACES OR SYMBOLS): ";
    getline(cin,mssg);    
    //Transforms lowercase letters to uppercase
    transform(mssg.begin(), mssg.end(), mssg.begin(), ::toupper); 

    
//Converts string to char
    char msg[mssg.size()+1];
    strcpy(msg, mssg.c_str());

    cout<<"Please input key for code: ";
    getline(cin,keyy);    
    //Transforms lowercase letters to uppercase
    transform(keyy.begin(), keyy.end(), keyy.begin(), ::toupper); 

    //Converts string to char
    char key[keyy.size()+1];
    strcpy(key, keyy.c_str());


    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
 
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

    
    //Generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
        
    newKey[i] = '\0';

    cout<<"Enter 1 to encrypt or 2 to decrypt: ";
    cin>>choices;
    //Encryption choice
    if(choices==1){
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';//encrypts message
    
    encryptedMsg[i] = '\0';

    printf("\nOriginal Message: %s", msg);
    printf("\nEncrypted Message: %s", encryptedMsg);

     //writes to file
    filelog.open("filelog.txt", fstream::app);
    filelog<<"\n***ENCRYPTION***";
    filelog<<"\nOriginal Message: "<<msg;
    filelog<<"\nKey: "<<key;
    filelog<<"\nNew Generated Key: "<<newKey;
    filelog<<"\nEncrypted Message: "<<encryptedMsg;
    filelog<<"\n***************************************";
    //Close File
    filelog.close();
}
    //Decryption choice
    if(choices==2){
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((msg[i] - newKey[i]) + 26) % 26) + 'A';//decrypts message
    
    decryptedMsg[i] = '\0';
    printf("\nOriginal Message: %s", msg);
    printf("\nDecrypted Message: %s", decryptedMsg);

     //writes to file
    filelog.open("filelog.txt", fstream::app);
    filelog<<"\n***DECRYPTION***";
    filelog<<"\nEncrypted Message: "<<msg;
    filelog<<"\nKey: "<<key;
    filelog<<"\nNew Generated Key: "<<newKey;
    filelog<<"\nDecrypted Message: "<<decryptedMsg;
    filelog<<"\n***************************************";
    //Close File
    filelog.close();
    }
     printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
   
    
    //Exit program!
    return 0;
}

