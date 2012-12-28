#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/distance.o \
	${OBJECTDIR}/src/tour.o \
	${OBJECTDIR}/src/town.o \
	${OBJECTDIR}/src/util.o \
	${OBJECTDIR}/src/parsing.o \
	${OBJECTDIR}/src/bruteForce.o \
	${OBJECTDIR}/src/instance.o \
	${OBJECTDIR}/src/errors.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce \
	${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce \
	${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce \
	${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce \
	${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce \
	${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce \
	${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce

# C Compiler Flags
CFLAGS=-lm

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/main.o: src/main.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.c

${OBJECTDIR}/src/distance.o: src/distance.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/distance.o src/distance.c

${OBJECTDIR}/src/tour.o: src/tour.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/tour.o src/tour.c

${OBJECTDIR}/src/town.o: src/town.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/town.o src/town.c

${OBJECTDIR}/src/util.o: src/util.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/util.o src/util.c

${OBJECTDIR}/src/parsing.o: src/parsing.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/parsing.o src/parsing.c

${OBJECTDIR}/src/bruteForce.o: src/bruteForce.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/bruteForce.o src/bruteForce.c

${OBJECTDIR}/src/instance.o: src/instance.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/instance.o src/instance.c

${OBJECTDIR}/src/errors.o: src/errors.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/errors.o src/errors.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce: ${TESTDIR}/tests/bruteForceTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c}   -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce $^ ${LDLIBSOPTIONS} 

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce: ${TESTDIR}/tests/distanceTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c}   -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce $^ ${LDLIBSOPTIONS} 

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce: ${TESTDIR}/tests/instanceTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c}   -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce $^ ${LDLIBSOPTIONS} 

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce: ${TESTDIR}/tests/parsingTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c}   -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce $^ ${LDLIBSOPTIONS} 

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce: ${TESTDIR}/tests/tourTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c}   -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce $^ ${LDLIBSOPTIONS} 

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce: ${TESTDIR}/tests/townTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c}   -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce $^ ${LDLIBSOPTIONS} 

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce: ${TESTDIR}/tests/utilTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c}   -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/bruteForceTest.o: tests/bruteForceTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${TESTDIR}/tests/bruteForceTest.o tests/bruteForceTest.c


${TESTDIR}/tests/distanceTest.o: tests/distanceTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${TESTDIR}/tests/distanceTest.o tests/distanceTest.c


${TESTDIR}/tests/instanceTest.o: tests/instanceTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${TESTDIR}/tests/instanceTest.o tests/instanceTest.c


${TESTDIR}/tests/parsingTest.o: tests/parsingTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${TESTDIR}/tests/parsingTest.o tests/parsingTest.c


${TESTDIR}/tests/tourTest.o: tests/tourTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${TESTDIR}/tests/tourTest.o tests/tourTest.c


${TESTDIR}/tests/townTest.o: tests/townTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${TESTDIR}/tests/townTest.o tests/townTest.c


${TESTDIR}/tests/utilTest.o: tests/utilTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -MMD -MP -MF $@.d -o ${TESTDIR}/tests/utilTest.o tests/utilTest.c


${OBJECTDIR}/src/main_nomain.o: ${OBJECTDIR}/src/main.o src/main.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main_nomain.o src/main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/main_nomain.o;\
	fi

${OBJECTDIR}/src/distance_nomain.o: ${OBJECTDIR}/src/distance.o src/distance.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/distance.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/distance_nomain.o src/distance.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/distance.o ${OBJECTDIR}/src/distance_nomain.o;\
	fi

${OBJECTDIR}/src/tour_nomain.o: ${OBJECTDIR}/src/tour.o src/tour.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/tour.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/tour_nomain.o src/tour.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/tour.o ${OBJECTDIR}/src/tour_nomain.o;\
	fi

${OBJECTDIR}/src/town_nomain.o: ${OBJECTDIR}/src/town.o src/town.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/town.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/town_nomain.o src/town.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/town.o ${OBJECTDIR}/src/town_nomain.o;\
	fi

${OBJECTDIR}/src/util_nomain.o: ${OBJECTDIR}/src/util.o src/util.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/util.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/util_nomain.o src/util.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/util.o ${OBJECTDIR}/src/util_nomain.o;\
	fi

${OBJECTDIR}/src/parsing_nomain.o: ${OBJECTDIR}/src/parsing.o src/parsing.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/parsing.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/parsing_nomain.o src/parsing.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/parsing.o ${OBJECTDIR}/src/parsing_nomain.o;\
	fi

${OBJECTDIR}/src/bruteForce_nomain.o: ${OBJECTDIR}/src/bruteForce.o src/bruteForce.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/bruteForce.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/bruteForce_nomain.o src/bruteForce.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/bruteForce.o ${OBJECTDIR}/src/bruteForce_nomain.o;\
	fi

${OBJECTDIR}/src/instance_nomain.o: ${OBJECTDIR}/src/instance.o src/instance.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/instance.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/instance_nomain.o src/instance.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/instance.o ${OBJECTDIR}/src/instance_nomain.o;\
	fi

${OBJECTDIR}/src/errors_nomain.o: ${OBJECTDIR}/src/errors.o src/errors.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/errors.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -O2 -I/development/cours/L2/algo3/TP/voyageurDeCommerce/lib -std=c99 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/errors_nomain.o src/errors.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/errors.o ${OBJECTDIR}/src/errors_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce || true; \
	    ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce || true; \
	    ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce || true; \
	    ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce || true; \
	    ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce || true; \
	    ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce || true; \
	    ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/voyagecommerce

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
