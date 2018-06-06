#include <Unknwn.h>

template <typename T>
class COM
{
public:
	COM();
	COM(T* pointer);
	~COM();
	T** operator&();
private:
	T* pointer_ = nullptr;
};

template<typename T>
inline COM<T>::COM()
{
}

template<typename T>
inline COM<T>::COM(T * pointer)
{
	pointer_ = pointer;
}

template<typename T>
inline COM<T>::~COM()
{
	pointer_->Release();
}

template<typename T>
inline T** COM<T>::operator&()
{
	return &pointer_;
}
