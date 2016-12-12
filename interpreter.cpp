/**
 * Title: Brainfuck Interpreter
 * Author: Tyler Petresky
 * Date: 12-03-16
 * Desc: Brainfuck is an esoteric language
 * that uses 8 commands to do computations.
 * Brainfuck is a Turing-complete language.
 * This means that is can be used to solve
 * any computational problem given enough
 * time and memory space.
 */

#include <iostream>
#include <fstream>
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
  std::ifstream input(file_name);

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
        std::cout << ticker[pointer];
        break;
      case ',':
        ticker[pointer] = getchar();
        break;
      case '[': {
        int bal = 1;
        if (ticker[pointer] == 0) {
        do {
          code_pointer++;
          if (code[code_pointer] == '[') bal++;
          else if (code[code_pointer] == ']') bal--;
        } while (bal != 0);
      }
        break;
      case ']': {
        int bal = 0;
        do {
          if      (code[code_pointer] == '[') bal++;
          else if (code[code_pointer] == ']') bal--;
          code_pointer--;
        } while ( bal != 0 ); }
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
  std::cout << "Error Code " << _code << ": ";
  switch (_code)
  {
    case 100:
      std::cout << "No input file specified." << std::endl;
      break;
    case 200:
      std::cout << "Invalid token read: " << char(_detail) << std::endl;
      break;
    case 300:
      std::cout << "Ending bracket not found." << std::endl;
      break;
  }

  exit(_code);
}
