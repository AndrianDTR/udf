ACLOCAL_AMFLAGS = -I m4

SUBDIRS =
BUILT_SOURCES = 

if WITH_WXWIDGETS
WXDIR = $(abs_builddir)/wxWidgets
WXLIBDIR = $(WXDIR)/lib

COMMON_WXDEP = $(WXLIBDIR)/wx/config/gtk3-unicode-static-2.9

BUILT_SOURCES += \
	$(COMMON_WXDEP) \
	$(WXLIBDIR)/libwx_gtk3u-2.9.a \
	$(WXLIBDIR)/libwxjpeg-2.9.a \
	$(WXLIBDIR)/libwxpng-2.9.a \
	$(WXLIBDIR)/libwxregexu-2.9.a \
	$(WXLIBDIR)/libwxtiff-2.9.a \
	$(WXLIBDIR)/libwxzlib-2.9.a

$(COMMON_WXDEP):
	@echo "Build wxWidgets"
	cd $(WXDIR) && ./configure --disable-shared --enable-monolithic --enable-unicode --with-libpng=builtin --with-libxpm=builtin --with-zlib=builtin && make -j3

$(WXLIBDIR)/libwx_gtk3u-2.9.a: $(COMMON_WXDEP)
	@echo "Build libwx_gtk3u-2.9.a"

$(WXLIBDIR)/libwxjpeg-2.9.a: $(COMMON_WXDEP)
	@echo "Build libwxjpeg-2.9.a"

$(WXLIBDIR)/libwxpng-2.9.a: $(COMMON_WXDEP)
	@echo "Build libwxpng-2.9.a"

$(WXLIBDIR)/libwxregexu-2.9.a: $(COMMON_WXDEP)
	@echo "Build libwxregexu-2.9.a"

$(WXLIBDIR)/libwxtiff-2.9.a: $(COMMON_WXDEP)
	@echo "Build libwxtiff-2.9.a"

$(WXLIBDIR)/libwxzlib-2.9.a: $(COMMON_WXDEP)
	@echo "Build libwxzlib-2.9.a"

endif

if WITH_BOOST
#It's not require any action
endif

if WITH_MYSQLCPPCON
MYSQLCONDIR = $(abs_builddir)/mysql-connector-c++
MYSQLCONLIBDIR = $(MYSQLCONDIR)/driver

BUILT_SOURCES += $(MYSQLCONLIBDIR)/libmysqlcppconn-static.a

$(MYSQLCONLIBDIR)/libmysqlcppconn-static.a:
	@echo "Build MySQL Connector C++ "
	cd $(MYSQLCONDIR) && cmake -DBOOST_ROOT=$(abs_builddir)/boost ./ && make -j3
endif

