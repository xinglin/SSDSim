#include "dm_layout_g2_zone_param.h"
#include <libparam/bitvector.h>
#include "../layout_g2.h"
static int DM_LAYOUT_G2_ZONE_FIRST_CYLINDER_NUMBER_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G2_ZONE_FIRST_CYLINDER_NUMBER_loader(struct dm_layout_g2_zone * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->cyllow = i;

}

static int DM_LAYOUT_G2_ZONE_LAST_CYLINDER_NUMBER_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G2_ZONE_LAST_CYLINDER_NUMBER_loader(struct dm_layout_g2_zone * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->cylhigh = i;

}

static int DM_LAYOUT_G2_ZONE_FIRST_LBN_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G2_ZONE_FIRST_LBN_loader(struct dm_layout_g2_zone * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->lbnlow = i;

}

static int DM_LAYOUT_G2_ZONE_LAST_LBN_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G2_ZONE_LAST_LBN_loader(struct dm_layout_g2_zone * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->lbnhigh = i;

}

static int DM_LAYOUT_G2_ZONE_BLOCKS_PER_TRACK_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G2_ZONE_BLOCKS_PER_TRACK_loader(struct dm_layout_g2_zone * result, int i) { 
if (! (i > 0)) { // foo 
 } 
 result->st = i;
 result->sector_width = (dm_angle_t)(((long long)1 << 32) / result->st);

}

static int DM_LAYOUT_G2_ZONE_ZONE_SKEW_depend(char *bv) {
if(!BIT_TEST(bv, DM_LAYOUT_G2_ZONE_BLOCKS_PER_TRACK)) { return DM_LAYOUT_G2_ZONE_BLOCKS_PER_TRACK; }
return -1;
}

static void DM_LAYOUT_G2_ZONE_ZONE_SKEW_loader(struct dm_layout_g2_zone * result, double d) { 
 {
 switch(result->skew_units) {
 case DM_SU_REVOLUTIONS:
 result->zskew = dm_angle_dtoi(d);
 break;
 case DM_SU_SECTORS:
 default:
 result->zskew = (int)d * result->sector_width;
 break;
 }
 }

}

static int DM_LAYOUT_G2_ZONE_SKEW_UNITS_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G2_ZONE_SKEW_UNITS_loader(struct dm_layout_g2_zone * result, char *s) { 
 if(!strcmp(s, "revolutions")) { result->skew_units = DM_SU_REVOLUTIONS; }
 else if(!strcmp(s, "sectors")) { result->skew_units = DM_SU_SECTORS; }
 else { ddbg_assert(0); }

}

static int DM_LAYOUT_G2_ZONE_SKEW_FOR_TRACK_SWITCH_depend(char *bv) {
if(!BIT_TEST(bv, DM_LAYOUT_G2_ZONE_BLOCKS_PER_TRACK)) { return DM_LAYOUT_G2_ZONE_BLOCKS_PER_TRACK; }
return -1;
}

static void DM_LAYOUT_G2_ZONE_SKEW_FOR_TRACK_SWITCH_loader(struct dm_layout_g2_zone * result, double d) { 
 {
 switch(result->skew_units) {
 case DM_SU_REVOLUTIONS:
 result->hsskew = dm_angle_dtoi(d);
 break;
 case DM_SU_SECTORS:
 default:
 result->hsskew = (int)d * result->sector_width;
 break;
 }
 }

}

static int DM_LAYOUT_G2_ZONE_SKEW_FOR_CYLINDER_SWITCH_depend(char *bv) {
if(!BIT_TEST(bv, DM_LAYOUT_G2_ZONE_BLOCKS_PER_TRACK)) { return DM_LAYOUT_G2_ZONE_BLOCKS_PER_TRACK; }
return -1;
}

static void DM_LAYOUT_G2_ZONE_SKEW_FOR_CYLINDER_SWITCH_loader(struct dm_layout_g2_zone * result, double d) { 
 {
 switch(result->skew_units) {
 case DM_SU_REVOLUTIONS:
 result->csskew = dm_angle_dtoi(d);
 break;
 case DM_SU_SECTORS:
 default:
 result->csskew = (int)d * result->sector_width;
 break;
 }
 }

}

void * DM_LAYOUT_G2_ZONE_loaders[] = {
(void *)DM_LAYOUT_G2_ZONE_FIRST_CYLINDER_NUMBER_loader,
(void *)DM_LAYOUT_G2_ZONE_LAST_CYLINDER_NUMBER_loader,
(void *)DM_LAYOUT_G2_ZONE_FIRST_LBN_loader,
(void *)DM_LAYOUT_G2_ZONE_LAST_LBN_loader,
(void *)DM_LAYOUT_G2_ZONE_BLOCKS_PER_TRACK_loader,
(void *)DM_LAYOUT_G2_ZONE_ZONE_SKEW_loader,
(void *)DM_LAYOUT_G2_ZONE_SKEW_UNITS_loader,
(void *)DM_LAYOUT_G2_ZONE_SKEW_FOR_TRACK_SWITCH_loader,
(void *)DM_LAYOUT_G2_ZONE_SKEW_FOR_CYLINDER_SWITCH_loader
};

lp_paramdep_t DM_LAYOUT_G2_ZONE_deps[] = {
DM_LAYOUT_G2_ZONE_FIRST_CYLINDER_NUMBER_depend,
DM_LAYOUT_G2_ZONE_LAST_CYLINDER_NUMBER_depend,
DM_LAYOUT_G2_ZONE_FIRST_LBN_depend,
DM_LAYOUT_G2_ZONE_LAST_LBN_depend,
DM_LAYOUT_G2_ZONE_BLOCKS_PER_TRACK_depend,
DM_LAYOUT_G2_ZONE_ZONE_SKEW_depend,
DM_LAYOUT_G2_ZONE_SKEW_UNITS_depend,
DM_LAYOUT_G2_ZONE_SKEW_FOR_TRACK_SWITCH_depend,
DM_LAYOUT_G2_ZONE_SKEW_FOR_CYLINDER_SWITCH_depend
};

