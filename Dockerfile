# This is a comment
FROM littlemole/devenv_clangpp_cmake
MAINTAINER me <little.mole@oha7.org>

ARG CXX=g++
ENV CXX=${CXX}

ARG BACKEND=
ENV BACKEND=${BACKEND}

ARG BUILDCHAIN=make
ENV BUILDCHAIN=${BUILDCHAIN}

RUN /usr/local/bin/install.sh repro 
RUN /usr/local/bin/install.sh prio 

RUN mkdir -p /usr/local/src/priohttp
ADD . /usr/local/src/priohttp

RUN SKIPTESTS=true /usr/local/bin/build.sh priohttp 

