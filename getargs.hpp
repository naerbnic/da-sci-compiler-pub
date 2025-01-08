//
// getargs
//
// This is a reconstructed file for processing an argument list.  Functionality
// is based on what I see as necessary from usage in sc.cpp.
//
// author: Stephen Nichols
//

#ifndef _GETARGS_HPP_
#define _GETARGS_HPP_

#include <cstdint>
#include <variant>

using ga_proc_t = void (*)(char *str);

using ArgValue = std::variant<bool *, int *, const char **, ga_proc_t>;

// define the Arg structure
typedef struct {
  char switchVal;
  ArgValue value;
  const char *desc;
} Arg;

// declate the usageStr extern
extern char usageStr[];

// declate the switches array extern
extern Arg switches[];

// this function prints the usage information
void ShowUsage(void);

// this function parses the available arguments and returns the number of valid
// arguments
int getargs(int argc, char **argv);

// this function extracts and processes each of the arguments and leaves the
// unprocessed arguments in the argument list
void exargs(int *argc, char ***argvPtr);

#endif
