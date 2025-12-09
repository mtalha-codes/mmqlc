if(DEFINED ENV{VCPKG_ROOT})
  message("VCPKG_ROOT has been detected, finding the toolchain file")
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
  if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux") # checks OS
    if(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "x86_64")
      # checks for achitecture, x86 archtecture 64bit
      if(CMAKE_CXX_COMPILER STREQUAL "x86_64-w64-mingw32-g++")
        set(Boost_DIR "../vcpkg_installed/x64-mingw-static/share/boost/")
      elseif(CMAKE_CXX_COMPILER STREQUAL "g++" OR CMAKE_CXX_COMPILER STREQUAL "clang++")
        set(Boost_DIR "../vcpkg_installed/x64-linux/share/boost/")
      endif()
    elseif(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "aarch64")
      # chekcs for architecture, arm architecutre 64bit
      # cross compiling from linux to windows on ARM CPUs is not supported by this project
      set(Boost_DIR "../vcpkg_installed/arm64-linux/share/boost/")
    else()
      message("Error: Unknown CPU Architecture !")
    endif()
  elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin")
    if(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "x86_64")
      # checks for achitecture, x86 archtecture 64bit
      set(Boost_DIR "../vcpkg_installed/x64-osx/share/boost/")
    elseif(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "arm64")
      # chekcs for architecture, arm architecutre 64bit
      set(Boost_DIR "../vcpkg_installed/arm64-osx/share/boost/")
    else()
      message("Error: Unknown CPU Architecture !")
    endif()

  elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    if(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "AMD64")
      # checks for achitecture, x86 archtecture 64bit
      set(Boost_DIR "../vcpkg_installed/x64-windows/share/boost/")
    elseif(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "ARM64")
      # chekcs for architecture, arm architecutre 64bit
      set(Boost_DIR "../vcpkg_installed/arm64-windows/share/boost/")
    else()
      message("Error: Unknown CPU Architecture !")
    endif()
  else()
    message("Error: Unsupported OS !")
  endif()
else()
  message("vcpkg is not installed, aborting !")
endif()

set(main "./main.cpp")
file(GLOB_RECURSE headers "./headers/*.hpp")

find_package(Boost REQUIRED COMPONENTS math multiprecision)
find_package(fmt CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(gmp REQUIRED IMPORTED_TARGET gmp)
pkg_check_modules(gmpxx REQUIRED IMPORTED_TARGET gmpxx)
pkg_check_modules(mpfr REQUIRED IMPORTED_TARGET mpfr)

add_executable(mmqlc ${main} ${headers})
target_link_libraries(mmqlc PRIVATE
    Boost::math
    Boost::multiprecision
    PkgConfig::gmp
    PkgConfig::gmpxx
    PkgConfig::mpfr
    fmt::fmt-header-only
)
