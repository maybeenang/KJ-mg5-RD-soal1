#include <iostream>
#include <string>
using namespace std;

// ABCDEFGHIJKLMNOPQRSTUVWXYZ
// ABCDEFGHIJKLMNOPQRSTUVWXYZ

// menggeser string alfabet dengan key ke kanan
void encrypt(string &plaintext, int key){
    for (int i = 0; i < plaintext.length(); i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            plaintext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            plaintext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        }
    }
}

// menggeser string alfabet dengan key ke kiri
void decrypt(string &plaintext, int key){
    for (int i = 0; i < plaintext.length(); i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            int value = plaintext[i] - 'a';
            value = (value - key) % 26;
            if (value < 0)
            {
                value = value + 26;
            }
            plaintext[i] = value + 'a';
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            int value = plaintext[i] - 'A';
            value = (value - key) % 26;
            if (value < 0)
            {
                value = value + 26;
            }
            plaintext[i] = value + 'A';
        }
    }
}

int main()
{
    string plaintext;
    int key;
    string kode;
    cin >> kode;
    cin >> key;
    cin.ignore();
    getline(cin, plaintext);
    if (kode == "encrypt")
    {
        encrypt(plaintext, key);
        cout << plaintext << endl;
    }
    else if (kode == "decrypt")
    {
        decrypt(plaintext, key);
        cout << plaintext << endl;
    }

    return 0;
}
