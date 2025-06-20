#include <x86intrin.h>  // for __rdtscp
#include <stdint.h>

// 序列化版本，防止乱序执行带来的误差
static inline uint64_t rdtscp_start() {
    unsigned int aux;
    _mm_mfence();  // memory fence to prevent reordering
    return __rdtscp(&aux);
}

static inline uint64_t rdtscp_end() {
    unsigned int aux;
    uint64_t t = __rdtscp(&aux);
    _mm_mfence();
    return t;
}
