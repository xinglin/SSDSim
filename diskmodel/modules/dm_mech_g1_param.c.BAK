#include "dm_mech_g1_param.h"
#include <libparam/bitvector.h>
#include "../mech_g1.h"
#include "../mech_g1_private.h"
static int DM_MECH_G1_ACCESS_TIME_TYPE_depend(char *bv) {
return -1;
}

static void DM_MECH_G1_ACCESS_TIME_TYPE_loader(struct dm_mech_g1 * result, char *s) { 
 if(!strcmp(s, "constant")) { }
 else if(!strcmp(s, "averageRotation")) {
 result->acctime = AVGROTATE;
 }
 else if(!strcmp(s, "trackSwitchPlusRotation")) {
 result->acctime = SKEWED_FOR_TRACK_SWITCH;
 }
 else {
 fprintf(stderr, "*** error: Unknown access time type: %s\n", s);
 ddbg_assert(0);
 }

}

static int DM_MECH_G1_CONSTANT_ACCESS_TIME_depend(char *bv) {
return -1;
}

static void DM_MECH_G1_CONSTANT_ACCESS_TIME_loader(struct dm_mech_g1 * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->acctime = d;

}

static int DM_MECH_G1_SEEK_TYPE_depend(char *bv) {
return -1;
}

static void DM_MECH_G1_SEEK_TYPE_loader(struct dm_mech_g1 * result, char *s) { 
 if(!strcmp(s, "constant")) {
 result->seektime = SEEK_CONST;
 }
 else if(!strcmp(s, "linear")) {
 result->seektime = SEEK_3PT_LINE;
 }
 else if(!strcmp(s, "curve")) {
 result->seektime = SEEK_3PT_CURVE;
 }
 else if(!strcmp(s, "hpl")) {
 result->seektime = SEEK_HPL;
 }
 else if(!strcmp(s, "hplplus10")) {
 result->seektime = SEEK_1ST10_PLUS_HPL;
 }
 else if(!strcmp(s, "extracted")) {
 result->seektime = SEEK_EXTRACTED;
 }
 else {
 fprintf(stderr, "*** error: Unknown seek type: %s\n", s);
 ddbg_assert(0);
 }
 result->seekfn = dm_mech_g1_seekfns[result->seektime];

}

static int DM_MECH_G1_AVERAGE_SEEK_TIME_depend(char *bv) {
return -1;
}

static void DM_MECH_G1_AVERAGE_SEEK_TIME_loader(struct dm_mech_g1 * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->seekavg = d;

}

static int DM_MECH_G1_CONSTANT_SEEK_TIME_depend(char *bv) {
return -1;
}

static void DM_MECH_G1_CONSTANT_SEEK_TIME_loader(struct dm_mech_g1 * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->seektime = d;

}

static int DM_MECH_G1_SINGLE_CYLINDER_SEEK_TIME_depend(char *bv) {
return -1;
}

static void DM_MECH_G1_SINGLE_CYLINDER_SEEK_TIME_loader(struct dm_mech_g1 * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->seekone = d;

}

static int DM_MECH_G1_FULL_STROBE_SEEK_TIME_depend(char *bv) {
return -1;
}

static void DM_MECH_G1_FULL_STROBE_SEEK_TIME_loader(struct dm_mech_g1 * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->seekfull = d;

}

static int DM_MECH_G1_FULL_SEEK_CURVE_depend(char *bv) {
if(!BIT_TEST(bv, DM_MECH_G1_SEEK_TYPE)) { return DM_MECH_G1_SEEK_TYPE; }
return -1;
}

static void DM_MECH_G1_FULL_SEEK_CURVE_loader(struct dm_mech_g1 * result, char *s) { 
 result->seektime = SEEK_EXTRACTED;
 dm_mech_g1_read_extracted_seek_curve(s,
	 &result->xseekcnt,
	 &result->xseekdists,
	 &result->xseektimes);


}

static int DM_MECH_G1_ADD_WRITE_SETTLING_DELAY_depend(char *bv) {
return -1;
}

static void DM_MECH_G1_ADD_WRITE_SETTLING_DELAY_loader(struct dm_mech_g1 * result, double d) { 
 result->seekwritedelta = dm_time_dtoi(d);

}

static int DM_MECH_G1_HEAD_SWITCH_TIME_depend(char *bv) {
return -1;
}

