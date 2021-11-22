#include <iostream>
#include <string>
#include <vector>
#include "turing.h"
#include "brainfuck.h"

int main() {
  TuringMachine* a_to_b = new TuringMachine("aaaa", {
        {"a", {{"b", rt}}},
        {"~", {RT}}
    });
  TuringMachine wtf("aaabbbaaa", {
    {"a", { {"c", nn, 1},    NN,          NN,           NN         }},
    {"b", { {"d", nn, 2},    NN,          NN,           NN         }},
    {"c", { LT,              RT,         RT,          {"a", rt} }},
    {"d", { LT,              RT,         RT,          {"b", rt} }},
    {"~", { {SKIP, rt, 3}, {"c", nn, 0}, {"d", nn, 0}, ST         }}
  }, 8);

  auto da = TuringMachine("   a   ,   b   ,   >   ,     0\n~,  ~    ,=,-1","aaaaaaa");
  auto brainfuck = brainfuckTM();
  brainfuck.setDefault("++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.:aab");
  brainfuck.run(100);
  std::cout << brainfuck.toStr() << std::endl;

  // Some examples
  // Hello world!
  //std::cout << brainfuck.getRes("++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.:aab", 100);
  // 2
  //std::cout << brainfuck.getRes(",>,>,>>++++++++[-<++++++>>++++++<]<[-<<<->->->]<<<[->++++++++++<]>[-<+++++>]>>>>++<<<<<[->>>>>.>+<<<<<<[->>>>>-------.+++++++.<<<<<]]>>[->>>>[-<-------.+++++++>]<.---.+++.<<<[->>>-------.+++++++.---.+++.<<<]]:010", 1);
  //+
  //std::cout << brainfuck.getRes("+++++++++>[][].", 1000);
}