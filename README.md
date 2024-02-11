# Programming Bitcoin in C++
- [Programming Bitcoin](https://www.amazon.com/Programming-Bitcoin-Learn-Program-Scratch/dp/1492031496)

## 1. On Mac

### Prerequisites
- [C++](https://isocpp.org/)
    - [C++20](https://en.cppreference.com/w/cpp/20)
- [Boost](https://www.boost.org/)
- [Autotools](https://www.gnu.org/software/automake/)
    - [Autoconf](https://www.gnu.org/software/autoconf/)
    - [Automake](https://www.gnu.org/software/automake/)
    - [Libtool](https://www.gnu.org/software/libtool/)

## Build

 - On my Mac

```bash
$ ./autogen.sh && CPPFLAGS="-I/usr/local/Cellar/boost/1.84.0/include" ./configure && make
```

### Run

```bash 
$ ./src/main
```

### Test

```bash
$ make test
```

## 2. On Docker
### Prerequisites
- [Docker](https://www.docker.com/)

```bash
$ docker build -t programming-bitcoin-cpp .
```

### Run

```bash
$ docker run -it --rm programming-bitcoin-cpp bash
```

### Build

```bash
xxxx@xxxxxxxxxxxx:/# make
```

### Test

```bash
xxxx@xxxxxxxxxxxx:/# make test
```