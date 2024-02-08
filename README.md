# Programming Bitcoin in C++

## Prerequisites
- [C++](https://isocpp.org/)
 - [C++20](https://en.cppreference.com/w/cpp/20)
- [Boost](https://www.boost.org/)
- [Autotools](https://www.gnu.org/software/automake/)
 - [Autoconf](https://www.gnu.org/software/autoconf/)
 - [Automake](https://www.gnu.org/software/automake/)
 - [Libtool](https://www.gnu.org/software/libtool/)

```bash
## Build

```bash
$ ./autogen.sh && CPPFLAGS="-I/usr/local/Cellar/boost/1.84.0/include" ./configure && make
```

## Run

```bash 
$ ./src/main
```

## Test

```bash
$ make test
```