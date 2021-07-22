// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cdebug.h>
#include <string_view>
#include <winrt/base.h>

int main()
{
  cdebug << "const char*";
  cdebug << L"Wide char";
  cdebug << 123;

  std::string str{ "hello" };
  cdebug << str;

  std::wstring wstr{ L"hello" };
  cdebug << wstr;

  std::string_view sv{ "string_view" };
  cdebug << sv;

  std::wstring_view wsv{ L"wstring_view" };
  cdebug << wsv;

  char buf[] = { 'B', 'u', 'f', '\0' };
  cdebug << buf;

  char buf2[4] = { 'B', 'u', 'f', '\0' };
  cdebug << buf2;

  cdebug << winrt::hstring(L"hstring");

}

