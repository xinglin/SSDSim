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


#include "disksim_synthio.h"
#include "modules/modules.h"

#define SYNTHIO_UNIFORM		0
#define SYNTHIO_NORMAL		1
#define SYNTHIO_EXPONENTIAL	2
#define SYNTHIO_POISSON		3
#define SYNTHIO_TWOVALUE	4


static double synthio_get_uniform (synthio_distr *fromdistr)
{
   return(((fromdistr->var - fromdistr->base) * DISKSIM_drand48()) + fromdistr->base);
}


static double synthio_get_normal (synthio_distr *fromdistr)
{
   double y1, y2;
   double y = 0;

   while (y <= 0.0) {
      y2 = - log((double) 1.0 - DISKSIM_drand48());
      y1 = - log((double) 1.0 - DISKSIM_drand48());
      y = y2 - ((y1 - (double) 1.0) * (y1 - (double) 1.0)) / 2;
   }
   if (DISKSIM_drand48() < 0.5) {
      y1 = -y1;
   }
   return((fromdistr->var * y1) + fromdistr->mean);
}


static double synthio_get_exponential (synthio_distr *fromdistr)
{
   double dtmp;

   dtmp = log((double) 1.0 - DISKSIM_drand48());
   return((fromdistr->base - (fromdistr->mean * dtmp)));
}


static double synthio_get_poisson (synthio_distr *fromdistr)
{
   double dtmp = 1.0;
   int count = 0;
   double stop;

   stop = exp(-fromdistr->mean);
   while (dtmp >= stop) {
      dtmp *= DISKSIM_drand48();
      count++;
   }
   count--;
   return((double) count + fromdistr->base);
}


static double synthio_get_twovalue (synthio_distr *fromdistr)
{
   if (DISKSIM_drand48() < fromdistr->var) {
      return(fromdistr->mean);
   } else {
      return(fromdistr->base);
   }
}


static double synthio_getrand (synthio_distr *fromdistr)
{
   switch (fromdistr->type) {
      case SYNTHIO_UNIFORM:
	                return(synthio_get_uniform(fromdistr));
      case SYNTHIO_NORMAL:
                        return(synthio_get_normal(fromdistr));
      case SYNTHIO_EXPONENTIAL:
			return(synthio_get_exponential(fromdistr));
      case SYNTHIO_POISSON:
			return(synthio_get_poisson(fromdistr));
      case SYNTHIO_TWOVALUE:
			return(synthio_get_twovalue(fromdistr));
      default:
	                fprintf(stderr, "Unrecognized distribution type - %d\n", fromdistr->type);
	                exit(1);
   }
}


