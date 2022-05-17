/*
	Kacper Domagala's basic library
	Last edit 14/04/2022
	Added output in timer

	Templater settings:
	Icon & preview image: https://www.pngwing.com/en/free-png-nwuho
	Description: C++ project template with main function, kdl and pch.
*/
#pragma once
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

	//generate random number of type based on type of parameters
	char generateNumber(char begin, char end);
	//generate random number of type based on type of parameters
	short generateNumber(short begin, short end);
	//generate random number of type based on type of parameters
	int generateNumber(int begin, int end);
	//generate random number of type based on type of parameters
	long generateNumber(long begin, long end);
	//generate random number of type based on type of parameters
	long long generateNumber(long long begin, long long end);
	//generate random number of type based on type of parameters
	unsigned char generateNumber(unsigned char begin, unsigned char end);
	//generate random number of type based on type of parameters
	unsigned short generateNumber(unsigned short begin, unsigned short end);
	//generate random number of type based on type of parameters
	unsigned int generateNumber(unsigned int begin, unsigned int end);
	//generate random number of type based on type of parameters
	unsigned long generateNumber(unsigned long begin, unsigned long end);
	//generate random number of type based on type of parameters
	unsigned long long generateNumber(unsigned long long begin, unsigned long long end);

	//generate random number of type based on type of parameters
	float generateNumber(float begin, float end);
	//generate random number of type based on type of parameters
	double generateNumber(double begin, double end);
	//generate random number of type based on type of parameters
	long double generateNumber(long double begin, long double end);

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
		Timer(const char* output);
		Timer(std::string& output);
		Timer(const Timer& t) = delete;
		Timer(Timer& t) = delete;
		Timer(Timer&& t) = delete;
		~Timer();
		void stop();
		void start();
	};

	class SetCursorPosition
	{
	private:
		HANDLE m_handle;
		static SetCursorPosition s_instance;
		SetCursorPosition();
		void m_set(unsigned y);
		void m_set(unsigned int x, unsigned int y);
	public:
		SetCursorPosition(const SetCursorPosition& c) = delete;
		SetCursorPosition(const SetCursorPosition&& c) = delete;
		SetCursorPosition(SetCursorPosition& c) = delete;
		SetCursorPosition(SetCursorPosition&& c) = delete;
		static SetCursorPosition& get();
		static void set(unsigned int y);
		static void set(unsigned int x, unsigned int y);
	};
}