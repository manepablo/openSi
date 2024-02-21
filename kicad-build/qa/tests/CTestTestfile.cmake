# CMake generated Testfile for 
# Source directory: /home/vboxuser/Desktop/openSi/kicad-source/qa/tests
# Build directory: /home/vboxuser/Desktop/openSi/kicad-build/qa/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[qa_python]=] "/usr/bin/python3" "-m" "pytest" "/home/vboxuser/Desktop/openSi/kicad-source/qa/tests/pcbnewswig")
set_tests_properties([=[qa_python]=] PROPERTIES  ENVIRONMENT "PATH=/home/vboxuser/Desktop/openSi/kicad-build/kicad/:/home/vboxuser/Desktop/openSi/kicad-build/common/:/home/vboxuser/Desktop/openSi/kicad-build/common/gal/:/home/vboxuser/Desktop/openSi/kicad-build/pcbnew/:/home/vboxuser/Desktop/openSi/kicad-build/eeschema/:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin:;PYTHONPATH=/home/vboxuser/Desktop/openSi/kicad-build/pcbnew;" WORKING_DIRECTORY "/home/vboxuser/Desktop/openSi/kicad-source/qa/tests" _BACKTRACE_TRIPLES "/home/vboxuser/Desktop/openSi/kicad-source/qa/tests/CMakeLists.txt;56;add_test;/home/vboxuser/Desktop/openSi/kicad-source/qa/tests/CMakeLists.txt;0;")
add_test([=[qa_cli]=] "/usr/bin/python3" "-m" "pytest" "/home/vboxuser/Desktop/openSi/kicad-source/qa/tests/cli")
set_tests_properties([=[qa_cli]=] PROPERTIES  ENVIRONMENT "PATH=/home/vboxuser/Desktop/openSi/kicad-build/kicad/:/home/vboxuser/Desktop/openSi/kicad-build/common/:/home/vboxuser/Desktop/openSi/kicad-build/common/gal/:/home/vboxuser/Desktop/openSi/kicad-build/pcbnew/:/home/vboxuser/Desktop/openSi/kicad-build/eeschema/:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin:;KICAD_RUN_FROM_BUILD_DIR=1;PYTHONPATH=/home/vboxuser/Desktop/openSi/kicad-build/pcbnew;" WORKING_DIRECTORY "/home/vboxuser/Desktop/openSi/kicad-source/qa/tests" _BACKTRACE_TRIPLES "/home/vboxuser/Desktop/openSi/kicad-source/qa/tests/CMakeLists.txt;67;add_test;/home/vboxuser/Desktop/openSi/kicad-source/qa/tests/CMakeLists.txt;0;")
subdirs("common")
subdirs("gerbview")
subdirs("eeschema")
subdirs("libs")
subdirs("pcbnew")
subdirs("spice")
