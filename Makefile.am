AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4

SUBDIRS = \
		3rd_party \
		common \
		dbmgr \
		gui 
		
all-local: $(abs_builddir)/gui/src/udf
	cp -f $(abs_builddir)/gui/src/udf $(abs_bin)/
	
clean-local:
	$(RM) -rf $(abs_bin)/*
