ACLOCAL_AMFLAGS = -I m4

SUBDIRS =
DIST_SUBDIRS =

EXTRA_DIST = README README.build

if WITH_UDF_3RD_PARTY
SUBDIRS += 3rd_party
endif

if WITH_UDF_FEATURETEST
SUBDIRS += test
endif

SUBDIRS += src tools

#if ENABLE_DOXYGEN
#SUBDIRS += doc
#else
#DIST_SUBDIRS += doc
#endif

DIST_SUBDIRS += $(SUBDIRS)

## Code Coverage
#if ENABLE_GCOV
#TOPSRCDIR = $(abs_top_srcdir)
#TOPOBJDIR = $(abs_top_builddir)
#
#LCOV_INFO    = $(TOPOBJDIR)/switchpp.info
#LCOV_OUTPUT  = $(TOPOBJDIR)/lcov.coverage
#LCOV_LCOV    = @LCOV@
#LCOV_GENHTML = @GENHTML@
#LCOV_INTERM_INFO =

#cov:
#if WITH_ONS_SWITCHPP
#	$(LCOV_LCOV) --directory $(TOPOBJDIR)/src/switchpp --capture --output-file $(LCOV_INFO)s0 --test-name SWITCHPP_LCOV
#	$(LCOV_LCOV) --remove $(LCOV_INFO)s0 "*/src/switchpp/src/infra/*" -o $(LCOV_INFO)s
#LCOV_INTERM_INFO += -a $(LCOV_INFO)s
#endif
#	$(LCOV_LCOV) $(LCOV_INTERM_INFO) -o $(LCOV_INFO)raw
#	python $(TOPSRCDIR)/tools/covpp.py -v -o $(LCOV_INFO) $(LCOV_INFO)raw
#
#	$(LCOV_GENHTML) --output-directory $(LCOV_OUTPUT) --title "SWITCHPP Code Coverage" --show-details $(LCOV_INFO)
#	@echo "========================================================================="
#	@echo "Open in a web browser: $(LCOV_OUTPUT)/index.html to see coverage results."
#	@echo "========================================================================="
#
#cov-clean:
#	$(RM) -r $(LCOV_OUTPUT)
#	$(RM) -r $(LCOV_INFO)*
#	$(LCOV_LCOV) --directory $(TOPOBJDIR) --zerocounters
#
#endif # ENABLE_GCOV

