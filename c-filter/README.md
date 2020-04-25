# c-filter

Simple pattern to read characters from an input file, do something with that
character then output result to output file

## usage
```
c-filter [infile] [outfile]
```

The `[infile]` and `[outfile]` are optional. If no arguments are given, then the
infile is `stdin`, and the outfile is `stdout`. If one argument is given, then
then in infile is the argument provived, and the output is `stdout`.

## examples

```
c-filter < Makefile
```
```
CFLAGS=-Wall -g

all: c-filter

clean:
        rm -f c-filter
```

Instead of using file direction, we can also call it like this
```
c-filter Makefile
```
```
CFLAGS=-Wall -g

all: c-filter

clean:
        rm -f c-filter
```

We can use file direction for input and output
```
c-filter < Makefile > test.txt
```
```
cat test.txt
CFLAGS=-Wall -g

all: c-filter

clean:
        rm -f c-filter
```

We can also use arguments for the input and output
```
c-filter Makefile test.txt
```
