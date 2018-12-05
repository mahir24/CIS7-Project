#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<cstring>

using namespace std; 

int main(){
    string mssg;
    string keyy;

    cout<<"Enter message to encrypt: ";
    cin>>mssg;

    char msg[mssg.size()+1];
    strcpy(msg, mssg.c_str());

    cout<<"Please input key for code: ";
    cin>>keyy;

    char key[keyy.size()+1];
    strcpy(key, keyy.c_str());


    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
 
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

    

    
    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
 
    newKey[i] = '\0';
 
    //encryption
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
 
    encryptedMsg[i] = '\0';
 
    //decryption
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
 
    decryptedMsg[i] = '\0';
 
    printf("Original Message: %s", msg);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);
 
    return 0;
}
