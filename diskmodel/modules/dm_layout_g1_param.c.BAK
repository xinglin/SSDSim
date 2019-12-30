#include "dm_layout_g1_param.h"
#include <libparam/bitvector.h>
#include "../layout_g1.h"
static int DM_LAYOUT_G1_LBN_TO_PBN_MAPPING_SCHEME_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_LBN_TO_PBN_MAPPING_SCHEME_loader(struct dm_layout_g1 * result, int i) { 
if (! (RANGE(i,0,LAYOUT_MAX))) { // foo 
 } 
 result->mapping = i;

}

static int DM_LAYOUT_G1_SPARING_SCHEME_USED_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_SPARING_SCHEME_USED_loader(struct dm_layout_g1 * result, int i) { 
if (! (RANGE(i,NO_SPARING,MAXSPARESCHEME))) { // foo 
 } 
 result->sparescheme = i;

}

static int DM_LAYOUT_G1_RANGESIZE_FOR_SPARING_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_RANGESIZE_FOR_SPARING_loader(struct dm_layout_g1 * result, int i) { 
if (! (i > 0)) { // foo 
 } 
 result->rangesize = i;

}

static int DM_LAYOUT_G1_SKEW_UNITS_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_SKEW_UNITS_loader(struct dm_layout_g1 * result, char *s) { 
 if(!strcmp(s, "revolutions")) { result->skew_units = DM_SU_REVOLUTIONS; }
 else if(!strcmp(s, "sectors")) { result->skew_units = DM_SU_SECTORS; }
 else { ddbg_assert(0); }

}

static int DM_LAYOUT_G1_ZONES_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_ZONES_loader(struct dm_layout_g1 * result, struct lp_list *l) { 
if (! (disk_load_zones(l,result))) { // foo 
 } 

}

void * DM_LAYOUT_G1_loaders[] = {
(void *)DM_LAYOUT_G1_LBN_TO_PBN_MAPPING_SCHEME_loader,
(void *)DM_LAYOUT_G1_SPARING_SCHEME_USED_loader,
(void *)DM_LAYOUT_G1_RANGESIZE_FOR_SPARING_loader,
(void *)DM_LAYOUT_G1_SKEW_UNITS_loader,
(void *)DM_LAYOUT_G1_ZONES_loader
};

lp_paramdep_t DM_LAYOUT_G1_deps[] = {
DM_LAYOUT_G1_LBN_TO_PBN_MAPPING_SCHEME_depend,
DM_LAYOUT_G1_SPARING_SCHEME_USED_depend,
DM_LAYOUT_G1_RANGESIZE_FOR_SPARING_depend,
DM_LAYOUT_G1_SKEW_UNITS_depend,
DM_LAYOUT_G1_ZONES_depend
};

