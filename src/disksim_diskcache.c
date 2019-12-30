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

#include "disksim_global.h"
#include "disksim_iosim.h"
#include "disksim_stat.h"
#include "disksim_disk.h"


/* This variable is now in the diskinfo structure, but the real question */
/* is why it exists at all...                                            */
//int LRU_at_seg_list_head = 0;


#if 0
static int disk_buffer_segment_wrap_needed (segment *seg, int endblkno)
{
   return(seg->startblkno < (endblkno - seg->size));
}
#endif


void disk_buffer_segment_wrap (segment *seg, int endblkno)
{
   seg->startblkno = max(seg->startblkno, (endblkno - seg->size));
}


/* Determines whether the iorequest passed in overlaps in any way with the given
 * segment in the cache -rcohen
 */

int disk_buffer_overlap (segment *seg, ioreq_event *curr)
{
   int tmp;

   if ((curr->blkno >= seg->startblkno) && (curr->blkno < seg->endblkno)) {
      return(TRUE);
   }

   tmp = curr->blkno + curr->bcount;
   if ((tmp > seg->startblkno) && (tmp <= seg->endblkno)) {
      return(TRUE);
   }

   if ((curr->blkno <= seg->startblkno) && (tmp >= seg->endblkno)) {
      return(TRUE);
   }

   return(FALSE);
}


void disk_buffer_remove_from_seg (diskreq *currdiskreq)
{
   segment *seg = currdiskreq->seg;

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "%12.6f  %8p  Entering disk_buffer_remove_from_seg\n",simtime,currdiskreq);
fflush(outputfile);
}

   ASSERT(seg != NULL);

   if (seg->diskreqlist == currdiskreq) {
      seg->diskreqlist = currdiskreq->seg_next;
   } else {
      diskreq *tmpdiskreq = seg->diskreqlist;

      while (tmpdiskreq) {
	 if (tmpdiskreq->seg_next == currdiskreq) {
	    tmpdiskreq->seg_next = currdiskreq->seg_next;
	    break;
	 }
	 tmpdiskreq = tmpdiskreq->seg_next;
      }
      ASSERT(tmpdiskreq != NULL);
   }
   currdiskreq->seg = NULL;

   ASSERT1((seg->diskreqlist || seg->state != BUFFER_DIRTY),"seg->state",seg->state);
}


/* return real or effective owner of segment or NULL.  For effective, a 
   READ segment OWNER may be overridden by a READ with an outblkno that 
   is less than the (effective) OWNER's outblkno
*/

diskreq* disk_buffer_seg_owner (segment *seg, int effective)
{
   diskreq *seg_owner = seg->diskreqlist;
   diskreq *tmpdiskreq = seg->diskreqlist;

   while (seg_owner) {
      if (seg_owner->flags & SEG_OWNED) {
	 break;
      }
      seg_owner = seg_owner->seg_next;
   }

   if (effective && seg->access && (seg->access->flags & READ)) {
      while (tmpdiskreq) {
	 if ((seg->recyclereq != tmpdiskreq) &&
	     (!tmpdiskreq->ioreqlist || 
	      (tmpdiskreq->ioreqlist->flags & READ))) {
	    if (!seg_owner || tmpdiskreq->outblkno < seg_owner->outblkno) {
	       seg_owner = tmpdiskreq;
/*
	       fprintf(stderr,"%.6f  effective seg_owner found\n",simtime);fflush(stderr);
*/
	    }
	 }
	 tmpdiskreq = tmpdiskreq->seg_next;
      }
   }

   return(seg_owner);
}


/* A recyclable/reusable segment has a single diskreq.  That diskreq must be a 
   read which has all of its remaining data in the segment or a write which 
   only needs to send completion up the line.
*/

int disk_buffer_reusable_segment_check (disk *currdisk, segment *currseg)
{
   diskreq *currdiskreq = currseg->diskreqlist;
   ioreq_event *currioreq;

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "%12.6f            Entering disk_buffer_reusable_segment_check\n",simtime);
fflush(outputfile);
}

   if (currdisk->acctime < 0.0 && !currseg->recyclereq && currdiskreq && 
       !currdiskreq->seg_next && currdiskreq->ioreqlist && 
       !(currdiskreq->flags & COMPLETION_RECEIVED)) {
      if (currdiskreq->ioreqlist->flags & READ) {
         currioreq = currdiskreq->ioreqlist;
         while (currioreq->next) {
            currioreq = currioreq->next;
         }
         if ((currdiskreq->outblkno >= currseg->startblkno) &&
             (currdiskreq->outblkno <  currseg->endblkno) &&
             ((currioreq->blkno + currioreq->bcount) > currseg->startblkno) &&
             ((currioreq->blkno + currioreq->bcount) <= currseg->endblkno)) {
            if (!(currdiskreq->flags & SEG_OWNED)) {
               disk_buffer_attempt_seg_ownership(currdisk,currdiskreq);
            }

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "                        segment %8p is reusable\n",currseg);
fflush(outputfile);
}

            return(TRUE);
         }
      } else {			/* WRITE */
         currioreq = currdiskreq->ioreqlist;
         while (currioreq->next) {
            currioreq = currioreq->next;
         }
         if (currdiskreq->inblkno >= (currioreq->blkno + currioreq->bcount)) {
            if (!(currdiskreq->flags & SEG_OWNED)) {
               disk_buffer_attempt_seg_ownership(currdisk,currdiskreq);
            }

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "                        segment %8p is reusable\n",currseg);
fflush(outputfile);
}

            return(TRUE);
         }
      }
   }

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "                        segment %8p is NOT reusable\n",currseg);
fflush(outputfile);
}

   return(FALSE);
}


static int disk_buffer_recyclable_segment_check (disk *currdisk, segment *currseg, int isread)
{
   diskreq *currdiskreq = currseg->diskreqlist;
   ioreq_event *currioreq;

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "%12.6f            Entering disk_buffer_recyclable_segment_check\n",simtime);
fflush(outputfile);
}

   if (currdisk->acctime < 0.0 && !currseg->recyclereq && currdiskreq && 
       !currdiskreq->seg_next && currdiskreq->ioreqlist && 
       !(currdiskreq->flags & COMPLETION_RECEIVED)) {
      if (currdiskreq->ioreqlist->flags & READ) {
         if (isread || 
	     (!currdisk->dedicatedwriteseg && 
	      (currdisk->numdirty < currdisk->numwritesegs))) {
            currioreq = currdiskreq->ioreqlist;
            while (currioreq->next) {
               currioreq = currioreq->next;
            }
            if ((currdiskreq->outblkno >= currseg->startblkno) &&
                (currdiskreq->outblkno <  currseg->endblkno) &&
                ((currioreq->blkno + currioreq->bcount) > currseg->startblkno) &&
                ((currioreq->blkno + currioreq->bcount) <= currseg->endblkno)) {
               if (!(currdiskreq->flags & SEG_OWNED)) {
                  disk_buffer_attempt_seg_ownership(currdisk,currdiskreq);
               }

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "                        segment %8p is recyclable\n",currseg);
fflush(outputfile);
}

               return(TRUE);
	    }
         }
      } else {			/* WRITE */
	 if (!isread || !currdisk->dedicatedwriteseg) {
            currioreq = currdiskreq->ioreqlist;
	    while (currioreq->next) {
	       currioreq = currioreq->next;
	    }
	    if (currdiskreq->inblkno >= (currioreq->blkno + currioreq->bcount)) {
               if (!(currdiskreq->flags & SEG_OWNED)) {
	          disk_buffer_attempt_seg_ownership(currdisk,currdiskreq);
	       }

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "                        segment %8p is recyclable\n",currseg);
fflush(outputfile);
}

               return(TRUE);
	    }
	 }
      }
   }

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "                        segment %8p is NOT recyclable\n",currseg);
fflush(outputfile);
}

   return(FALSE);
}


