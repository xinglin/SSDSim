#include "disksim_disk_param.h"
#include <libparam/bitvector.h>
#include "../disksim_disk.h"
static int DISKSIM_DISK_MODEL_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_MODEL_loader(struct disk * result, struct lp_block *blk) { 
if (! (result->model = (struct dm_disk_if *) dm_disk_loadparams(blk, 0))) { // foo 
 } 

}

static int DISKSIM_DISK_SCHEDULER_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_SCHEDULER_loader(struct disk * result, struct lp_block *blk) { 
if (! ((result->queue = (struct ioq *)disksim_ioqueue_loadparams(blk, device_printqueuestats, device_printcritstats, device_printidlestats, device_printintarrstats, device_printsizestats)))) { // foo 
 } 

}

static int DISKSIM_DISK_MAX_QUEUE_LENGTH_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_MAX_QUEUE_LENGTH_loader(struct disk * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->maxqlen = i;

}

static int DISKSIM_DISK_BULK_SECTOR_TRANSFER_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_BULK_SECTOR_TRANSFER_TIME_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->blktranstime = d;

}

static int DISKSIM_DISK_SEGMENT_SIZE__depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_SEGMENT_SIZE__loader(struct disk * result, int i) { 
if (! (RANGE(i, 1, result->model->dm_sectors))) { // foo 
 } 
 result->segsize = i;

}

static int DISKSIM_DISK_NUMBER_OF_BUFFER_SEGMENTS_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_NUMBER_OF_BUFFER_SEGMENTS_loader(struct disk * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->numsegs = i;

}

static int DISKSIM_DISK_PRINT_STATS_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_PRINT_STATS_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->printstats = i;

}

static int DISKSIM_DISK_PER_REQUEST_OVERHEAD_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_PER_REQUEST_OVERHEAD_TIME_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead = d;

}

static int DISKSIM_DISK_TIME_SCALE_FOR_OVERHEADS_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_TIME_SCALE_FOR_OVERHEADS_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->timescale = d;

}

static int DISKSIM_DISK_HOLD_BUS_ENTIRE_READ_XFER_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_HOLD_BUS_ENTIRE_READ_XFER_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->hold_bus_for_whole_read_xfer = i;

}

static int DISKSIM_DISK_HOLD_BUS_ENTIRE_WRITE_XFER_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_HOLD_BUS_ENTIRE_WRITE_XFER_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->hold_bus_for_whole_write_xfer = i;

}

static int DISKSIM_DISK_ALLOW_ALMOST_READ_HITS_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_ALLOW_ALMOST_READ_HITS_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->almostreadhits = i;

}

static int DISKSIM_DISK_ALLOW_SNEAKY_FULL_READ_HITS_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_ALLOW_SNEAKY_FULL_READ_HITS_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->sneakyfullreadhits = i;

}

static int DISKSIM_DISK_ALLOW_SNEAKY_PARTIAL_READ_HITS_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_ALLOW_SNEAKY_PARTIAL_READ_HITS_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->sneakypartialreadhits = i;

}

static int DISKSIM_DISK_ALLOW_SNEAKY_INTERMEDIATE_READ_HITS_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_ALLOW_SNEAKY_INTERMEDIATE_READ_HITS_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->sneakyintermediatereadhits = i;

}

static int DISKSIM_DISK_ALLOW_READ_HITS_ON_WRITE_DATA_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_ALLOW_READ_HITS_ON_WRITE_DATA_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->readhitsonwritedata = i;

}

static int DISKSIM_DISK_ALLOW_WRITE_PREBUFFERING_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_ALLOW_WRITE_PREBUFFERING_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->writeprebuffering = i;

}

static int DISKSIM_DISK_PRESEEKING_LEVEL_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_PRESEEKING_LEVEL_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,2))) { // foo 
 } 
 result->preseeking = i;

}

static int DISKSIM_DISK_NEVER_DISCONNECT_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_NEVER_DISCONNECT_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->neverdisconnect = i;

}

static int DISKSIM_DISK_AVG_SECTORS_PER_CYLINDER_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_AVG_SECTORS_PER_CYLINDER_loader(struct disk * result, int i) { 
if (! (RANGE(i,1,result->model->dm_sectors))) { // foo 
 } 
 result->sectpercyl = i;

}

