#pragma once

#include <windows.h>
#include <ostream>
#include <sstream>
#include <string_view>

struct cdebug_t : std::streambuf, std::ostream
{
  cdebug_t() : std::ostream(this) {}

  std::streambuf::int_type overflow(std::streambuf::int_type c)
  {
    char v[2] = {(char)c, 0};
    OutputDebugStringA(v);
    return 0;
  }
};

inline cdebug_t &operator<<(cdebug_t &os, const wchar_t *v)
{
  OutputDebugStringW(v);
  return os;
}

inline cdebug_t &operator<<(cdebug_t &os, const char *v)
{
  OutputDebugStringA(v);
  return os;
}

inline cdebug_t &operator<<(cdebug_t &os, const std::string &v)
{
  OutputDebugStringA(v.c_str());
  return os;
}

inline cdebug_t &operator<<(cdebug_t &os, const std::wstring &v)
{
  OutputDebugStringW(v.c_str());
  return os;
}

inline cdebug_t &operator<<(cdebug_t &os, const std::string_view &v)
{
  OutputDebugStringA(v.data());
  return os;
}

inline cdebug_t &operator<<(cdebug_t &os, const std::wstring_view &v)
{
  OutputDebugStringW(v.data());
  return os;
}

__declspec(selectany) cdebug_t cdebug;

#define DEBUG_HRESULT_ERROR(e)                    \
  cdebug << __FILE__ << " (" << __LINE__ << ") "; \
  cdebug.flush();                                 \
  cdebug << e.message().c_str() << std::endl;
