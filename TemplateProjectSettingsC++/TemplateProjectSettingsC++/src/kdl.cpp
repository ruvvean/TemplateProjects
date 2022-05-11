#include "kdl.h"
#include "pch.h"

bool kdl::saveToFile(const char* fileName, const std::string& data)
{
	std::fstream file;
	file.open(fileName, std::ios::out);
	if (file.good())
	{
		file << data;
		file.close();
		return true;
	}
	file.close();
	return false;
}

bool kdl::saveToFile(const std::string& fileName, const std::string& data)
{
	return saveToFile(fileName.c_str(), data);
}

bool kdl::loadFromFile(const char* fileName, std::string& data)
{
	std::fstream file;
	file.open(fileName, std::ios::in);
	bool first = false;
	std::string tmp;
	if (file.good())
	{
		while (!file.eof())
		{
			tmp.clear();
			std::getline(file, tmp);
			data += tmp;
			data += "\n";
		}
		data.erase(data.end());
		file.close();
		return true;
	}
	file.close();
	return false;
}

bool kdl::loadFromFile(const std::string& fileName, std::string& data)
{
	return loadFromFile(fileName.c_str(), data);
}

char kdl::generateNumber(char begin, char end)
{
	return begin + static_cast<char>(rand()) % (end - begin + 1);
}

short kdl::generateNumber(short begin, short end)
{
	return begin + static_cast<short>(rand()) % (end - begin + 1);
}

int kdl::generateNumber(int begin, int end)
{
	return begin + static_cast<int>(rand()) % (end - begin + 1);
}

long kdl::generateNumber(long begin, long end)
{
	return begin + static_cast<long>(rand()) % (end - begin + 1);
}

long long kdl::generateNumber(long long begin, long long end)
{
	return begin + static_cast<long long>(rand()) % (end - begin + 1);
}

unsigned char kdl::generateNumber(unsigned char begin, unsigned char end)
{
	return begin + static_cast<unsigned char>(rand()) % (end - begin + 1);
}

unsigned short kdl::generateNumber(unsigned short begin, unsigned short end)
{
	return begin + static_cast<unsigned short>(rand()) % (end - begin + 1);
}

unsigned int kdl::generateNumber(unsigned int begin, unsigned int end)
{
	return begin + static_cast<unsigned int>(rand()) % (end - begin + 1);
}

unsigned long kdl::generateNumber(unsigned long begin, unsigned long end)
{
	return begin + static_cast<unsigned long>(rand()) % (end - begin + 1);
}

unsigned long long kdl::generateNumber(unsigned long long begin, unsigned long long end)
{
	return begin + static_cast<unsigned long long>(rand()) % (end - begin + 1);
}

float kdl::generateNumber(float begin, float end)
{
	return begin + static_cast<float>(rand()) / RAND_MAX * (end - begin);
}

double kdl::generateNumber(double begin, double end)
{
	return begin + static_cast<double>(rand()) / RAND_MAX * (end - begin);
}

long double kdl::generateNumber(long double begin, long double end)
{
	return begin + static_cast<long double>(rand()) / RAND_MAX * (end - begin);
}

kdl::Timer::Timer() :m_Output(std::string())
{
	this->m_StartTimepoint = std::chrono::high_resolution_clock::now();
}

kdl::Timer::Timer(const char* output) : m_Output(output)
{
	this->m_StartTimepoint = std::chrono::high_resolution_clock::now();
}

kdl::Timer::Timer(std::string& output) : m_Output(output)
{
	this->m_StartTimepoint = std::chrono::high_resolution_clock::now();
}

kdl::Timer::~Timer()
{
	this->stop();
}

void kdl::Timer::stop()
{
	this->m_EndTimepoint = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::time_point_cast<std::chrono::microseconds>(this->m_EndTimepoint).time_since_epoch().count() - std::chrono::time_point_cast<std::chrono::microseconds>(this->m_StartTimepoint).time_since_epoch().count();
	if (this->m_Output.empty())
		std::cout << "Execution time: " << duration << " us" << "(" << duration * 0.001 << " ms)\n";
	else
		std::cout << "Execution of " << this->m_Output << " time: " << duration << " us" << "(" << duration * 0.001 << " ms)\n";
}

void kdl::Timer::start()
{
	this->m_StartTimepoint = std::chrono::high_resolution_clock::now();
}


