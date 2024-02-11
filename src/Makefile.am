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

LDADD=-lboost_random
ARCH=
AM_CPPFLAGS = $(ARCH) -I$(srcdir)
AM_CPPFLAGS_TEST = $(ARCH) -I$(srcdir)

include Makefile.test.include