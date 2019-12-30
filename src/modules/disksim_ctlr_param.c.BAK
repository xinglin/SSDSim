#include "disksim_ctlr_param.h"
#include <libparam/bitvector.h>
#include "../disksim_ctlr.h"
static int DISKSIM_CTLR_TYPE_depend(char *bv) {
return -1;
}

static void DISKSIM_CTLR_TYPE_loader(struct controller * result, int i) { 
if (! (RANGE(i,1,3))) { // foo 
 } 
 result->type = i;

}

static int DISKSIM_CTLR_SCALE_FOR_DELAYS_depend(char *bv) {
return -1;
}

static void DISKSIM_CTLR_SCALE_FOR_DELAYS_loader(struct controller * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->timescale = d;

}

static int DISKSIM_CTLR_BULK_SECTOR_TRANSFER_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_CTLR_BULK_SECTOR_TRANSFER_TIME_loader(struct controller * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->blktranstime = d;

}

static int DISKSIM_CTLR_MAXIMUM_QUEUE_LENGTH_depend(char *bv) {
return -1;
}

static void DISKSIM_CTLR_MAXIMUM_QUEUE_LENGTH_loader(struct controller * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->maxoutstanding = i + 1;

}

static int DISKSIM_CTLR_PRINT_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_CTLR_PRINT_STATS_loader(struct controller * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->printstats = i;

}

static int DISKSIM_CTLR_SCHEDULER_depend(char *bv) {
return -1;
}

static void DISKSIM_CTLR_SCHEDULER_loader(struct controller * result, struct lp_block *blk) { 
if (! (result->queue = (struct ioq *)disksim_ioqueue_loadparams(blk, disksim->ctlrinfo->ctl_printqueuestats, disksim->ctlrinfo->ctl_printcritstats, disksim->ctlrinfo->ctl_printidlestats, disksim->ctlrinfo->ctl_printintarrstats,disksim->ctlrinfo->ctl_printsizestats))) { // foo 
 } 

}

static int DISKSIM_CTLR_CACHE_depend(char *bv) {
return -1;
}

static void DISKSIM_CTLR_CACHE_loader(struct controller * result, struct lp_block *blk) { 
if (! (result->cache = disksim_cache_loadparams(blk))) { // foo 
 } 

}

static int DISKSIM_CTLR_MAX_PER_DISK_PENDING_COUNT_depend(char *bv) {
return -1;
}

static void DISKSIM_CTLR_MAX_PER_DISK_PENDING_COUNT_loader(struct controller * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->maxdiskqsize = i;

}

void * DISKSIM_CTLR_loaders[] = {
(void *)DISKSIM_CTLR_TYPE_loader,
(void *)DISKSIM_CTLR_SCALE_FOR_DELAYS_loader,
(void *)DISKSIM_CTLR_BULK_SECTOR_TRANSFER_TIME_loader,
(void *)DISKSIM_CTLR_MAXIMUM_QUEUE_LENGTH_loader,
(void *)DISKSIM_CTLR_PRINT_STATS_loader,
(void *)DISKSIM_CTLR_SCHEDULER_loader,
(void *)DISKSIM_CTLR_CACHE_loader,
(void *)DISKSIM_CTLR_MAX_PER_DISK_PENDING_COUNT_loader
};

lp_paramdep_t DISKSIM_CTLR_deps[] = {
DISKSIM_CTLR_TYPE_depend,
DISKSIM_CTLR_SCALE_FOR_DELAYS_depend,
DISKSIM_CTLR_BULK_SECTOR_TRANSFER_TIME_depend,
DISKSIM_CTLR_MAXIMUM_QUEUE_LENGTH_depend,
DISKSIM_CTLR_PRINT_STATS_depend,
DISKSIM_CTLR_SCHEDULER_depend,
DISKSIM_CTLR_CACHE_depend,
DISKSIM_CTLR_MAX_PER_DISK_PENDING_COUNT_depend
};

