#include "runtime_internal.h"

typedef int32_t zx_status_t;
typedef int64_t zx_time_t;
extern "C" zx_status_t zx_nanosleep(zx_time_t deadline);

extern "C" WEAK void halide_thread_yield() {
    zx_nanosleep(0);
}
