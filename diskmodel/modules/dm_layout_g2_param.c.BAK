#include "dm_layout_g2_param.h"
#include <libparam/bitvector.h>
#include "../layout_g2.h"
static int DM_LAYOUT_G2_LAYOUT_MAP_FILE_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G2_LAYOUT_MAP_FILE_loader(struct dm_layout_g2 * result, char *s) { 
 result->mapfile = strdup(s);

}

static int DM_LAYOUT_G2_ZONES_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G2_ZONES_loader(struct dm_layout_g2 * result, struct lp_list *l) { 
 g2_load_zones(result,l);

}

void * DM_LAYOUT_G2_loaders[] = {
(void *)DM_LAYOUT_G2_LAYOUT_MAP_FILE_loader,
(void *)DM_LAYOUT_G2_ZONES_loader
};

lp_paramdep_t DM_LAYOUT_G2_deps[] = {
DM_LAYOUT_G2_LAYOUT_MAP_FILE_depend,
DM_LAYOUT_G2_ZONES_depend
};

