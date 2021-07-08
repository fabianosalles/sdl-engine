#pragma once

template <typename T>
class Singleton
{
public:
	static auto& instance() {
		static T _instance;
		return _instance;
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton&&) = delete;
};

