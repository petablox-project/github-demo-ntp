/*  
 *  EDIT THIS FILE WITH CAUTION  (clktest-opts.h)
 *  
 *  It has been AutoGen-ed  November 17, 2009 at 06:37:09 AM by AutoGen 5.10
 *  From the definitions    clktest-opts.def
 *  and the template file   options
 *
 * Generated from AutoOpts 33:0:8 templates.
 */

/*
 *  This file was produced by an AutoOpts template.  AutoOpts is a
 *  copyrighted work.  This header file is not encumbered by AutoOpts
 *  licensing, but is provided under the licensing terms chosen by the
 *  clktest author or copyright holder.  AutoOpts is licensed under
 *  the terms of the LGPL.  The redistributable library (``libopts'') is
 *  licensed under the terms of either the LGPL or, at the users discretion,
 *  the BSD license.  See the AutoOpts and/or libopts sources for details.
 *
 * This source file is copyrighted and licensed under the following terms:
 *
 * clktest copyright (c) 1970-2009 David L. Mills and/or others - all rights reserved
 *
 * see html/copyright.html
 */
/*
 *  This file contains the programmatic interface to the Automated
 *  Options generated for the clktest program.
 *  These macros are documented in the AutoGen info file in the
 *  "AutoOpts" chapter.  Please refer to that doc for usage help.
 */
#ifndef AUTOOPTS_CLKTEST_OPTS_H_GUARD
#define AUTOOPTS_CLKTEST_OPTS_H_GUARD 1
#include "config.h"
#include <autoopts/options.h>

/*
 *  Ensure that the library used for compiling this generated header is at
 *  least as new as the version current when the header template was released
 *  (not counting patch version increments).  Also ensure that the oldest
 *  tolerable version is at least as old as what was current when the header
 *  template was released.
 */
#define AO_TEMPLATE_VERSION 135168
#if (AO_TEMPLATE_VERSION < OPTIONS_MINIMUM_VERSION) \
 || (AO_TEMPLATE_VERSION > OPTIONS_STRUCT_VERSION)
# error option template version mismatches autoopts/options.h header
  Choke Me.
#endif

/*
 *  Enumeration of each option:
 */
typedef enum {
    INDEX_OPT_SPEED       =  0,
    INDEX_OPT_DEBUG       =  1,
    INDEX_OPT_CRMOD       =  2,
    INDEX_OPT_COMMAND     =  3,
    INDEX_OPT_TIMEOUT     =  4,
    INDEX_OPT_VERSION     =  5,
    INDEX_OPT_HELP        =  6,
    INDEX_OPT_MORE_HELP   =  7,
    INDEX_OPT_SAVE_OPTS   =  8,
    INDEX_OPT_LOAD_OPTS   =  9
} teOptIndex;

#define OPTION_CT    10
#define CLKTEST_VERSION       "4.2.5p245-RC"
#define CLKTEST_FULL_VERSION  "clktest - test the clock line discipline - Ver. 4.2.5p245-RC"

/*
 *  Interface defines for all options.  Replace "n" with the UPPER_CASED
 *  option name (as in the teOptIndex enumeration above).
 *  e.g. HAVE_OPT( SPEED )
 */
#define         DESC(n) (clktestOptions.pOptDesc[INDEX_OPT_## n])
#define     HAVE_OPT(n) (! UNUSED_OPT(& DESC(n)))
#define      OPT_ARG(n) (DESC(n).optArg.argString)
#define    STATE_OPT(n) (DESC(n).fOptState & OPTST_SET_MASK)
#define    COUNT_OPT(n) (DESC(n).optOccCt)
#define    ISSEL_OPT(n) (SELECTED_OPT(&DESC(n)))
#define ISUNUSED_OPT(n) (UNUSED_OPT(& DESC(n)))
#define  ENABLED_OPT(n) (! DISABLED_OPT(& DESC(n)))
#define  STACKCT_OPT(n) (((tArgList*)(DESC(n).optCookie))->useCt)
#define STACKLST_OPT(n) (((tArgList*)(DESC(n).optCookie))->apzArgs)
#define    CLEAR_OPT(n) STMTS( \
                DESC(n).fOptState &= OPTST_PERSISTENT_MASK;   \
                if ( (DESC(n).fOptState & OPTST_INITENABLED) == 0) \
                    DESC(n).fOptState |= OPTST_DISABLED; \
                DESC(n).optCookie = NULL )

/* * * * * *
 *
 *  Globals exported from the test the clock line discipline option definitions
 */
#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/file.h>
#include <sgtty.h>

#include "../include/ntp_fp.h"
#include "../include/ntp.h"
#include "../include/ntp_unixtime.h"

