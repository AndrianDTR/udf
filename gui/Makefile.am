#build wxWidgets for Rel, Deb, RelWin

AM_CPPFLAGS = @UDF_WITH_CXXFLAGS@ @UDF_WITH_CPPFLAGS@

LDADD = libwx_baseu-2.9.a \
		libwx_gtk2u_core-2.9.a \
		libz.a \
		libld.a

bin_PROGRAMS = udf

udf_SOURCES = \
	src/main.cpp src/main.h
	
