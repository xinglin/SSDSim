/*
 * DiskSim Storage Subsystem Simulation Environment (Version 4.0)
 * Revision Authors: John Bucy, Greg Ganger
 * Contributors: John Griffin, Jiri Schindler, Steve Schlosser
 *
 * Copyright (c) of Carnegie Mellon University, 2001-2008.
 *
 * This software is being provided by the copyright holders under the
 * following license. By obtaining, using and/or copying this software,
 * you agree that you have read, understood, and will comply with the
 * following terms and conditions:
 *
 * Permission to reproduce, use, and prepare derivative works of this
 * software is granted provided the copyright and "No Warranty" statements
 * are included with all reproductions and derivative works and associated
 * documentation. This software may also be redistributed without charge
 * provided that the copyright and "No Warranty" statements are included
 * in all redistributions.
 *
 * NO WARRANTY. THIS SOFTWARE IS FURNISHED ON AN "AS IS" BASIS.
 * CARNEGIE MELLON UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER
 * EXPRESSED OR IMPLIED AS TO THE MATTER INCLUDING, BUT NOT LIMITED
 * TO: WARRANTY OF FITNESS FOR PURPOSE OR MERCHANTABILITY, EXCLUSIVITY
 * OF RESULTS OR RESULTS OBTAINED FROM USE OF THIS SOFTWARE. CARNEGIE
 * MELLON UNIVERSITY DOES NOT MAKE ANY WARRANTY OF ANY KIND WITH RESPECT
 * TO FREEDOM FROM PATENT, TRADEMARK, OR COPYRIGHT INFRINGEMENT.
 * COPYRIGHT HOLDERS WILL BEAR NO LIABILITY FOR ANY USE OF THIS SOFTWARE
 * OR DOCUMENTATION.
 *
 */



/*
 * DiskSim Storage Subsystem Simulation Environment (Version 2.0)
 * Revision Authors: Greg Ganger
 * Contributors: Ross Cohen, John Griffin, Steve Schlosser
 *
 * Copyright (c) of Carnegie Mellon University, 1999.
 *
 * Permission to reproduce, use, and prepare derivative works of
 * this software for internal use is granted provided the copyright
 * and "No Warranty" statements are included with all reproductions
 * and derivative works. This software may also be redistributed
 * without charge provided that the copyright and "No Warranty"
 * statements are included in all redistributions.
 *
 * NO WARRANTY. THIS SOFTWARE IS FURNISHED ON AN "AS IS" BASIS.
 * CARNEGIE MELLON UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER
 * EXPRESSED OR IMPLIED AS TO THE MATTER INCLUDING, BUT NOT LIMITED
 * TO: WARRANTY OF FITNESS FOR PURPOSE OR MERCHANTABILITY, EXCLUSIVITY
 * OF RESULTS OR RESULTS OBTAINED FROM USE OF THIS SOFTWARE. CARNEGIE
 * MELLON UNIVERSITY DOES NOT MAKE ANY WARRANTY OF ANY KIND WITH RESPECT
 * TO FREEDOM FROM PATENT, TRADEMARK, OR COPYRIGHT INFRINGEMENT.
 */

