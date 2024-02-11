bin_PROGRAMS = main

DEPENDENCY_SOURCES =\
    consts/math.cpp \
    util/int256.cpp \
    util/int512.cpp \
    util/math.cpp \
    field_element/field_element.cpp \
    elliptic/point.cpp \ 
    secp256k1/s256_field.cpp \ 
    secp256k1/s256_point.cpp \
    signature/signature.cpp \
    private_key/private_key.cpp 

main_SOURCES = main.cpp $(DEPENDENCY_SOURCES)

LDFLAGS=-L/opt/homebrew/Cellar/boost/1.84.0/lib
LDLIBS=-lboost_random
LDADD=
ARCH=
AM_CPPFLAGS = $(ARCH) $(LDFLAGS) -I$(srcdir) $(LDLIBS) $(LDADD)
AM_CPPFLAGS_TEST = $(ARCH) $(LDFLAGS) -I$(srcdir) $(LDLIBS) $(LDADD)

include Makefile.test.include