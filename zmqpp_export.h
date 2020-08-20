
#ifndef ZMQPP_EXPORT_H
#define ZMQPP_EXPORT_H

#ifdef ZMQPP_STATIC_DEFINE
#  define ZMQPP_EXPORT
#  define ZMQPP_NO_EXPORT
#else
#  ifndef ZMQPP_EXPORT
#    ifdef zmqpp_EXPORTS
        /* We are building this library */
#      define ZMQPP_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ZMQPP_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ZMQPP_NO_EXPORT
#    define ZMQPP_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ZMQPP_DEPRECATED
#  define ZMQPP_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ZMQPP_DEPRECATED_EXPORT
#  define ZMQPP_DEPRECATED_EXPORT ZMQPP_EXPORT ZMQPP_DEPRECATED
#endif

#ifndef ZMQPP_DEPRECATED_NO_EXPORT
#  define ZMQPP_DEPRECATED_NO_EXPORT ZMQPP_NO_EXPORT ZMQPP_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ZMQPP_NO_DEPRECATED
#    define ZMQPP_NO_DEPRECATED
#  endif
#endif

#endif /* ZMQPP_EXPORT_H */
