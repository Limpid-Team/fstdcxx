#ifndef _FSTDCXX_BASE_BASEDEFS_HH_
#define _FSTDCXX_BASE_BASEDEFS_HH_

#ifdef __cplusplus
#define FSTDCXX_EXTERN_C_BEGIN extern "C" {
#define FSTDCXX_EXTERN_C_END }
#else
#define FSTDCXX_EXTERN_C_BEGIN
#define FSTDCXX_EXTERN_C_END
#endif

#ifndef FSTDCXX_FORCEINLINE
	#if defined(__GNUC__) || defined(__clang__)
		#define FSTDCXX_FORCEINLINE __attribute__((__always_inline__)) inline
	#else
		#define FSTDCXX_FORCEINLINE
	#endif
#endif

#ifndef FSTDCXX_WEAK
	#if defined(__GNUC__) || defined(__clang__)
		#define FSTDCXX_WEAK __attribute__((__weak__))
	#else
		#warning "FSTDCXX_WEAK is not available, you may not able override the library functions"
	#endif
#endif

#if __cplusplus >= 202002L
	#define FSTDCXX_CONSTEXPR_SINCE_CXX20 constexpr
#else
	#define FSTDCXX_CONSTEXPR_SINCE_CXX20
#endif

#define FSTDCXX_API

#endif
