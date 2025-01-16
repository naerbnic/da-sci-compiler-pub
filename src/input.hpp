//	input.hpp		sc
//		definitions for input source structure

#ifndef INPUT_HPP
#define INPUT_HPP

#include <cstdio>
#include <memory>

#include "sc.hpp"

struct InputSource {
  InputSource();
  InputSource(char* fileName, int lineNum = 0);
  virtual ~InputSource() {}

  InputSource& operator=(InputSource&);

  virtual bool incrementPastNewLine(const char*&) = 0;
  virtual bool endInputLine() = 0;

  std::shared_ptr<InputSource> next;
  strptr fileName;
  int lineNum;
  strptr ptr;
};

struct InputFile : InputSource {
  InputFile(FILE*, const char* name);
  ~InputFile();

  bool incrementPastNewLine(const char*&) override;
  bool endInputLine() override;

  FILE* file;
  strptr fullFileName;
  fpos_t lineStart;
};

struct InputString : InputSource {
  InputString();
  InputString(const char* str);

  InputString& operator=(InputString&);

  bool incrementPastNewLine(const char*&);
  bool endInputLine();
};

bool CloseInputSource();
void FreeIncludePath();
bool GetNewInputLine();
std::shared_ptr<InputSource> OpenFileAsInput(strptr, bool);
void SetIncludePath();
void SetStringInput(strptr);
void SetInputToCurrentLine();
void RestoreInput();

void SetTokenStart();
void SetParseStart();
fpos_t GetParseStart();
fpos_t GetParsePos();
fpos_t GetTokenEnd();
void SetTokenEnd();

struct StrList;

extern char curFile[];
extern int curLine;
extern std::shared_ptr<InputSource> curSourceFile;
extern StrList* includePath;
extern std::shared_ptr<InputSource> is;
extern std::shared_ptr<InputSource> theFile;

#endif
