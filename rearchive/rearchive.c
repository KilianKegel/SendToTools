/*!
@copyright
    Copyright (c) 2019, MinnowWare. All rights reserved.
    This program and the accompanying materials are licensed and made
    available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license
    may be found at
    http://opensource.org/licenses/bsd-license.php
    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
@file unarchive.c
@brief reset the archive attributes, recursively for directories 

@details reset the archive attributes, recursively for directories.
        Best for usage in the Windows "sendto" folder

@todo
@mainpage
    rearchive support tool
@section intro_sec Introduction
    rearchive sets the archive attribute on given files and directories, passed
    in the command line

@subsection Parm_sec Command line parameters
    1. unarchive file1 file2 dir1 dir2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    int i,isdir;
    FILE* fp;
    char* pCmdLine;
    char* aszAttribParms0[] = {{"attrib +a \""},{"attrib +a /s \""}};
    char* aszAttribParms1[] = {{"\""},{"\"\\*.*"}};

    for (i = 1; i < argc; i++) {
        
        fp = fopen(argv[i], "rb");
        isdir = fp == NULL;

        if(!isdir)
            fclose(fp);

        pCmdLine = malloc(2 + strlen(aszAttribParms0[isdir]) + strlen(aszAttribParms1[isdir]) + strlen(argv[i]));

        strcpy(pCmdLine, aszAttribParms0[isdir]);

        strcat(pCmdLine, argv[i]);

        strcat(pCmdLine, aszAttribParms1[isdir]);

//        printf("%s\n", pCmdLine);
        system(pCmdLine);

        free(pCmdLine);
    }
//    printf("any ENTER...\n");getchar();
}