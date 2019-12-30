#include "disksim_synthgen_param.h"
#include <libparam/bitvector.h>
#include "../disksim_synthio.h"
static int DISKSIM_SYNTHGEN_STORAGE_CAPACITY_PER_DEVICE_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_STORAGE_CAPACITY_PER_DEVICE_loader(synthio_generator ** result, int i) { 
if (! (i > 0)) { // foo 
 } 
 (*result)->sectsperdisk = i;

}

static int DISKSIM_SYNTHGEN_DEVICES_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_DEVICES_loader(synthio_generator ** result, struct lp_list *l) { 
if (! (!loadsynthdevs((*result), l))) { // foo 
 } 

}

static int DISKSIM_SYNTHGEN_BLOCKING_FACTOR_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_BLOCKING_FACTOR_loader(synthio_generator ** result, int i) { 
if (! (i > 0)) { // foo 
 } 
 (*result)->blocksize = i;

}

static int DISKSIM_SYNTHGEN_PROBABILITY_OF_SEQUENTIAL_ACCESS_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_PROBABILITY_OF_SEQUENTIAL_ACCESS_loader(synthio_generator ** result, double d) { 
if (! (RANGE(d,0.0,1.0))) { // foo 
 } 
 (*result)->probseq = d;

}

static int DISKSIM_SYNTHGEN_PROBABILITY_OF_LOCAL_ACCESS_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_PROBABILITY_OF_LOCAL_ACCESS_loader(synthio_generator ** result, double d) { 
if (! (RANGE(d,0.0,1.0))) { // foo 
 } 
 (*result)->probloc = d;

}

static int DISKSIM_SYNTHGEN_PROBABILITY_OF_READ_ACCESS_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_PROBABILITY_OF_READ_ACCESS_loader(synthio_generator ** result, double d) { 
if (! (RANGE(d,0.0,1.0))) { // foo 
 } 
 (*result)->probread = d;

}

static int DISKSIM_SYNTHGEN_PROBABILITY_OF_TIME_CRITICAL_REQUEST_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_PROBABILITY_OF_TIME_CRITICAL_REQUEST_loader(synthio_generator ** result, double d) { 
if (! (RANGE(d,0.0,1.0))) { // foo 
 } 
 (*result)->probtmcrit = d;

}

static int DISKSIM_SYNTHGEN_PROBABILITY_OF_TIME_LIMITED_REQUEST_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_PROBABILITY_OF_TIME_LIMITED_REQUEST_loader(synthio_generator ** result, double d) { 
if (! (RANGE(d,0.0,1.0))) { // foo 
 } 
 (*result)->probtmlim = d;

}

static int DISKSIM_SYNTHGEN_TIME_LIMITED_THINK_TIMES_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_TIME_LIMITED_THINK_TIMES_loader(synthio_generator ** result, struct lp_list *l) { 
if (! (!loaddistn(l, &(*result)->tmlimit))) { // foo 
 } 

}

static int DISKSIM_SYNTHGEN_GENERAL_INTER_ARRIVAL_TIMES_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_GENERAL_INTER_ARRIVAL_TIMES_loader(synthio_generator ** result, struct lp_list *l) { 
if (! (!loaddistn(l, &(*result)->genintr))) { // foo 
 } 

}

static int DISKSIM_SYNTHGEN_SEQUENTIAL_INTER_ARRIVAL_TIMES_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_SEQUENTIAL_INTER_ARRIVAL_TIMES_loader(synthio_generator ** result, struct lp_list *l) { 
if (! (!loaddistn(l, &(*result)->seqintr))) { // foo 
 } 

}

static int DISKSIM_SYNTHGEN_LOCAL_INTER_ARRIVAL_TIMES_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_LOCAL_INTER_ARRIVAL_TIMES_loader(synthio_generator ** result, struct lp_list *l) { 
if (! (!loaddistn(l, &(*result)->locintr))) { // foo 
 } 

}

static int DISKSIM_SYNTHGEN_LOCAL_DISTANCES_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_LOCAL_DISTANCES_loader(synthio_generator ** result, struct lp_list *l) { 
if (! (!loaddistn(l, &(*result)->locdist))) { // foo 
 } 

}

static int DISKSIM_SYNTHGEN_SIZES_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHGEN_SIZES_loader(synthio_generator ** result, struct lp_list *l) { 
if (! (!loaddistn(l, &(*result)->sizedist))) { // foo 
 } 

}

void * DISKSIM_SYNTHGEN_loaders[] = {
(void *)DISKSIM_SYNTHGEN_STORAGE_CAPACITY_PER_DEVICE_loader,
(void *)DISKSIM_SYNTHGEN_DEVICES_loader,
(void *)DISKSIM_SYNTHGEN_BLOCKING_FACTOR_loader,
(void *)DISKSIM_SYNTHGEN_PROBABILITY_OF_SEQUENTIAL_ACCESS_loader,
(void *)DISKSIM_SYNTHGEN_PROBABILITY_OF_LOCAL_ACCESS_loader,
(void *)DISKSIM_SYNTHGEN_PROBABILITY_OF_READ_ACCESS_loader,
(void *)DISKSIM_SYNTHGEN_PROBABILITY_OF_TIME_CRITICAL_REQUEST_loader,
(void *)DISKSIM_SYNTHGEN_PROBABILITY_OF_TIME_LIMITED_REQUEST_loader,
(void *)DISKSIM_SYNTHGEN_TIME_LIMITED_THINK_TIMES_loader,
(void *)DISKSIM_SYNTHGEN_GENERAL_INTER_ARRIVAL_TIMES_loader,
(void *)DISKSIM_SYNTHGEN_SEQUENTIAL_INTER_ARRIVAL_TIMES_loader,
(void *)DISKSIM_SYNTHGEN_LOCAL_INTER_ARRIVAL_TIMES_loader,
(void *)DISKSIM_SYNTHGEN_LOCAL_DISTANCES_loader,
(void *)DISKSIM_SYNTHGEN_SIZES_loader
};

lp_paramdep_t DISKSIM_SYNTHGEN_deps[] = {
DISKSIM_SYNTHGEN_STORAGE_CAPACITY_PER_DEVICE_depend,
DISKSIM_SYNTHGEN_DEVICES_depend,
DISKSIM_SYNTHGEN_BLOCKING_FACTOR_depend,
DISKSIM_SYNTHGEN_PROBABILITY_OF_SEQUENTIAL_ACCESS_depend,
DISKSIM_SYNTHGEN_PROBABILITY_OF_LOCAL_ACCESS_depend,
DISKSIM_SYNTHGEN_PROBABILITY_OF_READ_ACCESS_depend,
DISKSIM_SYNTHGEN_PROBABILITY_OF_TIME_CRITICAL_REQUEST_depend,
DISKSIM_SYNTHGEN_PROBABILITY_OF_TIME_LIMITED_REQUEST_depend,
DISKSIM_SYNTHGEN_TIME_LIMITED_THINK_TIMES_depend,
DISKSIM_SYNTHGEN_GENERAL_INTER_ARRIVAL_TIMES_depend,
DISKSIM_SYNTHGEN_SEQUENTIAL_INTER_ARRIVAL_TIMES_depend,
DISKSIM_SYNTHGEN_LOCAL_INTER_ARRIVAL_TIMES_depend,
DISKSIM_SYNTHGEN_LOCAL_DISTANCES_depend,
DISKSIM_SYNTHGEN_SIZES_depend
};

