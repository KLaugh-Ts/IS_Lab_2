#include <iostream>
#include <string>
using namespace std;

const int n = 26; // длина алфавита

// создание ключа правильной длины из ключ-слова
string make_key (string str, string key) {
    string key_ = key;
    int i = str.length() - key.length() - 1;
    for (i; i<str.length(); i++)
        key_ += key[i%key.length()];
    return key_;
}

// функция шифрования
// сложение кодов ASCII символов исходного текста и ключа по модулю N
// и перевод обратно в char с + int('A')
string coding (string str, string key) {
    string new_str = "";
    for (int j = 0; j < str.length(); j++)
        new_str += static_cast<char>((int(str[j]) + int(key[j])) % n + int('A'));
    return new_str;
}

// функция расшифрования
// разность кодов ASCII символов зашифрованного текста и ключа плюс N по модулю N
// и перевод обратно в char с + int('A')
string decoding (string str, string key) {
    string source_str = "";
    for (int j=0; j< str.length(); j++)
        source_str += static_cast<char>((int(str[j] + n - int(key[j]))) % n + int('A'));
    return source_str;
}


int main() {
    string str = "SHIFROVANIE"; // открытый текст
    string key = "BOARD";
    key = make_key(str, key); // создание ключа правильной длины

    string new_str = coding(str, key); // шифрование
    cout << new_str << "\n\n";

    string source_text = decoding(new_str, key); // декодирование
    cout << source_text << "\n";

    return 0;
}