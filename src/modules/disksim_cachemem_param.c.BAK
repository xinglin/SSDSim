#include "disksim_cachemem_param.h"
#include <libparam/bitvector.h>
#include "disksim_cachemem.h"
static int DISKSIM_CACHEMEM_CACHE_SIZE_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_CACHE_SIZE_loader(struct cache_mem * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 if(result->map) { fprintf(stderr, "*** ignoring repeat cache size definition.\n"); }
 else { int c2; result->size = i; result->mapmask = 0; result->map = DISKSIM_malloc((result->mapmask+1)*sizeof(cache_mapentry)); result->map[0].freelist = NULL; for (c2=0; c2<CACHE_MAXSEGMENTS; c2++) { result->map[0].maxactive[c2] = result->size; result->map[0].lru[c2] = NULL; } }

}

static int DISKSIM_CACHEMEM_SLRU_SEGMENTS_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_SLRU_SEGMENTS_loader(struct cache_mem * result, struct lp_list *l) { 
 cachemem_setup_segs(result, l);

}

static int DISKSIM_CACHEMEM_LINE_SIZE_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_LINE_SIZE_loader(struct cache_mem * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->linesize = i;

}

static int DISKSIM_CACHEMEM_BIT_GRANULARITY_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_BIT_GRANULARITY_loader(struct cache_mem * result, int i) { 
if (! (i > 0)) { // foo 
 } 
 result->atomsperbit = i;

}

static int DISKSIM_CACHEMEM_LOCK_GRANULARITY_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_LOCK_GRANULARITY_loader(struct cache_mem * result, int i) { 
if (! (i > 0)) { // foo 
 } 
 result->lockgran = i;

}

static int DISKSIM_CACHEMEM_SHARED_READ_LOCKS_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_SHARED_READ_LOCKS_loader(struct cache_mem * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->sharedreadlocks = i;

}

static int DISKSIM_CACHEMEM_MAX_REQUEST_SIZE_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_MAX_REQUEST_SIZE_loader(struct cache_mem * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->maxreqsize = i;

}

static int DISKSIM_CACHEMEM_REPLACEMENT_POLICY_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_REPLACEMENT_POLICY_loader(struct cache_mem * result, int i) { 
if (! (RANGE(i,CACHE_REPLACE_MIN,CACHE_REPLACE_MAX))) { // foo 
 } 
 result->replacepolicy = i;

}

static int DISKSIM_CACHEMEM_ALLOCATION_POLICY_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_ALLOCATION_POLICY_loader(struct cache_mem * result, int i) { 
if (! (RANGE(i,CACHE_ALLOCATE_MIN,CACHE_ALLOCATE_MAX))) { // foo 
 } 
 result->allocatepolicy = i;

}

static int DISKSIM_CACHEMEM_WRITE_SCHEME_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_WRITE_SCHEME_loader(struct cache_mem * result, int i) { 
if (! (RANGE(i,CACHE_WRITE_MIN,CACHE_WRITE_MAX))) { // foo 
 } 
 result->writescheme = i;

}

static int DISKSIM_CACHEMEM_FLUSH_POLICY_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_FLUSH_POLICY_loader(struct cache_mem * result, int i) { 
if (! (RANGE(i,CACHE_FLUSH_MIN,CACHE_FLUSH_MAX))) { // foo 
 } 
 result->flush_policy = i;

}

static int DISKSIM_CACHEMEM_FLUSH_PERIOD_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_FLUSH_PERIOD_loader(struct cache_mem * result, double d) { 
if (! (d >= 0)) { // foo 
 } 
 result->flush_period = d;

}

static int DISKSIM_CACHEMEM_FLUSH_IDLE_DELAY_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_FLUSH_IDLE_DELAY_loader(struct cache_mem * result, double d) { 
if (! ((d >= 0) || (d == -1.0))) { // foo 
 } 
 result->flush_idledelay = d;

}

static int DISKSIM_CACHEMEM_FLUSH_MAX_LINE_CLUSTER_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_FLUSH_MAX_LINE_CLUSTER_loader(struct cache_mem * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->flush_maxlinecluster = i;

}

static int DISKSIM_CACHEMEM_READ_PREFETCH_TYPE_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_READ_PREFETCH_TYPE_loader(struct cache_mem * result, int i) { 
if (! (RANGE(i,CACHE_PREFETCH_MIN,CACHE_PREFETCH_MAX))) { // foo 
 } 
 result->read_prefetch_type = i;

}

