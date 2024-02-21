# Install script for directory: /home/vboxuser/Desktop/openSi/kicad-source/resources

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/opt/kicad")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "resources" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icons" TYPE DIRECTORY FILES "/home/vboxuser/Desktop/openSi/kicad-build/resources/linux/icons/" FILES_MATCHING REGEX "/[^/]*\\.png$" REGEX "/[^/]*\\.svg$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "resources" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/mime/packages" TYPE DIRECTORY FILES "/home/vboxuser/Desktop/openSi/kicad-build/resources/linux/mime/" FILES_MATCHING REGEX "/[^/]*\\.xml$" REGEX "/[^/]*\\.in$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "resources" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/applications" TYPE DIRECTORY FILES "/home/vboxuser/Desktop/openSi/kicad-build/resources/linux/launchers/" FILES_MATCHING REGEX "/[^/]*\\.desktop$" REGEX "/[^/]*\\.in$" EXCLUDE)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "resources" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/metainfo" TYPE DIRECTORY FILES "/home/vboxuser/Desktop/openSi/kicad-build/resources/linux/metainfo/" FILES_MATCHING REGEX "/[^/]*metainfo\\.xml$" REGEX "/[^/]*\\.in$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/vboxuser/Desktop/openSi/kicad-build/resources/bitmaps_png/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/vboxuser/Desktop/openSi/kicad-build/resources/project_template/cmake_install.cmake")
endif()

