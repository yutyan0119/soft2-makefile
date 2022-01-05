#include <stdio.h>
#include <stdlib.h>

#ifndef _PAINTSTRUCT_H_
#define _PAINTSTRUCT_H_

// Structure for canvas
typedef struct {
  int width;
  int height;
  char **canvas;
  char pen;
} Canvas;

// Command 構造体と History構造体
// [*]
typedef struct command Command;
struct command {
  char *str;
  size_t bufsize;
  Command *next;
};

typedef struct {
  Command *begin;
  size_t bufsize;  // [*] : この方が効率的ですね。一部の方から指摘ありました。
} History;

// enum for interpret_command results
typedef enum res {
  EXIT,
  LINE,
  UNDO,
  SAVE,
  UNKNOWN,
  ERRNONINT,
  ERRLACKARGS,
  NOCOMMAND
} Result;

#endif