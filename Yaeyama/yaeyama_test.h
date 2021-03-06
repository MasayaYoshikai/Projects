/*
** svn $Id$
*******************************************************************************
** Copyright (c) 2002-2015 The ROMS/TOMS Group                               **
**   Licensed under a MIT/X style license                                    **
**   See License_ROMS.txt                                                    **
*******************************************************************************
**
** Options for Lake Jersey forced with wind and various nested grids.  This
** is an idealized lake with several nested grids: bottom-left refined grid
** (1:3 ratio), top-righ refined grid (1:3 ratio).   The coare grid has a
** 500m resolution.
**
** Application flag: LAKE_JERSEY
**
** Input scripts:    ocean_lake_jersey_nested2_bot.in    coarse & bottom-left
**                   ocean_lake_jersey_nested2_top.in    coarse & top-right
**                   ocean_lake_jersey_nested3.in        coarse & bottom & top
*/

#define UV_ADV
#define UV_COR
#define DJ_GRADPS
#define NONLIN_EOS
#define SALINITY
#define SOLVE3D
#define MASKING
#define WET_DRY

#define ANA_BPFLUX
#define ANA_BTFLUX
#define ANA_BSFLUX
#define ANA_SPFLUX


#define SOLAR_SOURCE

#define BULK_FLUXES
#ifdef BULK_FLUXES
# define LONGWAVE
# define EMINUSP
/*# define ANA_CLOUD*/
/*# define ANA_HUMID*/
/*# define ANA_PAIR*/
/*# define ANA_TAIR*/
/*# define ANA_RAIN*/
/*# define ANA_WINDS*/
# define ANA_SRFLUX
# ifdef ANA_SRFLUX
#  define DIURNAL_SRFLUX
# endif
#else
# define ANA_SMFLUX
# define ANA_STFLUX
#endif

/* Bottom boundary layer options */

#ifdef SG_BBL
# define SG_CALC_ZNOT
# undef  SG_LOGINT
#endif
#ifdef MB_BBL
# define MB_CALC_ZNOT
# undef  MB_Z0BIO
# undef  MB_Z0BL
# undef  MB_Z0RIP
#endif
#ifdef SSW_BBL
# define SSW_CALC_UB
# define SSW_CALC_ZNOT
# undef  SSW_LOGINT
#endif

#if defined MB_BBL || defined SG_BBL || defined SSW_BBL
# define ANA_WWAVE
#endif

#ifdef SEDIMENT
# define SUSPLOAD
# define BEDLOAD_SOULSBY
# undef  SED_MORPH
#endif
#if defined SEDIMENT || defined SG_BBL || defined MB_BBL || defined SSW_BBL
# define ANA_SEDIMENT
#endif