static int DISKSIM_DISK_MAXIMUM_NUMBER_OF_WRITE_SEGMENTS_depend(char *bv) {
if(!BIT_TEST(bv, DISKSIM_DISK_NUMBER_OF_BUFFER_SEGMENTS)) { return DISKSIM_DISK_NUMBER_OF_BUFFER_SEGMENTS; }
return -1;
}

static void DISKSIM_DISK_MAXIMUM_NUMBER_OF_WRITE_SEGMENTS_loader(struct disk * result, int i) { 
if (! (RANGE(i,1,result->numsegs))) { // foo 
 } 
 result->numwritesegs = i;

}

static int DISKSIM_DISK_USE_SEPARATE_WRITE_SEGMENT_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_USE_SEPARATE_WRITE_SEGMENT_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->dedicatedwriteseg = (segment *)i;

}

static int DISKSIM_DISK_LOW__WATER_MARK_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_LOW__WATER_MARK_loader(struct disk * result, double d) { 
if (! (RANGE(d,0.0,1.0))) { // foo 
 } 
 result->writewater = d;

}

static int DISKSIM_DISK_HIGH__WATER_MARK_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_HIGH__WATER_MARK_loader(struct disk * result, double d) { 
if (! (RANGE(d,0.0,1.0))) { // foo 
 } 
 result->readwater = d;

}

static int DISKSIM_DISK_SET_WATERMARK_BY_REQSIZE_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_SET_WATERMARK_BY_REQSIZE_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->reqwater = i;

}

static int DISKSIM_DISK_CALC_SECTOR_BY_SECTOR_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_CALC_SECTOR_BY_SECTOR_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->sectbysect = i;

}

static int DISKSIM_DISK_ENABLE_CACHING_IN_BUFFER_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_ENABLE_CACHING_IN_BUFFER_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,2))) { // foo 
 } 
 result->enablecache = i;

}

static int DISKSIM_DISK_BUFFER_CONTINUOUS_READ_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_BUFFER_CONTINUOUS_READ_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,4))) { // foo 
 } 
 result->contread = i;

}

static int DISKSIM_DISK_MINIMUM_READ_AHEAD__depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_MINIMUM_READ_AHEAD__loader(struct disk * result, int i) { 
if (! (RANGE(i,0,result->segsize))) { // foo 
 } 
 result->minreadahead = i;

}

static int DISKSIM_DISK_MAXIMUM_READ_AHEAD__depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_MAXIMUM_READ_AHEAD__loader(struct disk * result, int i) { 
if (! (RANGE(i,0,result->segsize))) { // foo 
 } 
 result->maxreadahead = i;

}

static int DISKSIM_DISK_READ_AHEAD_OVER_REQUESTED_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_READ_AHEAD_OVER_REQUESTED_loader(struct disk * result, int i) { 
if (! (RANGE(i,-1,1))) { // foo 
 } 
 result->keeprequestdata = i;

}

static int DISKSIM_DISK_READ_AHEAD_ON_IDLE_HIT_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_READ_AHEAD_ON_IDLE_HIT_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->readaheadifidle = i;

}

static int DISKSIM_DISK_READ_ANY_FREE_BLOCKS_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_READ_ANY_FREE_BLOCKS_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->readanyfreeblocks = i;

}

static int DISKSIM_DISK_FAST_WRITE_LEVEL_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_FAST_WRITE_LEVEL_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,2))) { // foo 
 } 
 result->fastwrites = i;

}

static int DISKSIM_DISK_COMBINE_SEQ_WRITES_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_COMBINE_SEQ_WRITES_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->writecomb = i;

}

static int DISKSIM_DISK_STOP_PREFETCH_IN_SECTOR_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_STOP_PREFETCH_IN_SECTOR_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->stopinsector = i;

}

static int DISKSIM_DISK_DISCONNECT_WRITE_IF_SEEK_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_DISCONNECT_WRITE_IF_SEEK_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->disconnectinseek = i;

}

static int DISKSIM_DISK_WRITE_HIT_STOP_PREFETCH_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_WRITE_HIT_STOP_PREFETCH_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->write_hit_stop_readahead = i;

}

static int DISKSIM_DISK_READ_DIRECTLY_TO_BUFFER_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_READ_DIRECTLY_TO_BUFFER_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->read_direct_to_buffer = i;

}

