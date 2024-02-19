
#build the kicad project
build-kicad:
	@echo "Building kicad project"
	@cd kicad-master && mkdir -p build/release && mkdir -p build/debug && cd build/release && cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ../../ && make && sudo make install


#	cd <your kicad source mirror>
#	mkdir -p build/release
#	mkdir -p build/debug               # Optional for debug build.
#	cd build/release
#	cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo \
#			../../
#	make
#	sudo make install