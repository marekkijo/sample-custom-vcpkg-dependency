#pragma once

#if defined(_WIN32)
#if defined(LIBDEPENDENCY_SHARED)
#if defined(LIBDEPENDENCY_EXPORTS)
#define LIBDEPENDENCY_API __declspec(dllexport)
#else
#define LIBDEPENDENCY_API __declspec(dllimport)
#endif
#else
#define LIBDEPENDENCY_API
#endif
#else
#define LIBDEPENDENCY_API
#endif
