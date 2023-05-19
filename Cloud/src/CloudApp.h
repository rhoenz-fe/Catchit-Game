#pragma once

#include "pch.h"
#include "CloudUtil.h"

constexpr int FPS{ 60 };

namespace Cloud
{

	class CLOUD_API CloudApp
	{
	public:
		virtual void OnUpdate() = 0;

		void Run();

	private:
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};

}
