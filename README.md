A simple homework written in cpp. This is the first time that I use cmake. Mark 🚀

## How to start

You need to install cmake, clang compiler. Then execute these commands in the project's root directory (May be different on Windows or other operating system):

```bash
mkdir build
cd build
cmake ..
make
```

Then you can get the programme DijkstraHomework.

## The usage

Thanks to this repositories so that I can add command line parameter easily:

[https://github.com/tanakh/cmdline](https://github.com/tanakh/cmdline)

```
usage: ./DijkstraHomework --file=string --source=string --target=string [options] ...
options:
  -f, --file      the path of the input data file (string)
  -s, --source    the source vertex (string)
  -t, --target    the target vertex (string)
  -?, --help      print this message
```

for example:
`./DijkstraHomework -f "the path to data file" -s "s" -t "t"`
