#pragma once

enum _logTypeCCN {
    InfoCCNlogType,
    DebugCCNlogType,
    FatalCCNlogType,
    WarnCCNlogType,
    ErrorCCNlogType
};

extern void _CCNlogHandler(enum _logTypeCCN type, const char *file, const char *func, unsigned int line, const char *format, ...);

#ifndef NDEBUG
#define CCNlogInfo(...) (_CCNlogHandler(InfoCCNlogType, __FILE__, __func__, __LINE__, __VA_ARGS__))
#define CCNlogDebug(...) (_CCNlogHandler(DebugCCNlogType, __FILE__, __func__, __LINE__, __VA_ARGS__))
#define CCNlogFatal(...) (_CCNlogHandler(FatalCCNlogType, __FILE__, __func__, __LINE__, __VA_ARGS__))
#define CCNlogWarn(...) (_CCNlogHandler(WarnCCNlogType, __FILE__, __func__, __LINE__, __VA_ARGS__))
#define CCNlogError(...) (_CCNlogHandler(ErrorCCNlogType, __FILE__, __func__, __LINE__, __VA_ARGS__))
#else
#define CCNlogInfo(...) (void(0))
#define CCNlogDebug(...) (void(0)) 
#define CCNlogFatal(...) (void(0))
#define CCNlogWarn(...) (void(0))
#define CCNlogError(...) (void(0))
#endif

