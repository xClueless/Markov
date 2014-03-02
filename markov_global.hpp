#ifndef MARKOV_GLOBAL_HPP
#define MARKOV_GLOBAL_HPP

#include <QtCore/qglobal.h>

#if defined(MARKOV_LIBRARY)
#  define MARKOVSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MARKOVSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MARKOV_GLOBAL_HPP
