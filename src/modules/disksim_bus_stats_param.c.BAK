#include "disksim_bus_stats_param.h"
#include <libparam/bitvector.h>
#include "disksim_bus.h"
static int DISKSIM_BUS_STATS_PRINT_BUS_IDLE_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_BUS_STATS_PRINT_BUS_IDLE_STATS_loader(int result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 disksim->businfo->bus_printidlestats = i;

}

static int DISKSIM_BUS_STATS_PRINT_BUS_ARBWAIT_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_BUS_STATS_PRINT_BUS_ARBWAIT_STATS_loader(int result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 disksim->businfo->bus_printarbwaitstats = i;

}

void * DISKSIM_BUS_STATS_loaders[] = {
(void *)DISKSIM_BUS_STATS_PRINT_BUS_IDLE_STATS_loader,
(void *)DISKSIM_BUS_STATS_PRINT_BUS_ARBWAIT_STATS_loader
};

lp_paramdep_t DISKSIM_BUS_STATS_deps[] = {
DISKSIM_BUS_STATS_PRINT_BUS_IDLE_STATS_depend,
DISKSIM_BUS_STATS_PRINT_BUS_ARBWAIT_STATS_depend
};

