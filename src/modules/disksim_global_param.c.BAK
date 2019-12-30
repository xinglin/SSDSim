#include "disksim_global_param.h"
#include <libparam/bitvector.h>
#include "../disksim_global.h"
#include <libddbg/libddbg.h>
static int DISKSIM_GLOBAL_INIT_SEED_depend(char *bv) {
return -1;
}

static void DISKSIM_GLOBAL_INIT_SEED_loader(int result, int i) { 
 disksim->seedval = i;
 DISKSIM_srand48(disksim->seedval);

}

static int DISKSIM_GLOBAL_INIT_SEED_WITH_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_GLOBAL_INIT_SEED_WITH_TIME_loader(int result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 if(i) { disksim->seedval = DISKSIM_time(); }

}

static int DISKSIM_GLOBAL_REAL_SEED_depend(char *bv) {
return -1;
}

static void DISKSIM_GLOBAL_REAL_SEED_loader(int result, int i) { 
 disksim->seedval = i;

}

static int DISKSIM_GLOBAL_REAL_SEED_WITH_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_GLOBAL_REAL_SEED_WITH_TIME_loader(int result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 disksim->seedval = DISKSIM_time();

}

static int DISKSIM_GLOBAL_STATISTIC_WARM_UP_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_GLOBAL_STATISTIC_WARM_UP_TIME_loader(int result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 disksim->warmup_event = (timer_event *) getfromextraq();
 disksim->warmup_event->type = TIMER_EXPIRED;
 disksim->warmup_event->time = d * (double) 1000.0;
 disksim->warmup_event->func = &disksim->timerfunc_disksim;

}

static int DISKSIM_GLOBAL_STATISTIC_WARM_UP_IOS_depend(char *bv) {
return -1;
}

static void DISKSIM_GLOBAL_STATISTIC_WARM_UP_IOS_loader(int result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 disksim->warmup_iocnt = i;

}

static int DISKSIM_GLOBAL_STAT_DEFINITION_FILE_depend(char *bv) {
return -1;
}

static void DISKSIM_GLOBAL_STAT_DEFINITION_FILE_loader(int result, char *s) { 
 char *path = lp_search_path(lp_cwd, s);
 if(!path) {
 ddbg_assert2(0, "Couldn't find statdefs file in path");
 }
 else {
 statdeffile = fopen(path, "r");
 ddbg_assert2(statdeffile != 0, "failed to open statdefs file!");
 }

}

static int DISKSIM_GLOBAL_OUTPUT_FILE_FOR_TRACE_OF_IO_REQUESTS_SIMULATED_depend(char *bv) {
return -1;
}

static void DISKSIM_GLOBAL_OUTPUT_FILE_FOR_TRACE_OF_IO_REQUESTS_SIMULATED_loader(int result, char *s) { 
if (! ((outios = fopen(s, "w")) != NULL)) { // foo 
 } 
 strcpy(disksim->outiosfilename, s);

}

static int DISKSIM_GLOBAL_DETAILED_EXECUTION_TRACE_depend(char *bv) {
return -1;
}

static void DISKSIM_GLOBAL_DETAILED_EXECUTION_TRACE_loader(int result, char *s) { 
if (! ((disksim->exectrace = fopen(s, "w")) != NULL)) { // foo 
 } 
 disksim->exectrace_fn = strdup(s);

}

void * DISKSIM_GLOBAL_loaders[] = {
(void *)DISKSIM_GLOBAL_INIT_SEED_loader,
(void *)DISKSIM_GLOBAL_INIT_SEED_WITH_TIME_loader,
(void *)DISKSIM_GLOBAL_REAL_SEED_loader,
(void *)DISKSIM_GLOBAL_REAL_SEED_WITH_TIME_loader,
(void *)DISKSIM_GLOBAL_STATISTIC_WARM_UP_TIME_loader,
(void *)DISKSIM_GLOBAL_STATISTIC_WARM_UP_IOS_loader,
(void *)DISKSIM_GLOBAL_STAT_DEFINITION_FILE_loader,
(void *)DISKSIM_GLOBAL_OUTPUT_FILE_FOR_TRACE_OF_IO_REQUESTS_SIMULATED_loader,
(void *)DISKSIM_GLOBAL_DETAILED_EXECUTION_TRACE_loader
};

lp_paramdep_t DISKSIM_GLOBAL_deps[] = {
DISKSIM_GLOBAL_INIT_SEED_depend,
DISKSIM_GLOBAL_INIT_SEED_WITH_TIME_depend,
DISKSIM_GLOBAL_REAL_SEED_depend,
DISKSIM_GLOBAL_REAL_SEED_WITH_TIME_depend,
DISKSIM_GLOBAL_STATISTIC_WARM_UP_TIME_depend,
DISKSIM_GLOBAL_STATISTIC_WARM_UP_IOS_depend,
DISKSIM_GLOBAL_STAT_DEFINITION_FILE_depend,
DISKSIM_GLOBAL_OUTPUT_FILE_FOR_TRACE_OF_IO_REQUESTS_SIMULATED_depend,
DISKSIM_GLOBAL_DETAILED_EXECUTION_TRACE_depend
};