static void DM_MECH_G1_HEAD_SWITCH_TIME_loader(struct dm_mech_g1 * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->headswitch = dm_time_dtoi(d);

}

static int DM_MECH_G1_ROTATION_SPEED__depend(char *bv) {
return -1;
}

static void DM_MECH_G1_ROTATION_SPEED__loader(struct dm_mech_g1 * result, int i) { 
if (! (i > 0)) { // foo 
 } 
 result->rpm = i;

}

static int DM_MECH_G1_PERCENT_ERROR_IN_RPMS_depend(char *bv) {
return -1;
}

static void DM_MECH_G1_PERCENT_ERROR_IN_RPMS_loader(struct dm_mech_g1 * result, double d) { 
if (! (RANGE(d, 0.0, 100.0))) { // foo 
 } 
 result->rpmerr = d;

}

static int DM_MECH_G1_FIRST_TEN_SEEK_TIMES_depend(char *bv) {
if(!BIT_TEST(bv, DM_MECH_G1_SEEK_TYPE)) { return DM_MECH_G1_SEEK_TYPE; }
return -1;
}

static void DM_MECH_G1_FIRST_TEN_SEEK_TIMES_loader(struct dm_mech_g1 * result, struct lp_list *l) { 
if (! (!do_1st10_seeks(result,l))) { // foo 
 } 

}

static int DM_MECH_G1_HPL_SEEK_EQUATION_VALUES_depend(char *bv) {
if(!BIT_TEST(bv, DM_MECH_G1_SEEK_TYPE)) { return DM_MECH_G1_SEEK_TYPE; }
return -1;
}

static void DM_MECH_G1_HPL_SEEK_EQUATION_VALUES_loader(struct dm_mech_g1 * result, struct lp_list *l) { 
if (! (!do_hpl_seek(result,l))) { // foo 
 } 

}

void * DM_MECH_G1_loaders[] = {
(void *)DM_MECH_G1_ACCESS_TIME_TYPE_loader,
(void *)DM_MECH_G1_CONSTANT_ACCESS_TIME_loader,
(void *)DM_MECH_G1_SEEK_TYPE_loader,
(void *)DM_MECH_G1_AVERAGE_SEEK_TIME_loader,
(void *)DM_MECH_G1_CONSTANT_SEEK_TIME_loader,
(void *)DM_MECH_G1_SINGLE_CYLINDER_SEEK_TIME_loader,
(void *)DM_MECH_G1_FULL_STROBE_SEEK_TIME_loader,
(void *)DM_MECH_G1_FULL_SEEK_CURVE_loader,
(void *)DM_MECH_G1_ADD_WRITE_SETTLING_DELAY_loader,
(void *)DM_MECH_G1_HEAD_SWITCH_TIME_loader,
(void *)DM_MECH_G1_ROTATION_SPEED__loader,
(void *)DM_MECH_G1_PERCENT_ERROR_IN_RPMS_loader,
(void *)DM_MECH_G1_FIRST_TEN_SEEK_TIMES_loader,
(void *)DM_MECH_G1_HPL_SEEK_EQUATION_VALUES_loader
};

lp_paramdep_t DM_MECH_G1_deps[] = {
DM_MECH_G1_ACCESS_TIME_TYPE_depend,
DM_MECH_G1_CONSTANT_ACCESS_TIME_depend,
DM_MECH_G1_SEEK_TYPE_depend,
DM_MECH_G1_AVERAGE_SEEK_TIME_depend,
DM_MECH_G1_CONSTANT_SEEK_TIME_depend,
DM_MECH_G1_SINGLE_CYLINDER_SEEK_TIME_depend,
DM_MECH_G1_FULL_STROBE_SEEK_TIME_depend,
DM_MECH_G1_FULL_SEEK_CURVE_depend,
DM_MECH_G1_ADD_WRITE_SETTLING_DELAY_depend,
DM_MECH_G1_HEAD_SWITCH_TIME_depend,
DM_MECH_G1_ROTATION_SPEED__depend,
DM_MECH_G1_PERCENT_ERROR_IN_RPMS_depend,
DM_MECH_G1_FIRST_TEN_SEEK_TIMES_depend,
DM_MECH_G1_HPL_SEEK_EQUATION_VALUES_depend
};

