#ifndef READ_ARGS_H
#define READ_ARGS_H

#include <stddef.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int read_args(FILE *fp, char *buf, size_t bufsize, char **argv, int max_argv);


#ifdef __cplusplus
}
#endif

#endif /* READ_ARGS_H */
