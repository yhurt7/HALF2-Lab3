#include "string.h"
#include <string.h>
#include <iostream>

String::String()
{
  length = 0;
  string = new char[1];
  string[0] = '\0';
}

String::String(int _length, char c)
{
  length = _length;
  string = new char[length+1];

  for (int i = 0; i < _length; i++)
    string[i] = c;

  string[length] = '\0';
}

String::String(const String & a)
{
  length = a.length;
  string = new char[length + 1];

  for (int i = 0; i < length; i++)
    string[i] = a.string[i];
  string[length] = '\0';
}

String::String(const char * s)
{
  if (s == nullptr)
  {
    length = 0;
    string = new char[1];
    string[0] = '\0';
  }
  else
  {
    length = strlen(s);
    string = new char[length + 1];

    for (int i = 0; i < length; i++)
      string[i] = s[i];
    string[length] = '\0';
  }
}

String::~String()
{
  delete[] string;
}

int String::GetLength()
{
  return length;
}

char* String::GetString()
{
  char* a = new char[length];
  for (int i = 0; i <= length; i++)
    a[i] = string[i];
  return a;
}

void String::SetLength(int _length)
{
  length = _length;
}

void String::SetString(char *_string)
{
  int TemporaryLength = 0;
  if (_string == nullptr) throw "Error in SetString func. Your string = nullptr";

  if (string != nullptr) delete[] string;
  string = new char[strlen(_string) + 1];
  string[strlen(_string)] = '\0';

  for (int q = 0; q < strlen(_string); q++)
  {
    string[q] = _string[q];
  }

  length = (int)strlen(_string);
}

String String::operator+(String & other)
{
  int tlen = length + other.length;
  String total(tlen, 0);
  
  for (int i = 0; i < length; i++)
    total.string[i] = string[i];

  for (int i = length; i < tlen; i++)
    total.string[i] = other.string[i - length];

  string[tlen] = '\0';
  return total;
}

String String::operator=(const String & other)
{
  if (string != nullptr)
  {
    delete[] string;
    string = nullptr;
  }

  length = other.length;
  string = new char[length + 1];

  for (int i = 0; i < length; i++)
    string[i] = other.string[i];

  string[length] = '\0';

  return *this;
}

bool String::operator == (String & other)
{
  if (length == other.length)
  {
    for (int i = 0; i < length; i++)
      if (string[i] == other.string[i])
      {
      }
      else
        return false;
    
    return true;
  }
  return false;
}

bool String::operator<(const String & other)
{
  if (length < other.length)
  {
    return true;
  }
  else
    if (length > other.length)
    {
      return false;
    }
    else
    {
      for (int i = 0; i < length; i++)
      {
        if (string[i] < other.string[i])
        {
          return true;
        }
        else
          if (string[i] > other.string[i])
            return false;
      }
    }
  return false;
}

bool String::operator>(const String & other)
{
  if (length > other.length)
  {
    return true;
  }
  else
    if (length < other.length)
    {
      return false;
    }
    else
    {
      for (int i = 0; i < length; i++)
      {
        if (string[i] > other.string[i])
        {
          return true;
        }
        else
          if (string[i] < other.string[i])
            return false;
      }
    }
  return false;
}

char String::operator[](int i)
{
  if ((i >= 0) && (i <= length))
  {
    return string[i];
  }
  else
  {
    throw ("Error");
  }
}

int String::FWord(const char* _str)
{
  int lp = strlen(_str);
  bool f;

  for (int i = 0; i <= length - lp; i++)
  {
    f = true;

    if (string[i] == _str[0])
    {
      for (int j = 1; j < lp; j++)
      {
        if (string[i + j] == _str[j])
        {
          f = true;
        }
        else
        {
          f = false;
          break;
        }
      }
    
      if (f == true)
      {
        return i + 1;
      }
    }
  }

  return -1;
}

int String::FSymb(char c)
{
  for (int i = 0; i < length; i++)
    if (string[i] == c)
      return i;

  return -1;
}

void String::KStr(int k)
{
  for (int i = 0; i < k; i++)
  {
    std::cout << string << "\n";
  }
}

void String::IndsWord(const char* _str)
{
  int lp = strlen(_str);
  bool f;
  bool f1 = false;
  for (int i = 0; i <= length - lp; i++)
  {
    f = true;

    if (string[i] == _str[0])
    {
      for (int j = 1; j < lp; j++)
      {
        if (string[i + j] == _str[j])
        {
          f = true;
        }
        else
        {
          f = false;
          break;
        }
      }

      if (f == true)
      {
        std::cout<< i + 1 << " ";
        f1 = true;
      }
    }
  }
  if (f1 == false)
    std::cout << "No result";
}

void String::CountLetter()
{
  char* a = new char[length];
  int count[512];
  bool c;
  int indx = 0;

  a[length] = '\0';

  for (int i = 0; i < length; i++)
  {
    a[i] = '0';
    count[i] = 0;
  }

  for (int i = 0; i < length; i++)
  {
    c = false;

    for (int j = 0; j < length; j++)
    {
      if (string[i] == a[j])
      {
        c = true;
        count[j] += 1;
      }
    }

    if (c == false)
    {
      a[indx] = string[i];
      count[indx] = 1;
      indx += 1;
    }

  }

  a[indx] = '\0';
  
  for (int i = 0; i < indx; i++)
  {
    std::cout << a[i] << " - " << count[i] << "\t";
  }

}

char String::MostCommonSymb()
{
  int a[512];
  char c = '0';
  for (int i = 0; i < 512; i++)
    a[i] = 0;
  for (int i = 0; i < length; i++)
    a[char(string[i])]++;
  for (int i = 0; i < 512; i++)
    if (a[i] > a[int(char(c))])
      c = char(i);
  return char(c);
}

char * String::WithoutRepeat()
{
  char* a = new char[length];
  int count[512];
  bool c;
  int indx = 0;

  a[length] = '\0';

  for (int i = 0; i < length; i++)
  {
    a[i] = '0';
    count[i] = 0;
  }

  for (int i = 0; i < length; i++)
  {
    c = false;

    for (int j = 0; j < length; j++)
    {
      if (string[i] == a[j])
      {
        c = true;
        count[j] += 1;
      }
    }

    if (c == false)
    {
      a[indx] = string[i];
      count[i] = 1;
      indx += 1;
    }

  }

  a[indx] = '\0';
  return a;
}

std::ostream & operator<<(std::ostream & ostr, const String & other)
{
  other.string[other.length] = '\0';
  ostr << other.string;
  return ostr;
}

std::istream & operator>>(std::istream & istr, String & other)
{
  other.string = nullptr;

  char* tot = new char[1024];
  istr >> tot;
  
  String a(strlen(tot), ' ');

  for (int i = 0; i < strlen(tot); i++)
    a.string[i] = tot[i];
  
  other = a;

  return istr;
}
