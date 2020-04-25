# c-walkdir

This is a simple pattern which shows how to walk through a directory structure
in C.

For each folder and file that is found, this example just prints the name to
a file stream; it could be adapted to do other things.

## usage
```
c-walkdir [topdir] [outfile]
```

The [topdir] represents the top directory to use. If no argument is given, then
the current folder is used. The [outfile] is an optional output file. If no
[outfile] is given then stdout is used.
