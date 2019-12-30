#include "dm_layout_g1_zone_param.h"
#include <libparam/bitvector.h>
#include "../layout_g1.h"
static int DM_LAYOUT_G1_ZONE_FIRST_CYLINDER_NUMBER_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_ZONE_FIRST_CYLINDER_NUMBER_loader(struct dm_layout_g1_band * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->startcyl = i;

}

static int DM_LAYOUT_G1_ZONE_LAST_CYLINDER_NUMBER_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_ZONE_LAST_CYLINDER_NUMBER_loader(struct dm_layout_g1_band * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->endcyl = i;

}

static int DM_LAYOUT_G1_ZONE_BLOCKS_PER_TRACK_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_ZONE_BLOCKS_PER_TRACK_loader(struct dm_layout_g1_band * result, int i) { 
if (! (i > 0)) { // foo 
 } 
 result->blkspertrack = i;
 result->sector_width = ((long long)1 << 32) / result->blkspertrack;

}

static int DM_LAYOUT_G1_ZONE_OFFSET_OF_FIRST_BLOCK_depend(char *bv) {
if(!BIT_TEST(bv, DM_LAYOUT_G1_ZONE_BLOCKS_PER_TRACK)) { return DM_LAYOUT_G1_ZONE_BLOCKS_PER_TRACK; }
return -1;
}

static void DM_LAYOUT_G1_ZONE_OFFSET_OF_FIRST_BLOCK_loader(struct dm_layout_g1_band * result, double d) { 
 {
 switch(result->skew_units) {
 case DM_SU_REVOLUTIONS:
 result->firstblkangle = dm_angle_dtoi(d);
 break;
 case DM_SU_SECTORS:
 default:
 result->firstblkangle = (int)d * result->sector_width;
 break;
 }
 }

}

static int DM_LAYOUT_G1_ZONE_SKEW_UNITS_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_ZONE_SKEW_UNITS_loader(struct dm_layout_g1_band * result, char *s) { 
 if(!strcmp(s, "revolutions")) { result->skew_units = DM_SU_REVOLUTIONS; }
 else if(!strcmp(s, "sectors")) { result->skew_units = DM_SU_SECTORS; }
 else { ddbg_assert(0); }

}

static int DM_LAYOUT_G1_ZONE_EMPTY_SPACE_AT_ZONE_FRONT_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_ZONE_EMPTY_SPACE_AT_ZONE_FRONT_loader(struct dm_layout_g1_band * result, int i) { 
 result->deadspace = i;

}

static int DM_LAYOUT_G1_ZONE_SKEW_FOR_TRACK_SWITCH_depend(char *bv) {
if(!BIT_TEST(bv, DM_LAYOUT_G1_ZONE_BLOCKS_PER_TRACK)) { return DM_LAYOUT_G1_ZONE_BLOCKS_PER_TRACK; }
return -1;
}

static void DM_LAYOUT_G1_ZONE_SKEW_FOR_TRACK_SWITCH_loader(struct dm_layout_g1_band * result, double d) { 
 {
 switch(result->skew_units) {
 case DM_SU_REVOLUTIONS:
 result->trackskew = dm_angle_dtoi(d);
 break;
 case DM_SU_SECTORS:
 default:
 result->trackskew = (int)d * result->sector_width;
 break;
 }
 }

}

static int DM_LAYOUT_G1_ZONE_SKEW_FOR_CYLINDER_SWITCH_depend(char *bv) {
if(!BIT_TEST(bv, DM_LAYOUT_G1_ZONE_BLOCKS_PER_TRACK)) { return DM_LAYOUT_G1_ZONE_BLOCKS_PER_TRACK; }
return -1;
}

static void DM_LAYOUT_G1_ZONE_SKEW_FOR_CYLINDER_SWITCH_loader(struct dm_layout_g1_band * result, double d) { 
 {
 switch(result->skew_units) {
 case DM_SU_REVOLUTIONS:
 result->cylskew = dm_angle_dtoi(d);
 break;
 case DM_SU_SECTORS:
 default:
 result->cylskew = (int)d * result->sector_width;
 break;
 }
 }

}

static int DM_LAYOUT_G1_ZONE_NUMBER_OF_SPARES_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_ZONE_NUMBER_OF_SPARES_loader(struct dm_layout_g1_band * result, int i) { 
 result->sparecnt = i;

}

static int DM_LAYOUT_G1_ZONE_SLIPS_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_ZONE_SLIPS_loader(struct dm_layout_g1_band * result, struct lp_list *l) { 
if (! (!getslips(result, l))) { // foo 
 } 

}

static int DM_LAYOUT_G1_ZONE_DEFECTS_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G1_ZONE_DEFECTS_loader(struct dm_layout_g1_band * result, struct lp_list *l) { 
if (! (!getdefects(result, l))) { // foo 
 } 

}

void * DM_LAYOUT_G1_ZONE_loaders[] = {
(void *)DM_LAYOUT_G1_ZONE_FIRST_CYLINDER_NUMBER_loader,
(void *)DM_LAYOUT_G1_ZONE_LAST_CYLINDER_NUMBER_loader,
(void *)DM_LAYOUT_G1_ZONE_BLOCKS_PER_TRACK_loader,
(void *)DM_LAYOUT_G1_ZONE_OFFSET_OF_FIRST_BLOCK_loader,
(void *)DM_LAYOUT_G1_ZONE_SKEW_UNITS_loader,
(void *)DM_LAYOUT_G1_ZONE_EMPTY_SPACE_AT_ZONE_FRONT_loader,
(void *)DM_LAYOUT_G1_ZONE_SKEW_FOR_TRACK_SWITCH_loader,
(void *)DM_LAYOUT_G1_ZONE_SKEW_FOR_CYLINDER_SWITCH_loader,
(void *)DM_LAYOUT_G1_ZONE_NUMBER_OF_SPARES_loader,
(void *)DM_LAYOUT_G1_ZONE_SLIPS_loader,
(void *)DM_LAYOUT_G1_ZONE_DEFECTS_loader
};

lp_paramdep_t DM_LAYOUT_G1_ZONE_deps[] = {
DM_LAYOUT_G1_ZONE_FIRST_CYLINDER_NUMBER_depend,
DM_LAYOUT_G1_ZONE_LAST_CYLINDER_NUMBER_depend,
DM_LAYOUT_G1_ZONE_BLOCKS_PER_TRACK_depend,
DM_LAYOUT_G1_ZONE_OFFSET_OF_FIRST_BLOCK_depend,
DM_LAYOUT_G1_ZONE_SKEW_UNITS_depend,
DM_LAYOUT_G1_ZONE_EMPTY_SPACE_AT_ZONE_FRONT_depend,
DM_LAYOUT_G1_ZONE_SKEW_FOR_TRACK_SWITCH_depend,
DM_LAYOUT_G1_ZONE_SKEW_FOR_CYLINDER_SWITCH_depend,
DM_LAYOUT_G1_ZONE_NUMBER_OF_SPARES_depend,
DM_LAYOUT_G1_ZONE_SLIPS_depend,
DM_LAYOUT_G1_ZONE_DEFECTS_depend
};

