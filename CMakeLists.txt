############################################
# preamble
############################################
cmake_minimum_required(VERSION 2.8.9)
cmake_policy(SET CMP0054 NEW)
project(priohttp)
include(CTest)

############################################
# c++ std
############################################

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

############################################
# debug mode produces libs with d suffix
############################################

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

############################################
# basic dependecies
############################################

find_package(GTest REQUIRED)
find_package(OpenSSL REQUIRED)


############################################
# clang support
############################################

set(LINKERFLAGS "")
set(STDLIB "")
set(FLAGS "")


if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(STDLIB "c++abi")
    set(LINKERFLAGS "-stdlib=libc++ -fcoroutines-ts  -std=c++14")
    set(FLAGS "-stdlib=libc++ -fcoroutines-ts -D_RESUMABLE_FUNCTIONS_SUPPORTED")
endif()

############################################
# OS support (Linux/Windows)
############################################

IF (WIN32)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

message("+++++++++++++++++")
message("${CMAKE_BUILD_TYPE}")
message("+++++++++++++++++")

	set(OSLIBS "Ws2_32" "Rpcrt4" "Shlwapi")
	set(BUILDFLAGS "-await ${FLAGS}")

	find_library(LIBEVENT_LIBRARY NAMES event)
	find_library(NG2HTTP_LIBRARY NAMES nghttp2)
	set(LIBS ${NG2HTTP_LIBRARY} ${GTEST_LIBRARIES} ${OPENSSL_LIBRARIES} ${STDLIB}  )

	if(${CMAKE_BUILD_TYPE} MATCHES "Release")
			find_library(PRIOCPP_LIBRARY NAMES priocpp)
			find_library(ZLIB_LIBRARY NAMES zlib)
 		    find_library(CRYPTONEAT_LIBRARY NAMES cryptoneat)
			set(LIBS ${LIBS} debug ${CMAKE_PROJECT_NAME} optimized ${CMAKE_PROJECT_NAME} ${PRIOCPP_LIBRARY} ${CRYPTONEAT_LIBRARY} ${ZLIB_LIBRARY} )
    else()
    	find_library(PRIOCPP_LIBRARY NAMES priocpp.lib)
    	find_library(PRIOCPPD_LIBRARY NAMES priocppd.lib)
		find_library(CRYPTONEAT_LIBRARY NAMES cryptoneat)
		find_library(CRYPTONEATD_LIBRARY NAMES cryptoneatd)
		find_library(ZLIB_LIBRARY NAMES zlib)
		find_library(ZLIBD_LIBRARY NAMES zlibd)

		set(LIBS ${LIBS} 
				debug ${CMAKE_PROJECT_NAME} optimized ${CMAKE_PROJECT_NAME} 
				debug ${PRIOCPPD_LIBRARY} optimized  ${PRIOCPP_LIBRARY} 
				debug ${CRYPTONEATD_LIBRARY} optimized ${CRYPTONEAT_LIBRARY} 
				debug ${ZLIBD_LIBRARY} optimized ${ZLIB_LIBRARY}  
		)
	endif()

message("+++++++++++++++++")
message("LIBS: ${LIBS}")
message("+++++++++++++++++")

 ELSEIF (UNIX)

    set(OSLIBS "pthread")

    find_package(PkgConfig)
    pkg_check_modules(NGHTTP2 REQUIRED libnghttp2)
    pkg_check_modules(PRIOCPP REQUIRED priocpp)
    pkg_check_modules(LIBEVENT REQUIRED libevent_pthreads)
    pkg_check_modules(CRYPTONEAT REQUIRED cryptoneat)

    set(LIBEVENT_LIBRARY ${LIBEVENT_LIBRARIES})

    set(BUILDFLAGS " ${FLAGS}")
message("+++++++++++++++++")
message("${NGHTTP2_LIBRARIES}")
message("${NGHTTP2_LIBRARY}")
message("+++++++++++++++++")
    set(LIBS debug priocppd optimized priocpp ${CRYPTONEAT_LIBRARIES} ${GTEST_LIBRARIES} ${NGHTTP2_LIBRARIES} ${OPENSSL_LIBRARIES} z ${STDLIB}  )
message("+++++++++++++++++")
message("${LIBS}")
message("+++++++++++++++++")
    set(LIBS debug ${CMAKE_PROJECT_NAME} optimized ${CMAKE_PROJECT_NAME} ${LIBS} )

ENDIF ()

############################################
# set linker and compiler flags
############################################

set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINKERFLAGS}" )
set(CMAKE_CXX_FLAGS_DEBUG  	"${CMAKE_CXX_FLAGS_DEBUG} -DMOL_PROMISE_DEBUG")
set(CMAKE_CXX_FLAGS  		"${CMAKE_CXX_FLAGS} ${BUILDFLAGS}")


############################################
# backend: libevent or boost_asio
############################################

option(WITH_LIBEVENT "use libevent (default:on)" OFF)
if(WITH_LIBEVENT)
    add_definitions(-DPROMISE_USE_LIBEVENT)    
    set(BACKEND ${LIBEVENT_LIBRARY})
else()
    add_definitions(-DPROMISE_USE_BOOST_ASIO)
if (WIN32)
find_package( Boost COMPONENTS system date_time  REQUIRED )
    set(BACKEND "Boost::system" "Boost::date_time")
else()
    set(BACKEND "boost_system")
endif()
endif()



############################################
# include directories
############################################

include_directories(include)
include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(${PRIOCPP_INCLUDE_DIRS})


############################################
# sources
############################################

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/${CMAKE_PROJECT_NAME}/*.h")

############################################
# lib target
############################################

add_library(${CMAKE_PROJECT_NAME}  STATIC ${SOURCES})

############################################
# tests
############################################

add_executable(Tests t/test.cpp)

############################################
# libs for tests
############################################

target_link_libraries(Tests ${LIBS} ${BACKEND} ${OSLIBS} )


############################################
# run tests
############################################


add_test(NAME AllTests COMMAND Tests)

file(COPY pem DESTINATION .)
 
############################################
# install rules
############################################

install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION lib)

install(FILES ${HEADERS} DESTINATION include/${CMAKE_PROJECT_NAME})

install(FILES ${CMAKE_PROJECT_NAME}.pc DESTINATION lib/pkgconfig)



