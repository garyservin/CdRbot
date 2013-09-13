#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-pic18f25k50.mk)" "nbproject/Makefile-local-pic18f25k50.mk"
include nbproject/Makefile-local-pic18f25k50.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=pic18f25k50
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../hid.c ../main.c ../usb9.c ../usbctrltrf.c ../usbdrv.c ../usbdsc.c ../usbmmap.c ../BootPIC18NonJ.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/hid.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/usb9.o ${OBJECTDIR}/_ext/1472/usbctrltrf.o ${OBJECTDIR}/_ext/1472/usbdrv.o ${OBJECTDIR}/_ext/1472/usbdsc.o ${OBJECTDIR}/_ext/1472/usbmmap.o ${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/hid.o.d ${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1472/usb9.o.d ${OBJECTDIR}/_ext/1472/usbctrltrf.o.d ${OBJECTDIR}/_ext/1472/usbdrv.o.d ${OBJECTDIR}/_ext/1472/usbdsc.o.d ${OBJECTDIR}/_ext/1472/usbmmap.o.d ${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/hid.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/usb9.o ${OBJECTDIR}/_ext/1472/usbctrltrf.o ${OBJECTDIR}/_ext/1472/usbdrv.o ${OBJECTDIR}/_ext/1472/usbdsc.o ${OBJECTDIR}/_ext/1472/usbmmap.o ${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o

# Source Files
SOURCEFILES=../hid.c ../main.c ../usb9.c ../usbctrltrf.c ../usbdrv.c ../usbdsc.c ../usbmmap.c ../BootPIC18NonJ.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-pic18f25k50.mk dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F25K50
MP_PROCESSOR_OPTION_LD=18f25k50
MP_LINKER_DEBUG_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/hid.o: ../hid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/hid.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/hid.o   ../hid.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/hid.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/hid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/main.o   ../main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/usb9.o: ../usb9.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usb9.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/usb9.o   ../usb9.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usb9.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usb9.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/usbctrltrf.o: ../usbctrltrf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usbctrltrf.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/usbctrltrf.o   ../usbctrltrf.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usbctrltrf.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usbctrltrf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/usbdrv.o: ../usbdrv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usbdrv.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/usbdrv.o   ../usbdrv.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usbdrv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usbdrv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/usbdsc.o: ../usbdsc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usbdsc.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/usbdsc.o   ../usbdsc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usbdsc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usbdsc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/usbmmap.o: ../usbmmap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usbmmap.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/usbmmap.o   ../usbmmap.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usbmmap.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usbmmap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o: ../BootPIC18NonJ.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o   ../BootPIC18NonJ.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1472/hid.o: ../hid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/hid.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/hid.o   ../hid.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/hid.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/hid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/main.o   ../main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/usb9.o: ../usb9.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usb9.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/usb9.o   ../usb9.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usb9.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usb9.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/usbctrltrf.o: ../usbctrltrf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usbctrltrf.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/usbctrltrf.o   ../usbctrltrf.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usbctrltrf.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usbctrltrf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/usbdrv.o: ../usbdrv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usbdrv.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/usbdrv.o   ../usbdrv.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usbdrv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usbdrv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/usbdsc.o: ../usbdsc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usbdsc.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/usbdsc.o   ../usbdsc.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usbdsc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usbdsc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/usbmmap.o: ../usbmmap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/usbmmap.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/usbmmap.o   ../usbmmap.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/usbmmap.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/usbmmap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o: ../BootPIC18NonJ.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION)   -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o   ../BootPIC18NonJ.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BootPIC18NonJ.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../BootModified.18f45k50_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "../BootModified.18f45k50_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../BootModified.18f45k50_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "../BootModified.18f45k50_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/pic18f25k50
	${RM} -r dist/pic18f25k50

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
