SRC = @UDF_WXSRC@

CONFIG_FLAGS = 

if TARGET_OS_LINUX
	CONFIG_FLAGS += --disable-shared --with-gtk
endif #TARGET_OS_LINUX

if TARGET_OS_WINDOWS
	CONFIG_FLAGS += 
endif #TARGET_OS_WINDOWS

if WITH_WXWIDGETS

all-local:
	echo "Building wxWidgets libraries..."
	cd $(SRC)/buildwx && ../configure --disable-shared --with-gtk && make -j8


endif #WITH_WXWIDGETS
