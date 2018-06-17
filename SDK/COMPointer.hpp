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
		pointer.AddRef();
	}
	
	~COM()
	{
		pointer_->Release();

	}
	
	T** operator&()
	{
		return &pointer_;
	}
private:
	T* pointer_ = nullptr;
};
