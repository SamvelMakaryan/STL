#include <utility>
#include <cstddef>
namespace my {
    template <typename T>
    class Allocator {
    public:
        using value_type = T;
        Allocator() = default;
        ~Allocator() = default;
        static T* allocate(size_t n) {
            return static_cast<T*>(::operator new (sizeof(T) * n));
        }
        static void deallocate(T* ptr, size_t n) noexcept {
            ::operator delete(ptr, n * sizeof(T));
        }
        template <typename... Args>
        static void construct(T* ptr, Args&&... args) {
            ::new (ptr) T(std::forward<Args>(args)...);
        }
        static void destroy(T* ptr) noexcept {
            ptr->~T();
        }
    };
}