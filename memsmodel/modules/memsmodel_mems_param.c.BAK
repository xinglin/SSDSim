#include "memsmodel_mems_param.h"
#include <libparam/bitvector.h>
#include "../mems_global.h"
static int MEMSMODEL_MEMS_SCHEDULER_depend(char *bv) {
return -1;
}

static void MEMSMODEL_MEMS_SCHEDULER_loader(struct mems * result, struct lp_block *blk) { 
if (! (result->queue = (struct ioq *)disksim_ioqueue_loadparams(blk, device_printqueuestats, device_printcritstats, device_printidlestats, device_printintarrstats, device_printsizestats))) { // foo 
 } 

}

static int MEMSMODEL_MEMS_POINTS_IN_PRECOMPUTED_SEEK_CURVE_depend(char *bv) {
return -1;
}

static void MEMSMODEL_MEMS_POINTS_IN_PRECOMPUTED_SEEK_CURVE_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->precompute_seek_count = (i == 0) ? 0 : i+1;

}

static int MEMSMODEL_MEMS_SEEK_FUNCTION_depend(char *bv) {
return -1;
}

static void MEMSMODEL_MEMS_SEEK_FUNCTION_loader(struct mems * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->seek_function = i;

}

static int MEMSMODEL_MEMS_MAX_QUEUE_LENGTH_depend(char *bv) {
return -1;
}

static void MEMSMODEL_MEMS_MAX_QUEUE_LENGTH_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->maxqlen = i;

}

static int MEMSMODEL_MEMS_BULK_SECTOR_TRANSFER_TIME_depend(char *bv) {
return -1;
}

static void MEMSMODEL_MEMS_BULK_SECTOR_TRANSFER_TIME_loader(struct mems * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->blktranstime = d;

}

static int MEMSMODEL_MEMS_SEGMENT_SIZE__depend(char *bv) {
return -1;
}

static void MEMSMODEL_MEMS_SEGMENT_SIZE__loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->segsize = i;

}

static int MEMSMODEL_MEMS_NUMBER_OF_BUFFER_SEGMENTS_depend(char *bv) {
return -1;
}

static void MEMSMODEL_MEMS_NUMBER_OF_BUFFER_SEGMENTS_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->numsegs = i;

}

static int MEMSMODEL_MEMS_PRINT_STATS_depend(char *bv) {
return -1;
}

static void MEMSMODEL_MEMS_PRINT_STATS_loader(struct mems * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->printstats = i;

}

static int MEMSMODEL_MEMS_COMMAND_OVERHEAD_depend(char *bv) {
return -1;
}

static void MEMSMODEL_MEMS_COMMAND_OVERHEAD_loader(struct mems * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->overhead = d;

}

static int MEMSMODEL_MEMS_NUMBER_OF_SLEDS_depend(char *bv) {
return -1;
}

static void MEMSMODEL_MEMS_NUMBER_OF_SLEDS_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->num_sleds = i;
 result->sled = malloc(i * sizeof(mems_sled_t));
 bzero(result->sled, i * sizeof(mems_sled_t));

}

static int MEMSMODEL_MEMS_LAYOUT_POLICY_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_LAYOUT_POLICY_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].layout_policy = i;

}

static int MEMSMODEL_MEMS_SLED_MOVEMENT_X_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SLED_MOVEMENT_X_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].x_length_nm = i;

}

static int MEMSMODEL_MEMS_SLED_MOVEMENT_Y_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SLED_MOVEMENT_Y_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].y_length_nm = i;

}

static int MEMSMODEL_MEMS_BIT_CELL_LENGTH_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_BIT_CELL_LENGTH_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].bit_length_nm = i;

}

static int MEMSMODEL_MEMS_TIP_SECTOR_LENGTH_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_TIP_SECTOR_LENGTH_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].tip_sector_length_bits = i;

}

static int MEMSMODEL_MEMS_SERVO_BURST_LENGTH_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SERVO_BURST_LENGTH_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].servo_burst_length_bits = i;

}

static int MEMSMODEL_MEMS_TIP_SECTORS_PER_LBN_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_TIP_SECTORS_PER_LBN_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].tip_sectors_per_lbn = i;

}

static int MEMSMODEL_MEMS_NUMBER_OF_USABLE_TIPS_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_NUMBER_OF_USABLE_TIPS_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].tips_usable = i;

}

static int MEMSMODEL_MEMS_SIMULTANEOUSLY_ACTIVE_TIPS_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SIMULTANEOUSLY_ACTIVE_TIPS_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].tips_simultaneous = i;

}

