#include "disksim_iomap_param.h"
#include <libparam/bitvector.h>
#include "../disksim_iosim.h"
static int DISKSIM_IOMAP_TRACEDEV_depend(char *bv) {
return -1;
}

static void DISKSIM_IOMAP_TRACEDEV_loader(int result, int i) { 
 tracemap[result] = i;

}

static int DISKSIM_IOMAP_SIMDEV_depend(char *bv) {
return -1;
}

static void DISKSIM_IOMAP_SIMDEV_loader(int result, char *s) { 
if (! (getdevbyname(s, &tracemap1[result], 0, 0))) { // foo 
 } 

}

static int DISKSIM_IOMAP_LOCSCALE_depend(char *bv) {
return -1;
}

static void DISKSIM_IOMAP_LOCSCALE_loader(int result, int i) { 
if (! ((i > 0) && (!(512 % i) || !(i % 512)))) { // foo 
 } 
 tracemap2[result] = i;

}

static int DISKSIM_IOMAP_SIZESCALE_depend(char *bv) {
return -1;
}

static void DISKSIM_IOMAP_SIZESCALE_loader(int result, int i) { 
if (! (i > 0)) { // foo 
 } 
 tracemap3[result] = i;

}

static int DISKSIM_IOMAP_OFFSET_depend(char *bv) {
return -1;
}

static void DISKSIM_IOMAP_OFFSET_loader(int result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 tracemap4[result] = i;

}

void * DISKSIM_IOMAP_loaders[] = {
(void *)DISKSIM_IOMAP_TRACEDEV_loader,
(void *)DISKSIM_IOMAP_SIMDEV_loader,
(void *)DISKSIM_IOMAP_LOCSCALE_loader,
(void *)DISKSIM_IOMAP_SIZESCALE_loader,
(void *)DISKSIM_IOMAP_OFFSET_loader
};

lp_paramdep_t DISKSIM_IOMAP_deps[] = {
DISKSIM_IOMAP_TRACEDEV_depend,
DISKSIM_IOMAP_SIMDEV_depend,
DISKSIM_IOMAP_LOCSCALE_depend,
DISKSIM_IOMAP_SIZESCALE_depend,
DISKSIM_IOMAP_OFFSET_depend
};

