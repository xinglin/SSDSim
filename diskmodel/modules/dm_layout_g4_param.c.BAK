#include "dm_layout_g4_param.h"
#include <libparam/bitvector.h>
#include "../layout_g4.h"
static int DM_LAYOUT_G4_TP_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G4_TP_loader(struct dm_layout_g4 * result, struct lp_list *l) { 
 g4_load_tp(result, l);

}

static int DM_LAYOUT_G4_IDX_depend(char *bv) {
if(!BIT_TEST(bv, DM_LAYOUT_G4_TP)) { return DM_LAYOUT_G4_TP; }
return -1;
}

static void DM_LAYOUT_G4_IDX_loader(struct dm_layout_g4 * result, struct lp_list *l) { 
 g4_load_idx(result, l);

}

static int DM_LAYOUT_G4_SLIPS_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G4_SLIPS_loader(struct dm_layout_g4 * result, struct lp_list *l) { 
 g4_load_slips(result, l);

}

static int DM_LAYOUT_G4_REMAPS_depend(char *bv) {
return -1;
}

static void DM_LAYOUT_G4_REMAPS_loader(struct dm_layout_g4 * result, struct lp_list *l) { 
 g4_load_remaps(result, l);

}

void * DM_LAYOUT_G4_loaders[] = {
(void *)DM_LAYOUT_G4_TP_loader,
(void *)DM_LAYOUT_G4_IDX_loader,
(void *)DM_LAYOUT_G4_SLIPS_loader,
(void *)DM_LAYOUT_G4_REMAPS_loader
};

lp_paramdep_t DM_LAYOUT_G4_deps[] = {
DM_LAYOUT_G4_TP_depend,
DM_LAYOUT_G4_IDX_depend,
DM_LAYOUT_G4_SLIPS_depend,
DM_LAYOUT_G4_REMAPS_depend
};