static int DISKSIM_DISK_IMMED_TRANSFER_PARTIAL_HIT_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_IMMED_TRANSFER_PARTIAL_HIT_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->immedtrans_any_readhit = i;

}

static int DISKSIM_DISK_READ_HIT_OVER_AFTER_READ_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_READ_HIT_OVER_AFTER_READ_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_command_readhit_afterread = d;

}

static int DISKSIM_DISK_READ_HIT_OVER_AFTER_WRITE_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_READ_HIT_OVER_AFTER_WRITE_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_command_readhit_afterwrite = d;

}

static int DISKSIM_DISK_READ_MISS_OVER_AFTER_READ_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_READ_MISS_OVER_AFTER_READ_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_command_readmiss_afterread = d;

}

static int DISKSIM_DISK_READ_MISS_OVER_AFTER_WRITE_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_READ_MISS_OVER_AFTER_WRITE_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_command_readmiss_afterwrite = d;

}

static int DISKSIM_DISK_WRITE_HIT_OVER_AFTER_READ_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_WRITE_HIT_OVER_AFTER_READ_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_command_writehit_afterread = d;

}

static int DISKSIM_DISK_WRITE_HIT_OVER_AFTER_WRITE_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_WRITE_HIT_OVER_AFTER_WRITE_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_command_writehit_afterwrite = d;

}

static int DISKSIM_DISK_WRITE_MISS_OVER_AFTER_READ_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_WRITE_MISS_OVER_AFTER_READ_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_command_writemiss_afterread = d;

}

static int DISKSIM_DISK_WRITE_MISS_OVER_AFTER_WRITE_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_WRITE_MISS_OVER_AFTER_WRITE_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_command_writemiss_afterwrite = d;

}

static int DISKSIM_DISK_READ_COMPLETION_OVERHEAD_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_READ_COMPLETION_OVERHEAD_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_complete_read = d;

}

static int DISKSIM_DISK_WRITE_COMPLETION_OVERHEAD_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_WRITE_COMPLETION_OVERHEAD_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_complete_write = d;

}

static int DISKSIM_DISK_DATA_PREPARATION_OVERHEAD_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_DATA_PREPARATION_OVERHEAD_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_data_prep = d;

}

static int DISKSIM_DISK_FIRST_RESELECT_OVERHEAD_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_FIRST_RESELECT_OVERHEAD_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_reselect_first = d;

}

static int DISKSIM_DISK_OTHER_RESELECT_OVERHEAD_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_OTHER_RESELECT_OVERHEAD_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_reselect_other = d;

}

static int DISKSIM_DISK_READ_DISCONNECT_AFTERREAD_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_READ_DISCONNECT_AFTERREAD_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_disconnect_read_afterread = d;

}

static int DISKSIM_DISK_READ_DISCONNECT_AFTERWRITE_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_READ_DISCONNECT_AFTERWRITE_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_disconnect_read_afterwrite = d;

}

static int DISKSIM_DISK_WRITE_DISCONNECT_OVERHEAD_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_WRITE_DISCONNECT_OVERHEAD_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->overhead_disconnect_write = d;

}

static int DISKSIM_DISK_EXTRA_WRITE_DISCONNECT_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_EXTRA_WRITE_DISCONNECT_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->extra_write_disconnect = i;

}

static int DISKSIM_DISK_EXTRADISC_COMMAND_OVERHEAD_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_EXTRADISC_COMMAND_OVERHEAD_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->extradisc_command = d;

}

static int DISKSIM_DISK_EXTRADISC_DISCONNECT_OVERHEAD_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_EXTRADISC_DISCONNECT_OVERHEAD_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->extradisc_disconnect1 = d;

}

static int DISKSIM_DISK_EXTRADISC_INTER_DISCONNECT_DELAY_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_EXTRADISC_INTER_DISCONNECT_DELAY_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->extradisc_inter_disconnect = d;

}

static int DISKSIM_DISK_EXTRADISC_2ND_DISCONNECT_OVERHEAD_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_EXTRADISC_2ND_DISCONNECT_OVERHEAD_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->extradisc_disconnect2 = d;

}

static int DISKSIM_DISK_EXTRADISC_SEEK_DELTA_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_EXTRADISC_SEEK_DELTA_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->extradisc_seekdelta = d;

}

