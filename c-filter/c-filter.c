/*
Simple pattern to read characters from an input file, do something with that
character then output result to output file

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void func(FILE *fout, int c);

// =============================================================================
// Main Program
// =============================================================================

int main(int argc, char *argv[])
{
  FILE *fin = stdin;
  FILE *fout = stdout;

  int c;

  // If there are arguments use them
  switch (argc) {
  case 3:
    fout = fopen(argv[2], "w");
    // fall-through
  case 2:
    fin = fopen(argv[1], "r");
    break;
  case 1:
    // Use defaults
    break;
  default:
    fprintf(stderr, "usage: %s [infile] [outfile]\n", argv[0]);
    exit(2);
  }

  if (NULL == fin) {
    fprintf(stderr, "Unable to open input file %s\n", argv[1]);
    exit(2);
  }

  if (NULL == fout) {
    fprintf(stderr, "Unable to open output file %s\n", argv[2]);
    exit(2);
  }

  while ((c = fgetc(fin)) != EOF) {
    func(fout, c);
  }
  fprintf(fout, "\n");

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void func(FILE *fout, int c)
{
  fprintf(fout, "%c", c);
}