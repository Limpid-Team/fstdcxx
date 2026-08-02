#ifndef _FSTDCXX_BASE_FUNCTIONAL_INVOKE_
#define _FSTDCXX_BASE_FUNCTIONAL_INVOKE_

#include <_fstdcxx/cxx_basedefs.hh>
#include <_utility/forward.hh>

namespace std {
	template <typename F, typename... Args>
	FSTDCXX_CONSTEXPR_SINCE_CXX20 auto invoke(F &&f, Args &&...args)
		-> decltype(__builtin_invoke(std::forward<F>(f), std::forward<Args>(args)...)) {
		return __builtin_invoke(std::forward<F>(f), std::forward<Args>(args)...);
	}
}

#endif