static void synthio_appendio (process *procp, ioreq_event *tmp)
{
   synthio_generator *gen = (synthio_generator *) procp->space;
   sleep_event *limittmp = NULL;
   event *prev = NULL;
   sleep_event *newsleep = NULL;
   sleep_event *callsleep = NULL;
   sleep_event *retsleep = NULL;
   ioreq_event *new;
   int blocksize;
   int gennum;

   blocksize = gen->blocksize;
   gennum = gen->number;
   new = (ioreq_event *) getfromextraq();
   new->type = IOREQ_EVENT;
   new->time = tmp->time;
   new->devno = tmp->devno;
   new->blkno = tmp->blkno * blocksize;
   new->bcount = tmp->bcount * blocksize;
   new->flags = tmp->flags;
   new->cause = tmp->cause;
   new->opid = (synthio_endiocnt * gennum) + synthio_iocnt;
   /* this is being considered "ok" under the assumption that opid will */
   /* never exceed 2^32.....                                            */
   new->buf = (void *) new->opid;
   if(synthio_syscalls){
      retsleep = (sleep_event *) getfromextraq();
      retsleep->type = SLEEP_EVENT;
      retsleep->time = synthio_sysret_time;
      retsleep->chan = new->buf;
      retsleep->iosleep = 1;
      callsleep = (sleep_event *) getfromextraq();
      callsleep->type = SLEEP_EVENT;
      callsleep->time = synthio_syscall_time;
      callsleep->chan = new->buf;
      callsleep->iosleep = 1;
   }
   if (new->flags & (TIME_CRITICAL|TIME_LIMITED)) {
      newsleep = (sleep_event *) getfromextraq();
      newsleep->type = SLEEP_EVENT;
      newsleep->time = 0.0;
      newsleep->chan = new->buf;
      newsleep->iosleep = 1;
      if (new->flags & TIME_CRITICAL) {
	if(synthio_syscalls){
	  retsleep->next = procp->eventlist;
	  new->next = (ioreq_event *) retsleep;
	  callsleep->next = (event *) new;
	  new = (ioreq_event *) callsleep;
	  newsleep = NULL;
	}else{
	  newsleep->next = procp->eventlist;
	  new->next = (ioreq_event *) newsleep;
	}
      } else {
	new->next = (ioreq_event *) procp->eventlist;
	newsleep->time = -1.0;
	while (newsleep->time < 0.0) {
	  newsleep->time = synthio_getrand (&gen->tmlimit);
	}
	newsleep->time += new->time;
	limittmp = gen->limits;
	if ((limittmp == NULL) || (newsleep->time < limittmp->time)) {
	  newsleep->next = (event *) gen->limits;
	  gen->limits = (sleep_event *) newsleep;
	  if (limittmp) {
	    limittmp->time -= newsleep->time;
	  }
	} else {
	  newsleep->time -= limittmp->time;
	  while ((limittmp->next) && (newsleep->time >= limittmp->next->time)) {
	    limittmp = (sleep_event *) limittmp->next;
	    newsleep->time -= limittmp->time;
	  }
	  newsleep->next = limittmp->next;
	  limittmp->next = (event *) newsleep;
	  if (newsleep->next) {
	    newsleep->next->time -= newsleep->time;
	  }
	}
	newsleep = NULL;
      }
   } else {
     new->next = (ioreq_event *) procp->eventlist;
   }
   
   procp->eventlist = (event *) new;

synthio_check_genlimits:
   limittmp = gen->limits;
   while ((limittmp) && (limittmp->time < new->time)) {
      gen->limits = (sleep_event *) limittmp->next;
      new->time -= limittmp->time;
      limittmp->next = (event *) new;
      if (prev) {
         prev->next = (event *) limittmp;
      } else {
         procp->eventlist = (event *) limittmp;
      }
      prev = (event *) limittmp;
      limittmp = gen->limits;
   }

   if ((newsleep) && (gen->limits)) {
      prev = (event *) new;
      new = (ioreq_event *) newsleep;
      newsleep = NULL;
      goto synthio_check_genlimits;
   }


   //fprintf (stderr, "New request %d, time %f, devno %d, blkno %d, bcount %d, flags %x\n", synthio_iocnt, new->time, new->devno, new->blkno, new->bcount, new->flags);
}


void synthio_initialize_generator (process *procp)
{
   ioreq_event *tmp;
   synthio_generator *gen;
   event *evptr;
   double reqclass;

   evptr = getfromextraq();
   evptr->time = 0.0;
   evptr->type = SYNTHIO_EVENT;
   evptr->next = NULL;
   procp->eventlist = evptr;
   gen = (synthio_generator *) procp->space;
   if (gen == NULL) {
      fprintf(stderr, "Process with no synthetic generator in synthio_initialize\n");
      exit(1);
   }
   tmp = (ioreq_event *) getfromextraq();
   tmp->time = -1.0;
   while (tmp->time < 0.0) {
      tmp->time = synthio_getrand(&gen->genintr);
   }
   tmp->flags = 0;
   tmp->cause = gen->number;
   tmp->devno = gen->devno[(int) (DISKSIM_drand48() * (double) gen->numdisks)];
   tmp->blkno = tmp->bcount = gen->blksperdisk;
   while (((tmp->blkno + tmp->bcount) >= gen->blksperdisk) || (tmp->bcount == 0)) {
      tmp->blkno = (int) (DISKSIM_drand48() * (double) gen->blksperdisk);
      tmp->bcount = ((int) synthio_getrand(&gen->sizedist) + gen->blocksize - 1) / gen->blocksize;
   }
   if (DISKSIM_drand48() < gen->probread) {
      tmp->flags |= READ;
   }
   reqclass = DISKSIM_drand48() - gen->probtmcrit;
   if (reqclass < 0.0) {
      tmp->flags |= TIME_CRITICAL;
   } else if (reqclass < gen->probtmlim) {
      tmp->flags |= TIME_LIMITED;
   }
   gen->pendio = tmp;
   synthio_appendio(procp, tmp);

fprintf (outputfile, "Initialized synthio process #%d, first event at time %f\n", procp->pid, procp->eventlist->time);

}


