#include "disksim_simpledisk_param.h"
#include <libparam/bitvector.h>
#include "../disksim_simpledisk.h"
static int DISKSIM_SIMPLEDISK_SCHEDULER_depend(char *bv) {
return -1;
}

static void DISKSIM_SIMPLEDISK_SCHEDULER_loader(struct simpledisk * result, struct lp_block *blk) { 
if (! (result->queue = (struct ioq *)disksim_ioqueue_loadparams(blk, device_printqueuestats, device_printcritstats, device_printidlestats, device_printintarrstats, device_printsizestats))) { // foo 
 } 

}

static int DISKSIM_SIMPLEDISK_MAX_QUEUE_LENGTH_depend(char *bv) {
return -1;
}

static void DISKSIM_SIMPLEDISK_MAX_QUEUE_LENGTH_loader(struct simpledisk * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->maxqlen = i;

}

static int DISKSIM_SIMPLEDISK_BLOCK_COUNT_depend(char *bv) {
return -1;
}

static void DISKSIM_SIMPLEDISK_BLOCK_COUNT_loader(struct simpledisk * result, int i) { 
if (! (i >= 1)) { // foo 
 } 
 result->numblocks = i;

}

static int DISKSIM_SIMPLEDISK_BUS_TRANSACTION_LATENCY_depend(char *bv) {
return -1;
}

static void DISKSIM_SIMPLEDISK_BUS_TRANSACTION_LATENCY_loader(struct simpledisk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->bus_transaction_latency = d;

}

static int DISKSIM_SIMPLEDISK_BULK_SECTOR_TRANSFER_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_SIMPLEDISK_BULK_SECTOR_TRANSFER_TIME_loader(struct simpledisk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->blktranstime = d;

}

static int DISKSIM_SIMPLEDISK_NEVER_DISCONNECT_depend(char *bv) {
return -1;
}

static void DISKSIM_SIMPLEDISK_NEVER_DISCONNECT_loader(struct simpledisk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->neverdisconnect = i;

}

static int DISKSIM_SIMPLEDISK_PRINT_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_SIMPLEDISK_PRINT_STATS_loader(struct simpledisk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->printstats = i;

}

static int DISKSIM_SIMPLEDISK_COMMAND_OVERHEAD_depend(char *bv) {
return -1;
}

static void DISKSIM_SIMPLEDISK_COMMAND_OVERHEAD_loader(struct simpledisk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead = d;

}

static int DISKSIM_SIMPLEDISK_CONSTANT_ACCESS_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_SIMPLEDISK_CONSTANT_ACCESS_TIME_loader(struct simpledisk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->acctime = d;

}

static int DISKSIM_SIMPLEDISK_ACCESS_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_SIMPLEDISK_ACCESS_TIME_loader(struct simpledisk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->acctime = d;

}

void * DISKSIM_SIMPLEDISK_loaders[] = {
(void *)DISKSIM_SIMPLEDISK_SCHEDULER_loader,
(void *)DISKSIM_SIMPLEDISK_MAX_QUEUE_LENGTH_loader,
(void *)DISKSIM_SIMPLEDISK_BLOCK_COUNT_loader,
(void *)DISKSIM_SIMPLEDISK_BUS_TRANSACTION_LATENCY_loader,
(void *)DISKSIM_SIMPLEDISK_BULK_SECTOR_TRANSFER_TIME_loader,
(void *)DISKSIM_SIMPLEDISK_NEVER_DISCONNECT_loader,
(void *)DISKSIM_SIMPLEDISK_PRINT_STATS_loader,
(void *)DISKSIM_SIMPLEDISK_COMMAND_OVERHEAD_loader,
(void *)DISKSIM_SIMPLEDISK_CONSTANT_ACCESS_TIME_loader,
(void *)DISKSIM_SIMPLEDISK_ACCESS_TIME_loader
};

lp_paramdep_t DISKSIM_SIMPLEDISK_deps[] = {
DISKSIM_SIMPLEDISK_SCHEDULER_depend,
DISKSIM_SIMPLEDISK_MAX_QUEUE_LENGTH_depend,
DISKSIM_SIMPLEDISK_BLOCK_COUNT_depend,
DISKSIM_SIMPLEDISK_BUS_TRANSACTION_LATENCY_depend,
DISKSIM_SIMPLEDISK_BULK_SECTOR_TRANSFER_TIME_depend,
DISKSIM_SIMPLEDISK_NEVER_DISCONNECT_depend,
DISKSIM_SIMPLEDISK_PRINT_STATS_depend,
DISKSIM_SIMPLEDISK_COMMAND_OVERHEAD_depend,
DISKSIM_SIMPLEDISK_CONSTANT_ACCESS_TIME_depend,
DISKSIM_SIMPLEDISK_ACCESS_TIME_depend
};

