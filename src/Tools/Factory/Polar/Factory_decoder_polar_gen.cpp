#include <sstream>

#include "Tools/Exception/exception.hpp"

/* // GENERATED DECODERS // */

#define ENABLE_SHORT_GENERATED_DECODERS

// before to uncomment these next lines, make sure to run the script to generate the decoders
// (see "scripts/generate_polar_decoders.sh")

// RATE 1/2
// #define ENABLE_DECODER_SC_FAST_N4_K2_SNR25
// #define ENABLE_DECODER_SC_FAST_N8_K4_SNR25
// #define ENABLE_DECODER_SC_FAST_N16_K8_SNR25
// #define ENABLE_DECODER_SC_FAST_N32_K16_SNR25
// #define ENABLE_DECODER_SC_FAST_N64_K32_SNR25
// #define ENABLE_DECODER_SC_FAST_N128_K64_SNR25
// #define ENABLE_DECODER_SC_FAST_N256_K128_SNR25
// #define ENABLE_DECODER_SC_FAST_N512_K256_SNR25
// #define ENABLE_DECODER_SC_FAST_N1024_K512_SNR25
// #define ENABLE_DECODER_SC_FAST_N2048_K1024_SNR25
// #define ENABLE_DECODER_SC_FAST_N4096_K2048_SNR25
// #define ENABLE_DECODER_SC_FAST_N4096_K2048_SNR33
// #define ENABLE_DECODER_SC_FAST_N8192_K4096_SNR25
// #define ENABLE_DECODER_SC_FAST_N16384_K8192_SNR25
// #define ENABLE_DECODER_SC_FAST_N32768_K16384_SNR18
// #define ENABLE_DECODER_SC_FAST_N32768_K16384_SNR25
// #define ENABLE_DECODER_SC_FAST_N65536_K32768_SNR25
// #define ENABLE_DECODER_SC_FAST_N131072_K65536_SNR25
// #define ENABLE_DECODER_SC_FAST_N262144_K131072_SNR25
// #define ENABLE_DECODER_SC_FAST_N524288_K262144_SNR25
// #define ENABLE_DECODER_SC_FAST_N1048576_K524288_SNR25

// RATE 5/6
// #define ENABLE_DECODER_SC_FAST_N4_K3_SNR40
// #define ENABLE_DECODER_SC_FAST_N8_K7_SNR40
// #define ENABLE_DECODER_SC_FAST_N16_K13_SNR40
// #define ENABLE_DECODER_SC_FAST_N32_K27_SNR40
// #define ENABLE_DECODER_SC_FAST_N64_K53_SNR40
// #define ENABLE_DECODER_SC_FAST_N128_K107_SNR40
// #define ENABLE_DECODER_SC_FAST_N256_K213_SNR40
// #define ENABLE_DECODER_SC_FAST_N512_K427_SNR40
// #define ENABLE_DECODER_SC_FAST_N1024_K853_SNR40
// #define ENABLE_DECODER_SC_FAST_N2048_K1707_SNR40
// #define ENABLE_DECODER_SC_FAST_N4096_K3413_SNR40
// #define ENABLE_DECODER_SC_FAST_N8192_K6827_SNR40
// #define ENABLE_DECODER_SC_FAST_N16384_K13653_SNR40
// #define ENABLE_DECODER_SC_FAST_N32768_K27307_SNR40
// #define ENABLE_DECODER_SC_FAST_N65536_K54613_SNR40
// #define ENABLE_DECODER_SC_FAST_N131072_K109227_SNR40
// #define ENABLE_DECODER_SC_FAST_N262144_K218453_SNR40
// #define ENABLE_DECODER_SC_FAST_N524288_K436907_SNR40
// #define ENABLE_DECODER_SC_FAST_N1048576_K873813_SNR40

// RATE 0.84
// #define ENABLE_DECODER_SC_FAST_N32768_K27568_SNR40

// RATE 9/10
// #define ENABLE_DECODER_SC_FAST_N2048_K1843_SNR40
// #define ENABLE_DECODER_SC_FAST_N16384_K14746_SNR40
// #define ENABLE_DECODER_SC_FAST_N32768_K29492_SNR40

// RATE 1/10, 2/10, ..., 9/10 => N = 2048
// #define ENABLE_DECODER_SC_FAST_N2048_K205_SNR25  // R = 1/10
// #define ENABLE_DECODER_SC_FAST_N2048_K410_SNR25  // R = 2/10
// #define ENABLE_DECODER_SC_FAST_N2048_K614_SNR25  // R = 3/10
// #define ENABLE_DECODER_SC_FAST_N2048_K819_SNR25  // R = 4/10
// #define ENABLE_DECODER_SC_FAST_N2048_K1024_SNR25 // R = 5/10
// #define ENABLE_DECODER_SC_FAST_N2048_K1229_SNR25 // R = 6/10
// #define ENABLE_DECODER_SC_FAST_N2048_K1434_SNR25 // R = 7/10
// #define ENABLE_DECODER_SC_FAST_N2048_K1638_SNR25 // R = 8/10
// #define ENABLE_DECODER_SC_FAST_N2048_K1843_SNR25 // R = 9/10

