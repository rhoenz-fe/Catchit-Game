#pragma once

#include "pch.h"
#include "CloudUtil.h"
#include "CloudEvents.h"

constexpr int FPS{ 60 };

namespace Cloud
{

	class CLOUD_API CloudApp
	{
	public:
		virtual void OnUpdate() = 0;

		CloudApp();

		void Run();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function <void()> callbackFunc);

	private:
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;

		bool mGameWindowShouldClose{ false };

		void DefaultWindowCloseHandler();
	};

}
