#include "disksim_synthio_param.h"
#include <libparam/bitvector.h>
#include "../disksim_synthio.h"
static int DISKSIM_SYNTHIO_NUMBER_OF_IO_REQUESTS_TO_GENERATE_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHIO_NUMBER_OF_IO_REQUESTS_TO_GENERATE_loader(int result, int i) { 
if (! (i > 0)) { // foo 
 } 
 synthio_endiocnt = i;

}

static int DISKSIM_SYNTHIO_MAXIMUM_TIME_OF_TRACE_GENERATED_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHIO_MAXIMUM_TIME_OF_TRACE_GENERATED_loader(int result, double d) { 
if (! (d > 0.0)) { // foo 
 } 
 synthio_endtime = d; synthio_endtime *= 1000.0;

}

static int DISKSIM_SYNTHIO_SYSTEM_CALLRETURN_WITH_EACH_REQUEST_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHIO_SYSTEM_CALLRETURN_WITH_EACH_REQUEST_loader(int result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 synthio_syscalls = i;

}

static int DISKSIM_SYNTHIO_THINK_TIME_FROM_CALL_TO_REQUEST_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHIO_THINK_TIME_FROM_CALL_TO_REQUEST_loader(int result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 synthio_syscall_time = d;

}

static int DISKSIM_SYNTHIO_THINK_TIME_FROM_REQUEST_TO_RETURN_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHIO_THINK_TIME_FROM_REQUEST_TO_RETURN_loader(int result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 synthio_sysret_time = d;

}

static int DISKSIM_SYNTHIO_GENERATORS_depend(char *bv) {
return -1;
}

static void DISKSIM_SYNTHIO_GENERATORS_loader(int result, struct lp_list *l) { 
if (! (!loadsynthgenerators(0,l))) { // foo 
 } 

}

void * DISKSIM_SYNTHIO_loaders[] = {
(void *)DISKSIM_SYNTHIO_NUMBER_OF_IO_REQUESTS_TO_GENERATE_loader,
(void *)DISKSIM_SYNTHIO_MAXIMUM_TIME_OF_TRACE_GENERATED_loader,
(void *)DISKSIM_SYNTHIO_SYSTEM_CALLRETURN_WITH_EACH_REQUEST_loader,
(void *)DISKSIM_SYNTHIO_THINK_TIME_FROM_CALL_TO_REQUEST_loader,
(void *)DISKSIM_SYNTHIO_THINK_TIME_FROM_REQUEST_TO_RETURN_loader,
(void *)DISKSIM_SYNTHIO_GENERATORS_loader
};

lp_paramdep_t DISKSIM_SYNTHIO_deps[] = {
DISKSIM_SYNTHIO_NUMBER_OF_IO_REQUESTS_TO_GENERATE_depend,
DISKSIM_SYNTHIO_MAXIMUM_TIME_OF_TRACE_GENERATED_depend,
DISKSIM_SYNTHIO_SYSTEM_CALLRETURN_WITH_EACH_REQUEST_depend,
DISKSIM_SYNTHIO_THINK_TIME_FROM_CALL_TO_REQUEST_depend,
DISKSIM_SYNTHIO_THINK_TIME_FROM_REQUEST_TO_RETURN_depend,
DISKSIM_SYNTHIO_GENERATORS_depend
};

