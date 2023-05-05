#pragma once

#include "pch.h"
#include "CloudUtil.h"
//#include "ImplImage.h"

namespace Cloud
{
	class CLOUD_API Image
	{
	public:
		Image(const std::string& imageFile);
		Image(std::string&& imageFile);

		void Activate();

		int GetWidth() const;
		int GetHeight() const;

	private:
		//ImplImage* mImplementation{ nullptr };
	};

}