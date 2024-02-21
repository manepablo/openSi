ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

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
	
build-ngspice42:
	cd ngspice42 &&  ./compile_linux.sh
build-ngspice-essentials:
	sudo apt install build-essential flex bison libx11-6 libx11-dev libxaw7 libxaw7-dev fontconfig libxft-dev libxft2 libcairo2 libcairo2-dev libxmu6 libxext-dev libxext6 libxrender1 libxrender-dev libtool readline-common libreadline-dev gawk
build-open_pdk:
	#pulls the skywater pdk files and performs some transformations to make the accesable via ngspice
	echo ${ROOT_DIR}
	mkdir -p PDK
	cd open_pdks && ./configure --prefix=${ROOT_DIR}/pdk --enable-sky130-pdk --enable-magic --enable-openlane && sudo make DESTDIR=${ROOT_DIR}/pdk

# to run ngspice a initialization file is needed in the home directory	
init_skywater_pdk:
	#todo replace it to make it general for allp pdks
	cp ${ROOT_DIR}/simulation/siminitfiles/.spiceinit_syk130A ~/
	mv ~/.spiceinit_syk130A ~/.spiceinit
	
