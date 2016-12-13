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

void error(int _code, int _detail = -1);

int main(int argc, char* argv[])
{
  std::vector<char> code;
  int code_pointer = 0;

  std::vector<unsigned char> ticker;
  ticker.push_back(0);

  int pointer = 0;

  if (argc <= 1)
    error(100);

  std::string file_name = argv[1];
  std::ifstream input(file_name);

  char c;
  while (input.get(c))
    code.push_back(c);

  int nest;
  while (code_pointer < code.size())
  {
    switch (code[code_pointer])
    {
      case '#':
        while (code[++code_pointer] != '\n' && code_pointer < code.size());
      case ' ':
      case '\n':
      case '\t':
        break;
      case '>':
        if (pointer == ticker.size() - 1)
          ticker.push_back(0);
        ++pointer;
        break;
      case '<':
        if (pointer > 0)
          --pointer;
        break;
      case '+':
        // if (ticker[pointer] < INT_MAX)
          ++ticker[pointer];
        break;
      case '-':
        // if (ticker[pointer] > 0)
          --ticker[pointer];
        break;
      case '.':
        std::cout << char(ticker[pointer]);
        break;
      case ',':
        int t;

        ticker[pointer] = std::cin.get();
        std::cin.clear();
        break;
      case '[':
        nest = 1;
        if (ticker[pointer] == 0) {
          do {
            code_pointer++;
            if (code[code_pointer] == '[')
              nest++;
            else if (code[code_pointer] == ']')
              nest--;
          } while (nest != 0);
        }
        break;
      case ']':
        nest = 0;
        do {
          if (code[code_pointer] == '[')
            nest++;
          else if (code[code_pointer] == ']')
            nest--;
          code_pointer--;
        } while (nest != 0);
        break;
      default:
        // error(200, code[code_pointer]);
        break;
    }

    ++code_pointer;
  }

  return 0;
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
