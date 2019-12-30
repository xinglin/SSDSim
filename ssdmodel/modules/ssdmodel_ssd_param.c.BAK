#include "ssdmodel_ssd_param.h"
#include <libparam/bitvector.h>
#include "../ssd.h"
static int SSDMODEL_SSD_SCHEDULER_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_SCHEDULER_loader(struct ssd * result, struct lp_block *blk) { 
if (! (result->queue = (struct ioq *)disksim_ioqueue_loadparams(blk, device_printqueuestats, device_printcritstats, device_printidlestats, device_printintarrstats, device_printsizestats))) { // foo 
 } 

}

static int SSDMODEL_SSD_MAX_QUEUE_LENGTH_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_MAX_QUEUE_LENGTH_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->maxqlen = i;

}

static int SSDMODEL_SSD_BLOCK_COUNT_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_BLOCK_COUNT_loader(struct ssd * result, int i) { 
if (! ((i > 0))) { // foo 
 } 
 result->numblocks = i;

}

static int SSDMODEL_SSD_BUS_TRANSACTION_LATENCY_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_BUS_TRANSACTION_LATENCY_loader(struct ssd * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->bus_transaction_latency = d;

}

static int SSDMODEL_SSD_BULK_SECTOR_TRANSFER_TIME_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_BULK_SECTOR_TRANSFER_TIME_loader(struct ssd * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->blktranstime = d;

}

static int SSDMODEL_SSD_NEVER_DISCONNECT_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_NEVER_DISCONNECT_loader(struct ssd * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->neverdisconnect = i;

}

static int SSDMODEL_SSD_PRINT_STATS_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_PRINT_STATS_loader(struct ssd * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->printstats = i;

}

static int SSDMODEL_SSD_COMMAND_OVERHEAD_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_COMMAND_OVERHEAD_loader(struct ssd * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->overhead = d;

}

static int SSDMODEL_SSD_TIMING_MODEL_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_TIMING_MODEL_loader(struct ssd * result, int i) { 
if (! (RANGE(i,SSD_SIMPLE_MODEL,SSD_LOGDISK_MODEL))) { // foo 
 } 
 result->params.ssd_model = i;

}

static int SSDMODEL_SSD_FLASH_CHIP_ELEMENTS_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_FLASH_CHIP_ELEMENTS_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.nelements = i;

}

static int SSDMODEL_SSD_PAGE_SIZE_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_PAGE_SIZE_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.page_size = i;

}

static int SSDMODEL_SSD_PAGES_PER_BLOCK_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_PAGES_PER_BLOCK_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.pages_per_block = i;

}

static int SSDMODEL_SSD_BLOCKS_PER_ELEMENT_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_BLOCKS_PER_ELEMENT_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.blocks_per_element = i;

}

static int SSDMODEL_SSD_ELEMENT_STRIDE_PAGES_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_ELEMENT_STRIDE_PAGES_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.element_stride_pages = i;

}

static int SSDMODEL_SSD_CHIP_XFER_LATENCY_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_CHIP_XFER_LATENCY_loader(struct ssd * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->params.chip_xfer_latency = d;

}

static int SSDMODEL_SSD_PAGE_READ_LATENCY_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_PAGE_READ_LATENCY_loader(struct ssd * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->params.page_read_latency = d;

}

static int SSDMODEL_SSD_PAGE_WRITE_LATENCY_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_PAGE_WRITE_LATENCY_loader(struct ssd * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->params.page_write_latency = d;

}

static int SSDMODEL_SSD_BLOCK_ERASE_LATENCY_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_BLOCK_ERASE_LATENCY_loader(struct ssd * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->params.block_erase_latency = d;

}

static int SSDMODEL_SSD_WRITE_POLICY_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_WRITE_POLICY_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.write_policy = i;

}

static int SSDMODEL_SSD_RESERVE_PAGES_PERCENTAGE_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_RESERVE_PAGES_PERCENTAGE_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.reserve_blocks = i;

}

static int SSDMODEL_SSD_MINIMUM_FREE_BLOCKS_PERCENTAGE_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_MINIMUM_FREE_BLOCKS_PERCENTAGE_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.min_freeblks_percent = i;

}

static int SSDMODEL_SSD_CLEANING_POLICY_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_CLEANING_POLICY_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.cleaning_policy = i;

}

static int SSDMODEL_SSD_PLANES_PER_PACKAGE_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_PLANES_PER_PACKAGE_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.planes_per_pkg = i;

}

static int SSDMODEL_SSD_BLOCKS_PER_PLANE_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_BLOCKS_PER_PLANE_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.blocks_per_plane = i;

}

static int SSDMODEL_SSD_PLANE_BLOCK_MAPPING_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_PLANE_BLOCK_MAPPING_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.plane_block_mapping = i;

}

static int SSDMODEL_SSD_COPY_BACK_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_COPY_BACK_loader(struct ssd * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->params.copy_back = i;

}

static int SSDMODEL_SSD_NUMBER_OF_PARALLEL_UNITS_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_NUMBER_OF_PARALLEL_UNITS_loader(struct ssd * result, int i) { 
if (! ((i >= 0.0))) { // foo 
 } 
 result->params.num_parunits = i;

}

static int SSDMODEL_SSD_ELEMENTS_PER_GANG_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_ELEMENTS_PER_GANG_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.elements_per_gang = i;

}

static int SSDMODEL_SSD_CLEANING_IN_BACKGROUND_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_CLEANING_IN_BACKGROUND_loader(struct ssd * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->params.cleaning_in_background = i;

}

