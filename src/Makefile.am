bin_PROGRAMS = main

DEPENDENCY_SOURCES =\
    field_element/field_element.cpp \
    elliptic/point.cpp 

main_SOURCES = main.cpp $(DEPENDENCY_SOURCES)

LDADD=
AM_CPPFLAGS= -arch x86_64 -I$(srcdir)/field_element -I$(srcdir)/elliptic 

include Makefile.test.include