static int synthio_generatenextio (synthio_generator *gen)
{
   double type;
   double reqclass;
   int blkno;
   ioreq_event *tmp;

   if ((simtime >= synthio_endtime) || (synthio_iocnt >= synthio_endiocnt))
      return 0;

   tmp = gen->pendio;
   if (gen->tracefile) {
      gen->pendio = 
	(ioreq_event *)iotrace_get_ioreq_event(gen->tracefile, 
					       disksim->traceformat, 
					       tmp);
      if (gen->pendio) {
	 tmp->cause = gen->number;
	 /* tmp->time = 0; */
      } else {
	 fprintf(stderr, "Returning NULL event in synthio_generatenextio\n");
	 return 0;
      }
      return 1;
   }

   type = DISKSIM_drand48();

   if ((type < gen->probseq) && 
       ((tmp->blkno + 2*tmp->bcount) < gen->blksperdisk)) {

     tmp->time = -1.0;

     while (tmp->time < 0.0) {
       tmp->time = synthio_getrand(&gen->seqintr);
     }

     tmp->flags = SEQ | (tmp->flags & READ);
     tmp->cause = gen->number;
     tmp->blkno += tmp->bcount;
   } 
   else if ((type < (gen->probseq + gen->probloc)) && 
	    (type >= gen->probseq)) {

     tmp->time = -1.0;
     while (tmp->time < 0.0) {
       tmp->time = synthio_getrand(&gen->locintr);
     }
     tmp->flags = LOCAL;
     tmp->cause = gen->number;
     blkno = gen->blksperdisk;
     while (((blkno + tmp->bcount) >= gen->blksperdisk) 
	    || (blkno < 0) 
	    || (tmp->bcount <= 0)) 
       {
	 blkno = tmp->blkno + 
	   (int)synthio_getrand(&gen->locdist) / gen->blocksize;
	 tmp->bcount = ((int) synthio_getrand(&gen->sizedist) + 
			gen->blocksize - 1) / gen->blocksize;
       }
     tmp->blkno = blkno;
     if (DISKSIM_drand48() < gen->probread) {
       tmp->flags |= READ;
     }
   } 
   else {
      tmp->time = -1.0;
      while (tmp->time < 0.0) {
	tmp->time = synthio_getrand(&gen->genintr);
      }
      tmp->flags = 0;
      tmp->cause = gen->number;
      tmp->devno = gen->devno[(int)(DISKSIM_drand48() * 
				    (double)gen->numdisks)];

      tmp->blkno = tmp->bcount = gen->blksperdisk;
      while (((tmp->blkno + tmp->bcount) >= gen->blksperdisk) || 
	     (tmp->bcount <= 0)) {

	tmp->blkno = (int) (DISKSIM_drand48() * (double)gen->blksperdisk);
	tmp->bcount = ((int) synthio_getrand(&gen->sizedist) + 
		       gen->blocksize - 1) / gen->blocksize;
      }

      if (DISKSIM_drand48() < gen->probread) {
	tmp->flags = READ;
      }
   }
   reqclass = DISKSIM_drand48() - gen->probtmcrit;

   if (reqclass < 0.0) {
     tmp->flags |= TIME_CRITICAL;
   } 
   else if (reqclass < gen->probtmlim) {
     tmp->flags |= TIME_LIMITED;
   }
   return 1;
}


void synthio_generate_io_activity (process *procp)
{
   synthio_generator *gen;

   gen = (synthio_generator *) procp->space;

   //   fprintf (stderr, "simtime %f, endtime %f, iocnt %d, endiocnt %d\n", simtime, synthio_endtime, synthio_iocnt, synthio_endiocnt);
   
   synthio_iocnt++;
   if (synthio_generatenextio(gen)) {
      synthio_appendio(procp, gen->pendio);
   } else {
      disksim_simstop();
   }
}




void synthio_resetstats()
{
}


void synthio_cleanstats()
{
}


void synthio_printstats()
{
}


static void synthio_read_uniform (FILE *parfile, synthio_distr *newdistr, double mult)
{
   newdistr->type = SYNTHIO_UNIFORM;
   if (fscanf(parfile, "Minimum value: %lf\n", &newdistr->base) != 1) {
      fprintf(stderr, "Error reading 'minimum value'\n");
      exit(1);
   }
   fprintf (outputfile, "Minimum value: %f\n", newdistr->base);
   newdistr->base *= mult;
   if (fscanf(parfile, "Maximum value: %lf\n", &newdistr->var) != 1) {
      fprintf(stderr, "Error reading 'maximum value'\n");
      exit(1);
   }
   fprintf (outputfile, "Maximum value: %f\n", newdistr->var);
   newdistr->var *= mult;
   if (newdistr->var <= newdistr->base) {
      fprintf(stderr, "'maximum value' is not greater than 'minimum value' - %f <= %f\n", newdistr->var, newdistr->base);
      exit(1);
   }
}


