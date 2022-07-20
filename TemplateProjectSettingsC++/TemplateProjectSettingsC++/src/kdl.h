/*
	Kacper Domagala's basic library
	Last edit 21/05/2022
	Changed from unsigned int to short in set cursor position and added new line in timer

	Template settings:
	Icon & preview image: https://www.pngwing.com/en/free-png-nwuho
	Description: C++ project template with main function, kdl and pch.
*/
#pragma once
#ifndef KDL_LIBRARY
#define KDL_LIBRARY

#include "pch.h"

#define KDL_SRAND srand(static_cast<unsigned int>(time(nullptr)))

namespace kdl
{
	enum class OrderBy {
		ASC = 0, DESC
	};
	//functions:

	//save data to file
	bool saveToFile(const char* fileName, const std::string& data);
	//save data to file
	bool saveToFile(const std::string& fileName, const std::string& data);

	//load data from file to std::string
	bool loadFromFile(const char* fileName, std::string& data);
	//save data to file
	bool loadFromFile(const std::string& fileName, std::string& data);

	template<typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
	T randomF(T min = 0, T max = UINT_MAX)
	{
		static std::random_device dev;
		static std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
		return dist(rng);
	}

	template<typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
	T randomF(T min = .0, T max = std::numeric_limits<T>::max)
	{
		static std::random_device dev;
		static std::mt19937 rng(dev());
		std::uniform_real_distribution<T> dist(min, max);
		return dist(rng);
	}

	//---------------------------------------------------------------

	//templates functions:

	template<class Iterator>
	void displayArray(Iterator first, Iterator last, OrderBy orderBy = OrderBy::ASC)
	{
		Iterator data;
		if (orderBy == OrderBy::ASC)
			data = first;
		if (orderBy == OrderBy::DESC)
			data = last;

		switch (orderBy)
		{
		case OrderBy::ASC:
			while (data != last)
			{
				std::cout << *data << std::endl;
				data++;
			}
			break;
		case OrderBy::DESC:
			while (data != first)
			{
				data--;
				std::cout << *data << std::endl;
			}
			break;
		}
	}

	template<typename T>
	void displayArray(T* tab, size_t size, OrderBy orderBy = OrderBy::ASC)
	{
		switch (orderBy)
		{
		case OrderBy::ASC:
			for (size_t i = 0; i < size; i++)
				std::cout << tab[i] << std::endl;
			break;
		case OrderBy::DESC:
			size_t _size = size - 1;
			do {
				std::cout << tab[_size] << std::endl;
				_size--;
			} while (_size != 0);
			break;
		}

	}

	template<typename T>
	void print(const T& data)
	{
		std::cout << data;
	}

	template<typename T>
	void printN(const T& data)
	{
		std::cout << data << std::endl;
	}

	//---------------------------------------------------------------


	//classes:

	class Timer
	{
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_EndTimepoint;
		std::string m_Output;
	public:
		Timer();
		explicit Timer(const char* output);
		explicit Timer(const std::string& output);
		Timer(const Timer& t) = delete;
		Timer(Timer& t) = delete;
		Timer(Timer&& t) = delete;
		~Timer();
		void stop();
		void start();
	};
}

#endif // KDL_LIBRARY