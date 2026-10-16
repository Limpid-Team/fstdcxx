#ifndef _FSTDCXX_BASE_TYPE_TRAITS_IS_TRIVIAL_
#define _FSTDCXX_BASE_TYPE_TRAITS_IS_TRIVIAL_

#include "integral_constant.hh"

namespace std {
	template <typename T>
	struct is_trivial : std::bool_constant<__is_trivial(T)> {};

	template <typename T>
	constexpr bool is_trivial_v = is_trivial<T>::value;
}

#endif