segment* disk_buffer_recyclable_segment (disk *currdisk, int isread)
{
   segment *currseg = currdisk->seglist;

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "%12.6f            Entering disk_buffer_recyclable_segment\n",simtime);
fprintf (outputfile, "                        numdirty = %d\n", currdisk->numdirty);
fflush(outputfile);
}

   if (currdisk->acctime >= 0.0) {
      return(NULL);
   }

   while (currseg) {
      if (disk_buffer_recyclable_segment_check(currdisk, currseg, isread)) {

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "                        recyclable segment found\n");
fflush(outputfile);
}

	 return(currseg);
      }
      currseg = currseg->next;
   }


if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf(outputfile, "                        No recyclable segment found\n");
fflush(outputfile);
}

   return(NULL);
}


/* if BUFFER_READING, checks to see if cache can and should "fit in" blkno.
   if BUFFER_WRITING, checks to see if blkno is in the cache and can be
     written to media.
*/

int disk_buffer_block_available (disk *currdisk, segment *seg, int blkno)
{
   diskreq *seg_owner;

   if (blkno < 0) {
      return(FALSE);
   }
   if (seg->state == BUFFER_READING) {
      if ((blkno < seg->endblkno) && (blkno >= seg->startblkno)) {
	 return(FALSE);
      }
      if ((blkno < seg->startblkno) && 
	  ((!currdisk->readanyfreeblocks) ||
	   (seg->endblkno != seg->startblkno))) {
         return(FALSE);
      }
      seg_owner = disk_buffer_seg_owner(seg,TRUE);
      if (seg_owner && !(seg_owner->flags & COMPLETION_SENT) && 
	  ((blkno - seg_owner->outblkno) >= seg->size)) {
         return(FALSE);
      }
   } else if (seg->state == BUFFER_WRITING) {
      if ((blkno < currdisk->effectivehda->inblkno) || 
	  (blkno >= seg->endblkno)) {
	 return(FALSE);
      }
      if ((currdisk->effectivehda->ioreqlist) && 
	  (currdisk->extra_write_disconnect)) {
	 if (currdisk->effectivehda->ioreqlist->bcount < 45) {
	    if ((seg->endblkno - seg->startblkno) < 
		min(currdisk->effectivehda->ioreqlist->bcount, 10)) {
	       return(FALSE);
	    }
	 } else {
	    if ((seg->endblkno - seg->startblkno) < 15) {
	       return(FALSE);
	    }
	 }
      }
   } else {
      fprintf(stderr, "Not actively using disk at disk_buffer_block_available\n");
      exit(1);
   }
   return(TRUE);
}


/* This function may be out of date.  Goal is/was to assist in understanding */
/* how sequentiality/locality is affected by disk array data organizations   */
/* and disk striping in particular. */

void disk_interferestats (disk *currdisk, ioreq_event *curr)
{
   if (!device_printinterferestats) {
      return;
   }

   if ((curr->cause != currdisk->lastgen) && (curr->flags & (SEQ|LOCAL))) {
      if (curr->flags & SEQ) {
         currdisk->stat.interfere[0]++;
      } else {
         currdisk->stat.interfere[1]++;
      }
   }
   currdisk->lastgen = curr->cause;
}


static void disk_buffer_stats (disk *currdisk, ioreq_event *curr, segment *seg, int hittype)
{
   double size;

   if (!device_printbufferstats) {
      return;
   }

   /* Add stats for read hits on write data? */

   switch (hittype) {

      case BUFFER_NOMATCH:
         if (curr->flags & READ) {
            currdisk->stat.readmisses++;
         } else {
            currdisk->stat.writemisses++;
         }
         break;

      case BUFFER_WHOLE:
         currdisk->stat.fullreadhits++;
	 break;

      case BUFFER_APPEND:
         currdisk->stat.appendhits++;
	 break;

      case BUFFER_PREPEND:
         currdisk->stat.prependhits++;
	 break;

      case BUFFER_PARTIAL:
         if (seg->startblkno <= curr->blkno) {
            size = (double) (seg->endblkno - curr->blkno);
         } else {
/*
            size = (double) (curr->blkno + curr->bcount - seg->startblkno);
*/
            fprintf(stderr, "Tail hits not currently allowed.\n");
            exit(1);
         }
         if (seg->state == BUFFER_READING) {
/*
      fprintf (outputfile, "Ongoing hit: blkno %d  bcount %d  segstart %d  segstop %d  read %d\n", curr->blkno, curr->bcount, seg->startblkno, seg->endblkno, seg->access->type);
*/
            currdisk->stat.readinghits++;
            currdisk->stat.runreadingsize += size;
            currdisk->stat.remreadingsize += curr->bcount - size;
         } else {
/*
      fprintf (outputfile, "Partial hit: blkno %d  bcount %d  segstart %d  segstop %d  read %d\n", curr->blkno, curr->bcount, seg->startblkno, seg->endblkno, ((curr->flags & READ) && (seg->state == BUFFER_CLEAN)));
*/
            currdisk->stat.parthits++;
            currdisk->stat.runpartsize += size;
            currdisk->stat.rempartsize += curr->bcount - size;
         }
         break;

      default:
	 fprintf(stderr, "Invalid hittype in disk_buffer_stats - blkno %d, bcount %d, state %d\n", curr->blkno, curr->bcount, seg->state);
         exit(1);
   }
   return;
}


/* segment selection priority for read requests:
   11   BUFFER_WHOLE,   BUFFER_DIRTY   (write data is freshest, less chance of 
                                        data scrolling off the segment quickly)
   10                   BUFFER_WRITING (write data is freshest)
   9                    BUFFER_READING (possible prefetch-stream hit)
   8                    BUFFER_CLEAN
   7    BUFFER_PARTIAL, BUFFER_DIRTY   (write data is freshest)
   6                    BUFFER_WRITING (write data is freshest)
   5                    BUFFER_READING (possible prefetch-stream hit, includes
					case of current prefetch block is first
					block in the new request)
   4                    BUFFER_CLEAN
   3    BUFFER_NOMATCH, BUFFER_EMPTY   (doesn't trash other data)
   2                    BUFFER_CLEAN
   1	        	BUFFER_READING (must be last place for preempt check)
   
      not usable:
        BUFFER_NOMATCH, BUFFER_DIRTY
                        BUFFER_WRITING
			BUFFER_CLEAN   (if pending requests)
                        BUFFER_READING (if not pre-emptable or pending requests)
	recycled segs
        dedicatedwriteseg

      not usable if !enablecache
	BUFFER_DIRTY
	BUFFER_WRITING
	BUFFER_READING (if non-stoppable)

      not usable if no read hits on write data:
	BUFFER_WHOLE,   BUFFER_DIRTY
		        BUFFER_WRITING
		        BUFFER_CLEAN (if previous request was a write)
	BUFFER_PARTIAL, BUFFER_DIRTY
		        BUFFER_WRITING
		        BUFFER_CLEAN (if previous request was a write)

      NO seg usable if overlapping dirty data exists which cannot be "hit"
	-- return BUFFER_COLLISION hittype if seg in question is not "reusable".

      NO seg usable if two segments are found with overlapping dirty data
	-- return BUFFER_COLLISION hittype.
*/

