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

#if CLOUD_DEBUG==2
	#define CLOUD_LOG(x) std::clog<<"Log: "<<x<<std::endl;
	#define CLOUD_ERROR(x) std::cerr<<"ERROR: "<<x<<std::endl;
#elif CLOUD_DEBUG==1
	#define CLOUD_LOG(x)
	#define CLOUD_ERROR(x) std::cerr<<"ERROR: "<<x<<std::endl;
#else
	#define CLOUD_LOG(x)
	#define CLOUD_ERROR(x)
#endif