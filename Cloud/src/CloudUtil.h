#pragma once

#ifdef CLOUD_WINDOWS
	#ifdef CLOUD_LIB
		#define CLOUD_API __declspec(dllexport)
	#else
		#define CLOUD_API __declspec(dllimport)
	#endif
#else
	#define CLOUD_API
#endif


#define CLOUD_GAME_START(ClassName) \
int main() \
{\
	ClassName game;\
	game.Run();\
	return 0;\
}