/* this routine sets currdiskreq->seg and currdiskreq->hittype */
/* as per above table, it finds the best segment in the cache matching this
 * request. If it doesn't find one, it sets seg to NULL and hittype to
 * BUFFER_NOMATCH */

static segment * 
disk_buffer_select_read_segment(disk *currdisk, diskreq *currdiskreq)
{
   segment *seg;
   ioreq_event *first_ioreq = currdiskreq->ioreqlist;
   ioreq_event *tmpioreq;
   int best_value = 0;
   int curr_value;
   int curr_hittype = 0; 

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "%12.6f  %8p  Entering disk_buffer_select_read_segment\n",simtime,currdiskreq);
fflush(outputfile);
}

   currdiskreq->seg = NULL;
   currdiskreq->hittype = BUFFER_NOMATCH;
   seg = currdisk->seglist;
   while (seg) {
      curr_value = -1;
      if (currdiskreq->hittype == BUFFER_COLLISION) { } 
      else if (seg->recyclereq) { } 
      else if ((currdisk->dedicatedwriteseg) 
	       && (seg == currdisk->dedicatedwriteseg)) 
           {
	     /* check for collision with dirty data */
	     if ((seg->state == BUFFER_DIRTY) 
		 || (seg->state == BUFFER_WRITING)) 
	     {
	       tmpioreq = currdiskreq->ioreqlist;
	       while (tmpioreq) {
		 if (disk_buffer_overlap(seg,tmpioreq)) {
		   if (!disk_buffer_reusable_segment_check(currdisk, seg)) {
		     currdiskreq->hittype = BUFFER_COLLISION;
		     currdiskreq->seg = NULL;
		   }
		   break;
		 }
		 tmpioreq = tmpioreq->next;
	       }
	     }
	   } 
      else if (seg->state == BUFFER_EMPTY) {
	curr_value = 3;
	curr_hittype = BUFFER_NOMATCH;
      } 
      else if ((first_ioreq->blkno < seg->startblkno) 
	       || (first_ioreq->blkno >= seg->endblkno)) 
      {
	curr_hittype = BUFFER_NOMATCH;
	if ((seg->state == BUFFER_CLEAN) && !(seg->diskreqlist)) {
	  curr_value = 2;
	} 
	else if (seg->state == BUFFER_READING) {
	  if ((seg->endblkno == first_ioreq->blkno) && 
	      currdisk->almostreadhits) {
	    /* special case: block currently being prefetched is the
	     * first block of this request.  We count this as a
	     * partial read hit.  
	     */
	    curr_hittype = BUFFER_PARTIAL;
	    curr_value = 5;
	  } 
	  else {
	    if (!seg->diskreqlist->ioreqlist) {
	      curr_value = 1;
	    }
	  }
	} 
	else if ((first_ioreq->blkno < seg->startblkno) 
		 && ((seg->state == BUFFER_DIRTY) 
		     || (seg->state == BUFFER_WRITING))) 
	{
	  /* check for collision with dirty data */
	  tmpioreq = currdiskreq->ioreqlist;
	  while (tmpioreq) {
	    if (disk_buffer_overlap(seg,tmpioreq)) {
	      if (!disk_buffer_reusable_segment_check(currdisk, seg)) {
		currdiskreq->hittype = BUFFER_COLLISION;
		currdiskreq->seg = NULL;
	      }
	      break;
	    }
	    tmpioreq = tmpioreq->next;
	  }
	}
      } 
      else {
	switch (seg->state) {
	case BUFFER_DIRTY:
	  if (currdisk->enablecache) {
	    if ((currdisk->readhitsonwritedata) 
		&& (best_value < 10)) {
	      curr_value = 11;
	    } 
	    else {
	      if (!disk_buffer_reusable_segment_check(currdisk, seg)) {
		currdiskreq->hittype = BUFFER_COLLISION;
		currdiskreq->seg = NULL;
	      }
	    }
	  }
	  break;
	case BUFFER_WRITING:
	  if (currdisk->enablecache) {
	    if ((currdisk->readhitsonwritedata) 
		&& (best_value < 10)) 
            {
	      curr_value = 10;
	    } 
	    else {
	      if (!disk_buffer_reusable_segment_check(currdisk, seg)) {
		currdiskreq->hittype = BUFFER_COLLISION;
		currdiskreq->seg = NULL;
	      }
	    }
	  }
	  break;
	case BUFFER_READING:
	  if (currdisk->enablecache) {
	    curr_value = 9;
	  }
	  break;
	case BUFFER_CLEAN:
	  if (currdisk->readhitsonwritedata 
	      || (seg->access && (seg->access->flags & READ))) 
	  {
	    curr_value = 8;
	  }
	  break;

	 default:
	   ddbg_assert(0);
	}

	if (seg->endblkno >= (first_ioreq->blkno + first_ioreq->bcount)) {
	  curr_hittype = BUFFER_WHOLE;
	} 
	else {
	  curr_hittype = BUFFER_PARTIAL;
	  curr_value -= 4;
	}
      }

      if (curr_value > best_value) {
	 currdiskreq->seg = seg;
	 currdiskreq->hittype = curr_hittype;
	 best_value = curr_value;
      }
      seg = seg->next;
   }

   /* If BUFFER_NOMATCH && BUFFER_READING, perform preemption check.
    * Note that currdiskreq->seg should be set before the call.  
    */

   if ((best_value == 1) 
       && !disk_buffer_stopable_access(currdisk,currdiskreq)) 
   {
     currdiskreq->seg = NULL;
   }
   
if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "                        segment = %8p, hittype = %d\n",currdiskreq->seg,currdiskreq->hittype);
fflush(outputfile);
}

 return currdiskreq->seg;
}


/* segment selection priority for write requests:
   7    BUFFER_APPEND,  BUFFER_WRITING (keep the stream going)
   6                    BUFFER_DIRTY
   5    BUFFER_PREPEND, BUFFER_DIRTY
   4    BUFFER_NOMATCH, BUFFER_CLEAN, overlapping (will be emptied anyways)
   3                    BUFFER_EMPTY   (don't trash other data)
   2                    BUFFER_CLEAN
   1    BUFFER_NOMATCH, BUFFER_READING (must be last place for preempt check)

   
      not usable:
	BUFFER_APPEND                  (if no combining writes)
        BUFFER_PREPEND                 (if no combining writes)
        BUFFER_NOMATCH, BUFFER_DIRTY  
                        BUFFER_WRITING
                        BUFFER_READING (if not pre-emptable or pending requests)
			BUFFER_CLEAN   (if pending requests)
        recycled segs

      NO seg usable if overlapping data exists which cannot be "cleaned"
	-- return BUFFER_COLLISION hittype if seg is question isn't "reusable".
*/

