/*
Simple pattern walks through a directory

@author Justin Hadella (pitchnogle@gmail.com)
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------

void file_func(FILE *fout, char *file, int depth, int isdir);
void dir_func(FILE *fout, char *dir, int depth);

// =============================================================================
// Main Program
// =============================================================================

int main(int argc, char *argv[])
{
  char *topdir = ".";
  FILE *fout = stdout;

  // If there are arguments use them
  switch (argc) {
  case 3:
    fout = fopen(argv[2], "w");
    // fall-through
  case 2:
    topdir = argv[1];
    break;
  case 1:
    // Use defaults
    break;
  default:
    fprintf(stderr, "usage: %s [topdir] [outfile]\n", argv[0]);
    exit(2);
  }

  if (NULL == fout) {
    fprintf(stderr, "Unable to open output file %s\n", argv[2]);
    exit(2);
  }

  dir_func(fout, topdir, 0);
  fprintf(fout, "\n");

  return 0;
}

// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Local Functions
// ~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

void file_func(FILE *fout, char *file, int depth, int isdir)
{
  fprintf(fout, "%*s%s%s\n", depth, "", file, isdir ? "/" : "");
}

void dir_func(FILE *fout, char *dir, int depth)
{
  DIR *dp;
  struct dirent *entry;
  struct stat statbuf;

  if ((dp = opendir(dir)) == NULL) {
    //fprintf(stderr, "cannot open directory %s\n", dir);
    return;
  }
  chdir(dir);
  while ((entry = readdir(dp)) != NULL) {
    lstat(entry->d_name, &statbuf);
    if (S_ISDIR(statbuf.st_mode)) {
      // Ignore . and .. in this folder
      if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
        continue;
      // Do something with this file
      file_func(fout, entry->d_name, depth, 1);
      // Recurse at new depth
      dir_func(fout, entry->d_name, depth + 1);
    }
    else {
      file_func(fout, entry->d_name, depth, 0);
    }
  }
  chdir("..");
  closedir(dp);
}
