
/* diskmodel (version 1.0)
 * Authors: John Bucy, Greg Ganger
 * Contributors: John Griffin, Jiri Schindler, Steve Schlosser
 *
 * Copyright (c) of Carnegie Mellon University, 2001-2008.
 *
 * This software is being provided by the copyright holders under the
 * following license. By obtaining, using and/or copying this
 * software, you agree that you have read, understood, and will comply
 * with the following terms and conditions:
 *
 * Permission to reproduce, use, and prepare derivative works of this
 * software is granted provided the copyright and "No Warranty"
 * statements are included with all reproductions and derivative works
 * and associated documentation. This software may also be
 * redistributed without charge provided that the copyright and "No
 * Warranty" statements are included in all redistributions.
 *
 * NO WARRANTY. THIS SOFTWARE IS FURNISHED ON AN "AS IS" BASIS.
 * CARNEGIE MELLON UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER
 * EXPRESSED OR IMPLIED AS TO THE MATTER INCLUDING, BUT NOT LIMITED
 * TO: WARRANTY OF FITNESS FOR PURPOSE OR MERCHANTABILITY, EXCLUSIVITY
 * OF RESULTS OR RESULTS OBTAINED FROM USE OF THIS SOFTWARE. CARNEGIE
 * MELLON UNIVERSITY DOES NOT MAKE ANY WARRANTY OF ANY KIND WITH
 * RESPECT TO FREEDOM FROM PATENT, TRADEMARK, OR COPYRIGHT
 * INFRINGEMENT.  COPYRIGHT HOLDERS WILL BEAR NO LIABILITY FOR ANY USE
 * OF THIS SOFTWARE OR DOCUMENTATION.  
 */


#ifndef _DM_TYPES_H
#define _DM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif 


// this ought to work and I can't figure out why it doesn't
#ifdef _DISKMODEL_FREEBSD // || defined _BSD_SOURCE
#include <sys/types.h>
#else
#ifdef WIN32
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int16 uint16_t;
#else /* WIN32 */
#include <inttypes.h>
#endif /* WIN32 */
#endif

// fraction of a circle
// each increment ends up being \pi / 2^32 radians
typedef uint32_t dm_angle_t;

// denominator of angles
#define DM_ANGLE_DENOM ((dm_angle_t)-1)

// how far to shift when dividing, etc
#define DM_ANGLE_EXP 32

#define DM_TIME_EXP 40
#define DM_TIME_PSEC ((dm_time_t)1)      // pico
#define DM_TIME_NSEC (1000 * DM_TIME_PSEC)    // nano 
#define DM_TIME_USEC (1000 * DM_TIME_NSEC)    // micro
#define DM_TIME_MSEC (1000 * DM_TIME_USEC)    // milli
#define DM_TIME_SEC (1000 * DM_TIME_MSEC)

// in picoseconds
typedef int64_t dm_time_t;

typedef uint64_t dm_pbn_t;


#ifdef __cplusplus
}
#endif 


#endif  // _DM_TYPES_H
