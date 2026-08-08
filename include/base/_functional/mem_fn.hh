#ifndef _FSTDCXX_BASE_FUNCTIONAL_MEM_FN_
#define _FSTDCXX_BASE_FUNCTIONAL_MEM_FN_

#include <_fstdcxx/cxx_basedefs.hh>
#include <_type_traits/decay.hh>
#include <_type_traits/is_member_function_pointer.hh>
#include <_type_traits/is_member_pointer.hh>
#include <_type_traits/is_pointer.hh>
#include <_utility/forward.hh>
#include <_utility/move.hh>
#include "ref_wrapper.hh"

namespace std {
	template <typename T, typename M, typename = void>
	struct has_arrow_star : std::false_type {};

	template <typename T, typename M>
	struct has_arrow_star<T, M, void_t<decltype(std::declval<T>()->*std::declval<M>())>>
		: std::true_type {};

	template <typename T>
	struct is_reference_wrapper : std::false_type {};
	template <typename U>
	struct is_reference_wrapper<std::reference_wrapper<U>> : std::true_type {};

	template <typename M>
	class mem_fn_t {
		M _pm;

	public:
		explicit mem_fn_t(M pm) : _pm(pm) {}

		template <typename Arg0, typename... Rest>
		decltype(auto) operator()(Arg0 &&arg0, Rest &&...rest) const {
			using DecayArg0 = std::decay_t<Arg0>;

			if constexpr (std::is_member_function_pointer_v<M>) {
				if constexpr (is_reference_wrapper<DecayArg0>::value) {
					return (arg0.get().*_pm)(std::forward<Rest>(rest)...);
				}

				else if constexpr (std::is_pointer<DecayArg0>::value) {
					return (arg0->*_pm)(std::forward<Rest>(rest)...);
				}

				else {
					if constexpr (has_arrow_star<Arg0, M>::value) {
						return (std::forward<Arg0>(arg0)->*_pm)(std::forward<Rest>(rest)...);
					} else {
						return (std::forward<Arg0>(arg0).*_pm)(std::forward<Rest>(rest)...);
					}
				}
			}

			else {
				static_assert(sizeof...(Rest) == 0);
				if constexpr (is_reference_wrapper<DecayArg0>::value) {
					return arg0.get().*_pm;
				} else if constexpr (std::is_pointer<DecayArg0>::value) {
					return arg0->*_pm;
				} else {
					if constexpr (has_arrow_star<Arg0, M>::value) {
						return std::forward<Arg0>(arg0)->*_pm;
					} else {
						return std::forward<Arg0>(arg0).*_pm;
					}
				}
			}
		}
	};

	template <typename M>
	auto mem_fn(M pm) {
		return mem_fn_t<M>(pm);
	}
}

#endif
