#include <iostream>
#include <math.h>
#include<cstring>
#include<algorithm>
#include<stdbool.h>
#include<fstream>


using namespace std;
string vigenere(string text,string key,bool encdec);

int main()
{
    char x;
    int choice;
    string plaintext;
    string  ciphertext;
    string  key;

do{
   cout<<"Welcome to the encryption decryption application"<<endl;
   cout<<"Please choose any of the options below"<<endl;
   cout<<"1.Encryption"<<endl;
   cout<<"2.Decryption"<<endl;
   cout<<"3.Exit"<<endl;

   cout<<"Enter your choice"<<endl;
   cin>>choice;


   if (choice==1)
   {
       cout<<"Please enter the plaintext"<<endl;
       getline(cin>>ws,plaintext);
       cout<<"Please enter the key"<<endl;
       getline(cin>>ws,key);
        for(int i=0;i<=key.length();i++)
       {
           if(key[i]>='a'&& key[i]<='z')
            key[i]=key[i]-32;
       }
       for(int i=0;i<=plaintext.length();i++)
       {
           if(plaintext[i]>='a'&& plaintext[i]<='z')
            plaintext[i]=plaintext[i]-32;
       }

       ciphertext=vigenere(plaintext,key,0);
       cout<<"Cipher Text:"<<ciphertext<<endl;
       cout<<"If you want to repeat,then press Y/y and any other key to exit"<<endl;
       cin>>x;


   }
   if(choice==2)
    {cout<<"Please enter the ciphertext"<<endl;
      getline(cin>>ws,plaintext);
       cout<<"Please enter the key"<<endl;
       getline(cin>>ws,key);

        for(int i=0;i<=plaintext.length();i++)
       {
           if(plaintext[i]>='a'&& plaintext[i]<='z')
            plaintext[i]=plaintext[i]-32;
       }
        for(int i=0;i<=key.length();i++)
       {
           if(key[i]>='a'&& key[i]<='z')
            key[i]=key[i]-32;
       }
       ciphertext=vigenere(plaintext,key,1);
       cout<<"Plain Text:"<<ciphertext<<endl;

       cout<<"If you want to repeat,then press Y/y and any other key to exit"<<endl;
       cin>>x;


      }


       if(choice==3)
       {
          x='n';
          break;}
        if(choice!=1 && choice!=2 &&choice!=3)
        {       cout<<"Wrong input";
            break;
        }

}while(x=='y'||x=='Y');



}
string vigenere(string text,string key,bool encdec)
{
    string newkey=key,newtext;
    while(newkey.length()<text.length())
    {
        newkey=newkey+key;
    }
    if(encdec==0)
    {
        for(int i=0;i<text.length();i++)
        {

            newtext+=(text[i]+newkey[i])%26+65;

        }
    }
    else{
    for(int i=0;i<text.length();i++)
        {
            newtext+=(text[i]-newkey[i]+26)%26+65;
        }
    }
   return newtext;
}
/*whitespace ascii =20*/