/* this routine sets currdiskreq->seg and currdiskreq->hittype */

static segment* disk_buffer_select_write_segment(disk *currdisk, diskreq *currdiskreq)
{
   segment *seg;
   diskreq *tmp_diskreq;
   diskreq *holddiskreq;
   ioreq_event *first_ioreq;
   ioreq_event *last_ioreq;
   ioreq_event *tmpioreq;
   int best_value = 0;
   int curr_value;
   int curr_hittype;
/*
   int reusable_dirty_segment = FALSE;
*/

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "%12.6f  %8p  Entering disk_buffer_select_write_segment\n",simtime,currdiskreq);
fprintf (outputfile, "                        numdirty = %d\n", currdisk->numdirty);
fflush(outputfile);
}

   currdiskreq->seg = NULL;
   currdiskreq->hittype = BUFFER_NOMATCH;
   seg = currdisk->seglist;
   while (seg) {
      curr_value = -1;
      curr_hittype = BUFFER_NOMATCH;
      if (currdiskreq->hittype == BUFFER_COLLISION) {
      } else if (seg->recyclereq) {
      } else if ((currdisk->dedicatedwriteseg) && 
	  (seg != currdisk->dedicatedwriteseg)) {
         /* check for collision with uncleanable data */
         if (((seg->state == BUFFER_CLEAN) &&
	      (seg->diskreqlist)) ||
	     ((seg->state == BUFFER_READING) && 
	      ((seg->diskreqlist->ioreqlist) || 
	       (seg->diskreqlist->seg_next) ||
	       !disk_buffer_stopable_access(currdisk,currdiskreq)))) {
	    tmpioreq = currdiskreq->ioreqlist;
	    while (tmpioreq) {
	       if (disk_buffer_overlap(seg,tmpioreq)) {
		  if (!disk_buffer_reusable_segment_check(currdisk, seg)) {
		     currdiskreq->hittype = BUFFER_COLLISION;
		     currdiskreq->seg = NULL;
		  }
                  break;
	       }
	       tmpioreq = tmpioreq->next;
	    }
	 }
      } else if (seg->state == BUFFER_EMPTY) {
	 if (currdisk->numdirty < currdisk->numwritesegs) {
/*
	     || reusable_dirty_segment) {
*/
	    curr_value = 3;
	 }
      } else if (seg->state == BUFFER_READING) {
	 if (!seg->diskreqlist->ioreqlist && !seg->diskreqlist->seg_next) {
	    if (currdisk->numdirty < currdisk->numwritesegs) {
/*
		|| reusable_dirty_segment) {
*/
	       curr_value = 1;
	    }
         } else {
	    tmpioreq = currdiskreq->ioreqlist;
	    while (tmpioreq) {
	       if (disk_buffer_overlap(seg,tmpioreq)) {
		  if (!disk_buffer_reusable_segment_check(currdisk, seg)) {
		     currdiskreq->hittype = BUFFER_COLLISION;
		     currdiskreq->seg = NULL;
		  }
                  break;
	       }
	       tmpioreq = tmpioreq->next;
	    }
	 }
      } else if (seg->state == BUFFER_CLEAN) {
	 if (!seg->diskreqlist) {
	    if (currdisk->numdirty < currdisk->numwritesegs) {
/*
		|| reusable_dirty_segment) {
*/
	       curr_value = 2;
	       first_ioreq = currdiskreq->ioreqlist;
	       while (first_ioreq) {
	          if (disk_buffer_overlap(seg,first_ioreq)) {
	             curr_value = 4;
	             break;
                  }
	          first_ioreq = first_ioreq->next;
	       }
	    }
         } else {
            /* check for collision with uncleanable data */
	    tmpioreq = currdiskreq->ioreqlist;
	    while (tmpioreq) {
	       if (disk_buffer_overlap(seg,tmpioreq)) {
		  if (!disk_buffer_reusable_segment_check(currdisk, seg)) {
		     currdiskreq->hittype = BUFFER_COLLISION;
		     currdiskreq->seg = NULL;
		  }
                  break;
	       }
	       tmpioreq = tmpioreq->next;
	    }
	 }
      } else if ((!currdisk->writecomb) || 
		 (seg->outstate == BUFFER_TRANSFERING)) {
	 /* no PREPEND's or APPEND's allowed */
         /* check for collision with uncleanable data */
	 tmpioreq = currdiskreq->ioreqlist;
	 while (tmpioreq) {
	    if (disk_buffer_overlap(seg,tmpioreq)) {
	       if (!disk_buffer_reusable_segment_check(currdisk, seg)) {
	          currdiskreq->hittype = BUFFER_COLLISION;
	          currdiskreq->seg = NULL;
	       }
               break;
	    }
	    tmpioreq = tmpioreq->next;
	 }
/*
	 if ((currdisk->numdirty >= currdisk->numwritesegs) &&
	     !reusable_dirty_segment &&
	     disk_buffer_reusable_segment_check(currdisk, seg)) {
            reusable_dirty_segment = TRUE;
            currdiskreq->seg = NULL;
            currdiskreq->hittype = BUFFER_NOMATCH;
            seg = currdisk->seglist;
	    best_value = 0;
	    continue;
	 }
*/
      } else {
         first_ioreq = currdiskreq->ioreqlist;
	 tmp_diskreq = holddiskreq = seg->diskreqlist;
	 while (tmp_diskreq->seg_next) {
	    tmp_diskreq = tmp_diskreq->seg_next;
	    if (!(tmp_diskreq->ioreqlist->flags & READ)) {
	       holddiskreq = tmp_diskreq;
	    }
         }
	 last_ioreq = holddiskreq->ioreqlist;
         while (last_ioreq && last_ioreq->next) {
	    last_ioreq = last_ioreq->next;
	 }
	 if ((first_ioreq->blkno == (last_ioreq->blkno + last_ioreq->bcount)) &&
	     (first_ioreq->blkno == seg->endblkno) &&
	     (seg->size > (first_ioreq->blkno - (disk_buffer_seg_owner(seg,FALSE))->inblkno))) {
            curr_hittype = BUFFER_APPEND;
	    curr_value = ((seg->state == BUFFER_WRITING) ? 7 : 6);
	 } else if (seg->state == BUFFER_DIRTY) {
	    int total_bcount = currdiskreq->ioreqlist->bcount;

	    last_ioreq = currdiskreq->ioreqlist;
	    while (last_ioreq->next) {
	       last_ioreq = last_ioreq->next;
	       total_bcount += last_ioreq->bcount;
            }
	    holddiskreq = seg->diskreqlist;
	    while (holddiskreq->ioreqlist->flags & READ) {
	       holddiskreq = holddiskreq->seg_next;
            }
	    first_ioreq = holddiskreq->ioreqlist;
	    if ((first_ioreq->blkno == (last_ioreq->blkno + last_ioreq->bcount)) &&
	        (first_ioreq->blkno == seg->startblkno) &&
		((seg->startblkno == seg->endblkno) || (seg->hold_bcount == 0)) &&
		(seg->size >= ((seg->endblkno - seg->startblkno) + total_bcount)) &&
		(!currdisk->extradisc_diskreq || 
		 (currdisk->extradisc_diskreq->seg != seg))) {
               curr_hittype = BUFFER_PREPEND;
	       curr_value = 5;
	    }
         }
	 if (curr_hittype == BUFFER_NOMATCH) {
            /* check for collision with uncleanable data */
	    tmpioreq = currdiskreq->ioreqlist;
	    while (tmpioreq) {
	       if (disk_buffer_overlap(seg,tmpioreq)) {
	          if (!disk_buffer_reusable_segment_check(currdisk, seg)) {
	             currdiskreq->hittype = BUFFER_COLLISION;
	             currdiskreq->seg = NULL;
		  }
                  break;
	       }
	       tmpioreq = tmpioreq->next;
	    }
/*
	    if ((currdisk->numdirty >= currdisk->numwritesegs) &&
	        !reusable_dirty_segment &&
	        disk_buffer_reusable_segment_check(currdisk, seg)) {
               reusable_dirty_segment = TRUE;
               currdiskreq->seg = NULL;
               currdiskreq->hittype = BUFFER_NOMATCH;
               seg = currdisk->seglist;
	       best_value = 0;
	       continue;
	    }
*/
	 }
      }
      if (curr_value > best_value) {
	 currdiskreq->seg = seg;
	 currdiskreq->hittype = curr_hittype;
	 best_value = curr_value;
      }
      seg = seg->next;
   }

   /* If BUFFER_NOMATCH && BUFFER_READING, perform preemption check.
      Note that currdiskreq->seg should be set before the call.
   */

   if ((best_value == 1) &&
       !disk_buffer_stopable_access(currdisk,currdiskreq)) {
      /* check for collision with uncleanable data */
      tmpioreq = currdiskreq->ioreqlist;
      while (tmpioreq) {
         if (disk_buffer_overlap(currdiskreq->seg,tmpioreq)) {
	    if (!disk_buffer_reusable_segment_check(currdisk, seg)) {
  	       currdiskreq->hittype = BUFFER_COLLISION;
	    }
            break;
	 }
	 tmpioreq = tmpioreq->next;
      }
      currdiskreq->seg = NULL;
   }

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "                        segment = %8p, hittype = %d\n",currdiskreq->seg,currdiskreq->hittype);
fflush(outputfile);
}

   return(currdiskreq->seg);
}


