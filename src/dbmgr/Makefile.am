
AM_CPPFLAGS = 

libdbmgrdir = $(includedir)/dbmgr/src

libdbmgr_HEADERS = \
	dbmgr.h

CSRCS = 
HSRCS = 

HSRCS += \
	$(topsrcdir)/src/dbmgr.h \
	$(topsrcdir)/src/dberrors.h \
	$(topsrcdir)/src/dbutils.h \
	$(topsrcdir)/src/dbconnection.h \
	$(topsrcdir)/src/dbtable.h \
	$(topsrcdir)/src/tcategories.h
		
CSRCS += \
	$(topsrcdir)/src/dberrors.cpp \
	$(topsrcdir)/src/dbutils.cpp \
	$(topsrcdir)/src/dbconnection.cpp \
	$(topsrcdir)/src/dbtable.cpp \
	$(topsrcdir)/src/tcategories.cpp

lib_LTLIBRARIES = \
	libdbmgr.la

libdbmgr_la_SOURCES = \
	$(HSRCS) \
	$(CSRCS) 


#EXTRA_DIST = \
#	clitest.c clitest.txt \
#	libcli.spec COPYING README Makefile

	