// RATE 1/10, 2/10, ..., 9/10 => N = 32768
// #define ENABLE_DECODER_SC_FAST_N32768_K3277_SNR25  // R = 1/10
// #define ENABLE_DECODER_SC_FAST_N32768_K6554_SNR25  // R = 2/10
// #define ENABLE_DECODER_SC_FAST_N32768_K9830_SNR25  // R = 3/10
// #define ENABLE_DECODER_SC_FAST_N32768_K13107_SNR25 // R = 4/10
// #define ENABLE_DECODER_SC_FAST_N32768_K16384_SNR25 // R = 5/10
// #define ENABLE_DECODER_SC_FAST_N32768_K19661_SNR25 // R = 6/10
// #define ENABLE_DECODER_SC_FAST_N32768_K22938_SNR25 // R = 7/10
// #define ENABLE_DECODER_SC_FAST_N32768_K26214_SNR25 // R = 8/10
// #define ENABLE_DECODER_SC_FAST_N32768_K29491_SNR25 // R = 9/10

// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------

// RATE 1/2
//#define ENABLE_DECODER_SCL_FAST_CA_N4_K2_SNR25

// RATE ???
//#define ENABLE_DECODER_SCL_FAST_CA_N2048_K1755_SNR35
//#define ENABLE_DECODER_SCL_FAST_CA_N256_K64_SNR30

// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------

// RATE 1/2
#ifdef ENABLE_DECODER_SC_FAST_N4_K2_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N4_K2_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N4_K2_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8_K4_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N8_K4_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N8_K4_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16_K8_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N16_K8_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N16_K8_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32_K16_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32_K16_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32_K16_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N64_K32_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N64_K32_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N64_K32_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N128_K64_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N128_K64_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N128_K64_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N256_K128_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N256_K128_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N256_K128_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N512_K256_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N512_K256_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N512_K256_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1024_K512_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N1024_K512_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N1024_K512_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1024_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1024_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1024_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N4096_K2048_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N4096_K2048_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N4096_K2048_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N4096_K2048_SNR33
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N4096_K2048_SNR33.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N4096_K2048_SNR33.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8192_K4096_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N8192_K4096_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N8192_K4096_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16384_K8192_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N16384_K8192_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N16384_K8192_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K16384_SNR18
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K16384_SNR18.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K16384_SNR18.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K16384_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K16384_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K16384_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N65536_K32768_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N65536_K32768_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N65536_K32768_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N131072_K65536_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N131072_K65536_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N131072_K65536_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N262144_K131072_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N262144_K131072_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N262144_K131072_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N524288_K262144_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N524288_K262144_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N524288_K262144_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1048576_K524288_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N1048576_K524288_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N1048576_K524288_SNR25.hpp"
#endif
#endif
// RATE 5/6
#ifdef ENABLE_DECODER_SC_FAST_N4_K3_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N4_K3_SNR40.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N4_K3_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8_K7_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N8_K7_SNR40.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N8_K7_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16_K13_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N16_K13_SNR40.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N16_K13_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32_K27_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32_K27_SNR40.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32_K27_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N64_K53_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N64_K53_SNR40.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N64_K53_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N128_K107_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N128_K107_SNR40.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N128_K107_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N256_K213_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N256_K213_SNR40.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N256_K213_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N512_K427_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N512_K427_SNR40.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N512_K427_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1024_K853_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N1024_K853_SNR40.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N1024_K853_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1707_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1707_SNR40.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1707_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N4096_K3413_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N4096_K3413_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N4096_K3413_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8192_K6827_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N8192_K6827_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N8192_K6827_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16384_K13653_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N16384_K13653_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N16384_K13653_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K27307_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K27307_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K27307_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N65536_K54613_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N65536_K54613_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N65536_K54613_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N131072_K109227_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N131072_K109227_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N131072_K109227_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N262144_K218453_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N262144_K218453_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N262144_K218453_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N524288_K436907_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N524288_K436907_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N524288_K436907_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1048576_K873813_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N1048576_K873813_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N1048576_K873813_SNR40.hpp"
#endif
#endif
// RATE .84
#ifdef ENABLE_DECODER_SC_FAST_N32768_K27568_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K27568_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K27568_SNR40.hpp"
#endif
#endif
// RATE 9/10
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1843_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1843_SNR40.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1843_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16384_K14746_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N16384_K14746_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N16384_K14746_SNR40.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K29492_SNR40
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K29492_SNR40.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K29492_SNR40.hpp"
#endif
#endif
// RATE 1/10, 2/10, ..., 9/10 => N = 2048
#ifdef ENABLE_DECODER_SC_FAST_N2048_K205_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K205_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K205_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K410_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K410_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K410_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K614_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K614_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K614_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K819_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K819_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K819_SNR25.hpp"
#endif
#endif
//#ifdef ENABLE_DECODER_SC_FAST_N2048_K1024_SNR25
//#ifdef ENABLE_SHORT_GENERATED_DECODERS
//#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1024_SNR25.hpp"
//#else
//#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1024_SNR25.hpp"
//#endif
//#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1229_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1229_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1229_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1434_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1434_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1434_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1638_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1638_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1638_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1843_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1843_SNR25.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N2048_K1843_SNR25.hpp"
#endif
#endif
// RATE 1/10, 2/10, ..., 9/10 => N = 32768
#ifdef ENABLE_DECODER_SC_FAST_N32768_K3277_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K3277_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K3277_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K6554_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K6554_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K6554_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K9830_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K9830_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K9830_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K13107_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K13107_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K13107_SNR25.hpp"
#endif
#endif
//#ifdef ENABLE_DECODER_SC_FAST_N32768_K16384_SNR25
//#ifdef ENABLE_SHORT_GENERATED_DECODERS
//#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K16384_SNR25.short.hpp"
//#else
//#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K16384_SNR25.hpp"
//#endif
//#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K19661_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K19661_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K19661_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K22938_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K22938_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K22938_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K26214_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K26214_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K26214_SNR25.hpp"
#endif
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K29491_SNR25
#ifdef ENABLE_SHORT_GENERATED_DECODERS
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K29491_SNR25.short.hpp"
#else
#include "Module/Decoder/Polar/SC/Generated/Decoder_polar_SC_fast_sys_N32768_K29491_SNR25.hpp"
#endif
#endif