segment * disk_buffer_select_segment (disk *currdisk, diskreq *currdiskreq,
				      int set_extradisc)
{
   segment *seg;

   if (currdisk->const_acctime) {
      currdiskreq->seg = NULL;
      currdiskreq->hittype = BUFFER_NOMATCH;
      return(NULL);
   }

   if(currdiskreq->ioreqlist->flags & READ) {
      seg = disk_buffer_select_read_segment(currdisk, currdiskreq);
      if (currdisk->dedicatedwriteseg && (seg == currdisk->dedicatedwriteseg)) {
	 fprintf(stderr, "Read request about to use the write segment\n");
	 exit(1);
      }
   } 
   else {			/* WRITE */
      seg = disk_buffer_select_write_segment(currdisk, currdiskreq);
   }

   /* if suffering extra write disconnects and no extradisc_diskreq exists */
   /* and this is a write following a non-sequential write, set the        */
   /* EXTRA_WRITE_DISCONNECT diskreq flag.  */

   if (set_extradisc 
       && currdisk->extra_write_disconnect 
       && !currdisk->neverdisconnect 
       && !currdisk->extradisc_diskreq 
       && !(currdiskreq->ioreqlist->flags & READ) 
       && seg 
       && ((LRU_at_seg_list_head && !seg->prev) 
	   || (!LRU_at_seg_list_head && !seg->next)) 
       && seg->access 
       && !(seg->access->flags & READ) 
       && (currdiskreq->ioreqlist->blkno != seg->endblkno)) 
   {
      currdiskreq->flags |= EXTRA_WRITE_DISCONNECT;
   }
   return(seg);
}


/* check for BUFFER hit (and no COLLISIONS's) */

static int disk_buffer_check_read_segments (disk *currdisk, ioreq_event *currioreq, int* buffer_reading)
{
   segment *seg;
   int return_hittype = BUFFER_NOMATCH;
   int read_hit_on_dirty_data = FALSE;

if ((disk_printhack > 1) && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "%12.6f  %8p  Entering disk_buffer_check_read_segments\n",simtime,currioreq);
fflush(outputfile);
}

   if (!currdisk->enablecache) {
      return(BUFFER_NOMATCH);
   }

   seg = currdisk->seglist;
   while (seg) {
      if (seg->recyclereq) {
      } else if (seg->state == BUFFER_EMPTY) {
      } else if ((currdisk->dedicatedwriteseg) && 
	  (seg == currdisk->dedicatedwriteseg)) {
         /* check for collision with dirty data */
         if ((seg->state == BUFFER_DIRTY) || (seg->state == BUFFER_WRITING)) {
	    if (disk_buffer_overlap(seg,currioreq) &&
	        !disk_buffer_reusable_segment_check(currdisk, seg)) {
	       return(BUFFER_COLLISION);
	    }
	 }
      } else if ((currioreq->blkno < seg->startblkno) || 
		 (currioreq->blkno >= seg->endblkno)) {
	 if (seg->state == BUFFER_CLEAN) {
         } else if (seg->state == BUFFER_READING) {
	    if ((seg->endblkno == currioreq->blkno) && 
		currdisk->almostreadhits) {
	       /* special case:  block currently being prefetched is
		  the first block of this request.  We count this as
		  a partial read hit.
               */
	       if (return_hittype == BUFFER_NOMATCH) {
		  *buffer_reading = TRUE;
	          return_hittype = BUFFER_PARTIAL;
	       }
	    }
         } else if (currioreq->blkno < seg->startblkno) {
            /* check for collision with dirty data */
	    if (disk_buffer_overlap(seg,currioreq) &&
		!disk_buffer_reusable_segment_check(currdisk, seg)) {
	       return(BUFFER_COLLISION);
	    }
	 }
      } else {
	 switch (seg->state) {
	 case BUFFER_DIRTY:
	 case BUFFER_WRITING:
	   if (read_hit_on_dirty_data ||
	       (!currdisk->readhitsonwritedata &&
		!disk_buffer_reusable_segment_check(currdisk, seg))) {
	     return(BUFFER_COLLISION);
	   }
	   read_hit_on_dirty_data = TRUE;
	   break;
	 case BUFFER_READING:
	   break;
	 case BUFFER_CLEAN:
	       if (!currdisk->readhitsonwritedata &&
		   seg->access && !(seg->access->flags & READ)) {
		 continue;
	       }
	       break;
	 default:
	   ddbg_assert(0);
	 }
	 if (seg->endblkno >= (currioreq->blkno + currioreq->bcount)) {
            return_hittype = BUFFER_WHOLE;
	    *buffer_reading = (seg->state == BUFFER_READING);
         } else if (return_hittype != BUFFER_WHOLE) {
	    return_hittype = BUFFER_PARTIAL;
	    *buffer_reading = (seg->state == BUFFER_READING);
	 }
      }
      seg = seg->next;
   }

