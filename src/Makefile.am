bin_PROGRAMS = main
main_SOURCES = main.cpp \
    field_element/field_element.cpp \
    elliptic/point.cpp \
    elliptic/elliptic.cpp

AM_CXXFLAGS= -std=c++20 -Wall -Wextra -Werror -pedantic -O3 -g
AM_CPPFLAGS= -I$(srcdir)/field_element -I$(srcdir)/elliptic 