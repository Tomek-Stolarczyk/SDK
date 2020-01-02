#ifndef SDK_COMPOINTER_HPP
#define SDK_COMPOINTER_HPP

template <typename T>
class COM
{
public:
	COM() = default;
	
	COM(T* pointer)
	{
		pointer_ = pointer;
	}
	
	COM(COM && other)
	{
		pointer_ = other.pointer_;
		other.pointer_ = nullptr;
	}
	
	COM(const COM& other)
	{
		pointer_ = other.pointer_;
		pointer_.AddRef();
	}
	
	~COM()
	{
		pointer_->Release();
	}
	
	T** operator&()
	{
		return &pointer_;
	}

	T* operator->()
	{
		return pointer_;
	}

  T* get() const
  {
    return pointer_;
  }

private:
	T* pointer_ = nullptr;
};

#endif // !SDK_COMPOINTER_HPP