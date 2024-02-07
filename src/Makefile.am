bin_PROGRAMS = main

DEPENDENCY_SOURCES =\
    util/uint256.h \
    field_element/field_element.cpp \
    elliptic/point.cpp \ 
    secp256k1/s256_field.cpp \ 
    secp256k1/s256_point.cpp 

main_SOURCES = main.cpp $(DEPENDENCY_SOURCES)

LDADD=
ARCH=-arch x86_64
AM_CPPFLAGS = $(ARCH) -I$(srcdir)/field_element -I$(srcdir)/elliptic 
AM_CPPFLAGS_TEST = $(ARCH) -I$(srcdir)/field_element -I$(srcdir)/elliptic 

include Makefile.test.include