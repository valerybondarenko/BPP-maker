#ifndef RU_TCL_DXF_DEFS_H
#define RU_TCL_DXF_DEFS_H

#if defined(_BUILD_TCL_DXF_DLL)
#    define _TCL_DXF_CLASS  __export
#elif defined(_TCL_DXF_DLL)
#    define _TCL_DXF_CLASS  __import
#else
#    define _TCL_DXF_CLASS
#endif

#endif  // RU_TCL_DXF_DEFS_H
