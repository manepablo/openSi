# Install script for directory: /home/vboxuser/Desktop/openSi/kicad-source/eeschema/python_scripts

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "binary" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/opt/kicad/share/kicad/plugins/README-bom.txt;/opt/kicad/share/kicad/plugins/kicad_utils.py;/opt/kicad/share/kicad/plugins/kicad_netlist_reader.py;/opt/kicad/share/kicad/plugins/bom_csv_grouped_by_value.py;/opt/kicad/share/kicad/plugins/bom_csv_grouped_by_value_with_fp.py;/opt/kicad/share/kicad/plugins/bom_csv_grouped_extra.py;/opt/kicad/share/kicad/plugins/bom_csv_sorted_by_ref.py;/opt/kicad/share/kicad/plugins/bom_html_grouped_by_value.py;/opt/kicad/share/kicad/plugins/bom_html_with_advanced_grouping.py;/opt/kicad/share/kicad/plugins/bom_txt_sorted_by_ref.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/opt/kicad/share/kicad/plugins" TYPE FILE FILES
    "/home/vboxuser/Desktop/openSi/kicad-source/eeschema/python_scripts/README-bom.txt"
    "/home/vboxuser/Desktop/openSi/kicad-source/eeschema/python_scripts/kicad_utils.py"
    "/home/vboxuser/Desktop/openSi/kicad-source/eeschema/python_scripts/kicad_netlist_reader.py"
    "/home/vboxuser/Desktop/openSi/kicad-source/eeschema/python_scripts/bom_csv_grouped_by_value.py"
    "/home/vboxuser/Desktop/openSi/kicad-source/eeschema/python_scripts/bom_csv_grouped_by_value_with_fp.py"
    "/home/vboxuser/Desktop/openSi/kicad-source/eeschema/python_scripts/bom_csv_grouped_extra.py"
    "/home/vboxuser/Desktop/openSi/kicad-source/eeschema/python_scripts/bom_csv_sorted_by_ref.py"
    "/home/vboxuser/Desktop/openSi/kicad-source/eeschema/python_scripts/bom_html_grouped_by_value.py"
    "/home/vboxuser/Desktop/openSi/kicad-source/eeschema/python_scripts/bom_html_with_advanced_grouping.py"
    "/home/vboxuser/Desktop/openSi/kicad-source/eeschema/python_scripts/bom_txt_sorted_by_ref.py"
    )
endif()

