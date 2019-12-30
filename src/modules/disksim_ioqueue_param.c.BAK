#include "disksim_ioqueue_param.h"
#include <libparam/bitvector.h>
#include "../disksim_ioqueue.h"
static int DISKSIM_IOQUEUE_SCHEDULING_POLICY_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_SCHEDULING_POLICY_loader(struct ioq * result, int i) { 
if (! (RANGE(i,MINSCHED,MAXSCHED))) { // foo 
 } 
 result->base.sched_alg = i;

}

static int DISKSIM_IOQUEUE_CYLINDER_MAPPING_STRATEGY_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_CYLINDER_MAPPING_STRATEGY_loader(struct ioq * result, int i) { 
if (! (RANGE(i,0,6))) { // foo 
 } 
 result->cylmaptype = i;

}

static int DISKSIM_IOQUEUE_WRITE_INITIATION_DELAY_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_WRITE_INITIATION_DELAY_loader(struct ioq * result, double d) { 
if (! (d >= 0)) { // foo 
 } 
 result->writedelay = d;

}

static int DISKSIM_IOQUEUE_READ_INITIATION_DELAY_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_READ_INITIATION_DELAY_loader(struct ioq * result, double d) { 
if (! (d >= 0)) { // foo 
 } 
 result->readdelay = d;

}

static int DISKSIM_IOQUEUE_SEQUENTIAL_STREAM_SCHEME_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_SEQUENTIAL_STREAM_SCHEME_loader(struct ioq * result, int i) { 
 result->seqscheme = i;

}

static int DISKSIM_IOQUEUE_MAXIMUM_CONCAT_SIZE_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_MAXIMUM_CONCAT_SIZE_loader(struct ioq * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->concatmax = i;

}

static int DISKSIM_IOQUEUE_OVERLAPPING_REQUEST_SCHEME_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_OVERLAPPING_REQUEST_SCHEME_loader(struct ioq * result, int i) { 
if (! (RANGE(i,0,2))) { // foo 
 } 
 result->comboverlaps = i;

}

static int DISKSIM_IOQUEUE_SEQUENTIAL_STREAM_DIFF_MAXIMUM_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_SEQUENTIAL_STREAM_DIFF_MAXIMUM_loader(struct ioq * result, int i) { 
if (! (RANGE(i,0,2))) { // foo 
 } 
 result->seqstreamdiff = i;

}

static int DISKSIM_IOQUEUE_SCHEDULING_TIMEOUT_SCHEME_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_SCHEDULING_TIMEOUT_SCHEME_loader(struct ioq * result, int i) { 
 if(disksim->verbosity > 0) fprintf(stderr, "** warning: ignoring \"Scheduling timeout scheme\" \n");

}

static int DISKSIM_IOQUEUE_TIMEOUT_TIMEWEIGHT_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_TIMEOUT_TIMEWEIGHT_loader(struct ioq * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->to_time = i;

}

static int DISKSIM_IOQUEUE_TIMEOUT_SCHEDULING_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_TIMEOUT_SCHEDULING_loader(struct ioq * result, int i) { 
if (! (RANGE(i,0,21))) { // foo 
 } 
 result->timeout.sched_alg = i;

}

static int DISKSIM_IOQUEUE_SCHEDULING_PRIORITY_SCHEME_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_SCHEDULING_PRIORITY_SCHEME_loader(struct ioq * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->pri_scheme = i;

}

static int DISKSIM_IOQUEUE_PRIORITY_SCHEDULING_depend(char *bv) {
return -1;
}

static void DISKSIM_IOQUEUE_PRIORITY_SCHEDULING_loader(struct ioq * result, int i) { 
if (! (RANGE(i,0,21))) { // foo 
 } 
 result->priority.sched_alg = i;

}

void * DISKSIM_IOQUEUE_loaders[] = {
(void *)DISKSIM_IOQUEUE_SCHEDULING_POLICY_loader,
(void *)DISKSIM_IOQUEUE_CYLINDER_MAPPING_STRATEGY_loader,
(void *)DISKSIM_IOQUEUE_WRITE_INITIATION_DELAY_loader,
(void *)DISKSIM_IOQUEUE_READ_INITIATION_DELAY_loader,
(void *)DISKSIM_IOQUEUE_SEQUENTIAL_STREAM_SCHEME_loader,
(void *)DISKSIM_IOQUEUE_MAXIMUM_CONCAT_SIZE_loader,
(void *)DISKSIM_IOQUEUE_OVERLAPPING_REQUEST_SCHEME_loader,
(void *)DISKSIM_IOQUEUE_SEQUENTIAL_STREAM_DIFF_MAXIMUM_loader,
(void *)DISKSIM_IOQUEUE_SCHEDULING_TIMEOUT_SCHEME_loader,
(void *)DISKSIM_IOQUEUE_TIMEOUT_TIMEWEIGHT_loader,
(void *)DISKSIM_IOQUEUE_TIMEOUT_SCHEDULING_loader,
(void *)DISKSIM_IOQUEUE_SCHEDULING_PRIORITY_SCHEME_loader,
(void *)DISKSIM_IOQUEUE_PRIORITY_SCHEDULING_loader
};

lp_paramdep_t DISKSIM_IOQUEUE_deps[] = {
DISKSIM_IOQUEUE_SCHEDULING_POLICY_depend,
DISKSIM_IOQUEUE_CYLINDER_MAPPING_STRATEGY_depend,
DISKSIM_IOQUEUE_WRITE_INITIATION_DELAY_depend,
DISKSIM_IOQUEUE_READ_INITIATION_DELAY_depend,
DISKSIM_IOQUEUE_SEQUENTIAL_STREAM_SCHEME_depend,
DISKSIM_IOQUEUE_MAXIMUM_CONCAT_SIZE_depend,
DISKSIM_IOQUEUE_OVERLAPPING_REQUEST_SCHEME_depend,
DISKSIM_IOQUEUE_SEQUENTIAL_STREAM_DIFF_MAXIMUM_depend,
DISKSIM_IOQUEUE_SCHEDULING_TIMEOUT_SCHEME_depend,
DISKSIM_IOQUEUE_TIMEOUT_TIMEWEIGHT_depend,
DISKSIM_IOQUEUE_TIMEOUT_SCHEDULING_depend,
DISKSIM_IOQUEUE_SCHEDULING_PRIORITY_SCHEME_depend,
DISKSIM_IOQUEUE_PRIORITY_SCHEDULING_depend
};

