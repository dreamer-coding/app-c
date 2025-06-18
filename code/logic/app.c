/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/code/app.h"
#include <unistd.h>


void show_commands() {
    printf("Usage: fossil_app [OPTIONS]\n");
    printf("  --help           Show this help message\n");
    printf("  --version        Show version information\n");
    printf("  color            Enable colored output ('enable'/disable/auto)\n");
    exit(0);
}

void show_version() {
    printf("%s version %s\n", FOSSIL_APP_NAME, FOSSIL_APP_VERSION);
    exit(0);
}

bool app_entry(int argc, char** argv) {
    bool color_enabled = false;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--help") == 0) {
            show_commands();
        } else if (strcmp(argv[i], "--version") == 0) {
            show_version();
        } else if (strcmp(argv[i], "color") == 0) {
            if (i + 1 < argc) {
                if (strcmp(argv[i + 1], "enable") == 0) {
                    FOSSIL_IO_COLOR_ENABLE = true;
                } else if (strcmp(argv[i + 1], "disable") == 0) {
                    FOSSIL_IO_COLOR_ENABLE = false;
                } else if (strcmp(argv[i + 1], "auto") == 0) {
                    FOSSIL_IO_COLOR_ENABLE = isatty(STDOUT_FILENO);
                }
                ++i; // Skip next argument
            }
        }
    }

    return 0;
}