static int DISKSIM_DISK_MINIMUM_SEEK_DELAY_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_MINIMUM_SEEK_DELAY_loader(struct disk * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->minimum_seek_delay = d;

}

static int DISKSIM_DISK_IMMEDIATE_BUFFER_READ_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_IMMEDIATE_BUFFER_READ_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,2))) { // foo 
 } 
 result->immedread = i;

}

static int DISKSIM_DISK_IMMEDIATE_BUFFER_WRITE_depend(char *bv) {
return -1;
}

static void DISKSIM_DISK_IMMEDIATE_BUFFER_WRITE_loader(struct disk * result, int i) { 
if (! (RANGE(i,0,2))) { // foo 
 } 
 result->immedwrite = i;

}

void * DISKSIM_DISK_loaders[] = {
(void *)DISKSIM_DISK_MODEL_loader,
(void *)DISKSIM_DISK_SCHEDULER_loader,
(void *)DISKSIM_DISK_MAX_QUEUE_LENGTH_loader,
(void *)DISKSIM_DISK_BULK_SECTOR_TRANSFER_TIME_loader,
(void *)DISKSIM_DISK_SEGMENT_SIZE__loader,
(void *)DISKSIM_DISK_NUMBER_OF_BUFFER_SEGMENTS_loader,
(void *)DISKSIM_DISK_PRINT_STATS_loader,
(void *)DISKSIM_DISK_PER_REQUEST_OVERHEAD_TIME_loader,
(void *)DISKSIM_DISK_TIME_SCALE_FOR_OVERHEADS_loader,
(void *)DISKSIM_DISK_HOLD_BUS_ENTIRE_READ_XFER_loader,
(void *)DISKSIM_DISK_HOLD_BUS_ENTIRE_WRITE_XFER_loader,
(void *)DISKSIM_DISK_ALLOW_ALMOST_READ_HITS_loader,
(void *)DISKSIM_DISK_ALLOW_SNEAKY_FULL_READ_HITS_loader,
(void *)DISKSIM_DISK_ALLOW_SNEAKY_PARTIAL_READ_HITS_loader,
(void *)DISKSIM_DISK_ALLOW_SNEAKY_INTERMEDIATE_READ_HITS_loader,
(void *)DISKSIM_DISK_ALLOW_READ_HITS_ON_WRITE_DATA_loader,
(void *)DISKSIM_DISK_ALLOW_WRITE_PREBUFFERING_loader,
(void *)DISKSIM_DISK_PRESEEKING_LEVEL_loader,
(void *)DISKSIM_DISK_NEVER_DISCONNECT_loader,
(void *)DISKSIM_DISK_AVG_SECTORS_PER_CYLINDER_loader,
(void *)DISKSIM_DISK_MAXIMUM_NUMBER_OF_WRITE_SEGMENTS_loader,
(void *)DISKSIM_DISK_USE_SEPARATE_WRITE_SEGMENT_loader,
(void *)DISKSIM_DISK_LOW__WATER_MARK_loader,
(void *)DISKSIM_DISK_HIGH__WATER_MARK_loader,
(void *)DISKSIM_DISK_SET_WATERMARK_BY_REQSIZE_loader,
(void *)DISKSIM_DISK_CALC_SECTOR_BY_SECTOR_loader,
(void *)DISKSIM_DISK_ENABLE_CACHING_IN_BUFFER_loader,
(void *)DISKSIM_DISK_BUFFER_CONTINUOUS_READ_loader,
(void *)DISKSIM_DISK_MINIMUM_READ_AHEAD__loader,
(void *)DISKSIM_DISK_MAXIMUM_READ_AHEAD__loader,
(void *)DISKSIM_DISK_READ_AHEAD_OVER_REQUESTED_loader,
(void *)DISKSIM_DISK_READ_AHEAD_ON_IDLE_HIT_loader,
(void *)DISKSIM_DISK_READ_ANY_FREE_BLOCKS_loader,
(void *)DISKSIM_DISK_FAST_WRITE_LEVEL_loader,
(void *)DISKSIM_DISK_COMBINE_SEQ_WRITES_loader,
(void *)DISKSIM_DISK_STOP_PREFETCH_IN_SECTOR_loader,
(void *)DISKSIM_DISK_DISCONNECT_WRITE_IF_SEEK_loader,
(void *)DISKSIM_DISK_WRITE_HIT_STOP_PREFETCH_loader,
(void *)DISKSIM_DISK_READ_DIRECTLY_TO_BUFFER_loader,
(void *)DISKSIM_DISK_IMMED_TRANSFER_PARTIAL_HIT_loader,
(void *)DISKSIM_DISK_READ_HIT_OVER_AFTER_READ_loader,
(void *)DISKSIM_DISK_READ_HIT_OVER_AFTER_WRITE_loader,
(void *)DISKSIM_DISK_READ_MISS_OVER_AFTER_READ_loader,
(void *)DISKSIM_DISK_READ_MISS_OVER_AFTER_WRITE_loader,
(void *)DISKSIM_DISK_WRITE_HIT_OVER_AFTER_READ_loader,
(void *)DISKSIM_DISK_WRITE_HIT_OVER_AFTER_WRITE_loader,
(void *)DISKSIM_DISK_WRITE_MISS_OVER_AFTER_READ_loader,
(void *)DISKSIM_DISK_WRITE_MISS_OVER_AFTER_WRITE_loader,
(void *)DISKSIM_DISK_READ_COMPLETION_OVERHEAD_loader,
(void *)DISKSIM_DISK_WRITE_COMPLETION_OVERHEAD_loader,
(void *)DISKSIM_DISK_DATA_PREPARATION_OVERHEAD_loader,
(void *)DISKSIM_DISK_FIRST_RESELECT_OVERHEAD_loader,
(void *)DISKSIM_DISK_OTHER_RESELECT_OVERHEAD_loader,
(void *)DISKSIM_DISK_READ_DISCONNECT_AFTERREAD_loader,
(void *)DISKSIM_DISK_READ_DISCONNECT_AFTERWRITE_loader,
(void *)DISKSIM_DISK_WRITE_DISCONNECT_OVERHEAD_loader,
(void *)DISKSIM_DISK_EXTRA_WRITE_DISCONNECT_loader,
(void *)DISKSIM_DISK_EXTRADISC_COMMAND_OVERHEAD_loader,
(void *)DISKSIM_DISK_EXTRADISC_DISCONNECT_OVERHEAD_loader,
(void *)DISKSIM_DISK_EXTRADISC_INTER_DISCONNECT_DELAY_loader,
(void *)DISKSIM_DISK_EXTRADISC_2ND_DISCONNECT_OVERHEAD_loader,
(void *)DISKSIM_DISK_EXTRADISC_SEEK_DELTA_loader,
(void *)DISKSIM_DISK_MINIMUM_SEEK_DELAY_loader,
(void *)DISKSIM_DISK_IMMEDIATE_BUFFER_READ_loader,
(void *)DISKSIM_DISK_IMMEDIATE_BUFFER_WRITE_loader
};

