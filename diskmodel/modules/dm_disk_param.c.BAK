#include "dm_disk_param.h"
#include <libparam/bitvector.h>
#include "../dm.h"
static int DM_DISK_BLOCK_COUNT_depend(char *bv) {
return -1;
}

static void DM_DISK_BLOCK_COUNT_loader(struct dm_disk_if * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->dm_sectors = i;

}

static int DM_DISK_NUMBER_OF_DATA_SURFACES_depend(char *bv) {
return -1;
}

static void DM_DISK_NUMBER_OF_DATA_SURFACES_loader(struct dm_disk_if * result, int i) { 
if (! (i > 0)) { // foo 
 } 
 result->dm_surfaces = i;

}

static int DM_DISK_NUMBER_OF_CYLINDERS_depend(char *bv) {
return -1;
}

static void DM_DISK_NUMBER_OF_CYLINDERS_loader(struct dm_disk_if * result, int i) { 
if (! (i > 0)) { // foo 
 } 
 result->dm_cyls = i;

}

static int DM_DISK_MECHANICAL_MODEL_depend(char *bv) {
return -1;
}

static void DM_DISK_MECHANICAL_MODEL_loader(struct dm_disk_if * result, struct lp_block *blk) { 
if (! (result->mech = ((dm_mech_loader_t)blk->loader)(blk, result))) { // foo 
 } 

}

static int DM_DISK_LAYOUT_MODEL_depend(char *bv) {
return -1;
}

static void DM_DISK_LAYOUT_MODEL_loader(struct dm_disk_if * result, struct lp_block *blk) { 
if (! (result->layout = ((dm_layout_loader_t)blk->loader)(blk, result))) { // foo 
 } 

}

void * DM_DISK_loaders[] = {
(void *)DM_DISK_BLOCK_COUNT_loader,
(void *)DM_DISK_NUMBER_OF_DATA_SURFACES_loader,
(void *)DM_DISK_NUMBER_OF_CYLINDERS_loader,
(void *)DM_DISK_MECHANICAL_MODEL_loader,
(void *)DM_DISK_LAYOUT_MODEL_loader
};

lp_paramdep_t DM_DISK_deps[] = {
DM_DISK_BLOCK_COUNT_depend,
DM_DISK_NUMBER_OF_DATA_SURFACES_depend,
DM_DISK_NUMBER_OF_CYLINDERS_depend,
DM_DISK_MECHANICAL_MODEL_depend,
DM_DISK_LAYOUT_MODEL_depend
};

