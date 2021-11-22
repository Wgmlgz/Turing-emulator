#include "turing.h"

#include <stdio.h>
#include <string.h>

#include "brainfuck.h"

extern "C" {
TuringMachine* init(const char* s_table, const char* str, int pos) {
  std::string std_s_table(s_table);
  std::string std_str(str);
  TuringMachine* tm_p = new TuringMachine(std_s_table, std_str, pos);
  return tm_p;
}
void safeIterate(TuringMachine* tm) { tm->safeIterate(); }
void getStr(TuringMachine* tm, char* buf) {
  try {
    std::string st = tm->toStrUnity();
    strcpy(buf, st.c_str());
  } catch (const std::exception&) {
  }
}
}
