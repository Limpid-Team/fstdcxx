#ifndef _FSTDCXX_BASE_FUNCTIONAL_INVOKE_
#define _FSTDCXX_BASE_FUNCTIONAL_INVOKE_

#include <_fstdcxx/cxx_basedefs.hh>
#include <_utility/forward.hh>
#include <_type_traits/decay.hh>
#include <_type_traits/is_member_pointer.hh>
#include "mem_fn.hh"

namespace std {
	template<typename F, typename... Args>
    FSTDCXX_CONSTEXPR_SINCE_CXX20 decltype(auto) invoke(F&& f, Args&&... args) {
        if constexpr (std::is_member_pointer_v<std::decay_t<F>>) {
            return std::mem_fn(std::forward<F>(f))(std::forward<Args>(args)...);
        } else {
            return std::forward<F>(f)(std::forward<Args>(args)...);
        }
    }
}

#endif
