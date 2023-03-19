#include "pch.h"
#include "CloudApp.h"


namespace Cloud 
{

	void CloudApp::Run()
	{
		while (true)
		{
			OnUpdate();
		}
	}

}