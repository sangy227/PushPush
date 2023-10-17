#pragma once
#include <vector>
namespace ya 
{
	template <typename T>
	class vector
	{
	public:
		//ctrl + m + o 함수 모두 접기
		//ctrl + m + n 함수 하나만 접고 펴기
		vector(size_t cap = DEFAULT_CAP)
			:mArr(new T[cap])
			,mSize(0)
			,mCapacity(cap)
		{

		}
		vector(vector& other)
			:mArr(new T[other.mCapacity])
			, mSize(other.mSize)
			, mCapacity(other.mCapacity)
		{

			for (size_t i = 0; i < other.mSize; i++)
			{
				mArr[i] = other.mArr[i];
			}
		}
		~vector()
		{
			delete[] mArr;
		}

		void push_back(const T& data)
		{
			if (mSize >= mCapacity)
			{
				if (mCapacity < DEFAULT_CAP)
				{
					mCapacity = DEFAULT_CAP;
				}
				else
				{
					int mul = mCapacity *= 2;
					mul -= (mCapacity / 2);
					
				}

				T* newArr = new T[mCapacity];
				for (size_t i = 0; i < mSize; i++)
				{
					newArr[i] = mArr[i];
				}
				delete[] mArr;
				mArr = nullptr;

				mArr = newArr;
			}
			mArr[mSize] = data;
			mSize++;
		}

		vector& operator=(vector& other)
		{
			if(this != nullptr)
			{
				if (mCapacity < other.mCapacity)
				{
					delete[] mArr;
					mArr = nullptr;

					mCapacity = other.mCapacity;
					mArr = new T[mCapacity];
				}

				for (size_t i = 0; i < other.mSize; i++)
				{
					mArr[i] = other.mArr[i];
				}
				mSize = other.mSize;
			}

			return *this;
		}

		T& operator[](size_t idx)
		{
			return mArr[idx];
		}
		
		void pop_back()
		{
			//delete mArr[mSize];
			mSize 
				= mSize > 0 ? mSize - 1 : 0;
			
		}
		bool empty()
		{
			if (mSize > 0)
				return false;
			return true;
		}

		void clear()
		{
			mSize = 0;
		}
		
	public:
		size_t size() { return mSize; }
		size_t capacity() { return mCapacity; }


	private:
		static constexpr size_t DEFAULT_CAP = 32;

		T* mArr;
		size_t mSize;
		size_t mCapacity;

	};

	
}


