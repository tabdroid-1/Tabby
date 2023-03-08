#pragma once

#include <string>

namespace Tabby {

	class FileDialogs
	{
	public:
		// These return empty strings if cancelled
		static std::optional<std::string> OpenFile(const char* filter, const char* filePath);
		static std::optional<std::string> SaveFile(const char* filter, const char* filePath);
	};

}