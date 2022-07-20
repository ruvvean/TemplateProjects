#include "kdl.h"
#include "pch.h"


using namespace kdl;

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

kdl::Timer::Timer() :m_Output(std::string())
{
	this->m_StartTimepoint = std::chrono::high_resolution_clock::now();
}

kdl::Timer::Timer(const char* output) : m_Output(output)
{
	this->m_StartTimepoint = std::chrono::high_resolution_clock::now();
}

kdl::Timer::Timer(const std::string& output) : m_Output(output.c_str())
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
	std::cout.precision(5);
	std::cout.setf(std::ios::fixed);
	if (this->m_Output.empty())
		std::cout << "\nExecution time: " << duration << " us" << "(" << static_cast<long>(duration) * 0.001 << " ms)\n";
	else
		std::cout << "\nExecution of " << this->m_Output << " time: " << duration << " us" << "(" << static_cast<long>(duration) * 0.001 << " ms)\n";
}

void kdl::Timer::start()
{
	this->m_StartTimepoint = std::chrono::high_resolution_clock::now();
}