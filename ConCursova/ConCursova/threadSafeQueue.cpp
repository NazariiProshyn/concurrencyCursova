/**
 * @file      threadSafeQueue.cpp
 *
 * @brief     Realization of Thread-safe
 *            structure <queue> 
 *
 * @author    Proshyn Nazarii
 * Contact:   nazariyproshyn@gmail.com
 *
 */

#include "threadSafeQueue.h"


void ThreadSafeQueue::push(std::function<void(int, int, std::function<double(int, int)>)> funct, int i, int j, std::function<double(int, int)> value)
{
	std::lock_guard<std::mutex> lock(mut);
	dataQueue.push(std::move(funct));
	iQueue.push(i);
	jQueue.push(j);
	valueQueue.push(value);
	condVar.notify_one();
}

std::function<void(int, int, std::function<double(int, int)>)> ThreadSafeQueue::pop()
{
	std::unique_lock<std::mutex> lock(mut);
	condVar.wait(lock, [this] {return !dataQueue.empty(); });

	std::function<void(int, int, std::function<double(int, int)>)> value = std::move(dataQueue.front());
	dataQueue.pop();
	return value;
}

int ThreadSafeQueue::popI()
{
	std::unique_lock<std::mutex> lock(mut);
	condVar.wait(lock, [this] {return !iQueue.empty(); });

	int value = iQueue.front();
	iQueue.pop();
	return value;
}

int ThreadSafeQueue::popJ()
{
	std::unique_lock<std::mutex> lock(mut);
	condVar.wait(lock, [this] {return !jQueue.empty(); });

	int value = jQueue.front();
	jQueue.pop();
	return value;
}

std::function<double(int, int)> ThreadSafeQueue::popValue()
{
	std::unique_lock<std::mutex> lock(mut);
	condVar.wait(lock, [this] {return !valueQueue.empty(); });

	std::function<double(int, int)> value = std::move(valueQueue.front());
	valueQueue.pop();
	return value;
}

size_t ThreadSafeQueue::size() const
{
	std::lock_guard<std::mutex> lock(mut);
	return dataQueue.size();
}
