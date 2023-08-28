#pragma once

#if defined(_WIN32) || defined(WIN32)
#   ifdef MATHLIBRARY_EXPORTS
#       define MATHLIBRARY_API __declspec(dllexport)
#   else
#       define MATHLIBRARY_API __declspec(dllimport)
#   endif
#else
#   define MATHLIBRARY_API
#endif
