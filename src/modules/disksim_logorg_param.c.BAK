#include "disksim_logorg_param.h"
#include <libparam/bitvector.h>
#include "../disksim_logorg.h"
static int DISKSIM_LOGORG_ADDRESSING_MODE_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_ADDRESSING_MODE_loader(struct logorg * result, char *s) { 
if (! (!logorg_addr(result, s))) { // foo 
 } 

}

static int DISKSIM_LOGORG_DISTRIBUTION_SCHEME_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_DISTRIBUTION_SCHEME_loader(struct logorg * result, char *s) { 
if (! (!logorg_distn(result, s))) { // foo 
 } 

}

static int DISKSIM_LOGORG_REDUNDANCY_SCHEME_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_REDUNDANCY_SCHEME_loader(struct logorg * result, char *s) { 
if (! (!logorg_redun(result, s))) { // foo 
 } 

}

static int _depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_COMPONENTS_loader(struct logorg * result, char *s) { 

}

static int DISKSIM_LOGORG_DEVICES_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_DEVICES_loader(struct logorg * result, struct lp_list *l) { 
if (! (!getlogorgdevs(result,l))) { // foo 
 } 

}

static int DISKSIM_LOGORG_STRIPE_UNIT_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_STRIPE_UNIT_loader(struct logorg * result, int i) { 
if (! (i > 0)) { // foo 
 } 
 result->stripeunit = i;

}

static int DISKSIM_LOGORG_SYNCH_WRITES_FOR_SAFETY_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_SYNCH_WRITES_FOR_SAFETY_loader(struct logorg * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->writesync = i;

}

static int DISKSIM_LOGORG_NUMBER_OF_COPIES_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_NUMBER_OF_COPIES_loader(struct logorg * result, int i) { 
if (! (i > 0)) { // foo 
 } 
 result->copies = i;

}

static int DISKSIM_LOGORG_COPY_CHOICE_ON_READ_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_COPY_CHOICE_ON_READ_loader(struct logorg * result, int i) { 
if (! (RANGE(i,1,6))) { // foo 
 } 
 result->copychoice = i;

}

static int DISKSIM_LOGORG_RMW_VS_RECONSTRUCT_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_RMW_VS_RECONSTRUCT_loader(struct logorg * result, double d) { 
if (! (RANGE(d,0.0,1.0))) { // foo 
 } 
 result->rmwpoint = d;

}

static int DISKSIM_LOGORG_PARITY_STRIPE_UNIT_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_PARITY_STRIPE_UNIT_loader(struct logorg * result, int i) { 
if (! (i > 0)) { // foo 
 } 
 result->parityunit = i;

}

static int DISKSIM_LOGORG_PARITY_ROTATION_TYPE_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_PARITY_ROTATION_TYPE_loader(struct logorg * result, int i) { 
if (! (RANGE(i,1,4))) { // foo 
 } 
 result->rottype = i;

}

static int DISKSIM_LOGORG_TIME_STAMP_INTERVAL_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_TIME_STAMP_INTERVAL_loader(struct logorg * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->stampstart = d;

}

static int DISKSIM_LOGORG_TIME_STAMP_START_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_TIME_STAMP_START_TIME_loader(struct logorg * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->stampstart = d;

}

static int DISKSIM_LOGORG_TIME_STAMP_STOP_TIME_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_TIME_STAMP_STOP_TIME_loader(struct logorg * result, double d) { 
if (! (d >= 0.0)) { // foo 
 } 
 result->stampstop = d;

}

static int DISKSIM_LOGORG_TIME_STAMP_FILE_NAME_depend(char *bv) {
return -1;
}

static void DISKSIM_LOGORG_TIME_STAMP_FILE_NAME_loader(struct logorg * result, char *s) { 
if (! ((result->stampfile = fopen(s, "w")))) { // foo 
 } 

}

void * DISKSIM_LOGORG_loaders[] = {
(void *)DISKSIM_LOGORG_ADDRESSING_MODE_loader,
(void *)DISKSIM_LOGORG_DISTRIBUTION_SCHEME_loader,
(void *)DISKSIM_LOGORG_REDUNDANCY_SCHEME_loader,
(void *)DISKSIM_LOGORG_COMPONENTS_loader,
(void *)DISKSIM_LOGORG_DEVICES_loader,
(void *)DISKSIM_LOGORG_STRIPE_UNIT_loader,
(void *)DISKSIM_LOGORG_SYNCH_WRITES_FOR_SAFETY_loader,
(void *)DISKSIM_LOGORG_NUMBER_OF_COPIES_loader,
(void *)DISKSIM_LOGORG_COPY_CHOICE_ON_READ_loader,
(void *)DISKSIM_LOGORG_RMW_VS_RECONSTRUCT_loader,
(void *)DISKSIM_LOGORG_PARITY_STRIPE_UNIT_loader,
(void *)DISKSIM_LOGORG_PARITY_ROTATION_TYPE_loader,
(void *)DISKSIM_LOGORG_TIME_STAMP_INTERVAL_loader,
(void *)DISKSIM_LOGORG_TIME_STAMP_START_TIME_loader,
(void *)DISKSIM_LOGORG_TIME_STAMP_STOP_TIME_loader,
(void *)DISKSIM_LOGORG_TIME_STAMP_FILE_NAME_loader
};

lp_paramdep_t DISKSIM_LOGORG_deps[] = {
DISKSIM_LOGORG_ADDRESSING_MODE_depend,
DISKSIM_LOGORG_DISTRIBUTION_SCHEME_depend,
DISKSIM_LOGORG_REDUNDANCY_SCHEME_depend,
_depend,
DISKSIM_LOGORG_DEVICES_depend,
DISKSIM_LOGORG_STRIPE_UNIT_depend,
DISKSIM_LOGORG_SYNCH_WRITES_FOR_SAFETY_depend,
DISKSIM_LOGORG_NUMBER_OF_COPIES_depend,
DISKSIM_LOGORG_COPY_CHOICE_ON_READ_depend,
DISKSIM_LOGORG_RMW_VS_RECONSTRUCT_depend,
DISKSIM_LOGORG_PARITY_STRIPE_UNIT_depend,
DISKSIM_LOGORG_PARITY_ROTATION_TYPE_depend,
DISKSIM_LOGORG_TIME_STAMP_INTERVAL_depend,
DISKSIM_LOGORG_TIME_STAMP_START_TIME_depend,
DISKSIM_LOGORG_TIME_STAMP_STOP_TIME_depend,
DISKSIM_LOGORG_TIME_STAMP_FILE_NAME_depend
};

