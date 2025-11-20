//
// Created by ádám on 2024. 12. 10..
//

#ifndef CRASHHANDLER_H
#define CRASHHANDLER_H
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
int WINAPI crashhandler(EXCEPTION_POINTERS *ep) {
    unsigned code = ep->ExceptionRecord->ExceptionCode;

    switch (code) {
        case EXCEPTION_ACCESS_VIOLATION:
            fprintf(stderr,"Program crashed: segmentation fault");
            break;
        case EXCEPTION_ILLEGAL_INSTRUCTION:
            fprintf(stderr,"Program crashed: illegal instruction");
            break;
        case EXCEPTION_INT_DIVIDE_BY_ZERO:
            fprintf(stderr,"You tried to divide by zero dumbass");
            break;
        case EXCEPTION_STACK_OVERFLOW:
            fprintf(stderr,"Program crashed: stack overflow");
            break;
        default:
            fprintf(stderr,"Unhandled exception: 0x%08X\n", code);
    }

    fflush(stdout);

    // end with the same code Windows would give
    ExitProcess(code);
}
#define INIT_CRASH_HANDLER SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER) crashhandler)
#endif //CRASHHANDLER_H

