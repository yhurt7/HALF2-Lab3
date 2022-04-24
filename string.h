#pragma once
#include <iostream>

class String
{
protected:
  char* string;
  int length;
public:
  String();
  String(int length, char c);
  String(const String& a);
  String(const char* s);
  ~String();
  
  int GetLength();
  char* GetString();
  void SetLength(int _length);
  void SetString(char* _string);

  String operator + (String &other);
  String operator = (const String &other);
  bool operator == (String &other);
  bool operator < (const String &other);
  bool operator > (const String &other);
  char operator [] (int i);
  friend std::ostream& operator << (std::ostream& ostr, const String& other);
  friend std::istream& operator >> (std::istream& istr, String& other);

  int FWord(const char* _str);
  int FSymb(char c);

  void KStr(int k);
  void IndsWord(const char* _str);
  void CountLetter();
  char MostCommonSymb();
  char* WithoutRepeat();
  
};
