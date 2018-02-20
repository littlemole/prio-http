############################################
cmake_minimum_required(VERSION 2.8.9)
project(priohttp)
include(CTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINKERFLAGS}" )

message(" COMPILER: ${CMAKE_CXX_COMPILER_ID}")
message(" FLAGS: ${FLAGS}")

############################################
# OS support
############################################


IF (WIN32)

	set(OSLIBS "Ws2_32" "Rpcrt4")

	find_library(PRIO_LIBRARY NAMES priocpp)
	find_library(NG2HTTP_LIBRARY NAMES nghttp2)
	find_library(LIBEVENT_LIBRARY NAMES event)

	set(BUILDFLAGS "-await ${FLAGS}")
	set(DEBUGFLAGS -DMOL_PROMISE_DEBUG)

	set(LIBS ${PRIO_LIBRARY} ${CRYPTONEAT_LIBRARY} ${GTEST_LIBRARIES} ${OPENSSL_LIBRARIES} ${NG2HTTP_LIBRARY}  ${STDLIB}  )

 ELSEIF(UNIX)

    set(OSLIBS "pthread")

    find_package(PkgConfig)
    pkg_check_modules(NGHTTP2 REQUIRED libnghttp2)
    pkg_check_modules(PRIOCPP REQUIRED priocpp)
    pkg_check_modules(LIBEVENT REQUIRED libevent_pthreads)
    pkg_check_modules(ZLIB REQUIRED zlib)
    pkg_check_modules(CRYPTONEAT REQUIRED cryptoneat)

	set(LIBEVENT_LIBRARY ${LIBEVENT_LIBRARIES})

    set(BUILDFLAGS " ${FLAGS}")
	set(DEBUGFLAGS "-g -DMOL_PROMISE_DEBUG")

	set(LIBS ${GTEST_LIBRARIES} ${OPENSSL_LIBRARIES} ${NGHTTP2_LIBRARIES} ${CRYPTONEAT_LIBRARIES} ${ZLIB_LIBRARIES} ${STDLIB} )
ENDIF ()


############################################
# macros
############################################

macro(AddCompilerFlags target flags)
    get_target_property(CF ${target} COMPILE_FLAGS)
    if(CF STREQUAL "CF-NOTFOUND")
        SET(CF "") # set to empty string
    else()
        SET(CF "${CF} ") # a space to cleanly separate from existing content
    endif()

    SET(CF "${CF} ${flags}" )
    set_target_properties(${target} PROPERTIES COMPILE_FLAGS ${CF} )
endmacro()

############################################
# defaults
############################################

file(GLOB_RECURSE TMPMSG "/usr/local/include/priocpp/impl*.h")
message("${TMPMSG}")

set(BACKEND ${LIBEVENT_LIBRARY})

option(WITH_LIBEVENT "use libevent (default:on)" ON)
if(WITH_LIBEVENT)
    add_definitions(-DPROMISE_USE_LIBEVENT)
else()
    add_definitions(-DPROMISE_USE_BOOST_ASIO)
    set(BACKEND "boost_system")
endif()


############################################
# sources
############################################

include_directories(include)
include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(/usr/local/include)

file(GLOB SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/priohttp/*.h")

############################################
# targets
############################################

add_library(priohttp  STATIC ${SOURCES})
add_library(priohttpd STATIC ${SOURCES})

add_executable(Tests t/test.cpp)

AddCompilerFlags(priohttp ${BUILDFLAGS})

AddCompilerFlags(priohttpd ${BUILDFLAGS})
AddCompilerFlags(priohttpd ${DEBUGFLAGS})

AddCompilerFlags(Tests ${BUILDFLAGS})
AddCompilerFlags(Tests ${DEBUGFLAGS})


############################################
# libs
############################################

target_link_libraries(Tests priohttpd priocppd ${LIBS} ${BACKEND} ${OSLIBS} )


############################################
# tests
############################################

add_test(NAME AllTests COMMAND Tests)

file(COPY pem DESTINATION .)
 
############################################
# install rules
############################################
 
install(TARGETS priohttp DESTINATION lib)
install(TARGETS priohttpd DESTINATION lib)

install(DIRECTORY include/priohttp DESTINATION include)

install(FILES priohttp.pc DESTINATION lib/pkgconfig)