static void synthio_read_normal (FILE *parfile, synthio_distr *newdistr, double mult)
{
   newdistr->type = SYNTHIO_NORMAL;
   if (fscanf(parfile, "Mean: %lf\n", &newdistr->mean) != 1) {
      fprintf(stderr, "Error reading normal mean\n");
      exit(1);
   }
   fprintf (outputfile, "Mean: %f\n", newdistr->mean);
   newdistr->mean *= mult;
   if (fscanf(parfile, "Variance: %lf\n", &newdistr->var) != 1) {
      fprintf(stderr, "Error reading normal variance\n");
      exit(1);
   }
   fprintf (outputfile, "Variance: %f\n", newdistr->var);
   if (newdistr->var < 0) {
      fprintf(stderr, "Invalid value for 'variance' - %f\n", newdistr->var);
      exit(1);
   }
   newdistr->var = mult * sqrt(newdistr->var);
}


static void synthio_read_exponential (FILE *parfile, synthio_distr *newdistr, double mult)
{
   newdistr->type = SYNTHIO_EXPONENTIAL;
   if (fscanf(parfile, "Base value: %lf\n", &newdistr->base) != 1) {
      fprintf(stderr, "Error reading exponential base\n");
      exit(1);
   }
   fprintf (outputfile, "Base value: %f\n", newdistr->base);
   newdistr->base *= mult;
   if (fscanf(parfile, "Mean: %lf\n", &newdistr->mean) != 1) {
      fprintf(stderr, "Error reading exponential mean\n");
      exit(1);
   }
   fprintf (outputfile, "Mean: %f\n", newdistr->mean);
   newdistr->mean *= mult;
}


static void synthio_read_poisson (FILE *parfile, synthio_distr *newdistr, double mult)
{
   newdistr->type = SYNTHIO_POISSON;
   if (fscanf(parfile, "Base value: %lf\n", &newdistr->base) != 1) {
      fprintf(stderr, "Error reading 'base value'\n");
      exit(1);
   }
   fprintf (outputfile, "Base value: %f\n", newdistr->base);
   newdistr->base *= mult;
   if (fscanf(parfile, "Mean: %lf\n", &newdistr->mean) != 1) {
      fprintf(stderr, "Error reading poisson mean\n");
      exit(1);
   }
   fprintf (outputfile, "Mean: %f\n", newdistr->mean);
   newdistr->mean *= mult;
}


static void synthio_read_twovalue (FILE *parfile, synthio_distr *newdistr, double mult)
{
   newdistr->type = SYNTHIO_TWOVALUE;
   if (fscanf(parfile, "Default value: %lf\n", &newdistr->base) != 1) {
      fprintf(stderr, "Error reading 'default value'\n");
      exit(1);
   }
   fprintf(outputfile, "Default value: %f\n", newdistr->base);
   newdistr->base *= mult;
   if (fscanf(parfile, "Second value: %lf\n", &newdistr->mean) != 1) {
      fprintf(stderr, "Error reading 'second value'\n");
      exit(1);
   }
   fprintf(outputfile, "Second value: %f\n", newdistr->mean);
   newdistr->mean *= mult;
   if (fscanf(parfile, "Probability of second value: %lf\n", &newdistr->var) != 1) {
      fprintf(stderr, "Error reading 'probability of second value'\n");
      exit(1);
   }
   if ((newdistr->var < 0) || (newdistr->var > 1)) {
      fprintf(stderr, "Invalid probability of second value - %f\n", newdistr->var);
      exit(1);
   }
   fprintf(outputfile, "Probability of second value: %f\n", newdistr->var);
}