#ifdef ENABLE_DECODER_SCL_FAST_CA_N4_K2_SNR25
#include "Module/Decoder/Polar/SCL/CRC/Generated/Decoder_polar_SCL_fast_CA_sys_N4_K2_SNR25.hpp"
#endif

#ifdef ENABLE_DECODER_SCL_FAST_CA_N2048_K1755_SNR35
#include "Module/Decoder/Polar/SCL/CRC/Generated/Decoder_polar_SCL_fast_CA_sys_N2048_K1755_SNR35.hpp"
#endif

#ifdef ENABLE_DECODER_SCL_FAST_CA_N256_K64_SNR30
#include "Module/Decoder/Polar/SCL/CRC/Generated/Decoder_polar_SCL_fast_CA_sys_N256_K64_SNR30.hpp"
#endif

#include "Tools/Code/Polar/decoder_polar_functions.h"

//#define API_POLAR_DYNAMIC 1

#ifdef API_POLAR_DYNAMIC
#include "Tools/Code/Polar/API/API_polar_dynamic_seq.hpp"
#include "Tools/Code/Polar/API/API_polar_dynamic_inter.hpp"
#include "Tools/Code/Polar/API/API_polar_dynamic_inter_8bit_bitpacking.hpp"
#include "Tools/Code/Polar/API/API_polar_dynamic_intra.hpp"
#else
#include "Tools/Code/Polar/API/API_polar_static_seq.hpp"
#include "Tools/Code/Polar/API/API_polar_static_inter.hpp"
#include "Tools/Code/Polar/API/API_polar_static_inter_8bit_bitpacking.hpp"
#include "Tools/Code/Polar/API/API_polar_static_intra_8bit.hpp"
#include "Tools/Code/Polar/API/API_polar_static_intra_16bit.hpp"
#include "Tools/Code/Polar/API/API_polar_static_intra_32bit.hpp"
#endif

#include "Factory_decoder_polar_gen.hpp"

using namespace aff3ct::module;
using namespace aff3ct::tools;

