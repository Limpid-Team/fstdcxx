#ifndef _FSTDCXX_BASE_FUNCTIONAL_MISC_
#define _FSTDCXX_BASE_FUNCTIONAL_MISC_

#include <_type_traits/is_invocable.hh>
#include <_type_traits/remove_cvref.hh>
#include <_type_traits/decay.hh>
#include <_utility/forward.hh>
#include <_fstdcxx/cxx_basedefs.hh>
#include <memory>

namespace std {
	struct identity {
		template <typename T>
		FSTDCXX_FORCEINLINE constexpr T &&operator()(T &&t) const noexcept;

		using is_transparent = int;
	};

	template <typename T>
	struct unwrap_reference {
		using type = T;
	};
	template <class U>
	struct unwrap_reference<std::reference_wrapper<U>> {
		using type = U &;
	};

	template <typename T>
	using unwrap_reference_t = typename unwrap_reference<T>::type;

	template <typename T>
	struct unwrap_ref_decay : std::unwrap_reference<std::decay_t<T>> {};

	template <typename T>
	using unwrap_ref_decay_t = typename unwrap_ref_decay<T>::type;

#define __cpp_lib_unwrap_ref 201811L
}

#endif
