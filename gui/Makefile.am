#build wxWidgets for Rel, Deb, RelWin

MODULE = gui

AM_CPPFLAGS = @UDF_WITH_CXXFLAGS@ \
			@UDF_WITH_CPPFLAGS@ \
			-I@abs_srcdir@/$(MODULE)/res \
			-I@abs_srcdir@/$(MODULE)/src \
			-I@abs_srcdir@/dbmgr/src

AM_LDFLAGS = @UDF_WITH_LDADD@

bin_PROGRAMS = udf

AM_LDFLAGS += -lwx_baseu-2.9 -lwx_gtk2u_core-2.9 -lwx_gtk2u_adv-2.9 -lwx_gtk2u_aui-2.9 -lpthread -lz

		
udf_SOURCES = \
	src/cdbmanager.cpp src/cdbmanager.h \
	src/main.cpp src/main.h \
	src/udfAccountInfo.cpp src/udfAccountInfo.h \
	src/udfCategoriesMngrDlg.cpp src/udfCategoriesMngrDlg.h \
	src/udfChampionshipCategoriesMngrDlg.cpp src/udfChampionshipCategoriesMngrDlg.h \
	src/udfChampionshipJudgesTeamMngrDlg.cpp src/udfChampionshipJudgesTeamMngrDlg.h \
	src/udfClubsMngrDlg.cpp src/udfClubsMngrDlg.h \
	src/udf.cpp src/udf.h \
	src/udfDancersMngrDlg.cpp src/udfDancersMngrDlg.h \
	src/udfDancersTeamMngr.cpp src/udfDancersTeamMngr.h \
	src/udfDirectorInfo.cpp src/udfDirectorInfo.h \
	src/udfJudgesMngr.cpp src/udfJudgesMngr.h \
	src/udfMainFrameBase.cpp src/udfMainFrameBase.h \
	src/udfStartNumberAssignDlg.cpp src/udfStartNumberAssignDlg.h \
	src/udfTarinersMngrDlg.cpp src/udfTarinersMngrDlg.h \
	src/udfTeamCategoryMngrDlg.cpp src/udfTeamCategoryMngrDlg.h \
	src/udfTeamDancersMngrDlg.cpp src/udfTeamDancersMngrDlg.h

	
	