template <typename B, typename R>
template <class API_polar>
Decoder<B,R>* Factory_decoder_polar_gen<B,R>
::_build(const std::string      type,
         const std::string      implem,
         const int              K,
         const int              N,
         const mipp::vector<B> &frozen_bits,
         const int              L,
               CRC<B>          *crc,
         const int              n_frames)
{
	if (type == "SC")
	{
		// RATE 1/2
#ifdef ENABLE_DECODER_SC_FAST_N4_K2_SNR25
		if (implem == "N4_K2_SNR25"           ) return new Decoder_polar_SC_fast_sys_N4_K2_SNR25           <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8_K4_SNR25
		if (implem == "N8_K4_SNR25"           ) return new Decoder_polar_SC_fast_sys_N8_K4_SNR25           <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16_K8_SNR25
		if (implem == "N16_K8_SNR25"          ) return new Decoder_polar_SC_fast_sys_N16_K8_SNR25          <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32_K16_SNR25
		if (implem == "N32_K16_SNR25"         ) return new Decoder_polar_SC_fast_sys_N32_K16_SNR25         <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N64_K32_SNR25
		if (implem == "N64_K32_SNR25"         ) return new Decoder_polar_SC_fast_sys_N64_K32_SNR25         <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N128_K64_SNR25
		if (implem == "N128_K64_SNR25"        ) return new Decoder_polar_SC_fast_sys_N128_K64_SNR25        <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N256_K128_SNR25
		if (implem == "N256_K128_SNR25"       ) return new Decoder_polar_SC_fast_sys_N256_K128_SNR25       <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N512_K256_SNR25
		if (implem == "N512_K256_SNR25"       ) return new Decoder_polar_SC_fast_sys_N512_K256_SNR25       <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1024_K512_SNR25
		if (implem == "N1024_K512_SNR25"      ) return new Decoder_polar_SC_fast_sys_N1024_K512_SNR25      <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1024_SNR25
		if (implem == "N2048_K1024_SNR25"     ) return new Decoder_polar_SC_fast_sys_N2048_K1024_SNR25     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N4096_K2048_SNR25
		if (implem == "N4096_K2048_SNR25"     ) return new Decoder_polar_SC_fast_sys_N4096_K2048_SNR25     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N4096_K2048_SNR33
		if (implem == "N4096_K2048_SNR33"     ) return new Decoder_polar_SC_fast_sys_N4096_K2048_SNR33     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8192_K4096_SNR25
		if (implem == "N8192_K4096_SNR25"     ) return new Decoder_polar_SC_fast_sys_N8192_K4096_SNR25     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16384_K8192_SNR25
		if (implem == "N16384_K8192_SNR25"    ) return new Decoder_polar_SC_fast_sys_N16384_K8192_SNR25    <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K16384_SNR18
		if (implem == "N32768_K16384_SNR18"   ) return new Decoder_polar_SC_fast_sys_N32768_K16384_SNR18   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K16384_SNR25
		if (implem == "N32768_K16384_SNR25"   ) return new Decoder_polar_SC_fast_sys_N32768_K16384_SNR25   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N65536_K32768_SNR25
		if (implem == "N65536_K32768_SNR25"   ) return new Decoder_polar_SC_fast_sys_N65536_K32768_SNR25   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N131072_K65536_SNR25
		if (implem == "N131072_K65536_SNR25"  ) return new Decoder_polar_SC_fast_sys_N131072_K65536_SNR25  <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N262144_K131072_SNR25
		if (implem == "N262144_K131072_SNR25" ) return new Decoder_polar_SC_fast_sys_N262144_K131072_SNR25 <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N524288_K262144_SNR25
		if (implem == "N524288_K262144_SNR25" ) return new Decoder_polar_SC_fast_sys_N524288_K262144_SNR25 <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1048576_K524288_SNR25
		if (implem == "N1048576_K524288_SNR25") return new Decoder_polar_SC_fast_sys_N1048576_K524288_SNR25<B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
		// RATE 5/6
#ifdef ENABLE_DECODER_SC_FAST_N4_K3_SNR40
		if (implem == "N4_K3_SNR40"           ) return new Decoder_polar_SC_fast_sys_N4_K3_SNR40           <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8_K7_SNR40
		if (implem == "N8_K7_SNR40"           ) return new Decoder_polar_SC_fast_sys_N8_K7_SNR40           <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16_K13_SNR40
		if (implem == "N16_K13_SNR40"         ) return new Decoder_polar_SC_fast_sys_N16_K13_SNR40         <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32_K27_SNR40
		if (implem == "N32_K27_SNR40"         ) return new Decoder_polar_SC_fast_sys_N32_K27_SNR40         <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N64_K53_SNR40
		if (implem == "N64_K53_SNR40"         ) return new Decoder_polar_SC_fast_sys_N64_K53_SNR40         <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N128_K107_SNR40
		if (implem == "N128_K107_SNR40"       ) return new Decoder_polar_SC_fast_sys_N128_K107_SNR40       <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N256_K213_SNR40
		if (implem == "N256_K213_SNR40"       ) return new Decoder_polar_SC_fast_sys_N256_K213_SNR40       <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N512_K427_SNR40
		if (implem == "N512_K427_SNR40"       ) return new Decoder_polar_SC_fast_sys_N512_K427_SNR40       <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1024_K853_SNR40
		if (implem == "N1024_K853_SNR40"      ) return new Decoder_polar_SC_fast_sys_N1024_K853_SNR40      <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1707_SNR40
		if (implem == "N2048_K1707_SNR40"     ) return new Decoder_polar_SC_fast_sys_N2048_K1707_SNR40     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N4096_K3413_SNR40
		if (implem == "N4096_K3413_SNR40"     ) return new Decoder_polar_SC_fast_sys_N4096_K3413_SNR40     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8192_K6827_SNR40
		if (implem == "N8192_K6827_SNR40"     ) return new Decoder_polar_SC_fast_sys_N8192_K6827_SNR40     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16384_K13653_SNR40
		if (implem == "N16384_K13653_SNR40"   ) return new Decoder_polar_SC_fast_sys_N16384_K13653_SNR40   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K27307_SNR40
		if (implem == "N32768_K27307_SNR40"   ) return new Decoder_polar_SC_fast_sys_N32768_K27307_SNR40   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N65536_K54613_SNR40
		if (implem == "N65536_K54613_SNR40"   ) return new Decoder_polar_SC_fast_sys_N65536_K54613_SNR40   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N131072_K109227_SNR40
		if (implem == "N131072_K109227_SNR40" ) return new Decoder_polar_SC_fast_sys_N131072_K109227_SNR40 <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N262144_K218453_SNR40
		if (implem == "N262144_K218453_SNR40" ) return new Decoder_polar_SC_fast_sys_N262144_K218453_SNR40 <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N524288_K436907_SNR40
		if (implem == "N524288_K436907_SNR40" ) return new Decoder_polar_SC_fast_sys_N524288_K436907_SNR40 <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1048576_K873813_SNR40
		if (implem == "N1048576_K873813_SNR40") return new Decoder_polar_SC_fast_sys_N1048576_K873813_SNR40<B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
		// RATE 0.84
#ifdef ENABLE_DECODER_SC_FAST_N32768_K27568_SNR40
		if (implem == "N32768_K27568_SNR40"   ) return new Decoder_polar_SC_fast_sys_N32768_K27568_SNR40   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
		// RATE 9/10
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1843_SNR40
		if (implem == "N2048_K1843_SNR40"     ) return new Decoder_polar_SC_fast_sys_N2048_K1843_SNR40     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16384_K14746_SNR40
		if (implem == "N16384_K14746_SNR40"   ) return new Decoder_polar_SC_fast_sys_N16384_K14746_SNR40   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K29492_SNR40
		if (implem == "N32768_K29492_SNR40"   ) return new Decoder_polar_SC_fast_sys_N32768_K29492_SNR40   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
		// RATE 1/10, 2/10, ..., 9/10 => N = 2048
#ifdef ENABLE_DECODER_SC_FAST_N2048_K205_SNR25
		if (implem == "N2048_K205_SNR25"      ) return new Decoder_polar_SC_fast_sys_N2048_K205_SNR25      <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K410_SNR25
		if (implem == "N2048_K410_SNR25"      ) return new Decoder_polar_SC_fast_sys_N2048_K410_SNR25      <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K614_SNR25
		if (implem == "N2048_K614_SNR25"      ) return new Decoder_polar_SC_fast_sys_N2048_K614_SNR25      <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K819_SNR25
		if (implem == "N2048_K819_SNR25"      ) return new Decoder_polar_SC_fast_sys_N2048_K819_SNR25      <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
//#ifdef ENABLE_DECODER_SC_FAST_N2048_K1024_SNR25
//		if (implem == "N2048_K1024_SNR25"     ) return new Decoder_polar_SC_fast_sys_N2048_K1024_SNR25     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
//#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1229_SNR25
		if (implem == "N2048_K1229_SNR25"     ) return new Decoder_polar_SC_fast_sys_N2048_K1229_SNR25     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1434_SNR25
		if (implem == "N2048_K1434_SNR25"     ) return new Decoder_polar_SC_fast_sys_N2048_K1434_SNR25     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1638_SNR25
		if (implem == "N2048_K1638_SNR25"     ) return new Decoder_polar_SC_fast_sys_N2048_K1638_SNR25     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1843_SNR25
		if (implem == "N2048_K1843_SNR25"     ) return new Decoder_polar_SC_fast_sys_N2048_K1843_SNR25     <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
		// RATE 1/10, 2/10, ..., 9/10 => N = 32768
#ifdef ENABLE_DECODER_SC_FAST_N32768_K3277_SNR25
		if (implem == "N32768_K3277_SNR25"    ) return new Decoder_polar_SC_fast_sys_N32768_K3277_SNR25    <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K6554_SNR25
		if (implem == "N32768_K6554_SNR25"    ) return new Decoder_polar_SC_fast_sys_N32768_K6554_SNR25    <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K9830_SNR25
		if (implem == "N32768_K9830_SNR25"    ) return new Decoder_polar_SC_fast_sys_N32768_K9830_SNR25    <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K13107_SNR25
		if (implem == "N32768_K13107_SNR25"   ) return new Decoder_polar_SC_fast_sys_N32768_K13107_SNR25   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
//#ifdef ENABLE_DECODER_SC_FAST_N32768_K16384_SNR25
//		if (implem == "N32768_K16384_SNR25"   ) return new Decoder_polar_SC_fast_sys_N32768_K16384_SNR25   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
//#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K19661_SNR25
		if (implem == "N32768_K19661_SNR25"   ) return new Decoder_polar_SC_fast_sys_N32768_K19661_SNR25   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K22938_SNR25
		if (implem == "N32768_K22938_SNR25"   ) return new Decoder_polar_SC_fast_sys_N32768_K22938_SNR25   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K26214_SNR25
		if (implem == "N32768_K26214_SNR25"   ) return new Decoder_polar_SC_fast_sys_N32768_K26214_SNR25   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K29491_SNR25
		if (implem == "N32768_K29491_SNR25"   ) return new Decoder_polar_SC_fast_sys_N32768_K29491_SNR25   <B, R, API_polar>(K, N,    frozen_bits,       n_frames);
#endif
	}
	else if (type == "SCL" && crc != nullptr && crc->get_size() > 0)
	{
#ifdef ENABLE_DECODER_SCL_FAST_CA_N4_K2_SNR25
		if (implem == "CA_N4_K2_SNR25"        ) return new Decoder_polar_SCL_fast_CA_sys_N4_K2_SNR25       <B, R, API_polar>(K, N, L, frozen_bits, *crc, n_frames);
#endif
#ifdef ENABLE_DECODER_SCL_FAST_CA_N2048_K1755_SNR35
		if (implem == "CA_N2048_K1755_SNR35"  ) return new Decoder_polar_SCL_fast_CA_sys_N2048_K1755_SNR35 <B, R, API_polar>(K, N, L, frozen_bits, *crc, n_frames);
#endif
#ifdef ENABLE_DECODER_SCL_FAST_CA_N256_K64_SNR30
		if (implem == "CA_N256_K64_SNR30"     ) return new Decoder_polar_SCL_fast_CA_sys_N256_K64_SNR30    <B, R, API_polar>(K, N, L, frozen_bits, *crc, n_frames);
#endif
	}

	throw cannot_allocate(__FILE__, __LINE__, __func__);
}

