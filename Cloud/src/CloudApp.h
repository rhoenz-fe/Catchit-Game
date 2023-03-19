#pragma once

#include "CloudUtil.h"

namespace Cloud
{

	class CLOUD_API CloudApp
	{
	public:
		virtual void OnUpdate() = 0;

		void Run();

	private:

	};

}
