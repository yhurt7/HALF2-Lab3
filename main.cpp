#include "string.h"
#include <string>

int main()
{
  String a;
  String b(9, 'x');
  String c (b);
  a = b;
  std::cout << a.GetString() <<"\n";

  String d;
  d = a + b;

  if (a == b)
  {
    std::cout << "true\n";
  }
  else
  {
    std::cout << "false\n";
  }

  std::cout << d.GetLength() << "\n";

  d = "efcdeefgfeffef";

  std::cout << "\nFirstTimeWord " << d.FWord("gf") << "\n\n";
  d.KStr(6);
  
  std::cout << "\nAllWordIndexes ";  d.IndsWord("ef");
  std::cout << "\n" << d.FSymb('g');
  std::cout << "\nMostCommonSymb " << d.MostCommonSymb() << "\n";
  std::cout << "\nLetterWithoutRepeat " << d.WithoutRepeat() << "\n";
  std::cout << "\nCountLetters\n"; d.CountLetter();

  if (a > d)
    std::cout << "\ntrue\n";
  else
    std::cout << "\nfalse\n";

  a = "abcdefgs";
  d = "abcdefg";
  
  if (a > d)
    std::cout << "\ntrue\n";
  else
    std::cout << "\nfalse\n";

  std::cout << a[5] << "\n";

  return 0;
}