if ((disk_printhack > 1) && (simtime >= disk_printhacktime) && 
    (return_hittype != BUFFER_NOMATCH)) {
fprintf (outputfile, "                        HITable segment found\n");
fflush(outputfile);
}

   return(return_hittype);

}


/* check for directly APPENDable WRITING segment (and no COLLISION's) */

static int disk_buffer_check_write_segments (disk *currdisk, ioreq_event *currioreq)
{
   segment *seg;
   int return_hittype = BUFFER_NOMATCH;
   diskreq *tmp_diskreq;
   diskreq *holddiskreq;
   ioreq_event *last_ioreq;

if ((disk_printhack > 1) && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "%12.6f  %8p  Entering disk_buffer_check_write_segments\n",simtime,currioreq);
fflush(outputfile);
}

   if (!currdisk->writecomb) {
      return(BUFFER_NOMATCH);
   }

   seg = currdisk->seglist;
   while (seg) {
      if (seg->recyclereq) {
      } 
      else if (seg->state == BUFFER_EMPTY) {
      } 
      else if (seg->state == BUFFER_READING) {
	 return(BUFFER_NOMATCH);
      } 
      else if ((currdisk->dedicatedwriteseg) && 
	  (seg != currdisk->dedicatedwriteseg)) {
         /* check for collision with uncleanable data */
         if ((seg->state == BUFFER_CLEAN) && seg->diskreqlist) {
	    if (disk_buffer_overlap(seg,currioreq) &&
	        !disk_buffer_reusable_segment_check(currdisk, seg)) {
	       return(BUFFER_COLLISION);
	    }
	 }
      } 
      else if ((seg->state == BUFFER_CLEAN) || 
	       (seg->state == BUFFER_DIRTY)) 
	{
	  /* check for collision with uncleanable data */
	  if (seg->diskreqlist) {
	    if (disk_buffer_overlap(seg,currioreq) &&
		!disk_buffer_reusable_segment_check(currdisk, seg)) {
	      return(BUFFER_COLLISION);
	    }
	  }
      } 
      else if (seg->outstate == BUFFER_TRANSFERING) {
         /* check for collision with uncleanable data */
	 if (disk_buffer_overlap(seg,currioreq) &&
	     !disk_buffer_reusable_segment_check(currdisk, seg)) {
	    return(BUFFER_COLLISION);
	 }
      } 
      else {
	 tmp_diskreq = holddiskreq = seg->diskreqlist;
	 while (tmp_diskreq->seg_next) {
	    tmp_diskreq = tmp_diskreq->seg_next;
	    if (!(tmp_diskreq->ioreqlist->flags & READ)) {
	       holddiskreq = tmp_diskreq;
	    }
         }
	 last_ioreq = holddiskreq->ioreqlist;
         while (last_ioreq && last_ioreq->next) {
	    last_ioreq = last_ioreq->next;
	 }
	 if ((currioreq->blkno == (last_ioreq->blkno + last_ioreq->bcount)) &&
	     (currioreq->blkno == seg->endblkno) &&
	     (seg->size > (currioreq->blkno - (disk_buffer_seg_owner(seg,FALSE))->inblkno))) {
            return_hittype = BUFFER_APPEND;
	 } 
	 else {
            /* check for collision with uncleanable data */
	    if (disk_buffer_overlap(seg,currioreq) &&
	        !disk_buffer_reusable_segment_check(currdisk, seg)) {
	       return(BUFFER_COLLISION);
	    }
	 }
      }
      seg = seg->next;
   }

if ((disk_printhack > 1) && (simtime >= disk_printhacktime) && 
    (return_hittype == BUFFER_APPEND)) {
fprintf (outputfile, "                        APPENDable segment found\n");
fflush(outputfile);
}

   return(return_hittype);
}


/* Checks for cache/buffer hits */

int disk_buffer_check_segments (disk *currdisk, ioreq_event *currioreq,
			        int* buffer_reading)
{
   if (currioreq->flags & READ) {
      return(disk_buffer_check_read_segments(currdisk, currioreq, buffer_reading));
   } else {
      return(disk_buffer_check_write_segments(currdisk, currioreq));
   }
}


