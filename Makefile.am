ACLOCAL_AMFLAGS = -I m4

SUBDIRS =
DIST_SUBDIRS =
SRCDIR = $(srcdir)
BUILDDIR = $(builddir)

VERFILE = $(SRCDIR)/version.num

BUILT_SOURCES =

update-ver:
	$(SRCDIR)/update-ver.sh $(VERFILE)

all-local: update-ver

EXTRA_DIST = README.build

if WITH_UDF_3RD_PARTY
SUBDIRS += 3rd_party
endif

if WITH_UDF_FEATURETEST
SUBDIRS += test
endif

SUBDIRS += src tools

DIST_SUBDIRS += $(SUBDIRS)


