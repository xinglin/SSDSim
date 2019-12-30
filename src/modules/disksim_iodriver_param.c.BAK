#include "disksim_iodriver_param.h"
#include <libparam/bitvector.h>
#include "../disksim_iodriver.h"
static int DISKSIM_IODRIVER_TYPE_depend(char *bv) {
return -1;
}

static void DISKSIM_IODRIVER_TYPE_loader(struct iodriver * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->type = i;

}

static int DISKSIM_IODRIVER_CONSTANT_ACCESS_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_IODRIVER_CONSTANT_ACCESS_TIME_loader(struct iodriver * result, double d) { 
if (! ((d >= 0.0) || (d == -3.0) || (d == -2.0) || (d == -1.0))) { // foo 
 } 
 result->consttime = d;

}

static int DISKSIM_IODRIVER_USE_QUEUEING_IN_SUBSYSTEM_depend(char *bv) {
return -1;
}

static void DISKSIM_IODRIVER_USE_QUEUEING_IN_SUBSYSTEM_loader(struct iodriver * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->usequeue = i;

}

static int DISKSIM_IODRIVER_SCHEDULER_depend(char *bv) {
return -1;
}

static void DISKSIM_IODRIVER_SCHEDULER_loader(struct iodriver * result, struct lp_block *blk) { 
if (! (result->queue = (struct ioq *)disksim_ioqueue_loadparams(blk, drv_printqueuestats, drv_printcritstats, drv_printidlestats, drv_printintarrstats, drv_printsizestats))) { // foo 
 } 

}

void * DISKSIM_IODRIVER_loaders[] = {
(void *)DISKSIM_IODRIVER_TYPE_loader,
(void *)DISKSIM_IODRIVER_CONSTANT_ACCESS_TIME_loader,
(void *)DISKSIM_IODRIVER_USE_QUEUEING_IN_SUBSYSTEM_loader,
(void *)DISKSIM_IODRIVER_SCHEDULER_loader
};

lp_paramdep_t DISKSIM_IODRIVER_deps[] = {
DISKSIM_IODRIVER_TYPE_depend,
DISKSIM_IODRIVER_CONSTANT_ACCESS_TIME_depend,
DISKSIM_IODRIVER_USE_QUEUEING_IN_SUBSYSTEM_depend,
DISKSIM_IODRIVER_SCHEDULER_depend
};