lp_paramdep_t DISKSIM_DISK_deps[] = {
DISKSIM_DISK_MODEL_depend,
DISKSIM_DISK_SCHEDULER_depend,
DISKSIM_DISK_MAX_QUEUE_LENGTH_depend,
DISKSIM_DISK_BULK_SECTOR_TRANSFER_TIME_depend,
DISKSIM_DISK_SEGMENT_SIZE__depend,
DISKSIM_DISK_NUMBER_OF_BUFFER_SEGMENTS_depend,
DISKSIM_DISK_PRINT_STATS_depend,
DISKSIM_DISK_PER_REQUEST_OVERHEAD_TIME_depend,
DISKSIM_DISK_TIME_SCALE_FOR_OVERHEADS_depend,
DISKSIM_DISK_HOLD_BUS_ENTIRE_READ_XFER_depend,
DISKSIM_DISK_HOLD_BUS_ENTIRE_WRITE_XFER_depend,
DISKSIM_DISK_ALLOW_ALMOST_READ_HITS_depend,
DISKSIM_DISK_ALLOW_SNEAKY_FULL_READ_HITS_depend,
DISKSIM_DISK_ALLOW_SNEAKY_PARTIAL_READ_HITS_depend,
DISKSIM_DISK_ALLOW_SNEAKY_INTERMEDIATE_READ_HITS_depend,
DISKSIM_DISK_ALLOW_READ_HITS_ON_WRITE_DATA_depend,
DISKSIM_DISK_ALLOW_WRITE_PREBUFFERING_depend,
DISKSIM_DISK_PRESEEKING_LEVEL_depend,
DISKSIM_DISK_NEVER_DISCONNECT_depend,
DISKSIM_DISK_AVG_SECTORS_PER_CYLINDER_depend,
DISKSIM_DISK_MAXIMUM_NUMBER_OF_WRITE_SEGMENTS_depend,
DISKSIM_DISK_USE_SEPARATE_WRITE_SEGMENT_depend,
DISKSIM_DISK_LOW__WATER_MARK_depend,
DISKSIM_DISK_HIGH__WATER_MARK_depend,
DISKSIM_DISK_SET_WATERMARK_BY_REQSIZE_depend,
DISKSIM_DISK_CALC_SECTOR_BY_SECTOR_depend,
DISKSIM_DISK_ENABLE_CACHING_IN_BUFFER_depend,
DISKSIM_DISK_BUFFER_CONTINUOUS_READ_depend,
DISKSIM_DISK_MINIMUM_READ_AHEAD__depend,
DISKSIM_DISK_MAXIMUM_READ_AHEAD__depend,
DISKSIM_DISK_READ_AHEAD_OVER_REQUESTED_depend,
DISKSIM_DISK_READ_AHEAD_ON_IDLE_HIT_depend,
DISKSIM_DISK_READ_ANY_FREE_BLOCKS_depend,
DISKSIM_DISK_FAST_WRITE_LEVEL_depend,
DISKSIM_DISK_COMBINE_SEQ_WRITES_depend,
DISKSIM_DISK_STOP_PREFETCH_IN_SECTOR_depend,
DISKSIM_DISK_DISCONNECT_WRITE_IF_SEEK_depend,
DISKSIM_DISK_WRITE_HIT_STOP_PREFETCH_depend,
DISKSIM_DISK_READ_DIRECTLY_TO_BUFFER_depend,
DISKSIM_DISK_IMMED_TRANSFER_PARTIAL_HIT_depend,
DISKSIM_DISK_READ_HIT_OVER_AFTER_READ_depend,
DISKSIM_DISK_READ_HIT_OVER_AFTER_WRITE_depend,
DISKSIM_DISK_READ_MISS_OVER_AFTER_READ_depend,
DISKSIM_DISK_READ_MISS_OVER_AFTER_WRITE_depend,
DISKSIM_DISK_WRITE_HIT_OVER_AFTER_READ_depend,
DISKSIM_DISK_WRITE_HIT_OVER_AFTER_WRITE_depend,
DISKSIM_DISK_WRITE_MISS_OVER_AFTER_READ_depend,
DISKSIM_DISK_WRITE_MISS_OVER_AFTER_WRITE_depend,
DISKSIM_DISK_READ_COMPLETION_OVERHEAD_depend,
DISKSIM_DISK_WRITE_COMPLETION_OVERHEAD_depend,
DISKSIM_DISK_DATA_PREPARATION_OVERHEAD_depend,
DISKSIM_DISK_FIRST_RESELECT_OVERHEAD_depend,
DISKSIM_DISK_OTHER_RESELECT_OVERHEAD_depend,
DISKSIM_DISK_READ_DISCONNECT_AFTERREAD_depend,
DISKSIM_DISK_READ_DISCONNECT_AFTERWRITE_depend,
DISKSIM_DISK_WRITE_DISCONNECT_OVERHEAD_depend,
DISKSIM_DISK_EXTRA_WRITE_DISCONNECT_depend,
DISKSIM_DISK_EXTRADISC_COMMAND_OVERHEAD_depend,
DISKSIM_DISK_EXTRADISC_DISCONNECT_OVERHEAD_depend,
DISKSIM_DISK_EXTRADISC_INTER_DISCONNECT_DELAY_depend,
DISKSIM_DISK_EXTRADISC_2ND_DISCONNECT_OVERHEAD_depend,
DISKSIM_DISK_EXTRADISC_SEEK_DELTA_depend,
DISKSIM_DISK_MINIMUM_SEEK_DELAY_depend,
DISKSIM_DISK_IMMEDIATE_BUFFER_READ_depend,
DISKSIM_DISK_IMMEDIATE_BUFFER_WRITE_depend
};