void disk_buffer_set_segment (disk *currdisk, diskreq *currdiskreq)
{
   segment     *seg = currdiskreq->seg;
   segment     *tmp_seg;
   diskreq     *tmp_diskreq;
   ioreq_event *tmp_ioreq;
   int          is_read = (currdiskreq->ioreqlist->flags & READ);

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "%12.6f  %8p  Entering disk_buffer_set_segment\n",simtime,currdiskreq);
fflush(outputfile);
}

   if (!seg) {
      fprintf(stderr, "diskreq has NULL segment in disk_buffer_set_segment\n");
      exit(1);
   }

   /* check to make sure segment/diskreq combination is valid */

   if (is_read && (seg == currdisk->dedicatedwriteseg)) {
      fprintf(stderr, "Read request about to use the write segment\n");
      exit(1);
   }

   if (seg->recyclereq && (currdiskreq != seg->recyclereq)) {
      fprintf(stderr, "non-recyclereq detected for recycled segment in disk_buffer_set_segment\n");
      exit(1);
   }

   switch (seg->state) {
      case BUFFER_EMPTY:
	 if (currdiskreq == seg->recyclereq) {
            fprintf(stderr, "seg->state of BUFFER_EMPTY for recyclereq in disk_buffer_set_segment\n");
            exit(1);
	 }
	 break;

      case BUFFER_CLEAN:
	 if (currdiskreq == seg->recyclereq) {
            fprintf(stderr, "seg->state of BUFFER_CLEAN for recyclereq in disk_buffer_set_segment\n");
            exit(1);
	 }
	 if (is_read && currdiskreq->hittype != BUFFER_NOMATCH && !currdisk->readhitsonwritedata && seg->access && !(seg->access->flags & READ)) {
            fprintf(stderr, "Unallowed read hit on write data disk_buffer_set_segment\n");
            exit(1);
	 }
	 break;

      case BUFFER_DIRTY:
	 if (currdiskreq == seg->recyclereq) {
            fprintf(stderr, "seg->state of BUFFER_DIRTY for recyclereq in disk_buffer_set_segment\n");
            exit(1);
	 }
	 if (currdiskreq->hittype == BUFFER_NOMATCH) {
            fprintf(stderr, "Attempt to overwrite dirty data in disk_buffer_set_segment\n");
            exit(1);
	 } else if (is_read && !currdisk->readhitsonwritedata) {
            fprintf(stderr, "Unallowed read hit on write data disk_buffer_set_segment\n");
            exit(1);
	 }
	 if (!is_read) {
	    currdisk->stat.writecombs++;
         }
	 break;

      case BUFFER_READING:
	 if (currdiskreq == seg->recyclereq) {
	    if (!(currdiskreq->ioreqlist->flags & READ)) {
               fprintf(stderr, "seg->state of BUFFER_READING for write recyclereq in disk_buffer_set_segment\n");
               exit(1);
	    }
	 } else if (!is_read || (currdiskreq->hittype == BUFFER_NOMATCH)) {
	    if (!disk_buffer_stopable_access(currdisk,currdiskreq)) {
               fprintf(stderr, "Attempt to re-target active read segment in disk_buffer_set_segment\n");
               exit(1);
	    }
         }
	 break;

      case BUFFER_WRITING:
	 if (currdiskreq == seg->recyclereq) {
	    if (currdiskreq->ioreqlist->flags & READ) {
               fprintf(stderr, "seg->state of BUFFER_WRITING for read recyclereq in disk_buffer_set_segment\n");
               exit(1);
	    }
         } else {
	    if ((currdiskreq->hittype == BUFFER_NOMATCH) || 
	        (currdiskreq->hittype == BUFFER_PREPEND)) {
               fprintf(stderr, "Attempt to re-target active write segment in disk_buffer_set_segment\n");
               exit(1);
	    }
	    if (!is_read) {
	       currdisk->stat.writecombs++;
            }
	 }
	 break;

      default:
	 fprintf(stderr, "Invalid segment state in disk_buffer_set_segment - blkno %d, bcount %d, state %d\n", currdiskreq->ioreqlist->blkno, currdiskreq->ioreqlist->bcount, seg->state);
         exit(1);
   }

   /* end of sanity checks, now do the work */

   disk_buffer_stats(currdisk,currdiskreq->ioreqlist,seg,currdiskreq->hittype);

   if (LRU_at_seg_list_head) {
      /* place segment at beginning of disk's segment list (for LRU) */
      if (seg->prev) {
         seg->prev->next = seg->next;
         if (seg->next) {
	    seg->next->prev = seg->prev;
         }
         seg->next = currdisk->seglist;
         currdisk->seglist->prev = seg;
         seg->prev = NULL;
         currdisk->seglist = seg;
      }
   } else {
      /* place segment at end of disk's segment list (for LRU) */
      if (seg->next) {
         if (seg->prev) {
            seg->prev->next = seg->next;
         } else {
   	 currdisk->seglist = seg->next;
         }
         seg->next->prev = seg->prev;
         tmp_seg = currdisk->seglist;
         while (tmp_seg->next) {
   	 tmp_seg = tmp_seg->next;
         }
         tmp_seg->next = seg;
         seg->prev = tmp_seg;
         seg->next = NULL;
      }
   }

   /* clear out clean, non-active, overlapping segments if write */

   if (!is_read) {
      tmp_seg = currdisk->seglist;
      while (tmp_seg) {
	 if (tmp_seg != seg) {
            tmp_ioreq= currdiskreq->ioreqlist;
            while (tmp_ioreq) {
               if ((tmp_seg->state != BUFFER_EMPTY) &&
                   disk_buffer_overlap(tmp_seg,tmp_ioreq)) {
                  if ((tmp_seg->state == BUFFER_CLEAN) &&
                      (tmp_seg->diskreqlist == NULL)) {
                     tmp_seg->state = BUFFER_EMPTY;
/*
	          } else {
                     fprintf(stderr, "Request overlaps with non-clean segment in disk_buffer_set_segment\n");
                     exit(1);
*/
	          }
               }
               tmp_ioreq = tmp_ioreq->next;
            }
	 }
         tmp_seg = tmp_seg->next;
      }
   }


   /* add diskreq to seg's diskreq list, sorted in ascending blkno order */

   if (!seg->diskreqlist) {
      if (seg->access == NULL) {
         seg->access = ioreq_copy(currdiskreq->ioreqlist);
	 seg->access->type = NULL_EVENT;
      }
      seg->diskreqlist = currdiskreq;
      currdiskreq->seg_next = NULL;
   } else {				/* non-empty list */
      diskreq *prev_diskreq = 0;
      tmp_diskreq = seg->diskreqlist;
      while (tmp_diskreq) {
	 if (tmp_diskreq->ioreqlist && 
	     (currdiskreq->ioreqlist->blkno < tmp_diskreq->ioreqlist->blkno)) {
	    currdiskreq->seg_next = tmp_diskreq;
            if (seg->diskreqlist == tmp_diskreq) {
	       seg->diskreqlist = currdiskreq;
	    } else {
	       prev_diskreq->seg_next = currdiskreq;
	    }
	    break;
         }
         prev_diskreq = tmp_diskreq;
	 tmp_diskreq = tmp_diskreq->seg_next;
      }
      if (!tmp_diskreq) {
	 prev_diskreq->seg_next = currdiskreq;
         currdiskreq->seg_next = NULL;
      }
   }

   /* set watermark */
   /* I'm still figuring out this watermark business -rcohen */

   tmp_ioreq = currdiskreq->ioreqlist;

   if (is_read) {
      if (currdisk->reqwater) {
         currdiskreq->watermark = max(1, (int) ((double) min(seg->size, tmp_ioreq->bcount) * currdisk->readwater));
      } else {
         currdiskreq->watermark = (int) (((double) seg->size * currdisk->readwater) + (double) 0.9999999999);
      }
   } else {			/* WRITE */
      if (currdisk->reqwater) {
         currdiskreq->watermark = max(1, (int) ((double) min(seg->size, tmp_ioreq->bcount) * currdisk->writewater));
      } else {
         currdiskreq->watermark = (int) (((double) seg->size * currdisk->writewater) + (double) 0.9999999999);
      }
   }
}


