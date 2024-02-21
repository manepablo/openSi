
#build the kicad project
build-kicad-essentials:
	sudo add-apt-repository -s --yes ppa:kicad/kicad-dev-nightly && sudo apt build-dep kicad-nightly
build-kicad:
#	check https://gitlab.com/eelik-kicad/kicad/-/wikis/How-to-build-KiCad-on-Linux-(the-easy-way)
	mkdir kicad-build
	cd kicad-build && cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=/opt/kicad ../kicad-source
	@echo "Building kicad project"
	@cd ../kicad-source && cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ../kicad-build
	echo "installing ..."
	sudo chmod o+x ./kicad-build
	chmod a+rx
	cd kicad-build && sudo make install

clean-all-build:
	sudo rm -r ./kicad-build
