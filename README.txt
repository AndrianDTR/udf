WINDOWS:
Required packages
-----------------------------
1. Download and install MinGW
	a.	Download latest from http://www.mingw.org
	b.	Install to C:\MinGW\
	
2. Download and install 7z
	a.	Download from http://7-zip.org
	b.	Install to C:\7-Zip\
	
3. Download and install cmake

4. Copy source files to 
	c:\SRC_DIR

5. Build
	cd  c:\SRC_DIR\
	mkdir c:\SRC_DIR\build
	cd c:\SRC_DIR\build
	cmake -DWITH_WX_WIDGETS=yes -DWITH_BOOST=yes -DWITH_MYSQL_CONNECTOR=yes -G "MinGW Makefiles" ../.
	make -j8

6. Executeble files are located in 
	c:\SRC_DIR\build\bin

*******************************************************************************************************

LINUX:
1. install cmake
	sudo apt-get install cmake

2. install "build esentials" packcage
	sudo apt-get install build-essential

3. Copy source files to
	~/udf
	
4. Build
	cd ~/udf
	mkdir build
	cd build
	cmake -DWITH_WX_WIDGETS=yes -DWITH_BOOST=yes -DWITH_MYSQL_CONNECTOR=yes ../.
	make -j8

5. Executeble files are located in 
	~/udf/build/bin

