/* 
 * File:   main.cpp
 * Author: Mahir Rahman & Shane Osgood
 * Created on November 2018
 * Purpose: Cis 7 Vigenère Cipher.
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

    string mssg;
    string keyy;
    
    string convert;
    //Initial Variables
    
    //Map/Process Inputs to Outputs
    cout<<"Enter message to encrypt(MESSAGE MUST BE SINGLE STRING WITH NO SPACES OR SYMBOLS): ";
    getline(cin,mssg);    
    //Transforms lowercase letters to uppercase
    transform(mssg.begin(), mssg.end(), mssg.begin(), ::toupper); 

    
//Converts string to char
    char msg[mssg.size()+1];
    strcpy(msg, mssg.c_str());

    cout<<"Please input key for code (MUST BE SINGLE STRING WITH NO SPACES OR SYMBOLS): ";
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
 
    //Encryption
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
    
    encryptedMsg[i] = '\0';
 
    //Decryption
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
    
    decryptedMsg[i] = '\0';
    
    //Display Outputs
    printf("\nOriginal Message: %s", msg);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);
    
    //Open File
    filelog.open("filelog.txt", fstream::app);
    filelog<<"\nOriginal Message: "<<msg;
    filelog<<"\nKey: "<<key;
    filelog<<"\nNew Generated Key: "<<newKey;
    filelog<<"\nEncrypted Message: "<<encryptedMsg;
    filelog<<"\nDecrypted Message: "<<decryptedMsg;
    filelog<<"\n***************************************";
    //Close File
    filelog.close();
    
    //Exit program!
    return 0;
}