#ifdef CLKLDISC
# define DEFMAGIC	'\r'
#endif

#ifdef CLKLDISC
# ifdef STREAM
#  include <stropts.h>
#  ifdef HAVE_SYS_CLKDEFS_H
#   include <sys/clkdefs.h>
#  endif
#  undef  DEFMAGIC
#  define DEFMAGIC	"\r"
# endif
#endif

/*
 *  Make sure there are no #define name conflicts with the option names
 */
#ifndef     NO_OPTION_NAME_WARNINGS
# ifdef    SPEED
#  warning undefining SPEED due to option name conflict
#  undef   SPEED
# endif
# ifdef    DEBUG
#  warning undefining DEBUG due to option name conflict
#  undef   DEBUG
# endif
# ifdef    CRMOD
#  warning undefining CRMOD due to option name conflict
#  undef   CRMOD
# endif
# ifdef    COMMAND
#  warning undefining COMMAND due to option name conflict
#  undef   COMMAND
# endif
# ifdef    TIMEOUT
#  warning undefining TIMEOUT due to option name conflict
#  undef   TIMEOUT
# endif
#else  /* NO_OPTION_NAME_WARNINGS */
# undef SPEED
# undef DEBUG
# undef CRMOD
# undef COMMAND
# undef TIMEOUT
#endif  /*  NO_OPTION_NAME_WARNINGS */

/* * * * * *
 *
 *  Interface defines for specific options.
 */
#define VALUE_OPT_SPEED          'b'
#define VALUE_OPT_DEBUG          'd'
#define VALUE_OPT_CRMOD          'f'
#define VALUE_OPT_COMMAND        's'
#define VALUE_OPT_TIMEOUT        't'

#define OPT_VALUE_TIMEOUT        (DESC(TIMEOUT).optArg.argInt)
#define VALUE_OPT_HELP          '?'
#define VALUE_OPT_MORE_HELP     '!'
#define VALUE_OPT_VERSION       INDEX_OPT_VERSION
#define VALUE_OPT_SAVE_OPTS     '>'
#define VALUE_OPT_LOAD_OPTS     '<'
#define SET_OPT_SAVE_OPTS(a)   STMTS( \
        DESC(SAVE_OPTS).fOptState &= OPTST_PERSISTENT_MASK; \
        DESC(SAVE_OPTS).fOptState |= OPTST_SET; \
        DESC(SAVE_OPTS).optArg.argString = (char const*)(a) )
/*
 *  Interface defines not associated with particular options
 */
#define ERRSKIP_OPTERR  STMTS( clktestOptions.fOptSet &= ~OPTPROC_ERRSTOP )
#define ERRSTOP_OPTERR  STMTS( clktestOptions.fOptSet |= OPTPROC_ERRSTOP )
#define RESTART_OPT(n)  STMTS( \
                clktestOptions.curOptIdx = (n); \
                clktestOptions.pzCurOpt  = NULL )
#define START_OPT       RESTART_OPT(1)
#define USAGE(c)        (*clktestOptions.pUsageProc)( &clktestOptions, c )
/* extracted from /usr/local/gnu/share/autogen/opthead.tpl near line 409 */

/* * * * * *
 *
 *  Declare the clktest option descriptor.
 */
#ifdef  __cplusplus
extern "C" {
#endif

extern tOptions   clktestOptions;

#if defined(ENABLE_NLS)
# ifndef _
#   include <stdio.h>
    static inline char* aoGetsText( char const* pz ) {
        if (pz == NULL) return NULL;
        return (char*)gettext( pz );
    }
#   define _(s)  aoGetsText(s)
# endif /* _() */

# define OPT_NO_XLAT_CFG_NAMES  STMTS(clktestOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT_CFG;)
# define OPT_NO_XLAT_OPT_NAMES  STMTS(clktestOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG;)

# define OPT_XLAT_CFG_NAMES     STMTS(clktestOptions.fOptSet &= \
                                  ~(OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG);)
# define OPT_XLAT_OPT_NAMES     STMTS(clktestOptions.fOptSet &= \
                                  ~OPTPROC_NXLAT_OPT;)

#else   /* ENABLE_NLS */
# define OPT_NO_XLAT_CFG_NAMES
# define OPT_NO_XLAT_OPT_NAMES

# define OPT_XLAT_CFG_NAMES
# define OPT_XLAT_OPT_NAMES

# ifndef _
#   define _(_s)  _s
# endif
#endif  /* ENABLE_NLS */

#ifdef  __cplusplus
}
#endif
#endif /* AUTOOPTS_CLKTEST_OPTS_H_GUARD */
/* clktest-opts.h ends here */