static int MEMSMODEL_MEMS_BIDIRECTIONAL_ACCESS_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_BIDIRECTIONAL_ACCESS_loader(struct mems * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->sled[0].bidirectional_access = i;

}

static int MEMSMODEL_MEMS_SLED_ACCELERATION_X_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SLED_ACCELERATION_X_loader(struct mems * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->sled[0].x_accel_nm_s2 = d * 1000000000.0;

}

static int MEMSMODEL_MEMS_SLED_ACCELERATION_Y_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SLED_ACCELERATION_Y_loader(struct mems * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->sled[0].y_accel_nm_s2 = d * 1000000000.0;

}

static int MEMSMODEL_MEMS_SLED_ACCESS_SPEED_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SLED_ACCESS_SPEED_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].y_access_speed_bit_s = i;

}

static int MEMSMODEL_MEMS_SLED_RESONANT_FREQUENCY_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SLED_RESONANT_FREQUENCY_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].sled_resonant_freq_hz = i;

}

static int MEMSMODEL_MEMS_SETTLING_TIME_CONSTANTS_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SETTLING_TIME_CONSTANTS_loader(struct mems * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->sled[0].num_time_constants = d;

}

static int MEMSMODEL_MEMS_SPRING_CONSTANT_FACTOR_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SPRING_CONSTANT_FACTOR_loader(struct mems * result, double d) { 
if (! ((d >= 0))) { // foo 
 } 
 result->sled[0].spring_factor = d;

}

static int MEMSMODEL_MEMS_PREFETCH_DEPTH_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_PREFETCH_DEPTH_loader(struct mems * result, int i) { 
if (! ((i >= 0))) { // foo 
 } 
 result->sled[0].prefetch_depth = i;

}

static int MEMSMODEL_MEMS_TIME_BEFORE_SLED_INACTIVE_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_TIME_BEFORE_SLED_INACTIVE_loader(struct mems * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->sled[0].inactive_delay_ms = d;

}

static int MEMSMODEL_MEMS_STARTUP_DELAY_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_STARTUP_DELAY_loader(struct mems * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->sled[0].startup_time_ms = d;

}

static int MEMSMODEL_MEMS_SLED_ACTIVE_POWER_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SLED_ACTIVE_POWER_loader(struct mems * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->sled[0].active_power_mw = d;

}

static int MEMSMODEL_MEMS_SLED_INACTIVE_POWER_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_SLED_INACTIVE_POWER_loader(struct mems * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->sled[0].inactive_power_mw = d;

}

static int MEMSMODEL_MEMS_TIP_ACCESS_POWER_depend(char *bv) {
if(!BIT_TEST(bv, MEMSMODEL_MEMS_NUMBER_OF_SLEDS)) { return MEMSMODEL_MEMS_NUMBER_OF_SLEDS; }
return -1;
}

static void MEMSMODEL_MEMS_TIP_ACCESS_POWER_loader(struct mems * result, double d) { 
if (! ((d >= 0.0))) { // foo 
 } 
 result->sled[0].tip_power_mw = d;

}