static void synthio_read_distr (FILE *parfile, synthio_distr *newdistr, double mult)
{
   char type[80];

   if (fscanf(parfile, "Type of distribution: %s\n", type) != 1) {
      fprintf(stderr, "Error reading 'type of distribution'\n");
      exit(1);
   }
   fprintf (outputfile, "Type of distribution: %s\n", type);
   switch (type[0]) {
      case 'u':
		synthio_read_uniform(parfile, newdistr, mult);
		break;
      case 'n':
		synthio_read_normal(parfile, newdistr, mult);
		break;
      case 'e':
		synthio_read_exponential(parfile, newdistr, mult);
		break;
      case 'p':
		synthio_read_poisson(parfile, newdistr, mult);
		break;
      case 't':
		synthio_read_twovalue(parfile, newdistr, mult);
		break;
      default:
                fprintf(stderr, "Invalid value for 'type of distribution' - %s\n", type);
                exit(1);
   }

}


static void synthio_distrcopy (synthio_distr *distr1, synthio_distr *distr2)
{
   distr2->base = distr1->base;
   distr2->mean = distr1->mean;
   distr2->var = distr1->var;
   distr2->type = distr1->type;
}


static void synthio_gencopy (synthio_generator *gen1, synthio_generator *gen2)
{
   gen2->probseq = gen1->probseq;
   gen2->probloc = gen1->probloc;
   gen2->probread = gen1->probread;
   gen2->probtmcrit = gen1->probtmcrit;
   gen2->probtmlim = gen1->probtmlim;
   gen2->tracefile = NULL; /* No good way to copy the descriptor */
   gen2->pendio = NULL;
   gen2->limits = NULL;
   gen2->numdisks = gen1->numdisks;
   memcpy(gen2->devno, gen1->devno, gen1->numdisks * sizeof(int));
   gen2->numblocks = gen1->numblocks;
   gen2->sectsperdisk = gen1->sectsperdisk;
   gen2->blksperdisk = gen1->blksperdisk;
   gen2->blocksize = gen1->blocksize;
   synthio_distrcopy(&gen1->tmlimit, &gen2->tmlimit);
   synthio_distrcopy(&gen1->genintr, &gen2->genintr);
   synthio_distrcopy(&gen1->seqintr, &gen2->seqintr);
   synthio_distrcopy(&gen1->locintr, &gen2->locintr);
   synthio_distrcopy(&gen1->locdist, &gen2->locdist);
   synthio_distrcopy(&gen1->sizedist, &gen2->sizedist);
}





int loadsynthgenerators(synthio_generator *result,
			struct lp_list *l);


/*  static void add_gen(synthio_generator **a, int *len,  */
/*  		    synthio_generator *newgen) { */
/*    int c, newlen; */

/*    for(c = 0; c < (*len); c++) { */
/*      if(!a[c]) goto foundslot; */
/*    } */

/*    newlen = (*len) ? 2 *(*len) : 2; */
/*    a = realloc(a, newlen * sizeof(synthio_generator *)); */
/*    if(*len) */
/*      bzero(a + c, c * sizeof(synthio_generator *)); */
/*    else */
/*      bzero(a, 2 * sizeof(synthio_generator *)); */

/*   *l = newlen; */

/*   foundslot: */
/*   a[c] = newgen; */


/*  } */

int disksim_synthio_loadparams(struct lp_block *b) {

  if(!disksim->synthio_info) {
    disksim->synthio_info = DISKSIM_malloc (sizeof(synthio_info_t));
    bzero ((char *)disksim->synthio_info, sizeof(synthio_info_t));
  }

    
/*    unparse_block(b, outputfile); */

  //#include "modules/disksim_synthio_param.c"
  lp_loadparams(0, b, &disksim_synthio_mod);

  return 1;
}


static int loadgen(struct lp_block *b, synthio_generator **result);

int 
loadsynthgenerators(synthio_generator *junk,
		    struct lp_list *l)
{
  int c;
  process *procp;
  int slot = 0;

  if(synthio_gens) {
    fprintf(stderr, "*** error: tried to redefine synth. I/O generators.\n");
    return -1;
  }

  synthio_gens = malloc(l->values_len * sizeof(synthio_generator));
  bzero(synthio_gens, l->values_len * sizeof(synthio_generator));
  disksim->synthio_info->synthio_gens_len = l->values_len;

  for(c = 0; c < l->values_len; c++) {
    if(!l->values[c]) continue;

    if(l->values[c]->t != BLOCK) {
      fprintf(stderr, "*** error: bad synthio io generator spec -- must be a block.\n");
      return -1;
    }

    if(loadgen(l->values[c]->v.b, &synthio_gens[slot]))
      return -1;

    slot++;
  }

