FROM ubuntu:latest

# Install build essentials, C++20 compiler, and autotools
RUN apt update && apt install -y vim less build-essential g++ autotools-dev autoconf automake libtool

# Set the default C++ compiler to use g++
ENV CXX=g++

# Install Boost libraries
RUN apt-get install -y libboost-all-dev

COPY . /app
WORKDIR /app

RUN ./autogen.sh && ./configure