#ifndef BSHUFFLESESSION_GLOBAL_H
#define BSHUFFLESESSION_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BSHUFFLESESSION_LIBRARY)
#  define BSHUFFLESESSIONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BSHUFFLESESSIONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BSHUFFLESESSION_GLOBAL_H