  for(c = 0; c < slot; c++) {
    procp = pf_new_process(); 
    // XXX ??
    procp->space = (char *)synthio_gens[c];
    synthio_gens[c]->number = c;
  }

  synthio_gencnt = slot;
  return 0;
}


static char *distnames[] = {
  "uniform",
  "normal",
  "exponential",
  "poisson",
  "twovalue"
};

static int distname(char *name) {
  int c;
  for(c = SYNTHIO_UNIFORM; c <= SYNTHIO_TWOVALUE; c++) {
    if(!strcmp(name, distnames[c])) return c;
  }
  return -1;
}

int loaddistn(struct lp_list *l, struct dist *result) {
  int d;
  char *type;

  if(!l->values[0]) {
    return -1;
  }
  else if(l->values[0]->t != S) {
    return -1;
  }
  type = l->values[0]->v.s;

  result->type = distname(type);
  switch(result->type) {

  case SYNTHIO_UNIFORM:
    if(l->values_len < 3) {

    }
    for(d = 1; d <= 3; d++) {
      if(!l->values[d]) { }
      else if(l->values[d]->t != D) { }
    }

    result->base = l->values[1]->v.d;
    result->var = l->values[2]->v.d;
    break;

  case SYNTHIO_NORMAL:
    if(l->values_len < 3) {

    }
    for(d = 1; d <= 3; d++) {
      if(!l->values[d]) { }
      else if(l->values[d]->t != D) { }
    }

/*      result->base = l->values[1]->v.d; */
    result->mean = l->values[1]->v.d; 
    result->var = l->values[2]->v.d;
    break;

  case SYNTHIO_EXPONENTIAL:
    if(l->values_len < 3) {

    }
    for(d = 1; d <= 3; d++) {
      if(!l->values[d]) { }
      else if(l->values[d]->t != D) { }
    }

    result->base = l->values[1]->v.d;
    result->mean = l->values[2]->v.d;
    break;

  case SYNTHIO_POISSON:
    if(l->values_len < 3) {

    }
    for(d = 1; d <= 3; d++) {
      if(!l->values[d]) { }
      else if(l->values[d]->t != D) { }
    }

    result->base = l->values[1]->v.d;
    result->mean = l->values[2]->v.d;
    break;

  case SYNTHIO_TWOVALUE:
    if(l->values_len < 4) {

    }
    for(d = 1; d <= 4; d++) {
      if(!l->values[d]) { }
      else if(l->values[d]->t != D) { }
    }

    result->base = l->values[1]->v.d;
    result->mean = l->values[2]->v.d;
    result->var = l->values[3]->v.d;
    if(!RANGE(result->var,0.0,1.0)) {

    }
    break;

  default:
    fprintf(stderr, "*** error: unknown distribution: %s\n", type);
    return -1;
    break;
  }


  return 0;
}

/* this is a dummy that should never be called */
int disksim_synthgen_loadparams(struct lp_block *b) { 
  ddbg_assert2(0, "this is a dummy that isn't supposed to be called");
  return 0;
}

int loadsynthdevs(synthio_generator *result, struct lp_list *l);

static int loadgen(struct lp_block *b, synthio_generator **result) {

  (*result) = malloc(sizeof(synthio_generator));
  bzero((*result), sizeof(synthio_generator));

  //#include "modules/disksim_synthgen_param.c"
  lp_loadparams(result, b, &disksim_synthgen_mod);

  (*result)->numblocks = (*result)->sectsperdisk * (*result)->numdisks; 
  (*result)->blksperdisk = (*result)->sectsperdisk / (*result)->blocksize;

  return 0;
}



int 
loadsynthdevs(synthio_generator *result, struct lp_list *l)
{
  int c;
  int num, type;
  char *name;
  int slot = 0;

  result->devno = malloc(l->values_len * sizeof(int));
  bzero(result->devno, l->values_len * sizeof(int));
  
  for(c = 0; c < l->values_len; c++) {
    if(!l->values[c]) continue;
    if(l->values[c]->t != S) {
      /* error */
      return -1;
    }
    name = l->values[c]->v.s;
    
    if(!getdevbyname(name, &num, 0, &type)) {
      if(!getlogorgbyname(sysorgs, numsysorgs, name, &num)) {
	fprintf(stderr, "*** error: bad device %s in synthetic generator spec: no such device or logorg.\n", name);
	return -1;
      }
    }

    result->devno[slot++] = num;
  }


  result->numdisks = slot;

  return 0;
}
