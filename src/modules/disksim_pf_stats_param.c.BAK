#include "disksim_pf_stats_param.h"
#include <libparam/bitvector.h>
#include "../disksim_pfsim.h"
static int DISKSIM_PF_STATS_PRINT_PER_PROCESS_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_PF_STATS_PRINT_PER_PROCESS_STATS_loader(int result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 pf_print_perprocessstats = i;

}

static int DISKSIM_PF_STATS_PRINT_PER_CPU_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_PF_STATS_PRINT_PER_CPU_STATS_loader(int result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 pf_print_percpustats = i;

}

static int DISKSIM_PF_STATS_PRINT_ALL_INTERRUPT_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_PF_STATS_PRINT_ALL_INTERRUPT_STATS_loader(int result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 pf_print_intrstats = i;

}

static int DISKSIM_PF_STATS_PRINT_SLEEP_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_PF_STATS_PRINT_SLEEP_STATS_loader(int result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 pf_print_sleepstats = i;

}

void * DISKSIM_PF_STATS_loaders[] = {
(void *)DISKSIM_PF_STATS_PRINT_PER_PROCESS_STATS_loader,
(void *)DISKSIM_PF_STATS_PRINT_PER_CPU_STATS_loader,
(void *)DISKSIM_PF_STATS_PRINT_ALL_INTERRUPT_STATS_loader,
(void *)DISKSIM_PF_STATS_PRINT_SLEEP_STATS_loader
};

lp_paramdep_t DISKSIM_PF_STATS_deps[] = {
DISKSIM_PF_STATS_PRINT_PER_PROCESS_STATS_depend,
DISKSIM_PF_STATS_PRINT_PER_CPU_STATS_depend,
DISKSIM_PF_STATS_PRINT_ALL_INTERRUPT_STATS_depend,
DISKSIM_PF_STATS_PRINT_SLEEP_STATS_depend
};

