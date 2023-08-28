#ifndef INTEGRAL_CONSTANT_HPP_
#define INTEGRAL_CONSTANT_HPP_

namespace my {
	
	template <typename T, T Value>
	struct integral_constant {
	    constexpr static T value = Value;
		
		using value_type = T;
		using type       = integral_constant<T, Value>; 

		constexpr value_type operator()() const noexcept {
			return value;
		}

		constexpr operator value_type() const noexcept {
			return value;
		}
	};
	
	using true_type = integral_constant<bool, true>;	
	using false_type = integral_constant<bool, false>;	

}

#endif //INTEGRAL_CONSTANT_HPP_