static int SSDMODEL_SSD_GANG_SHARE_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_GANG_SHARE_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.gang_share = i;

}

static int SSDMODEL_SSD_ALLOCATION_POOL_LOGIC_depend(char *bv) {
return -1;
}

static void SSDMODEL_SSD_ALLOCATION_POOL_LOGIC_loader(struct ssd * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->params.alloc_pool_logic = i;

}

void * SSDMODEL_SSD_loaders[] = {
(void *)SSDMODEL_SSD_SCHEDULER_loader,
(void *)SSDMODEL_SSD_MAX_QUEUE_LENGTH_loader,
(void *)SSDMODEL_SSD_BLOCK_COUNT_loader,
(void *)SSDMODEL_SSD_BUS_TRANSACTION_LATENCY_loader,
(void *)SSDMODEL_SSD_BULK_SECTOR_TRANSFER_TIME_loader,
(void *)SSDMODEL_SSD_NEVER_DISCONNECT_loader,
(void *)SSDMODEL_SSD_PRINT_STATS_loader,
(void *)SSDMODEL_SSD_COMMAND_OVERHEAD_loader,
(void *)SSDMODEL_SSD_TIMING_MODEL_loader,
(void *)SSDMODEL_SSD_FLASH_CHIP_ELEMENTS_loader,
(void *)SSDMODEL_SSD_PAGE_SIZE_loader,
(void *)SSDMODEL_SSD_PAGES_PER_BLOCK_loader,
(void *)SSDMODEL_SSD_BLOCKS_PER_ELEMENT_loader,
(void *)SSDMODEL_SSD_ELEMENT_STRIDE_PAGES_loader,
(void *)SSDMODEL_SSD_CHIP_XFER_LATENCY_loader,
(void *)SSDMODEL_SSD_PAGE_READ_LATENCY_loader,
(void *)SSDMODEL_SSD_PAGE_WRITE_LATENCY_loader,
(void *)SSDMODEL_SSD_BLOCK_ERASE_LATENCY_loader,
(void *)SSDMODEL_SSD_WRITE_POLICY_loader,
(void *)SSDMODEL_SSD_RESERVE_PAGES_PERCENTAGE_loader,
(void *)SSDMODEL_SSD_MINIMUM_FREE_BLOCKS_PERCENTAGE_loader,
(void *)SSDMODEL_SSD_CLEANING_POLICY_loader,
(void *)SSDMODEL_SSD_PLANES_PER_PACKAGE_loader,
(void *)SSDMODEL_SSD_BLOCKS_PER_PLANE_loader,
(void *)SSDMODEL_SSD_PLANE_BLOCK_MAPPING_loader,
(void *)SSDMODEL_SSD_COPY_BACK_loader,
(void *)SSDMODEL_SSD_NUMBER_OF_PARALLEL_UNITS_loader,
(void *)SSDMODEL_SSD_ELEMENTS_PER_GANG_loader,
(void *)SSDMODEL_SSD_CLEANING_IN_BACKGROUND_loader,
(void *)SSDMODEL_SSD_GANG_SHARE_loader,
(void *)SSDMODEL_SSD_ALLOCATION_POOL_LOGIC_loader
};

lp_paramdep_t SSDMODEL_SSD_deps[] = {
SSDMODEL_SSD_SCHEDULER_depend,
SSDMODEL_SSD_MAX_QUEUE_LENGTH_depend,
SSDMODEL_SSD_BLOCK_COUNT_depend,
SSDMODEL_SSD_BUS_TRANSACTION_LATENCY_depend,
SSDMODEL_SSD_BULK_SECTOR_TRANSFER_TIME_depend,
SSDMODEL_SSD_NEVER_DISCONNECT_depend,
SSDMODEL_SSD_PRINT_STATS_depend,
SSDMODEL_SSD_COMMAND_OVERHEAD_depend,
SSDMODEL_SSD_TIMING_MODEL_depend,
SSDMODEL_SSD_FLASH_CHIP_ELEMENTS_depend,
SSDMODEL_SSD_PAGE_SIZE_depend,
SSDMODEL_SSD_PAGES_PER_BLOCK_depend,
SSDMODEL_SSD_BLOCKS_PER_ELEMENT_depend,
SSDMODEL_SSD_ELEMENT_STRIDE_PAGES_depend,
SSDMODEL_SSD_CHIP_XFER_LATENCY_depend,
SSDMODEL_SSD_PAGE_READ_LATENCY_depend,
SSDMODEL_SSD_PAGE_WRITE_LATENCY_depend,
SSDMODEL_SSD_BLOCK_ERASE_LATENCY_depend,
SSDMODEL_SSD_WRITE_POLICY_depend,
SSDMODEL_SSD_RESERVE_PAGES_PERCENTAGE_depend,
SSDMODEL_SSD_MINIMUM_FREE_BLOCKS_PERCENTAGE_depend,
SSDMODEL_SSD_CLEANING_POLICY_depend,
SSDMODEL_SSD_PLANES_PER_PACKAGE_depend,
SSDMODEL_SSD_BLOCKS_PER_PLANE_depend,
SSDMODEL_SSD_PLANE_BLOCK_MAPPING_depend,
SSDMODEL_SSD_COPY_BACK_depend,
SSDMODEL_SSD_NUMBER_OF_PARALLEL_UNITS_depend,
SSDMODEL_SSD_ELEMENTS_PER_GANG_depend,
SSDMODEL_SSD_CLEANING_IN_BACKGROUND_depend,
SSDMODEL_SSD_GANG_SHARE_depend,
SSDMODEL_SSD_ALLOCATION_POOL_LOGIC_depend
};

