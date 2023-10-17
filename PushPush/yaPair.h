#pragma once
#define MOVE(x) std::forward(x)
namespace ya
{
	template<typename T1, typename T2>
	class pair
	{
	public:
		pair()
			: first( T1() ), second( T2() )
		{

		}

	
		pair(const T1& f ,const T2& s)
			: first(f), second(s)
		{

		}

		//ÀÌµ¿ ÀÎÀÚ
		//'A' std::string
		template<typename U1, typename U2>
		pair( U1&& f, U2&& s)
			: first(std::forward<U1>(f)), second(std::forward<U2>(s))
		{
		
		}

		//¾ÆÁÖ µöÇÑ ³»¿ë


		template<typename U1, typename U2>
		pair(const pair<U1, U2>& other)
			: first(other.first) , second(other.second)
		{

		}

		template<typename U1, typename U2>
		pair(const pair<U1, U2>&& other) : first(MOVE(other.first)) , second(std::forward(other.second))
		{
			
		}


		~pair() = default; 

	
		void swap(pair& other)
		{
			std::swap(first, other.first);
			std::swap(second, other.second);
		}

	public:

		pair& operator=(const pair& other)
		{
			first = other.first;
			second = other.second;

			return *this;
		}

		pair& operator=(const pair&& other)
		{
			first = std::move(other.first);
			second = std::move(other.second);
			

			return *this;
		}


		bool operator==(const pair& other) const {
			//¼÷Á¦
			if (first == other.first && second == other.second)
				return true;
			else
			{
				return false;
			}
			
		}
		bool operator!=(const pair& other) const {
			//¼÷Á¦'
			if (first == other.first && second == other.second)
				return false;
			else
			{
				return true;
			}
			
		}
		bool operator<(const pair& other) const {
			if (first < other.first && second < other.second)
				return true;
			return false;
			//¼÷Á¦
		}
		bool operator<=(const pair& other) const {
			if (first <= other.first && second <= other.second)
				return true;
			return false;
			//¼÷Á¦
		}
		bool operator>(const pair& other) const {
			//¼÷Á¦
			if (first > other.first && second > other.second)
				return true;
			return false;
		}
		bool operator>=(const pair& other) const {
			//¼÷Á¦
			if (first >= other.first && second >= other.second)
				return true;
			return false;
		}




	public:
		T1 first;
		T2 second;
	};
}