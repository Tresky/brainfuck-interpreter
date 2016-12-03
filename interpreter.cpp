#include <iostream>
  using std::cout;
  using std::endl;
#include <fstream>
  using std::ifstream;
#include <algorithm>
#include <vector>
#include <stack>

#define CODE_SIZE 30000
#define TICKER_SIZE 30000

void error(int _code, int _detail = -1);

int main(int argc, char* argv[])
{
  char code[CODE_SIZE];
  short code_pointer = 0;

  char ticker[TICKER_SIZE];
  short pointer = 0;

  if (argc <= 1)
  error(100);

  std::string file_name = argv[1];
  ifstream input(file_name);

  std::fill(ticker, ticker + TICKER_SIZE, 0);

  char c;
  while (input.get(c))
    code[code_pointer++] = c;
  code[code_pointer] = '#';

  std::stack<short> loop_pointers;

  code_pointer = 0;
  while ((c = code[code_pointer]) != '#')
  {
    switch (c)
    {
      case ' ':
      case '\n':
      case '\t':
        break;
      case '>':
        ++pointer;
        break;
      case '<':
        --pointer;
        break;
      case '+':
        ++ticker[pointer];
        break;
      case '-':
        --ticker[pointer];
        break;
      case '.':
        cout << ticker[pointer];
        break;
      case ',':
        ticker[pointer] = getchar();
        break;
      case '[':
        if (ticker[pointer] != 0)
          loop_pointers.push(code_pointer);
        else
        {
          char i;
          short end = code_pointer + 1;
          while ((i = code[end]) != ']' && i != '#')
            ++end;

          if (i == ']')
            code_pointer = end;
          else
            error(300);
        }
        break;
      case ']':
        if (ticker[pointer] != 0)
          code_pointer = loop_pointers.top();
        else
          loop_pointers.pop();
        break;
      default:
        error(200, c);
        break;
    }

    ++code_pointer;
  }
}

void error(int _code, int _detail)
{
  cout << "Error Code " << _code << ": ";
  switch (_code)
  {
    case 100:
      cout << "No input file specified." << endl;
      break;
    case 200:
      cout << "Invalid token read: " << char(_detail) << endl;
      break;
    case 300:
      cout << "Ending bracket not found." << endl;
      break;
  }

  exit(_code);
}
