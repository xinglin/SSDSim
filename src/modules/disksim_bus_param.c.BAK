#include "disksim_bus_param.h"
#include <libparam/bitvector.h>
#include "../disksim_bus.h"
static int DISKSIM_BUS_TYPE_depend(char *bv) {
return -1;
}

static void DISKSIM_BUS_TYPE_loader(struct bus * result, int i) { 
if (! (RANGE(i,1,2))) { // foo 
 } 
 result->type = i;

}

static int DISKSIM_BUS_ARBITRATION_TYPE_depend(char *bv) {
return -1;
}

static void DISKSIM_BUS_ARBITRATION_TYPE_loader(struct bus * result, int i) { 
if (! (RANGE(i,1,2))) { // foo 
 } 
 result->arbtype = i;

}

static int DISKSIM_BUS_ARBITRATION_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_BUS_ARBITRATION_TIME_loader(struct bus * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->arbtime = d;

}

static int DISKSIM_BUS_READ_BLOCK_TRANSFER_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_BUS_READ_BLOCK_TRANSFER_TIME_loader(struct bus * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->readblktranstime = d;

}

static int DISKSIM_BUS_WRITE_BLOCK_TRANSFER_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_BUS_WRITE_BLOCK_TRANSFER_TIME_loader(struct bus * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->writeblktranstime = d;

}

static int DISKSIM_BUS_PRINT_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_BUS_PRINT_STATS_loader(struct bus * result, int i) { 
 result->printstats = i;

}

void * DISKSIM_BUS_loaders[] = {
(void *)DISKSIM_BUS_TYPE_loader,
(void *)DISKSIM_BUS_ARBITRATION_TYPE_loader,
(void *)DISKSIM_BUS_ARBITRATION_TIME_loader,
(void *)DISKSIM_BUS_READ_BLOCK_TRANSFER_TIME_loader,
(void *)DISKSIM_BUS_WRITE_BLOCK_TRANSFER_TIME_loader,
(void *)DISKSIM_BUS_PRINT_STATS_loader
};

lp_paramdep_t DISKSIM_BUS_deps[] = {
DISKSIM_BUS_TYPE_depend,
DISKSIM_BUS_ARBITRATION_TYPE_depend,
DISKSIM_BUS_ARBITRATION_TIME_depend,
DISKSIM_BUS_READ_BLOCK_TRANSFER_TIME_depend,
DISKSIM_BUS_WRITE_BLOCK_TRANSFER_TIME_depend,
DISKSIM_BUS_PRINT_STATS_depend
};

