/**
 * @Author: Xia Yunkai
 * @Date:   2024-11-16 20:33:15
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-12-09 15:44:53
 */

#ifndef __XVIZ_LOG_H__
#define __XVIZ_LOG_H__

#ifdef __cplusplus

extern "C"
{
#endif
    void LogPrintf(const int log_level, const char *func_name, const char *file_name,
                   int line, const char *fmt, ...);
#ifdef __cplusplus
}
#endif

#define XVIZ_TRACE(fmt, ...) LogPrintf(6, __func__, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define XVIZ_DEBUG(fmt, ...) LogPrintf(5, __func__, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define XVIZ_INFO(fmt, ...) LogPrintf(4, __func__, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define XVIZ_WARN(fmt, ...) LogPrintf(2, __func__, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define XVIZ_ERROR(fmt, ...) LogPrintf(1, __func__, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define XVIZ_CRITICAL(fmt, ...) LogPrintf(0, __func__, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#endif /* __XVIZ_LOG_H__ */
