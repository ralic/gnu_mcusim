#ifndef MSIM_X86_TSC_H_
#define MSIM_X86_TSC_H_ 1

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdio.h>
#include <cpuid.h>
#include <sys/io.h>

#include "tools/util/tsc.h"

/*
 * Standard way to access the cycle counter.
 */
typedef uint64_t cycles_t;

/*
 * Calibrated TSC frequency.
 *
 * Should be initialized before use.
 */
extern uint64_t tsc_khz;

/* Public prototypes */

uint64_t pit_calibrate_tsc(void);

int tsc_init(void);

/* END Public prototypes */

/* Functions */

static inline cycles_t get_cycles(void)
{
	return rdtsc();
}

/* END Functions */

#ifdef __cplusplus
}
#endif

#endif /* MSIM_X86_TSC_H_ */
