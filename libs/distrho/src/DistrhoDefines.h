/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2014 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef DISTRHO_DEFINES_H_INCLUDED
#define DISTRHO_DEFINES_H_INCLUDED

#include "DistrhoPluginInfo.h"

#ifndef DISTRHO_PLUGIN_NAME
# error DISTRHO_PLUGIN_NAME undefined!
#endif

#ifndef DISTRHO_PLUGIN_HAS_UI
# error DISTRHO_PLUGIN_HAS_UI undefined!
#endif

#ifndef DISTRHO_PLUGIN_IS_SYNTH
# error DISTRHO_PLUGIN_IS_SYNTH undefined!
#endif

#ifndef DISTRHO_PLUGIN_NUM_INPUTS
# error DISTRHO_PLUGIN_NUM_INPUTS undefined!
#endif

#ifndef DISTRHO_PLUGIN_NUM_OUTPUTS
# error DISTRHO_PLUGIN_NUM_OUTPUTS undefined!
#endif

#ifndef DISTRHO_PLUGIN_WANT_LATENCY
# error DISTRHO_PLUGIN_WANT_LATENCY undefined!
#endif

#ifndef DISTRHO_PLUGIN_WANT_PROGRAMS
# error DISTRHO_PLUGIN_WANT_PROGRAMS undefined!
#endif

#ifndef DISTRHO_PLUGIN_WANT_STATE
# error DISTRHO_PLUGIN_WANT_STATE undefined!
#endif

#ifndef DISTRHO_PLUGIN_WANT_TIMEPOS
# error DISTRHO_PLUGIN_WANT_TIMEPOS undefined!
#endif

#ifndef DISTRHO_PLUGIN_WANT_DIRECT_ACCESS
# define DISTRHO_PLUGIN_WANT_DIRECT_ACCESS 0
#endif

/* Compatibility with non-clang compilers */
#ifndef __has_feature
# define __has_feature(x) 0
#endif
#ifndef __has_extension
# define __has_extension __has_feature
#endif

/* Check OS */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
# define DISTRHO_PLUGIN_EXPORT extern "C" __declspec (dllexport)
# define DISTRHO_OS_WINDOWS    1
# define DISTRHO_DLL_EXTENSION "dll"
#else
# define DISTRHO_PLUGIN_EXPORT extern "C" __attribute__ ((visibility("default")))
# if defined(__APPLE__)
#  define DISTRHO_OS_MAC        1
#  define DISTRHO_DLL_EXTENSION "dylib"
# elif defined(__HAIKU__)
#  define DISTRHO_OS_HAIKU      1
#  define DISTRHO_DLL_EXTENSION "so"
# elif defined(__linux__)
#  define DISTRHO_OS_LINUX      1
#  define DISTRHO_DLL_EXTENSION "so"
# endif
#endif

#ifndef DISTRHO_DLL_EXTENSION
# define DISTRHO_DLL_EXTENSION "so"
#endif

/* Check for C++11 support */
#if defined(HAVE_CPP11_SUPPORT)
# define PROPER_CPP11_SUPPORT
#elif __cplusplus >= 201103L || (defined(__GNUC__) && defined(__GXX_EXPERIMENTAL_CXX0X__) && (__GNUC__ * 100 + __GNUC_MINOR__) >= 405) || __has_extension(cxx_noexcept)
# define PROPER_CPP11_SUPPORT
# if (defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__) < 407) || ! __has_extension(cxx_override_control)
#  define override // gcc4.7+ only
#  define final    // gcc4.7+ only
# endif
#endif

#ifndef PROPER_CPP11_SUPPORT
# define noexcept throw()
# define override
# define final
# define nullptr (0)
#endif

/* Define namespace */
#ifndef DISTRHO_NO_NAMESPACE
# ifndef DISTRHO_NAMESPACE
#  define DISTRHO_NAMESPACE DISTRHO
# endif
# define START_NAMESPACE_DISTRHO namespace DISTRHO_NAMESPACE {
# define END_NAMESPACE_DISTRHO }
# define USE_NAMESPACE_DISTRHO using namespace DISTRHO_NAMESPACE;
#else
# define START_NAMESPACE_DISTRHO
# define END_NAMESPACE_DISTRHO
# define USE_NAMESPACE_DISTRHO
#endif

#define DISTRHO_UI_URI DISTRHO_PLUGIN_URI "#UI"

#endif // DISTRHO_DEFINES_H_INCLUDED
