AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4
DST = @TOP_SRCDIR@/bin/
BUILD = @TOP_BUILDDIR@

SUBDIRS = \
		3rd_party \
		common \
		dbmgr \
		gui 
		
all-local: $(BUILD)/gui/udf
	cp -f $(BUILD)/gui/udf $(DST)
	
clean-local:
	$(RM) -rf $(BUILD)/*
