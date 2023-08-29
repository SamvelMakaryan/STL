#ifndef TYPE_IDENTITY_HPP_
#define TYPE_IDENTITY_HPP_

namespace my {
	
	template <typename T>
	struct type_identity {
		using type = T;
	};

}

#endif //TYPE_IDENTITY_HPP_