template <typename B, typename R>
Decoder<B,R>* Factory_decoder_polar_gen<B,R>
::build(const std::string      type,
        const std::string      implem,
        const int              K,
        const int              N,
        const mipp::vector<B> &frozen_bits,
        const std::string      simd_strategy,
        const bool             sys_encoding,
        const int              L,
              CRC<B>          *crc,
        const int              n_frames)
{
	if (sys_encoding)
	{
		if (simd_strategy == "INTER" && type == "SC")
		{
			if (typeid(B) == typeid(signed char))
			{
#ifdef ENABLE_BIT_PACKING
#ifdef API_POLAR_DYNAMIC
				using API_polar = API_polar_dynamic_inter_8bit_bitpacking
				                  <B, R, f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#else
				using API_polar = API_polar_static_inter_8bit_bitpacking
				                  <B, R, f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#endif
#else
#ifdef API_POLAR_DYNAMIC
				using API_polar = API_polar_dynamic_inter
				                  <B, R, f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#else
				using API_polar = API_polar_static_inter
				                  <B, R, f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#endif
#endif
				return _build<API_polar>(type, implem, K, N , frozen_bits, L, crc, n_frames);
			}
			else
			{
#ifdef API_POLAR_DYNAMIC
				using API_polar = API_polar_dynamic_inter
				                  <B, R, f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#else
				using API_polar = API_polar_static_inter
				                  <B, R, f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#endif
				return _build<API_polar>(type, implem, K, N , frozen_bits, L, crc, n_frames);
			}
		}
		else if (simd_strategy == "INTRA")
		{
			if (typeid(B) == typeid(signed char))
			{
#ifdef API_POLAR_DYNAMIC
				using API_polar = API_polar_dynamic_intra
				                  <B, R, f_LLR  <R>, g_LLR  <B,R>, g0_LLR  <R>, h_LLR  <B,R>, xo_STD  <B>,
				                         f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#else
				using API_polar = API_polar_static_intra_8bit
				                  <B, R, f_LLR  <R>, g_LLR  <B,R>, g0_LLR  <R>, h_LLR  <B,R>, xo_STD  <B>,
				                         f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#endif
				return _build<API_polar>(type, implem, K, N , frozen_bits, L, crc, n_frames);
			}
			else if (typeid(B) == typeid(short))
			{
#ifdef API_POLAR_DYNAMIC
				using API_polar = API_polar_dynamic_intra
				                  <B, R, f_LLR  <R>, g_LLR  <B,R>, g0_LLR  <R>, h_LLR  <B,R>, xo_STD  <B>,
				                         f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#else
				using API_polar = API_polar_static_intra_16bit
				                  <B, R, f_LLR  <R>, g_LLR  <B,R>, g0_LLR  <R>, h_LLR  <B,R>, xo_STD  <B>,
				                         f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#endif
				return _build<API_polar>(type, implem, K, N , frozen_bits, L, crc, n_frames);
			}
			else if (typeid(B) == typeid(int))
			{
#ifdef API_POLAR_DYNAMIC
				using API_polar = API_polar_dynamic_intra
				                  <B, R, f_LLR  <R>, g_LLR  <B,R>, g0_LLR  <R>, h_LLR  <B,R>, xo_STD  <B>,
				                         f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#else
				using API_polar = API_polar_static_intra_32bit
				                  <B, R, f_LLR  <R>, g_LLR  <B,R>, g0_LLR  <R>, h_LLR  <B,R>, xo_STD  <B>,
				                         f_LLR_i<R>, g_LLR_i<B,R>, g0_LLR_i<R>, h_LLR_i<B,R>, xo_STD_i<B>>;
#endif
				return _build<API_polar>(type, implem, K, N , frozen_bits, L, crc, n_frames);
			}
		}
		else if (simd_strategy.empty())
		{
#ifdef API_POLAR_DYNAMIC
			using API_polar = API_polar_dynamic_seq
			                  <B, R, f_LLR<R>, g_LLR<B,R>, g0_LLR<R>, h_LLR<B,R>, xo_STD<B>>;
#else
			using API_polar = API_polar_static_seq
			                  <B, R, f_LLR<R>, g_LLR<B,R>, g0_LLR<R>, h_LLR<B,R>, xo_STD<B>>;
#endif
			return _build<API_polar>(type, implem, K, N , frozen_bits, L, crc, n_frames);
		}
	}

	throw cannot_allocate(__FILE__, __LINE__, __func__);
}

