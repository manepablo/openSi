# Install script for directory: /home/vboxuser/Desktop/openSi/kicad-source/demos

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
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/opt/kicad/share/kicad/demos/complex_hierarchy;/opt/kicad/share/kicad/demos/custom_pads_test;/opt/kicad/share/kicad/demos/ecc83;/opt/kicad/share/kicad/demos/flat_hierarchy;/opt/kicad/share/kicad/demos/interf_u;/opt/kicad/share/kicad/demos/kit-dev-coldfire-xilinx_5213;/opt/kicad/share/kicad/demos/microwave;/opt/kicad/share/kicad/demos/pic_programmer;/opt/kicad/share/kicad/demos/python_scripts_examples;/opt/kicad/share/kicad/demos/simulation;/opt/kicad/share/kicad/demos/sonde xilinx;/opt/kicad/share/kicad/demos/stickhub;/opt/kicad/share/kicad/demos/test_pads_inside_pads;/opt/kicad/share/kicad/demos/test_xil_95108;/opt/kicad/share/kicad/demos/tiny_tapeout;/opt/kicad/share/kicad/demos/video")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/opt/kicad/share/kicad/demos" TYPE DIRECTORY FILES
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/complex_hierarchy"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/custom_pads_test"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/ecc83"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/flat_hierarchy"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/interf_u"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/kit-dev-coldfire-xilinx_5213"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/microwave"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/pic_programmer"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/python_scripts_examples"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/simulation"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/sonde xilinx"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/stickhub"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/test_pads_inside_pads"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/test_xil_95108"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/tiny_tapeout"
    "/home/vboxuser/Desktop/openSi/kicad-source/demos/video"
    )
endif()