int disk_buffer_attempt_seg_ownership (disk *currdisk, diskreq *currdiskreq)
{
   segment     *seg = currdiskreq->seg;
   diskreq     *tmp_diskreq;
   ioreq_event *currioreq = currdiskreq->ioreqlist;
   int         currdiskreq_found = FALSE;
   int         write_found = FALSE;
   int	       write_incomplete = 0;
   ioreq_event *tmpioreq;

if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "%12.6f  %8p  Entering disk_buffer_attempt_seg_ownership\n",simtime,currdiskreq);
fflush(outputfile);
}

   if (!seg) {
      fprintf(stderr, "diskreq has NULL segment in disk_buffer_attempt_seg_ownership\n");
      exit(1);
   }

   if (currdiskreq->flags & SEG_OWNED) {
      fprintf(stderr, "diskreq already owns seg in disk_buffer_attempt_seg_ownership\n");
      exit(1);
   }

   tmp_diskreq = seg->diskreqlist;
   while (tmp_diskreq) {
      if (tmp_diskreq->flags & SEG_OWNED) {
         if (currdiskreq->hittype == BUFFER_PREPEND) {
            if (seg->state != BUFFER_DIRTY) {
               fprintf(stderr, "PREPEND of active request detected in disk_buffer_attempt_seg_ownership\n");
               exit(1);
	    }
	    /* release ownership to new request and set up hold areas */
	    tmp_diskreq->flags &= ~SEG_OWNED;
	    tmp_diskreq->hittype = BUFFER_APPEND;
	    if (seg->endblkno != seg->startblkno) {
	       if (seg->hold_bcount != 0) {
                  fprintf(stderr, "PREPEND of segment already 'holding' data detected in disk_buffer_attempt_seg_ownership\n");
                  exit(1);
	       }
               seg->hold_blkno = seg->startblkno;
	       seg->hold_bcount = seg->endblkno - seg->startblkno;
	    }
	 } else {
	    break;
         }
      }
      if (tmp_diskreq == currdiskreq) {
	 currdiskreq_found = TRUE;
      } else if (!currdiskreq_found && tmp_diskreq->ioreqlist && 
		 !(tmp_diskreq->ioreqlist->flags & READ)) {
	 write_found = TRUE;
	 tmpioreq = tmp_diskreq->ioreqlist;
	 while (tmpioreq->next) {
	    tmpioreq = tmpioreq->next;
	 }
	 if (tmp_diskreq->inblkno < (tmpioreq->blkno + tmpioreq->bcount)) {
	    write_incomplete = TRUE;
	 }
      }
      tmp_diskreq = tmp_diskreq->seg_next;
   }


   if (!tmp_diskreq) {
      ASSERT(!write_found || !write_incomplete);
      currdiskreq->flags |= SEG_OWNED;
      if (currioreq &&
          (!currdisk->effectivehda || 
	   (currdisk->effectivehda == currdiskreq) ||
	   (currdisk->effectivehda->seg != seg))) {
         seg->access->flags = currioreq->flags;
      }

      /* set state, startblkno, endblkno, and readahead fields */

      if (!currioreq || (currioreq->flags & READ)) {

	 /* check to see if the cache segment needs to be reset */

#if 0	/* GROK: removed on 10/10/99, because it causes problems, but */
	/* we are not sure that removing this won't break something   */
	/* else down the road...                                      */
	 if ((currdiskreq->hittype != BUFFER_NOMATCH) &&
	     (seg->startblkno > currdiskreq->outblkno)) {
	    currdiskreq->hittype = BUFFER_NOMATCH;
         }
#endif

	 if (currdiskreq->hittype == BUFFER_NOMATCH) {
            ASSERT(currioreq != NULL);
	    ASSERT1(((seg->access->type == NULL_EVENT) ||
		     (seg->recyclereq == currdiskreq)),"seg->access->type",seg->access->type);
	    if (currdiskreq != seg->recyclereq) {
	       seg->state = BUFFER_CLEAN;
               seg->access->blkno = currdiskreq->outblkno;
	    }
	    seg->startblkno = seg->endblkno = currdiskreq->outblkno;
	    seg->minreadaheadblkno = seg->maxreadaheadblkno = -1;
	    seg->hold_bcount = 0;
	 }

         if (currioreq) {
	    while (currioreq->next) {
	       currioreq = currioreq->next;
	    }
	    seg->minreadaheadblkno = max(seg->minreadaheadblkno, min((currioreq->blkno + currioreq->bcount + currdisk->minreadahead), currdisk->model->dm_sectors));

	    seg->maxreadaheadblkno = max(seg->maxreadaheadblkno, min(disk_buffer_get_max_readahead(currdisk,seg,currioreq), currdisk->model->dm_sectors));

	    if ((seg->endblkno >= (currioreq->blkno + currioreq->bcount)) &&
	        (currdisk->effectivehda == currdiskreq)) {
               seg->access->flags |= BUFFER_BACKGROUND;
            }
	 }

      } else {			/* WRITE */
	 if (!currdisk->effectivehda || 
	     (currdisk->effectivehda == currdiskreq) ||
	     (currdisk->effectivehda->seg != seg)) {
	    if ((currdiskreq != seg->recyclereq) &&
		(seg->access->type == NULL_EVENT)){
               seg->access->blkno = currdiskreq->inblkno;
	    }
            if (currdiskreq->flags & COMPLETION_RECEIVED) {
               seg->access->flags |= BUFFER_BACKGROUND;
            }
	 }
	 if (currdiskreq->hittype == BUFFER_NOMATCH) {
	    seg->minreadaheadblkno = seg->maxreadaheadblkno = -1;
	    seg->hold_bcount = 0;
	    seg->startblkno = seg->endblkno = currdiskreq->inblkno;
	    if (currdiskreq != seg->recyclereq) {
	       seg->state = BUFFER_DIRTY;
	       currdisk->numdirty++;
if ((disk_printhack > 1) && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "                        numdirty++ = %d\n",currdisk->numdirty);
fflush(outputfile);
}
	       ASSERT1(((currdisk->numdirty >= 0) && (currdisk->numdirty <= currdisk->numwritesegs)),"numdirty",currdisk->numdirty);
	    }
	 } else if (currdiskreq->hittype == BUFFER_PREPEND) {
	    seg->startblkno = seg->endblkno = currdiskreq->inblkno;
	 }
      }
   }
if (disk_printhack && (simtime >= disk_printhacktime)) {
fprintf (outputfile, "                        Ownership = %d\n",(currdiskreq->flags & SEG_OWNED));
fflush(outputfile);
}

   return(currdiskreq->flags & SEG_OWNED);
}


int disk_buffer_get_max_readahead (disk *currdisk, segment *seg, ioreq_event *curr)
{
   int endreq;

   if (!(curr->flags & READ)) {
      fprintf(stderr, "No read-ahead for write accesses, in disk_buffer_get_max_readahead\n");
      exit(1);
   }

   endreq = curr->blkno + curr->bcount;

   if (currdisk->contread == BUFFER_NO_READ_AHEAD) {
      return(endreq);
   } else if (currdisk->contread == BUFFER_DEC_PREFETCH_SCHEME) {
      int startlbn;
      int endlbn;
      struct dm_pbn pbn;
      //      band* bandptr;

      curr->blkno += curr->bcount;

      // bandptr = 
      // was MAP_FULL
      currdisk->model->layout->dm_translate_ltop(currdisk->model, 
						 curr->blkno, 
						 MAP_FULL,
						 &pbn, 
						 0); // remapsector

      currdisk->model->layout->dm_get_track_boundaries(currdisk->model,
						       &pbn,
						       &startlbn, 
						       &endlbn,
						       0); // remapsector
      // new track_boundaries semantics
      endlbn++;

      curr->blkno -= curr->bcount;

      if (seg->startblkno < startlbn) {
	return (endlbn + currdisk->model->layout->dm_get_sectors_lbn(currdisk->model, curr->blkno));
      } else {
	  return(endlbn);
      }
   }

   if (currdisk->maxreadahead) {
      return(endreq + currdisk->maxreadahead);
   }
   if (currdisk->keeprequestdata > 0) {
      if ((curr->bcount >= seg->size) 
	  || ((seg->size - curr->bcount) < currdisk->minreadahead)) 
	{
	  return(endreq + currdisk->minreadahead);
	}
      return(curr->blkno + seg->size);
   }

   return(endreq + seg->size);
}