static int DISKSIM_CACHEMEM_WRITE_PREFETCH_TYPE_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_WRITE_PREFETCH_TYPE_loader(struct cache_mem * result, int i) { 
if (! (RANGE(i,CACHE_PREFETCH_MIN,CACHE_PREFETCH_MAX))) { // foo 
 } 
 result->writefill_prefetch_type = i;

}

static int DISKSIM_CACHEMEM_LINE_BY_LINE_FETCHES_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_LINE_BY_LINE_FETCHES_loader(struct cache_mem * result, int i) { 
if (! (RANGE(i,0,1))) { // foo 
 } 
 result->read_line_by_line = i; result->write_line_by_line = i;

}

static int DISKSIM_CACHEMEM_MAX_GATHER_depend(char *bv) {
return -1;
}

static void DISKSIM_CACHEMEM_MAX_GATHER_loader(struct cache_mem * result, int i) { 
if (! (i >= 0)) { // foo 
 } 
 result->maxscatgath = i;

}

void * DISKSIM_CACHEMEM_loaders[] = {
(void *)DISKSIM_CACHEMEM_CACHE_SIZE_loader,
(void *)DISKSIM_CACHEMEM_SLRU_SEGMENTS_loader,
(void *)DISKSIM_CACHEMEM_LINE_SIZE_loader,
(void *)DISKSIM_CACHEMEM_BIT_GRANULARITY_loader,
(void *)DISKSIM_CACHEMEM_LOCK_GRANULARITY_loader,
(void *)DISKSIM_CACHEMEM_SHARED_READ_LOCKS_loader,
(void *)DISKSIM_CACHEMEM_MAX_REQUEST_SIZE_loader,
(void *)DISKSIM_CACHEMEM_REPLACEMENT_POLICY_loader,
(void *)DISKSIM_CACHEMEM_ALLOCATION_POLICY_loader,
(void *)DISKSIM_CACHEMEM_WRITE_SCHEME_loader,
(void *)DISKSIM_CACHEMEM_FLUSH_POLICY_loader,
(void *)DISKSIM_CACHEMEM_FLUSH_PERIOD_loader,
(void *)DISKSIM_CACHEMEM_FLUSH_IDLE_DELAY_loader,
(void *)DISKSIM_CACHEMEM_FLUSH_MAX_LINE_CLUSTER_loader,
(void *)DISKSIM_CACHEMEM_READ_PREFETCH_TYPE_loader,
(void *)DISKSIM_CACHEMEM_WRITE_PREFETCH_TYPE_loader,
(void *)DISKSIM_CACHEMEM_LINE_BY_LINE_FETCHES_loader,
(void *)DISKSIM_CACHEMEM_MAX_GATHER_loader
};

lp_paramdep_t DISKSIM_CACHEMEM_deps[] = {
DISKSIM_CACHEMEM_CACHE_SIZE_depend,
DISKSIM_CACHEMEM_SLRU_SEGMENTS_depend,
DISKSIM_CACHEMEM_LINE_SIZE_depend,
DISKSIM_CACHEMEM_BIT_GRANULARITY_depend,
DISKSIM_CACHEMEM_LOCK_GRANULARITY_depend,
DISKSIM_CACHEMEM_SHARED_READ_LOCKS_depend,
DISKSIM_CACHEMEM_MAX_REQUEST_SIZE_depend,
DISKSIM_CACHEMEM_REPLACEMENT_POLICY_depend,
DISKSIM_CACHEMEM_ALLOCATION_POLICY_depend,
DISKSIM_CACHEMEM_WRITE_SCHEME_depend,
DISKSIM_CACHEMEM_FLUSH_POLICY_depend,
DISKSIM_CACHEMEM_FLUSH_PERIOD_depend,
DISKSIM_CACHEMEM_FLUSH_IDLE_DELAY_depend,
DISKSIM_CACHEMEM_FLUSH_MAX_LINE_CLUSTER_depend,
DISKSIM_CACHEMEM_READ_PREFETCH_TYPE_depend,
DISKSIM_CACHEMEM_WRITE_PREFETCH_TYPE_depend,
DISKSIM_CACHEMEM_LINE_BY_LINE_FETCHES_depend,
DISKSIM_CACHEMEM_MAX_GATHER_depend
};