void * MEMSMODEL_MEMS_loaders[] = {
(void *)MEMSMODEL_MEMS_SCHEDULER_loader,
(void *)MEMSMODEL_MEMS_POINTS_IN_PRECOMPUTED_SEEK_CURVE_loader,
(void *)MEMSMODEL_MEMS_SEEK_FUNCTION_loader,
(void *)MEMSMODEL_MEMS_MAX_QUEUE_LENGTH_loader,
(void *)MEMSMODEL_MEMS_BULK_SECTOR_TRANSFER_TIME_loader,
(void *)MEMSMODEL_MEMS_SEGMENT_SIZE__loader,
(void *)MEMSMODEL_MEMS_NUMBER_OF_BUFFER_SEGMENTS_loader,
(void *)MEMSMODEL_MEMS_PRINT_STATS_loader,
(void *)MEMSMODEL_MEMS_COMMAND_OVERHEAD_loader,
(void *)MEMSMODEL_MEMS_NUMBER_OF_SLEDS_loader,
(void *)MEMSMODEL_MEMS_LAYOUT_POLICY_loader,
(void *)MEMSMODEL_MEMS_SLED_MOVEMENT_X_loader,
(void *)MEMSMODEL_MEMS_SLED_MOVEMENT_Y_loader,
(void *)MEMSMODEL_MEMS_BIT_CELL_LENGTH_loader,
(void *)MEMSMODEL_MEMS_TIP_SECTOR_LENGTH_loader,
(void *)MEMSMODEL_MEMS_SERVO_BURST_LENGTH_loader,
(void *)MEMSMODEL_MEMS_TIP_SECTORS_PER_LBN_loader,
(void *)MEMSMODEL_MEMS_NUMBER_OF_USABLE_TIPS_loader,
(void *)MEMSMODEL_MEMS_SIMULTANEOUSLY_ACTIVE_TIPS_loader,
(void *)MEMSMODEL_MEMS_BIDIRECTIONAL_ACCESS_loader,
(void *)MEMSMODEL_MEMS_SLED_ACCELERATION_X_loader,
(void *)MEMSMODEL_MEMS_SLED_ACCELERATION_Y_loader,
(void *)MEMSMODEL_MEMS_SLED_ACCESS_SPEED_loader,
(void *)MEMSMODEL_MEMS_SLED_RESONANT_FREQUENCY_loader,
(void *)MEMSMODEL_MEMS_SETTLING_TIME_CONSTANTS_loader,
(void *)MEMSMODEL_MEMS_SPRING_CONSTANT_FACTOR_loader,
(void *)MEMSMODEL_MEMS_PREFETCH_DEPTH_loader,
(void *)MEMSMODEL_MEMS_TIME_BEFORE_SLED_INACTIVE_loader,
(void *)MEMSMODEL_MEMS_STARTUP_DELAY_loader,
(void *)MEMSMODEL_MEMS_SLED_ACTIVE_POWER_loader,
(void *)MEMSMODEL_MEMS_SLED_INACTIVE_POWER_loader,
(void *)MEMSMODEL_MEMS_TIP_ACCESS_POWER_loader
};

lp_paramdep_t MEMSMODEL_MEMS_deps[] = {
MEMSMODEL_MEMS_SCHEDULER_depend,
MEMSMODEL_MEMS_POINTS_IN_PRECOMPUTED_SEEK_CURVE_depend,
MEMSMODEL_MEMS_SEEK_FUNCTION_depend,
MEMSMODEL_MEMS_MAX_QUEUE_LENGTH_depend,
MEMSMODEL_MEMS_BULK_SECTOR_TRANSFER_TIME_depend,
MEMSMODEL_MEMS_SEGMENT_SIZE__depend,
MEMSMODEL_MEMS_NUMBER_OF_BUFFER_SEGMENTS_depend,
MEMSMODEL_MEMS_PRINT_STATS_depend,
MEMSMODEL_MEMS_COMMAND_OVERHEAD_depend,
MEMSMODEL_MEMS_NUMBER_OF_SLEDS_depend,
MEMSMODEL_MEMS_LAYOUT_POLICY_depend,
MEMSMODEL_MEMS_SLED_MOVEMENT_X_depend,
MEMSMODEL_MEMS_SLED_MOVEMENT_Y_depend,
MEMSMODEL_MEMS_BIT_CELL_LENGTH_depend,
MEMSMODEL_MEMS_TIP_SECTOR_LENGTH_depend,
MEMSMODEL_MEMS_SERVO_BURST_LENGTH_depend,
MEMSMODEL_MEMS_TIP_SECTORS_PER_LBN_depend,
MEMSMODEL_MEMS_NUMBER_OF_USABLE_TIPS_depend,
MEMSMODEL_MEMS_SIMULTANEOUSLY_ACTIVE_TIPS_depend,
MEMSMODEL_MEMS_BIDIRECTIONAL_ACCESS_depend,
MEMSMODEL_MEMS_SLED_ACCELERATION_X_depend,
MEMSMODEL_MEMS_SLED_ACCELERATION_Y_depend,
MEMSMODEL_MEMS_SLED_ACCESS_SPEED_depend,
MEMSMODEL_MEMS_SLED_RESONANT_FREQUENCY_depend,
MEMSMODEL_MEMS_SETTLING_TIME_CONSTANTS_depend,
MEMSMODEL_MEMS_SPRING_CONSTANT_FACTOR_depend,
MEMSMODEL_MEMS_PREFETCH_DEPTH_depend,
MEMSMODEL_MEMS_TIME_BEFORE_SLED_INACTIVE_depend,
MEMSMODEL_MEMS_STARTUP_DELAY_depend,
MEMSMODEL_MEMS_SLED_ACTIVE_POWER_depend,
MEMSMODEL_MEMS_SLED_INACTIVE_POWER_depend,
MEMSMODEL_MEMS_TIP_ACCESS_POWER_depend
};