template <typename B, typename R>
void Factory_decoder_polar_gen<B,R>
::get_frozen_bits(const std::string      implem,
                  const int              N,
                        mipp::vector<B> &frozen_bits)
{
	const char* fb_ptr = nullptr;

	// RATE 1/2
#ifdef ENABLE_DECODER_SC_FAST_N4_K2_SNR25
	if (implem == "N4_K2_SNR25"           ) fb_ptr = Decoder_polar_SC_fast_sys_fb_4_2_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8_K4_SNR25
	if (implem == "N8_K4_SNR25"           ) fb_ptr = Decoder_polar_SC_fast_sys_fb_8_4_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16_K8_SNR25
	if (implem == "N16_K8_SNR25"          ) fb_ptr = Decoder_polar_SC_fast_sys_fb_16_8_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32_K16_SNR25
	if (implem == "N32_K16_SNR25"         ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32_16_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N64_K32_SNR25
	if (implem == "N64_K32_SNR25"         ) fb_ptr = Decoder_polar_SC_fast_sys_fb_64_32_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N128_K64_SNR25
	if (implem == "N128_K64_SNR25"        ) fb_ptr = Decoder_polar_SC_fast_sys_fb_128_64_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N256_K128_SNR25
	if (implem == "N256_K128_SNR25"       ) fb_ptr = Decoder_polar_SC_fast_sys_fb_256_128_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N512_K256_SNR25
	if (implem == "N512_K256_SNR25"       ) fb_ptr = Decoder_polar_SC_fast_sys_fb_512_256_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1024_K512_SNR25
	if (implem == "N1024_K512_SNR25"      ) fb_ptr = Decoder_polar_SC_fast_sys_fb_1024_512_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1024_SNR25
	if (implem == "N2048_K1024_SNR25"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_1024_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N4096_K2048_SNR25
	if (implem == "N4096_K2048_SNR25"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_4096_2048_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N4096_K2048_SNR33
	if (implem == "N4096_K2048_SNR33"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_4096_2048_33;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8192_K4096_SNR25
	if (implem == "N8192_K4096_SNR25"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_8192_4096_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16384_K8192_SNR25
	if (implem == "N16384_K8192_SNR25"    ) fb_ptr = Decoder_polar_SC_fast_sys_fb_16384_8192_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K16384_SNR18
	if (implem == "N32768_K16384_SNR18"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_16384_18;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K16384_SNR25
	if (implem == "N32768_K16384_SNR25"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_16384_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N65536_K32768_SNR25
	if (implem == "N65536_K32768_SNR25"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_65536_32768_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N131072_K65536_SNR25
	if (implem == "N131072_K65536_SNR25"  ) fb_ptr = Decoder_polar_SC_fast_sys_fb_131072_65536_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N262144_K131072_SNR25
	if (implem == "N262144_K131072_SNR25" ) fb_ptr = Decoder_polar_SC_fast_sys_fb_262144_131072_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N524288_K262144_SNR25
	if (implem == "N524288_K262144_SNR25" ) fb_ptr = Decoder_polar_SC_fast_sys_fb_524288_262144_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1048576_K524288_SNR25
	if (implem == "N1048576_K524288_SNR25") fb_ptr = Decoder_polar_SC_fast_sys_fb_1048576_524288_25;
#endif

	// RATE 5/6
#ifdef ENABLE_DECODER_SC_FAST_N4_K3_SNR40
	if (implem == "N4_K3_SNR40"           ) fb_ptr = Decoder_polar_SC_fast_sys_fb_4_3_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8_K7_SNR40
	if (implem == "N8_K7_SNR40"           ) fb_ptr = Decoder_polar_SC_fast_sys_fb_8_7_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16_K13_SNR40
	if (implem == "N16_K13_SNR40"         ) fb_ptr = Decoder_polar_SC_fast_sys_fb_16_13_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32_K27_SNR40
	if (implem == "N32_K27_SNR40"         ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32_27_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N64_K53_SNR40
	if (implem == "N64_K53_SNR40"         ) fb_ptr = Decoder_polar_SC_fast_sys_fb_64_53_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N128_K107_SNR40
	if (implem == "N128_K107_SNR40"       ) fb_ptr = Decoder_polar_SC_fast_sys_fb_128_107_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N256_K213_SNR40
	if (implem == "N256_K213_SNR40"       ) fb_ptr = Decoder_polar_SC_fast_sys_fb_256_213_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N512_K427_SNR40
	if (implem == "N512_K427_SNR40"       ) fb_ptr = Decoder_polar_SC_fast_sys_fb_512_427_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1024_K853_SNR40
	if (implem == "N1024_K853_SNR40"      ) fb_ptr = Decoder_polar_SC_fast_sys_fb_1024_853_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1707_SNR40
	if (implem == "N2048_K1707_SNR40"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_1707_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N4096_K3413_SNR40
	if (implem == "N4096_K3413_SNR40"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_4096_3413_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N8192_K6827_SNR40
	if (implem == "N8192_K6827_SNR40"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_8192_6827_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16384_K13653_SNR40
	if (implem == "N16384_K13653_SNR40"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_16384_13653_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K27307_SNR40
	if (implem == "N32768_K27307_SNR40"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_27307_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N65536_K54613_SNR40
	if (implem == "N65536_K54613_SNR40"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_65536_54613_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N131072_K109227_SNR40
	if (implem == "N131072_K109227_SNR40" ) fb_ptr = Decoder_polar_SC_fast_sys_fb_131072_109227_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N262144_K218453_SNR40
	if (implem == "N262144_K218453_SNR40" ) fb_ptr = Decoder_polar_SC_fast_sys_fb_262144_218453_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N524288_K436907_SNR40
	if (implem == "N524288_K436907_SNR40" ) fb_ptr = Decoder_polar_SC_fast_sys_fb_524288_436907_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N1048576_K873813_SNR40
	if (implem == "N1048576_K873813_SNR40") fb_ptr = Decoder_polar_SC_fast_sys_fb_1048576_873813_40;
#endif

	// RATE 0.84
#ifdef ENABLE_DECODER_SC_FAST_N32768_K27568_SNR40
	if (implem == "N32768_K27568_SNR40"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_27568_40;
#endif

	// RATE 9/10
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1843_SNR40
	if (implem == "N2048_K1843_SNR40"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_1843_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N16384_K14746_SNR40
	if (implem == "N16384_K14746_SNR40"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_16384_14746_40;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K29492_SNR40
	if (implem == "N32768_K29492_SNR40"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_29492_40;
#endif

	// RATE 1/10, 2/10, ..., 9/10 => N = 2048
#ifdef ENABLE_DECODER_SC_FAST_N2048_K205_SNR25
	if (implem == "N2048_K205_SNR25"      ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_205_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K410_SNR25
	if (implem == "N2048_K410_SNR25"      ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_410_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K614_SNR25
	if (implem == "N2048_K614_SNR25"      ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_614_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K819_SNR25
	if (implem == "N2048_K819_SNR25"      ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_819_25;
#endif
// #ifdef ENABLE_DECODER_SC_FAST_N2048_K1024_SNR25
// 	if (implem == "N2048_K1024_SNR25"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_1024_25;
// #endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1229_SNR25
	if (implem == "N2048_K1229_SNR25"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_1229_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1434_SNR25
	if (implem == "N2048_K1434_SNR25"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_1434_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1638_SNR25
	if (implem == "N2048_K1638_SNR25"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_1638_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N2048_K1843_SNR25
	if (implem == "N2048_K1843_SNR25"     ) fb_ptr = Decoder_polar_SC_fast_sys_fb_2048_1843_25;
#endif

	// RATE 1/10, 2/10, ..., 9/10 => N = 32768
#ifdef ENABLE_DECODER_SC_FAST_N32768_K3277_SNR25
	if (implem == "N32768_K3277_SNR25"    ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_3277_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K6554_SNR25
	if (implem == "N32768_K6554_SNR25"    ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_6554_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K9830_SNR25
	if (implem == "N32768_K9830_SNR25"    ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_9830_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K13107_SNR25
	if (implem == "N32768_K13107_SNR25"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_13107_25;
#endif
// #ifdef ENABLE_DECODER_SC_FAST_N32768_K16384_SNR25
// 	if (implem == "N32768_K16384_SNR25"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_16384_25;
// #endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K19661_SNR25
	if (implem == "N32768_K19661_SNR25"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_19661_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K22938_SNR25
	if (implem == "N32768_K22938_SNR25"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_22938_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K26214_SNR25
	if (implem == "N32768_K26214_SNR25"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_26214_25;
#endif
#ifdef ENABLE_DECODER_SC_FAST_N32768_K29491_SNR25
	if (implem == "N32768_K29491_SNR25"   ) fb_ptr = Decoder_polar_SC_fast_sys_fb_32768_29491_25;
#endif

	// RATE 1/2
#ifdef ENABLE_DECODER_SCL_FAST_CA_N4_K2_SNR25
	if (implem == "CA_N4_K2_SNR25"        ) fb_ptr = Decoder_polar_SCL_fast_CA_sys_fb_4_2_25;
#endif

	// RATE ??
#ifdef ENABLE_DECODER_SCL_FAST_CA_N2048_K1755_SNR35
	if (implem == "CA_N2048_K1755_SNR35"  ) fb_ptr = Decoder_polar_SCL_fast_CA_sys_fb_2048_1755_35;
#endif
#ifdef ENABLE_DECODER_SCL_FAST_CA_N256_K64_SNR30
	if (implem == "CA_N256_K64_SNR30"     ) fb_ptr = Decoder_polar_SCL_fast_CA_sys_fb_256_64_30;
#endif

	if (fb_ptr == nullptr)
	{
		std::stringstream message;
		message << "'implem' frozen bits does not exist ('implem' = " << implem << ").";
		throw runtime_error(__FILE__, __LINE__, __func__, message.str());
	}

	for (auto i = 0; i < N; i++)
		frozen_bits[i] = (B)fb_ptr[i];
}

// ==================================================================================== explicit template instantiation
#include "Tools/types.h"
#ifdef MULTI_PREC
template struct aff3ct::tools::Factory_decoder_polar_gen<B_8,Q_8>;
template struct aff3ct::tools::Factory_decoder_polar_gen<B_16,Q_16>;
template struct aff3ct::tools::Factory_decoder_polar_gen<B_32,Q_32>;
template struct aff3ct::tools::Factory_decoder_polar_gen<B_64,Q_64>;
#else
template struct aff3ct::tools::Factory_decoder_polar_gen<B,Q>;
#endif
// ==================================================================================== explicit template instantiation