/*
 * DiskSim Storage Subsystem Simulation Environment
 * Authors: Greg Ganger, Bruce Worthington, Yale Patt
 *
 * Copyright (C) 1993, 1995, 1997 The Regents of the University of Michigan 
 *
 * This software is being provided by the copyright holders under the
 * following license. By obtaining, using and/or copying this software,
 * you agree that you have read, understood, and will comply with the
 * following terms and conditions:
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose and without fee or royalty is
 * hereby granted, provided that the full text of this NOTICE appears on
 * ALL copies of the software and documentation or portions thereof,
 * including modifications, that you make.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS," AND COPYRIGHT HOLDERS MAKE NO
 * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED. BY WAY OF EXAMPLE,
 * BUT NOT LIMITATION, COPYRIGHT HOLDERS MAKE NO REPRESENTATIONS OR
 * WARRANTIES OF MERCHANTABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE OR
 * THAT THE USE OF THE SOFTWARE OR DOCUMENTATION WILL NOT INFRINGE ANY
 * THIRD PARTY PATENTS, COPYRIGHTS, TRADEMARKS OR OTHER RIGHTS. COPYRIGHT
 * HOLDERS WILL BEAR NO LIABILITY FOR ANY USE OF THIS SOFTWARE OR
 * DOCUMENTATION.
 *
 *  This software is provided AS IS, WITHOUT REPRESENTATION FROM THE
 * UNIVERSITY OF MICHIGAN AS TO ITS FITNESS FOR ANY PURPOSE, AND
 * WITHOUT WARRANTY BY THE UNIVERSITY OF MICHIGAN OF ANY KIND, EITHER
 * EXPRESSED OR IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE REGENTS
 * OF THE UNIVERSITY OF MICHIGAN SHALL NOT BE LIABLE FOR ANY DAMAGES,
 * INCLUDING SPECIAL , INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES,
 * WITH RESPECT TO ANY CLAIM ARISING OUT OF OR IN CONNECTION WITH THE
 * USE OF OR IN CONNECTION WITH THE USE OF THE SOFTWARE, EVEN IF IT HAS
 * BEEN OR IS HEREAFTER ADVISED OF THE POSSIBILITY OF SUCH DAMAGES
 *
 * The names and trademarks of copyright holders or authors may NOT be
 * used in advertising or publicity pertaining to the software without
 * specific, written prior permission. Title to copyright in this software
 * and any associated documentation will at all times remain with copyright
 * holders.
 */

#ifndef DISKSIM_ASSERTLIB_H
#define DISKSIM_ASSERTLIB_H

#include <assert.h>

#ifndef ASSERTS

#define ASSERT(cond)
#define ASSERT1(cond,S1,V1)
#define ASSERT1D(cond,S1,V1)
#define ASSERT2(cond,S1,V1,S2,V2)
#define ASSERT2p(cond,S1,V1,S2,V2)

#else /* ASSERTS */

#define ASSERT(cond)                                  \
  if (!(cond)) {                                      \
    fprintf(stderr, "\nAssertion failed:\n");         \
    fprintf(stderr, "simtime\t = %f\n", simtime);    \
    fprintf(stderr, "totalreqs\t = %d\n", disksim->totalreqs); \
  }                                                   \
  assert(cond);

#define ASSERT1(cond,S1,V1)                           \
  if (!(cond)) {                                      \
    fprintf(stderr, "\nAssertion failed:\n");         \
    fprintf(stderr, "simtime\t = %f\n", simtime);    \
    fprintf(stderr, "totalreqs\t = %d\n", disksim->totalreqs); \
    fprintf(stderr, "%s\t = %d\n",(S1),(V1));         \
  }                                                   \
  assert(cond);

#define ASSERT1D(cond,S1,V1)                          \
  if (!(cond)) {                                      \
    fprintf(stderr, "\nAssertion failed:\n");         \
    fprintf(stderr, "simtime\t = %f\n", simtime);    \
    fprintf(stderr, "totalreqs\t = %d\n", disksim->totalreqs); \
    fprintf(stderr, "%s\t = %f\n",(S1),(V1));        \
  }                                                   \
  assert(cond);

#define ASSERT2(cond,S1,V1,S2,V2)                     \
  if (!(cond)) {                                      \
    fprintf(stderr, "\nAssertion failed:\n");         \
    fprintf(stderr, "simtime\t = %f\n", simtime);    \
    fprintf(stderr, "totalreqs\t = %d\n", disksim->totalreqs); \
    fprintf(stderr, "%s\t = %d\n",(S1),(V1));         \
    fprintf(stderr, "%s\t = %d\n",(S2),(V2));         \
  }                                                   \
  assert(cond);

#define ASSERT2p(cond,S1,V1,S2,V2)                     \
  if (!(cond)) {                                      \
    fprintf(stderr, "\nAssertion failed:\n");         \
    fprintf(stderr, "simtime\t = %f\n", simtime);    \
    fprintf(stderr, "totalreqs\t = %d\n", disksim->totalreqs); \
    fprintf(stderr, "%s\t = %p\n",(S1),(V1));         \
    fprintf(stderr, "%s\t = %p\n",(S2),(V2));         \
  }                                                   \
  assert(cond);

#endif /* ASSERTS */

#endif /* DISKSIM_ASSERTLIB_H */

