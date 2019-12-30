#include "disksim_stats_param.h"
#include <libparam/bitvector.h>
static int DISKSIM_STATS_IODRIVER_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_STATS_IODRIVER_STATS_loader(int result, struct lp_block *blk) { 
if (! (disksim_iodriver_stats_loadparams(blk))) { // foo 
 } 

}

static int DISKSIM_STATS_BUS_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_STATS_BUS_STATS_loader(int result, struct lp_block *blk) { 
if (! (disksim_bus_stats_loadparams(blk))) { // foo 
 } 

}

static int DISKSIM_STATS_CTLR_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_STATS_CTLR_STATS_loader(int result, struct lp_block *blk) { 
if (! (disksim_ctlr_stats_loadparams(blk))) { // foo 
 } 

}

static int DISKSIM_STATS_DEVICE_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_STATS_DEVICE_STATS_loader(int result, struct lp_block *blk) { 
if (! (disksim_device_stats_loadparams(blk))) { // foo 
 } 

}

static int DISKSIM_STATS_PROCESS_FLOW_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_STATS_PROCESS_FLOW_STATS_loader(int result, struct lp_block *blk) { 
if (! (disksim_pf_stats_loadparams(blk))) { // foo 
 } 

}

void * DISKSIM_STATS_loaders[] = {
(void *)DISKSIM_STATS_IODRIVER_STATS_loader,
(void *)DISKSIM_STATS_BUS_STATS_loader,
(void *)DISKSIM_STATS_CTLR_STATS_loader,
(void *)DISKSIM_STATS_DEVICE_STATS_loader,
(void *)DISKSIM_STATS_PROCESS_FLOW_STATS_loader
};

lp_paramdep_t DISKSIM_STATS_deps[] = {
DISKSIM_STATS_IODRIVER_STATS_depend,
DISKSIM_STATS_BUS_STATS_depend,
DISKSIM_STATS_CTLR_STATS_depend,
DISKSIM_STATS_DEVICE_STATS_depend,
DISKSIM_STATS_PROCESS_FLOW_STATS_depend
};

