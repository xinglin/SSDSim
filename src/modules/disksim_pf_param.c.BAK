#include "disksim_pf_param.h"
#include <libparam/bitvector.h>
#include "../disksim_pfsim.h"
static int DISKSIM_PF_NUMBER_OF_PROCESSORS_depend(char *bv) {
return -1;
}

static void DISKSIM_PF_NUMBER_OF_PROCESSORS_loader(int result, int i) { 
if (! (i > 0)) { // foo 
 } 
 numcpus = i; cpus = (cpu *) DISKSIM_malloc (numcpus * sizeof(cpu));

}

static int DISKSIM_PF_PROCESS_FLOW_TIME_SCALE_depend(char *bv) {
return -1;
}

static void DISKSIM_PF_PROCESS_FLOW_TIME_SCALE_loader(int result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 pfscale = d;

}

void * DISKSIM_PF_loaders[] = {
(void *)DISKSIM_PF_NUMBER_OF_PROCESSORS_loader,
(void *)DISKSIM_PF_PROCESS_FLOW_TIME_SCALE_loader
};

lp_paramdep_t DISKSIM_PF_deps[] = {
DISKSIM_PF_NUMBER_OF_PROCESSORS_depend,
DISKSIM_PF_PROCESS_FLOW_TIME_SCALE_depend
};

